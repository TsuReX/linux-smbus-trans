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
#include <string.h>
#include <getopt.h>

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

int32_t i2c_smbus_write_word_data(int file, uint8_t command, uint16_t value)
{
	union i2c_smbus_data data;
	data.word = value;
	return i2c_smbus_access(file, I2C_SMBUS_WRITE, command,
				I2C_SMBUS_WORD_DATA, &data);
}
void mps_register_word_write(int device_fd, uint32_t page_num, uint32_t reg_addr, uint16_t reg_value)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	i2c_smbus_write_word_data(device_fd, reg_addr, reg_value);
}

void mps_register_byte_write(int device_fd, uint32_t page_num, uint32_t reg_addr, uint8_t reg_value)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	i2c_smbus_write_byte_data(device_fd, reg_addr, reg_value);
}

int16_t mps_register_word_read(int device_fd, uint32_t page_num, uint32_t reg_addr)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	return i2c_smbus_read_word_data(device_fd, reg_addr);
}

int8_t mps_register_byte_read(int device_fd, uint32_t page_num, uint32_t reg_addr)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	return i2c_smbus_read_byte_data(device_fd, reg_addr);
}

void mps_command_write(int device_fd, uint32_t page_num, uint8_t command)
{
	i2c_smbus_write_byte_data(device_fd, 0x00, page_num);
	i2c_smbus_write_byte(device_fd, command);
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

int32_t mps_register_map_load(const char *src_file, struct mps *mps)
{
	int src_file_fd = open(src_file, O_RDONLY);
	if (src_file_fd < 0) {
		perror("Function open() returned with error");
		return -1;
	}

	int ret_val = 0;
//	int ret_val = read(src_file_fd, mps, sizeof(struct mps));
//	if (ret_val < 0) {
//			perror("Function read() 1 returned with error");
//			close(src_file_fd);
//			return -1;
//	}

	size_t reg_num;

	for (reg_num = 0; ; ++reg_num) {

		ret_val = read(src_file_fd, &mps->mps_reg_map.page0[reg_num], sizeof(struct mps_register));

		if (ret_val < 0) {
			perror("Function read() returned with error");
			close(src_file_fd);
			return -1;
		}

		if ((mps->mps_reg_map.page0[reg_num].addr == 0xFF) &&
			(mps->mps_reg_map.page0[reg_num].length == 0xFF) &&
			(mps->mps_reg_map.page0[reg_num].data == 0xFFFF)) {

			break;
		}
	}

	for (reg_num = 0; ; ++reg_num) {

		ret_val = read(src_file_fd, &mps->mps_reg_map.page1[reg_num], sizeof(struct mps_register));

		if (ret_val < 0) {
			perror("Function read() returned with error");
			close(src_file_fd);
			return -1;
		}

		if ((mps->mps_reg_map.page1[reg_num].addr == 0xFF) &&
			(mps->mps_reg_map.page1[reg_num].length == 0xFF) &&
			(mps->mps_reg_map.page1[reg_num].data == 0xFFFF)) {

			break;
		}
	}

	for (reg_num = 0; ; ++reg_num) {

		ret_val = read(src_file_fd, &mps->mps_reg_map.page2[reg_num], sizeof(struct mps_register));

		if (ret_val < 0) {
			perror("Function read() returned with error");
			close(src_file_fd);
			return -1;
		}

		if ((mps->mps_reg_map.page2[reg_num].addr == 0xFF) &&
			(mps->mps_reg_map.page2[reg_num].length == 0xFF) &&
			(mps->mps_reg_map.page2[reg_num].data == 0xFFFF)) {

			break;
		}
	}

	close(src_file_fd);
	return 0;
}

int32_t mps_register_map_store(const char *dst_file, const struct mps *mps)
{
	int dst_file_fd = open(dst_file, O_CREAT|O_WRONLY|O_TRUNC);
	if (dst_file_fd < 0) {
		perror("Function open() returned with error");
		return -1;
	}

	int ret_val = 0;
//	int ret_val = write(dst_file_fd, mps, sizeof(struct mps));
//	if (ret_val < 0) {
//			perror("Function write() returned with error");
//			close(dst_file_fd);
//			return -1;
//	}

	size_t reg_num;

	for (reg_num = 0; ; ++reg_num) {

		ret_val = write(dst_file_fd, &mps->mps_reg_map.page0[reg_num], sizeof(struct mps_register));

		if (ret_val < 0) {
			perror("Function write() returned with error");
			close(dst_file_fd);
			return -1;
		}

		if ((mps->mps_reg_map.page0[reg_num].addr == 0xFF) &&
			(mps->mps_reg_map.page0[reg_num].length == 0xFF) &&
			(mps->mps_reg_map.page0[reg_num].data == 0xFFFF)) {

			break;
		}
	}

	for (reg_num = 0; ; ++reg_num) {

		ret_val = write(dst_file_fd, &mps->mps_reg_map.page1[reg_num], sizeof(struct mps_register));

		if (ret_val < 0) {
			perror("Function write() returned with error");
			close(dst_file_fd);
			return -1;
		}

		if ((mps->mps_reg_map.page1[reg_num].addr == 0xFF) &&
			(mps->mps_reg_map.page1[reg_num].length == 0xFF) &&
			(mps->mps_reg_map.page1[reg_num].data == 0xFFFF)) {

			break;
		}
	}

	for (reg_num = 0; ; ++reg_num) {

		ret_val = write(dst_file_fd, &mps->mps_reg_map.page2[reg_num], sizeof(struct mps_register));

		if (ret_val < 0) {
			perror("Function write() returned with error");
			close(dst_file_fd);
			return -1;
		}

		if ((mps->mps_reg_map.page2[reg_num].addr == 0xFF) &&
			(mps->mps_reg_map.page2[reg_num].length == 0xFF) &&
			(mps->mps_reg_map.page2[reg_num].data == 0xFFFF)) {

			break;
		}
	}

	close(dst_file_fd);
	return 0;
}

#define PAGE0						0x00
#define PAGE1						0x01
#define PAGE2						0x01

#define STATUS_CML_REG_ADDR			0x7E
#define SATUS_CML_PWD_MATCH			0x08

#define MTP_WRITE_PROTECT_ADDR		0x10
#define MTP_WRITE_PROTECT_DIS_PROT	0x63
#define MTP_WRITE_PROTECT_EN_PROT	0x63
#define PWD_CHECK_CMD_ADDR			0xF8
#define PASSWORD					0xFF

#define CLEAR_FAULTS_CMD			0x03

#define STORE_NORMAL_CODE_CMD		0xF1
#define RESTORE_NORMAL_CODE_CMD		0xF2
#define STORE_USER_CODE_CMD			0x17
#define RESTORE_USER_CODE_CMD		0x18

#define MFR_CRC_NORMAL_CODE_ADDR	0xAB
#define MFR_CRC_MULTI_CONFIG_ADDR	0xAD

void mps_register_map_write(int device_fd, const struct mps_register_map *mps_reg_map)
{
	/* Unlock password */
	uint8_t status_cml = 0xFF;
	status_cml = mps_register_byte_read(device_fd, PAGE0, STATUS_CML_REG_ADDR);
	printf("STATUS_CML 0x%02X\n", status_cml);

	/* Clear latched status */
	mps_command_write(device_fd, PAGE0, CLEAR_FAULTS_CMD);
	usleep(100000);

#if 0
	if ((status_cml & SATUS_CML_PWD_MATCH) == 0) {
		printf("Password unlock\n");
		mps_register_word_write(device_fd, PAGE0, PWD_CHECK_CMD_ADDR, PASSWORD);
		usleep(100000);
	}

	status_cml = mps_register_byte_read(device_fd, PAGE0, STATUS_CML_REG_ADDR);

	if ((status_cml & SATUS_CML_PWD_MATCH) == 0) {
		printf("Password can't be unlocked\n");
		return;
	}
#else
	status_cml = mps_register_byte_read(device_fd, PAGE0, STATUS_CML_REG_ADDR);
#endif
	printf("STATUS_CML 0x%02X\n", status_cml);

	/* Unlock MTP protection */
//	mps_register_byte_write(device_fd, PAGE0, MTP_WRITE_PROTECT_ADDR, MTP_WRITE_PROTECT_DIS_PROT);

	uint16_t mfr_crc_normal_code = mps_register_word_read(device_fd, PAGE1, MFR_CRC_NORMAL_CODE_ADDR);
	printf("MFR_CRC_NORMAL_CODE 0x%04X\n", mfr_crc_normal_code);

	uint16_t mfr_crc_multi_config = mps_register_word_read(device_fd, PAGE1, MFR_CRC_MULTI_CONFIG_ADDR);
	printf("MFR_CRC_MULTI_CONFIG_ADDR 0x%04X\n", mfr_crc_multi_config);

	printf("Page 0 writing\n");

	mps_page_select(device_fd, PAGE0);

	size_t reg_num;
	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page0[reg_num].addr == 0xFF) &&
			(mps_reg_map->page0[reg_num].length == 0xFF) &&
			(mps_reg_map->page0[reg_num].data == 0xFFFF)) {
			break;
		}

		if (mps_reg_map->page0[reg_num].addr == 0x9D) /* CONFIG_ID */
			continue;

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
	printf("Page 0 writing finished\n");

	printf("Page 1 writing\n");
	mps_page_select(device_fd, PAGE1);

	for (reg_num = 0; ; ++reg_num) {
		if ((mps_reg_map->page1[reg_num].addr == 0xFF) &&
			(mps_reg_map->page1[reg_num].length == 0xFF) &&
			(mps_reg_map->page1[reg_num].data == 0xFFFF)) {
			break;
		}
#if 0
		if (mps_reg_map->page1[reg_num].addr == 0xC6) { /* MFR_VR_CONFIG5 */
			i2c_smbus_write_word_data(device_fd, mps_reg_map->page1[reg_num].addr,
										mps_reg_map->page1[reg_num].data & (~0x0800));
			continue;
		}
#endif
		if (mps_reg_map->page1[reg_num].length == 1) {

			i2c_smbus_write_byte_data(device_fd, mps_reg_map->page1[reg_num].addr,
										mps_reg_map->page1[reg_num].data);

		} else if (mps_reg_map->page1[reg_num].length == 2) {
			i2c_smbus_write_word_data(device_fd, mps_reg_map->page1[reg_num].addr,
										mps_reg_map->page1[reg_num].data);
		} else {
			continue;
		}
	}
	printf("Page 1 writing finished\n");
