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

struct mps_register {
	uint8_t		addr;
	uint8_t		length;
	uint16_t	data;
};

struct mps_register page0 [] = {
		{0x01, 0x01, 0xFFFF},
		{0x10, 0x01, 0xFFFF},
		{0x1B, 0x02, 0xFFFF},
		{0x21, 0x02, 0xFFFF},
		{0x22, 0x02, 0xFFFF},
		{0x24, 0x02, 0xFFFF},
		{0x25, 0x02, 0xFFFF},
		{0x26, 0x02, 0xFFFF},
		{0x27, 0x02, 0xFFFF},
		{0x29, 0x02, 0xFFFF},
		{0x35, 0x02, 0xFFFF},
		{0x36, 0x02, 0xFFFF},
		{0x3C, 0x02, 0xFFFF},
		{0x4F, 0x02, 0xFFFF},
		{0x50, 0x01, 0xFFFF},
		{0x51, 0x02, 0xFFFF},
		{0x52, 0x02, 0xFFFF},
		{0x53, 0x02, 0xFFFF},
		{0x54, 0x02, 0xFFFF},
		{0x55, 0x02, 0xFFFF},
		{0x56, 0x02, 0xFFFF},
		{0x57, 0x02, 0xFFFF},
		{0x58, 0x02, 0xFFFF},
		{0x59, 0x02, 0xFFFF},
		{0x5A, 0x02, 0xFFFF},
		{0x5B, 0x02, 0xFFFF},
		{0x5C, 0x02, 0xFFFF},
		{0x5D, 0x02, 0xFFFF},
		{0x5E, 0x02, 0xFFFF},
		{0x5F, 0x02, 0xFFFF},
		{0x60, 0x02, 0xFFFF},
		{0x61, 0x02, 0xFFFF},
		{0x62, 0x02, 0xFFFF},
		{0x63, 0x02, 0xFFFF},
		{0x64, 0x02, 0xFFFF},
		{0x65, 0x02, 0xFFFF},
		{0x66, 0x02, 0xFFFF},
		{0x68, 0x02, 0xFFFF},
		{0x69, 0x02, 0xFFFF},
		{0x6A, 0x02, 0xFFFF},
		{0x6B, 0x02, 0xFFFF},
		{0x6C, 0x02, 0xFFFF},
		{0x6D, 0x02, 0xFFFF},
		{0x6E, 0x02, 0xFFFF},
		{0x6F, 0x02, 0xFFFF},
		{0x72, 0x02, 0xFFFF},
		{0x73, 0x02, 0xFFFF},
		{0x74, 0x02, 0xFFFF},
		{0x75, 0x02, 0xFFFF},
		{0x76, 0x02, 0xFFFF},
		{0x99, 0x02, 0xFFFF},
		{0x9A, 0x02, 0xFFFF},
		{0x9B, 0x02, 0xFFFF},
		{0x9C, 0x02, 0xFFFF},
		{0x9D, 0x02, 0xFFFF},
		{0x9E, 0x02, 0xFFFF},
		{0x9F, 0x02, 0xFFFF},
		{0xB7, 0x02, 0xFFFF},
		{0xBF, 0x02, 0xFFFF},
		{0xC2, 0x02, 0xFFFF},
		{0xC3, 0x02, 0xFFFF},
		{0xE5, 0x02, 0xFFFF},
		{0xE6, 0x02, 0xFFFF},
		{0xF0, 0x02, 0xFFFF},
		{0xFF, 0xFF, 0xFFFF},
};

