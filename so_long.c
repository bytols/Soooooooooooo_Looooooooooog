#include "so_long.h"

int main(int argc, char *argv[])
{
    int fd;
    int result;

    if(argc != 2)
        return (0);
    fd = ft_strlen(argv[1]);
    if(ft_strnstr(argv[1], ".ber", fd) == NULL)
    {
        result = write(2, "Error\ninvalid map name", 23);
        return (0);
    }
    fd = open(argv[1], O_RDWR);
    if(fd == -1)
    {
        result = write(2, "Error\nfile descriptor error", 23);
        return (0);
    }
    result = get_map(fd, argv[1]);
    close(fd);
    if(result == 0)
    {
		result = write(2, "Error\n Map error", 16);
        return (0);
    }
    game(argv[1], fd);
    return(0);
}