#if 0
	printf("Storing data into MTP\n");
	mps_command_write(device_fd, PAGE0, STORE_NORMAL_CODE_CMD);
	usleep(500000);
	printf("Storing data into MTP finished\n");

	mfr_crc_normal_code = mps_register_word_read(device_fd, PAGE1, MFR_CRC_NORMAL_CODE_ADDR);
	printf("MFR_CRC_NORMAL_CODE 0x%04X\n", mfr_crc_normal_code);

	/* Restore data from MTP */
	mps_command_write(device_fd, PAGE0, RESTORE_NORMAL_CODE_CMD);
	usleep(50000);
#endif

	printf("Page 2 writing\n");
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
	printf("Page 2 writing finished\n");

	mps_command_write(device_fd, PAGE1, STORE_USER_CODE_CMD);
	sleep(1);

	mfr_crc_normal_code = mps_register_word_read(device_fd, PAGE1, MFR_CRC_NORMAL_CODE_ADDR);
	printf("MFR_CRC_NORMAL_CODE 0x%04X\n", mfr_crc_normal_code);

	mfr_crc_multi_config = mps_register_word_read(device_fd, PAGE1, MFR_CRC_MULTI_CONFIG_ADDR);
	printf("MFR_CRC_MULTI_CONFIG_ADDR 0x%04X\n", mfr_crc_multi_config);

	/* Restore data from MTP */
	mps_command_write(device_fd, PAGE0, RESTORE_USER_CODE_CMD);
	usleep(50000);

	mfr_crc_normal_code = mps_register_word_read(device_fd, PAGE1, MFR_CRC_NORMAL_CODE_ADDR);
	printf("MFR_CRC_NORMAL_CODE 0x%04X\n", mfr_crc_normal_code);

	mfr_crc_multi_config = mps_register_word_read(device_fd, PAGE1, MFR_CRC_MULTI_CONFIG_ADDR);
	printf("MFR_CRC_MULTI_CONFIG_ADDR 0x%04X\n", mfr_crc_multi_config);
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