struct mps_register page1 [] = {
		{0x01, 0x01, 0xFFFF},
		{0x04, 0x02, 0xFFFF},
		{0x06, 0x02, 0xFFFF},
		{0x07, 0x02, 0xFFFF},
		{0x08, 0x02, 0xFFFF},
		{0x09, 0x02, 0xFFFF},
		{0x0A, 0x02, 0xFFFF},
		{0x0B, 0x02, 0xFFFF},
		{0x0C, 0x02, 0xFFFF},
		{0x0D, 0x02, 0xFFFF},
		{0x0E, 0x02, 0xFFFF},
		{0x10, 0x01, 0xFFFF},
		{0x11, 0x02, 0xFFFF},
		{0x12, 0x02, 0xFFFF},
		{0x13, 0x02, 0xFFFF},
		{0x14, 0x02, 0xFFFF},
		{0x1A, 0x02, 0xFFFF},
		{0x1B, 0x02, 0xFFFF},
		{0x1C, 0x02, 0xFFFF},
		{0x1D, 0x02, 0xFFFF},
		{0x1E, 0x02, 0xFFFF},
		{0x1F, 0x02, 0xFFFF},
		{0x20, 0x02, 0xFFFF},
		{0x21, 0x02, 0xFFFF},
		{0x22, 0x02, 0xFFFF},
		{0x24, 0x02, 0xFFFF},
		{0x25, 0x02, 0xFFFF},
		{0x26, 0x02, 0xFFFF},
		{0x27, 0x02, 0xFFFF},
		{0x29, 0x02, 0xFFFF},
		{0x2B, 0x02, 0xFFFF},
		{0x35, 0x02, 0xFFFF},
		{0x36, 0x02, 0xFFFF},
		{0x38, 0x02, 0xFFFF},
		{0x39, 0x02, 0xFFFF},
		{0x3A, 0x02, 0xFFFF},
		{0x3B, 0x02, 0xFFFF},
		{0x3C, 0x02, 0xFFFF},
		{0x3D, 0x02, 0xFFFF},
		{0x3E, 0x02, 0xFFFF},
		{0x3F, 0x02, 0xFFFF},
		{0x40, 0x02, 0xFFFF},
		{0x41, 0x02, 0xFFFF},
		{0x42, 0x02, 0xFFFF},
		{0x43, 0x02, 0xFFFF},
		{0x44, 0x02, 0xFFFF},
		{0x45, 0x02, 0xFFFF},
		{0x46, 0x02, 0xFFFF},
		{0x47, 0x02, 0xFFFF},
		{0x48, 0x02, 0xFFFF},
		{0x49, 0x02, 0xFFFF},
		{0x4A, 0x02, 0xFFFF},
		{0x4B, 0x02, 0xFFFF},
		{0x4C, 0x02, 0xFFFF},
		{0x4D, 0x02, 0xFFFF},
		{0x4E, 0x02, 0xFFFF},
		{0x4F, 0x02, 0xFFFF},
		{0x50, 0x02, 0xFFFF},
		{0x51, 0x02, 0xFFFF},
		{0x52, 0x02, 0xFFFF},
		{0x53, 0x02, 0xFFFF},
		{0x54, 0x02, 0xFFFF},
		{0x55, 0x02, 0xFFFF},
		{0x56, 0x02, 0xFFFF},
		{0x57, 0x02, 0xFFFF},
		{0x58, 0x02, 0xFFFF},
		{0x59, 0x02, 0xFFFF},
		{0X5A, 0x02, 0xFFFF},
		{0x5B, 0x02, 0xFFFF},
		{0x5C, 0x02, 0xFFFF},
		{0x5D, 0x02, 0xFFFF},
		{0x5E, 0x02, 0xFFFF},
		{0x5F, 0x02, 0xFFFF},
		{0x60, 0x02, 0xFFFF},
		{0x61, 0x02, 0xFFFF},
		{0x62, 0x02, 0xFFFF},
		{0x63, 0x02, 0xFFFF},
		{0x64, 0x02, 0xFFFF},
		{0x65, 0x02, 0xFFFF},
		{0x66, 0x02, 0xFFFF},
		{0x68, 0x02, 0xFFFF},
		{0x69, 0x02, 0xFFFF},
		{0x6A, 0x02, 0xFFFF},
		{0x6B, 0x02, 0xFFFF},
		{0x6C, 0x02, 0xFFFF},
		{0x6D, 0x02, 0xFFFF},
		{0x6E, 0x02, 0xFFFF},
		{0x6F, 0x02, 0xFFFF},
		{0x72, 0x02, 0xFFFF},
		{0x73, 0x02, 0xFFFF},
		{0x74, 0x02, 0xFFFF},
		{0x75, 0x02, 0xFFFF},
		{0x76, 0x02, 0xFFFF},
		{0x99, 0x02, 0xFFFF},
		{0x9A, 0x02, 0xFFFF},
		{0x9B, 0x02, 0xFFFF},
		{0x9D, 0x02, 0xFFFF},
		{0x9E, 0x02, 0xFFFF},
		{0x9F, 0x02, 0xFFFF},
		{0xB0, 0x02, 0xFFFF},
		{0xB1, 0x02, 0xFFFF},
		{0xB2, 0x02, 0xFFFF},
		{0xB3, 0x02, 0xFFFF},
		{0xB4, 0x02, 0xFFFF},
		{0xB5, 0x02, 0xFFFF},
		{0xB6, 0x02, 0xFFFF},
		{0xB7, 0x02, 0xFFFF},
		{0xB8, 0x02, 0xFFFF},
		{0xB9, 0x02, 0xFFFF},
		{0xBA, 0x02, 0xFFFF},
		{0xBB, 0x02, 0xFFFF},
		{0xBC, 0x02, 0xFFFF},
		{0xBD, 0x02, 0xFFFF},
		{0xBE, 0x02, 0xFFFF},
		{0xBF, 0x02, 0xFFFF},
		{0xC0, 0x02, 0xFFFF},
		{0xC2, 0x02, 0xFFFF},
		{0xC3, 0x02, 0xFFFF},
		{0xC4, 0x02, 0xFFFF},
		{0xC6, 0x02, 0xFFFF},
		{0xE5, 0x02, 0xFFFF},
		{0xE6, 0x02, 0xFFFF},
		{0xFF, 0xFF, 0xFFFF},
};

