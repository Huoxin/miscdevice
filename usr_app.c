#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define MISC_DEV_NAME "/dev/my_misc_dev"

int main(void)
{
	int ret;
	char buf[32];
	int fd = open(MISC_DEV_NAME, O_RDONLY|O_NDELAY);
	if(fd < 0)
	{
		printf("open file %s failed\n", MISC_DEV_NAME);
		return -1;
	}

	read(fd, buf, 32);
	close(fd);
	
	return 0;
}
