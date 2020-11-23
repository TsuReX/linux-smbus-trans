#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#include <errno.h>
#include <unistd.h>

int32_t i2c_smbus_access(int file, char read_write, __u8 command,
		       int size, union i2c_smbus_data *data)
{
	struct i2c_smbus_ioctl_data args;
	int32_t err;

	args.read_write = read_write;
	args.command = command;
	args.size = size;
	args.data = data;

	err = ioctl(file, I2C_SMBUS, &args);
	if (err == -1)
		err = -errno;
	return err;
}

int32_t i2c_smbus_read_byte_data(int file, __u8 command)
{
	union i2c_smbus_data data;
	int err;

	err = i2c_smbus_access(file, I2C_SMBUS_READ, command,
			       I2C_SMBUS_BYTE_DATA, &data);
	if (err < 0)
		return err;

	return 0x0FF & data.byte;
}

int32_t main(int32_t argc, const char *argv[])
{
	printf("linux-smbus-trans\n");

	if (argc != 3) {
		printf("Invalid arguments count\n");
		return -1;
	}

//	int32_t adapter_nr = 2; /* probably dynamically determined */
//	char filename[512];
//	snprintf(filename, sizeof(filename) - 1, argv[2], adapter_nr);
//	file = open(filename, O_RDWR);

	int32_t i2c_bus_file = open(argv[1], O_RDWR);
	if (i2c_bus_file < 0) {
		perror("Function open() returned with error");
		return -2;
	}
	printf("File %s opened\n", argv[1]);

//	int32_t dev_bus_addr = atoi(argv[2]);
	int32_t dev_bus_addr = 0;
	sscanf(argv[2], "0x%02X", &dev_bus_addr);
	if (ioctl(i2c_bus_file, I2C_SLAVE, dev_bus_addr) < 0) {
		perror("Function ioctl() returned with error");
		close(i2c_bus_file);
		return -3;
	}

	uint32_t dev_reg_num = 0x00; /* Device register to access */
	int32_t ret_val;

	for (; dev_reg_num <= 0xFF; ++dev_reg_num) {
		/* Using SMBus commands */
		ret_val = i2c_smbus_read_byte_data(i2c_bus_file, dev_reg_num);
//		if (ret_val < 0) {
//			perror("Function i2c_smbus_read_byte_data() returned with error");
//			/* ERROR HANDLING: i2c transaction failed */
//			close(i2c_bus_file);
//			return -4;
//		}
		if (ret_val < 0) {
//			printf("%02X:XX ",dev_reg_num);
			printf("XX ");
		} else {
//			printf("%02X:%02X ", dev_reg_num, ret_val);
			printf("%02X ", ret_val);
		}
		if (((dev_reg_num + 1) % 16) == 0 && dev_reg_num != 0)
			printf("\n");

		fflush(stdout);
	}

	return 0;
}