struct mps_register page2 [] = {
		{0x01, 0x02, 0xFFFF},
		{0x02, 0x02, 0xFFFF},
		{0x03, 0x02, 0xFFFF},
		{0x04, 0x02, 0xFFFF},
		{0x05, 0x02, 0xFFFF},
		{0x06, 0x02, 0xFFFF},
		{0x07, 0x02, 0xFFFF},
		{0x08, 0x02, 0xFFFF},
		{0x09, 0x02, 0xFFFF},
		{0x0A, 0x02, 0xFFFF},
		{0x0B, 0x02, 0xFFFF},
		{0x0C, 0x02, 0xFFFF},
		{0x0D, 0x02, 0xFFFF},
		{0x0E, 0x02, 0xFFFF},
		{0x0F, 0x02, 0xFFFF},
		{0x10, 0x02, 0xFFFF},
		{0x11, 0x02, 0xFFFF},
		{0x12, 0x02, 0xFFFF},
		{0x13, 0x02, 0xFFFF},
		{0x14, 0x02, 0xFFFF},
		{0x15, 0x02, 0xFFFF},
		{0x16, 0x02, 0xFFFF},
		{0x17, 0x02, 0xFFFF},
		{0x18, 0x02, 0xFFFF},
		{0x19, 0x02, 0xFFFF},
		{0x1A, 0x02, 0xFFFF},
		{0x1B, 0x02, 0xFFFF},
		{0x1C, 0x02, 0xFFFF},
		{0x1D, 0x02, 0xFFFF},
		{0x1E, 0x02, 0xFFFF},
		{0xFF, 0xFF, 0xFFFF},
};

struct mps_register_map {
		struct mps_register *page0;
		struct mps_register *page1;
		struct mps_register *page2;
};

struct mps_register_map mps_reg_map = {
		page0,
		page1,
		page2,
};