int32_t mps_detect(int device_fd)
{
	mps_page_select(device_fd, PAGE0);
	int32_t ret_val = mps_register_word_read(device_fd, 0x00, 0x9D);
	if (ret_val < 0)
		return -1;
	printf("Data 0x%04X\n", ret_val);
	return 0;
}

int32_t main(int32_t argc, const char *argv[])
{

	enum action {
		detect = 0,
		load,
		store,
		print,
		readdr,
		no_action
	};
	enum action action = no_action;

	const char *opt_string = "dslpf:h?";

	const struct option long_opt[] = {
		{ "device", required_argument, NULL, 0 },
	    { "file", required_argument, NULL, 'f' },
		{ "addr", required_argument, NULL, 0 },
		{ "newaddr", required_argument, NULL, 0 },
		{ "readdr", no_argument, NULL, 0 },
	    { NULL, no_argument, NULL, 0 }
	};

	char conf_file[2048];
	char dev_file[2048];
	int32_t long_opt_ind = 0;
	uint32_t smbus_addr = 0;
	uint32_t smbus_new_addr = 0;

	memset(conf_file, 0, sizeof(conf_file));
	memset(dev_file, 0, sizeof(dev_file));
	int32_t opt_res = getopt_long(argc, (char * const*)argv, opt_string, long_opt, &long_opt_ind);
	while( opt_res != -1 ) {
		switch( opt_res ) {
			case 'd':
				printf("Detect devices on the bus\n");
				action = detect;
				break;

			case 'l':
				printf("Load device's configuration from the file\n");
				action = load;
				break;

			case 's':
				printf("Store device's configuration to the file\n");
				action = store;
				break;

			case 'p':
				printf("Print configuration\n");
				action = print;
				break;

			case 'f':
				printf("Configuration file: %s\n", optarg);
				strcpy(conf_file, optarg);
				break;

			case 'h':
			case '?':
				printf("Help\n");
				break;

			 case 0:
				 switch(long_opt_ind) {

				 case 0: /* device file */
					 printf("File of device: %s\n", optarg);
					 strcpy(dev_file, optarg);
					 break;

				 case 1: /* configuration file */
					 printf("Configuration file: %s\n", optarg);
					 strcpy(conf_file, optarg);
					 break;

				 case 2: /* bus address */
					 sscanf(optarg, "0x%02X", &smbus_addr);
					 printf("Bus address: 0x%02X\n", smbus_addr);
					 break;

				 case 3: /* bus address */
					 sscanf(optarg, "0x%02X", &smbus_new_addr);
					 printf("New bus address: 0x%02X\n", smbus_new_addr);
					 break;

				 case 4: /* readdr */
					 printf("Set new bus address\n");
					 action = readdr;
					 break;
				 }
				break;

			default:
				printf("Unknown argument \'%c\'\n", opt_res);
				break;
		}
		opt_res = getopt_long(argc, (char * const*)argv, opt_string, long_opt, &long_opt_ind);
	}

	int32_t i2c_bus_fd = open(dev_file, O_RDWR);
	if (i2c_bus_fd < 0) {
		perror("Function open() returned with error");
		return -2;
	}

	uint16_t mfr_vr_config5_c6 = 0;
	struct mps mps;
	mps.mps_reg_map = mps_reg_map;
	switch((int32_t)action) {
	case detect:
		for (; smbus_addr <= 0x7F; smbus_addr++) {

			if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_addr) < 0) {
				perror("Function ioctl() returned with error");
				close(i2c_bus_fd);
				return -3;
			}

			if (mps_detect(i2c_bus_fd) == 0) {
				printf("Detected 0x%02X\n", smbus_addr);
			}
		}
		break;

	case load:
		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}

