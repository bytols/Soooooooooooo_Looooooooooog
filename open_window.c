#include "so_long.h" 

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int print(int keycode, t_vars *vars)
{
	if(vars->closed == 0)
		return (0);
	if (keycode == XK_Escape)
	{
		vars->closed = 0;
		printf("fechei!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
		exit(0);
	}
	else if (keycode == XK_Up)
		printf("tecla pressionada up! %d \n", keycode);
	else if (keycode == XK_Down)
		printf("tecla pressionada down! %d \n", keycode);
	else if (keycode == XK_Left)
		printf("tecla pressionada left! %d \n", keycode);
	else if (keycode == XK_Right)
		printf("tecla pressionada rigth! %d \n", keycode);
	else
		printf("tecla pressionada! %d \n", keycode);
	return (0);
}

int destroy(t_vars *vars)
{
	if(vars->closed == 0)
		return (0);
	vars->closed = 0;
	printf("Fechando janela via botão X\n");
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
	return (0);
}

int print_pixel(t_vars *param)
{
	printf("entrei aqui\n");
	while (param->width < 600)
	{
		my_mlx_pixel_put(param->img, param->height, param->width, 0x00FF0000);
		param->height = param->height + 1;
		param->width = param->width + 1; 
		mlx_put_image_to_window(param->mlx, param->win, param->img->img, 10, 10);
	}
	return(0);
}
/*int	main(void)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init(); //malloc
	vars.win = mlx_new_window(vars.mlx, 1280, 720, "Hello world!");
	vars.closed = 1;
	if(vars.win == NULL)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
	}
	img.img = mlx_new_image(vars.mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	vars.img = &img;
	vars.width = 200;
	vars.height = 200;
	vars.color = 0x00FF0000;
	for (int i = 0; i < 200; i++)
	{
		my_mlx_pixel_put(&img, (200 + i), (200 + i), 0x00FF0000); // Vermelho
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 10, 10);
	mlx_hook(vars.win , 2, 1L<<0, print, &vars);
	mlx_hook(vars.win ,17, 0, destroy, &vars);
	img.img = mlx_xpm_file_to_image(vars.mlx, "sprites/a004.xpm", &vars.width, &vars.height );

	mlx_loop_hook(vars.mlx, print_pixel, &vars);
	mlx_loop(vars.mlx);
	return (0);
}*/