struct mps {
	struct mps_register_map	mps_reg_map;
	uint16_t				vid;		/* P0:0x99[15:0] 50 */
	uint16_t				pid;		/* P0:0x9A[15:0] 51 */
	uint16_t				i2c_addr;	/* P2:0x1A[15:8] 25 */
};

int32_t i2c_smbus_access(int file, char read_write, uint8_t command, int size, union i2c_smbus_data *data)
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

int32_t i2c_smbus_read_byte(int file)
{
	union i2c_smbus_data data;
	int err;

	err = i2c_smbus_access(file, I2C_SMBUS_READ, 0, I2C_SMBUS_BYTE, &data);
	if (err < 0)
		return err;

	return 0x0FF & data.byte;
}

int32_t i2c_smbus_write_byte(int file, uint8_t value)
{
	return i2c_smbus_access(file, I2C_SMBUS_WRITE, value, I2C_SMBUS_BYTE, NULL);
}

int32_t i2c_smbus_read_byte_data(int file, uint8_t command)
{
	union i2c_smbus_data data;
	int err;

	err = i2c_smbus_access(file, I2C_SMBUS_READ, command, I2C_SMBUS_BYTE_DATA, &data);
	if (err < 0)
		return err;

	return 0x0FF & data.byte;
}

int32_t i2c_smbus_write_byte_data(int file, uint8_t command, uint8_t value)
{
	union i2c_smbus_data data;
	data.byte = value;
	return i2c_smbus_access(file, I2C_SMBUS_WRITE, command, I2C_SMBUS_BYTE_DATA, &data);
}

int32_t i2c_smbus_read_word_data(int file, uint8_t command)
{
	union i2c_smbus_data data;
	int err;

	err = i2c_smbus_access(file, I2C_SMBUS_READ, command,
			       I2C_SMBUS_WORD_DATA, &data);
	if (err < 0)
		return err;

	return 0x0FFFF & data.word;
}

int32_t i2c_smbus_write_word_data(int file, uint8_t command, uint8_t value)
{
	union i2c_smbus_data data;
	data.word = value;
	return i2c_smbus_access(file, I2C_SMBUS_WRITE, command,
				I2C_SMBUS_WORD_DATA, &data);
}

void mps_memory_write(int device_fd)
{
	i2c_smbus_write_byte(device_fd, 0xF1);
}

void mps_page_select(int device_fd, uint32_t page_num)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
}

void mps_register_map_read(int device_fd, const struct mps_register_map *mps_reg_map)
{
	size_t reg_num;
	int32_t ret_val = 0;

	mps_page_select(device_fd, 0x00);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page0[reg_num].addr == 0xFF) &&
			(mps_reg_map->page0[reg_num].length == 0xFF) &&
			(mps_reg_map->page0[reg_num].data == 0xFFFF)) {
			break;
		}
		if (mps_reg_map->page0[reg_num].length == 1) {
			ret_val = i2c_smbus_read_byte_data(device_fd, mps_reg_map->page0[reg_num].addr);

		} else if (mps_reg_map->page0[reg_num].length == 2) {
			ret_val = i2c_smbus_read_word_data(device_fd, mps_reg_map->page0[reg_num].addr);
		} else {
			continue;
		}

		if (ret_val < 0)
			continue;

		mps_reg_map->page0[reg_num].data = (uint16_t)ret_val;
	}

	mps_page_select(device_fd, 0x01);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page1[reg_num].addr == 0xFF) &&
			(mps_reg_map->page1[reg_num].length == 0xFF) &&
			(mps_reg_map->page1[reg_num].data == 0xFFFF)) {
			break;
		}
		if (mps_reg_map->page1[reg_num].length == 1) {
			ret_val = i2c_smbus_read_byte_data(device_fd, mps_reg_map->page1[reg_num].addr);

		} else if (mps_reg_map->page1[reg_num].length == 2) {
			ret_val = i2c_smbus_read_word_data(device_fd, mps_reg_map->page1[reg_num].addr);
		} else {
			continue;
		}

		if (ret_val < 0)
			continue;

		mps_reg_map->page1[reg_num].data = (uint16_t)ret_val;
	}

	mps_page_select(device_fd, 0x02);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page2[reg_num].addr == 0xFF) &&
			(mps_reg_map->page2[reg_num].length == 0xFF) &&
			(mps_reg_map->page2[reg_num].data == 0xFFFF)) {
			break;
		}
		if (mps_reg_map->page2[reg_num].length == 1) {
			ret_val = i2c_smbus_read_byte_data(device_fd, mps_reg_map->page2[reg_num].addr);

		} else if (mps_reg_map->page2[reg_num].length == 2) {
			ret_val = i2c_smbus_read_word_data(device_fd, mps_reg_map->page2[reg_num].addr);
		} else {
			continue;
		}

		if (ret_val < 0)
			continue;

		mps_reg_map->page2[reg_num].data = (uint16_t)ret_val;
	}
}