//		mfr_vr_config5_c6 = mps_register_word_read(i2c_bus_fd, 0x1, 0xC6);
//		mps_register_word_write(i2c_bus_fd, 0x1, 0xC6, mfr_vr_config5_c6 & (~0x0800));
//
		mps_register_map_load(conf_file, &mps);

		if (smbus_addr != (mps.mps_reg_map.page2[25].data >> 8)) {
			printf("File contains registers for device with different address\n");
			close(i2c_bus_fd);
			return -6;
		}

		mps_register_map_write(i2c_bus_fd, &mps.mps_reg_map);
		break;

	case store:
		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}
		mps_register_map_read(i2c_bus_fd, &mps.mps_reg_map);
		mps_register_map_store(conf_file, &mps);
		break;

	case print:

		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}
		mps_register_map_read(i2c_bus_fd, &mps.mps_reg_map);
		mps_register_map_print(&mps.mps_reg_map);
		break;

	case readdr:

		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}

		if ((mps_register_word_read(i2c_bus_fd, 0x2, 0x1A) >> 8) != smbus_addr) {
				printf("There isn't device with address 0x%02X\n", smbus_addr);
				return -6;
		}

		/* Check target address. */

		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_new_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}
		mps_register_map_read(i2c_bus_fd, &mps.mps_reg_map);

		if ((mps_register_word_read(i2c_bus_fd, 0x2, 0x1A) >> 8) == smbus_new_addr) {
			printf("There already exists device with address 0x%02X\n", smbus_new_addr);
			return -6;
		}

		/* Save current P2 configuration into all configurations. */

		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}

