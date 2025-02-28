#include "so_long.h"

int main(int argc, char *argv[])
{
    int fd;
    int num;
    char    buffer[20];

    if(argc != 2)
        return (0);
    num = 0;
    fd = open(argv[1], O_RDWR);
    get_map(fd);
    if(fd > 0)
        num = read(fd, &buffer, 20);
    printf("%s %d", buffer, num);
}