void mps_register_map_load(const char *src_file, const struct mps_register_map *mps_reg_map)
{

}

void mps_register_map_write(int device_fd, const struct mps_register_map *mps_reg_map)
{
	size_t reg_num;

	mps_page_select(device_fd, 0x00);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page0[reg_num].addr == 0xFF) &&
			(mps_reg_map->page0[reg_num].length == 0xFF) &&
			(mps_reg_map->page0[reg_num].data == 0xFFFF)) {
			break;
		}
		if (mps_reg_map->page0[reg_num].length == 1) {

			i2c_smbus_write_byte_data(device_fd, mps_reg_map->page0[reg_num].addr,
										mps_reg_map->page0[reg_num].data);

		} else if (mps_reg_map->page0[reg_num].length == 2) {
			i2c_smbus_write_word_data(device_fd, mps_reg_map->page0[reg_num].addr,
										mps_reg_map->page0[reg_num].data);
		} else {
			continue;
		}
	}

	mps_page_select(device_fd, 0x01);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page1[reg_num].addr == 0xFF) &&
			(mps_reg_map->page1[reg_num].length == 0xFF) &&
			(mps_reg_map->page1[reg_num].data == 0xFFFF)) {
			break;
		}
		if (mps_reg_map->page1[reg_num].length == 1) {

			i2c_smbus_write_byte_data(device_fd, mps_reg_map->page1[reg_num].addr,
										mps_reg_map->page0[reg_num].data);

		} else if (mps_reg_map->page1[reg_num].length == 2) {
			i2c_smbus_write_word_data(device_fd, mps_reg_map->page1[reg_num].addr,
										mps_reg_map->page1[reg_num].data);
		} else {
			continue;
		}
	}

	mps_page_select(device_fd, 0x02);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page2[reg_num].addr == 0xFF) &&
			(mps_reg_map->page2[reg_num].length == 0xFF) &&
			(mps_reg_map->page2[reg_num].data == 0xFFFF)) {
			break;
		}
		if (mps_reg_map->page2[reg_num].length == 1) {

			i2c_smbus_write_byte_data(device_fd, mps_reg_map->page2[reg_num].addr,
										mps_reg_map->page2[reg_num].data);

		} else if (mps_reg_map->page2[reg_num].length == 2) {
			i2c_smbus_write_word_data(device_fd, mps_reg_map->page2[reg_num].addr,
										mps_reg_map->page2[reg_num].data);
		} else {
			continue;
		}
	}

	i2c_smbus_write_byte(device_fd, 0xF1);
}