//		mps_page_select(i2c_bus_fd, 0x00);
//		i2c_smbus_write_byte(i2c_bus_fd, 0xF1);
//
//		sleep(1);
//
//		mps_page_select(i2c_bus_fd, 0x01);
//		i2c_smbus_write_byte(i2c_bus_fd, 0xF1);
//
//		sleep(1);

		mps_page_select(i2c_bus_fd, PAGE2);
		i2c_smbus_write_byte(i2c_bus_fd, 0x17);

		sleep(1);

		/* Disable CONFIG_PL bit */

		mfr_vr_config5_c6 = mps_register_word_read(i2c_bus_fd, 0x1, 0xC6);
		printf("mfr_vr_config_c6 0x%02X\n", mfr_vr_config5_c6);

		mps_register_word_write(i2c_bus_fd, 0x1, 0xC6, mfr_vr_config5_c6 & (~0x0800));
		printf("mfr_vr_config_c6 0x%02X\n", mfr_vr_config5_c6 & (~0x0800));

		sleep(1);

		mfr_vr_config5_c6 = mps_register_word_read(i2c_bus_fd, 0x1, 0xC6);
		printf("mfr_vr_config_c6 0x%02X\n", mfr_vr_config5_c6);

		sleep(1);

		/* Set new address */

		mps_register_word_write(i2c_bus_fd, 0x2, 0x1A, smbus_new_addr << 8);
		sleep(1);
		/* Save new address */

		if (ioctl(i2c_bus_fd, I2C_SLAVE, smbus_new_addr) < 0) {
			perror("Function ioctl() returned with error");
			close(i2c_bus_fd);
			return -3;
		}

		mps_page_select(i2c_bus_fd, PAGE2);
		i2c_smbus_write_byte(i2c_bus_fd, 0x17);
		break;
	}

	close(i2c_bus_fd);
	return 0;
}


#if 0
int32_t _main(int32_t argc, const char *argv[])
{
	if (argc < 3) {
		printf("Invalid arguments count\n");
		return -1;
	}

	int32_t i2c_bus_fd = open(argv[1], O_RDWR);
	if (i2c_bus_fd < 0) {
		perror("Function open() returned with error");
		return -2;
	}

	int32_t dev_bus_addr = 0;
	if (argc == 3) {
		if (strcmp(argv[2], "d") != 0) {
			printf("Invalid argument\n");
			printf("It needs to declare d argument\n");
		}

		for (; dev_bus_addr <= 0x7F; dev_bus_addr++) {

			if (ioctl(i2c_bus_fd, I2C_SLAVE, dev_bus_addr) < 0) {
				perror("Function ioctl() returned with error");
				close(i2c_bus_fd);
				return -3;
			}

			if (mps_detect(i2c_bus_fd) == 0) {
				printf("Detected 0x%02X\n", dev_bus_addr);
			} else {
//				printf("Not detected 0x%02X\n", dev_bus_addr);
			}

		}
		close(i2c_bus_fd);
		return 0;
	}

	sscanf(argv[2], "0x%02X", &dev_bus_addr);
	if (ioctl(i2c_bus_fd, I2C_SLAVE, dev_bus_addr) < 0) {
		perror("Function ioctl() returned with error");
		close(i2c_bus_fd);
		return -3;
	}

	struct mps mps;
	mps.mps_reg_map = mps_reg_map;

	/* Read MPS registers and save in file. */
	if (strcmp(argv[3], "s") == 0) {
		if (argc < 5) {
			printf("Invalid arguments count\n");
			printf("It needs to declare file name to store registers\n");
			close(i2c_bus_fd);
			return -4;
		}

		mps_register_map_read(i2c_bus_fd, &mps.mps_reg_map);
		mps_register_map_store(argv[4], &mps);

	/* Load MPS registers from file and write in chip. */
	} else if (strcmp(argv[3], "l") == 0) {
		if (argc < 5) {
			printf("Invalid arguments count\n");
			printf("It needs to declare file name to load registers from\n");
			close(i2c_bus_fd);
			return -5;
		}

		mps_register_map_load(argv[4], &mps);

		if (dev_bus_addr != (mps.mps_reg_map.page2[25].data >> 8)) {
			printf("File contains registers for device with different address\n");
			close(i2c_bus_fd);
			return -6;
		}

		mps_register_map_write(i2c_bus_fd, &mps.mps_reg_map);

	/* Read MPS registers and print. */
	} else if (strcmp(argv[3], "p") == 0) {
		mps_register_map_read(i2c_bus_fd, &mps.mps_reg_map);
		mps_register_map_print(&mps.mps_reg_map);
	} else {
		printf("Invalid argument %s\n", argv[3]);
		close(i2c_bus_fd);
		return -7;
	}

//	mps_register_map_print(&mps_reg_map);
#if 0
	mps.i2c_addr = mps_reg_map.page2[25].data >> 8;
	mps.vid = mps_reg_map.page0[50].data;
	mps.pid = mps_reg_map.page0[51].data;
#endif

	close(i2c_bus_fd);
	return 0;
}
#endif
