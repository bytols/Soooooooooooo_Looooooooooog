#include "./mlx_linux/mlx.h" 
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		closed;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int close(int keycode, t_vars *vars)
{
	if(vars->closed == 0)
		return (0);
	vars->closed = 0;
	printf("fechei! %d \n", keycode);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int destroy(t_vars *vars)
{
	printf("Fechando janela via botão X\n");
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.closed = 1;
	if(vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 200; i++)
	{
		my_mlx_pixel_put(&img, (200 + i), (200 + i), 0x00FF0000); // Vermelho
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 10, 10);
	mlx_hook(vars.win , 2, 1L<<0, close, &vars);
	mlx_hook(vars.win ,17, 0, destroy, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