void mps_register_map_print(const struct mps_register_map *mps_reg_map)
{
	size_t reg_num;

	printf("Page 0:\n");
	printf("address\tlength\tvalue\n");
	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page0[reg_num].addr == 0xFF) &&
			(mps_reg_map->page0[reg_num].length == 0xFF) &&
			(mps_reg_map->page0[reg_num].data == 0xFFFF)) {
			break;
		}
		printf("0x%02X\t0x%02X\t0x%04X\n",
				mps_reg_map->page0[reg_num].addr,
				mps_reg_map->page0[reg_num].length,
				mps_reg_map->page0[reg_num].data);
	}

	printf("Page 1:\n");
	printf("address\tlength\tvalue\n");
	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page1[reg_num].addr == 0xFF) &&
			(mps_reg_map->page1[reg_num].length == 0xFF) &&
			(mps_reg_map->page1[reg_num].data == 0xFFFF)) {
			break;
		}
		printf("0x%02X\t0x%02X\t0x%04X\n",
				mps_reg_map->page1[reg_num].addr,
				mps_reg_map->page1[reg_num].length,
				mps_reg_map->page1[reg_num].data);
	}

	printf("Page 2:\n");
	printf("address\tlength\tvalue\n");
	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page2[reg_num].addr == 0xFF) &&
			(mps_reg_map->page2[reg_num].length == 0xFF) &&
			(mps_reg_map->page2[reg_num].data == 0xFFFF)) {
			break;
		}
		printf("0x%02X\t0x%02X\t0x%04X\n",
				mps_reg_map->page2[reg_num].addr,
				mps_reg_map->page2[reg_num].length,
				mps_reg_map->page2[reg_num].data);
	}
}

void mps_register_word_write(int device_fd, uint32_t page_num, uint32_t reg_addr, uint16_t reg_value)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	i2c_smbus_write_word_data(device_fd, reg_addr, reg_value);
	i2c_smbus_write_byte(device_fd, 0xF1);
}

void mps_register_byte_write(int device_fd, uint32_t page_num, uint32_t reg_addr, uint8_t reg_value)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	i2c_smbus_write_byte_data(device_fd, reg_addr, reg_value);
	i2c_smbus_write_byte(device_fd, 0xF1);
}

void mps_writing_test(int device_fd)
{
	printf("Writing P0:E5 register\n");
	printf("Writing P1:E5 register\n");
	printf("Writing P2:1E register\n");
	mps_register_word_write(device_fd, 0, 0xE5, 0x0028);
	mps_register_word_write(device_fd, 1, 0xE5, 0x0029);
	mps_register_word_write(device_fd, 2, 0x1E, 0x0006);
}

int32_t main(int32_t argc, const char *argv[])
{
	printf("linux-smbus-trans\n");

	if (argc != 3) {
		printf("Invalid arguments count\n");
		return -1;
	}

	int32_t i2c_bus_fd = open(argv[1], O_RDWR);
	if (i2c_bus_fd < 0) {
		perror("Function open() returned with error");
		return -2;
	}
	printf("File %s opened\n", argv[1]);

	int32_t dev_bus_addr = 0;
	sscanf(argv[2], "0x%02X", &dev_bus_addr);
	if (ioctl(i2c_bus_fd, I2C_SLAVE, dev_bus_addr) < 0) {
		perror("Function ioctl() returned with error");
		close(i2c_bus_fd);
		return -3;
	}

#if 0
	uint32_t dev_reg_num = 0x00; /* Device register to access */
	int32_t ret_val;

	for (; dev_reg_num <= 0xFF; ++dev_reg_num) {
		/* Using SMBus commands */
		ret_val = i2c_smbus_read_byte_data(i2c_bus_fd, dev_reg_num);
		if (ret_val < 0) {
			printf("XX ");
		} else {
			printf("%02X ", ret_val);
		}
		if (((dev_reg_num + 1) % 16) == 0 && dev_reg_num != 0)
			printf("\n");
	}
#endif


	mps_register_map_read(i2c_bus_fd, &mps_reg_map);
	mps_register_map_print(&mps_reg_map);
	mps_writing_test(i2c_bus_fd);
	mps_register_map_read(i2c_bus_fd, &mps_reg_map);
	mps_register_map_print(&mps_reg_map);
	return 0;
}
