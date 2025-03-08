#include "so_long.h"

int main(int argc, char *argv[])
{
    int fd;
    int result;


    if(argc != 2)
        return (0);
    printf("\naté aqui foi?\n");
    fd = open(argv[1], O_RDWR);
    printf("\naté aqui foi2?\n");
    result = get_map(fd, argv[1]);
    close(fd);
    printf("result %d\n", result);
    if(result == 0)
    {
		result = write(2, "Error\n", 6);
        return (0);
    }
    return(0);
}