/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:45:28 by bde-meij          #+#    #+#             */
/*   Updated: 2022/06/01 11:18:01 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ini_struct(t_fruct *fs, char **av, int ac)
{
	fs->i = 0;
	fs->x = 0;
	fs->y = 0;
	fs->yp = 0;
	fs->xp = 0;
	fs->zum = 1;
	fs->xtmp = 0;
	fs->ytmp = 0;
	fs->movx = 0;
	fs->movy = 0;
	fs->mousx = 0;
	fs->mousy = 0;
	fs->arg = av;
	fs->arc = ac;
	fs->v = 0;
	fs->colpal[0] = 0x800008FF;
	fs->colpal[1] = 0xFF0008FF;
	fs->colpal[2] = 0xFFFF44FF;
	fs->colpal[3] = 0xFF00FFFF;
	fs->colpal[4] = 0xFFAC1CFF;
	fs->colpal[5] = 0xF28C28FF;
	fs->colpal[6] = 0x00A36CFF;
	fs->colpal[7] = 0x7DF9FFFF;
	fs->colpal[8] = 0x006400FF;
	fs->colpal[9] = 0xBDB76BFF;
}

int	display_options(int gen_value)
{
	if (gen_value == 0)
	{
		ft_putstr_fd("\noh no! invalid input\n\n\
options are: 'mandelbrot', 'julia_one',\n'julia_two',\
'julia_three' and 'burningship'\n\
OR... you can give two values ranging from '-2' to '2'\n\
example: ./fractol -0.85 -0.22\n\n", 1);
	}
	else
		ft_putstr_fd("\nwelcome to my fractal explorer!\n\n\
Controls are: arrow keys for movement,\n\
'z' and 'x' will zoom to/from current centre,\n\
while mousewheel will zoom to mouseposition.\n\
Press 'c' and 'v' quickly to !*** DISCO ***!\n\n\
press 'r' to restart position, or hit 'escape' to quit.\n\n", 1);
	return (gen_value);
}

int	checkiftof(const char *str)
{
	size_t	i;
	int		dot;

	i = 0;
	dot = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || \
		(str[i] == '-' && i == 0))
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (i != ft_strlen(str) || dot > 1)
		return (-2);
	return (0);
}

double	ft_atof(const char *str)
{
	int		powa;
	int		index;
	double	value;
	double	sign;

	powa = 0;
	index = 0;
	value = 0;
	sign = 1;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while ((str[index] >= '0' && str[index] <= '9') || str[index] == '.')
	{
		if ((str[index - 1] == '.') || (powa > 0))
			powa += 1;
		if (str[index] != '.')
			value = value * 10 + (str[index] - 48);
		index++;
	}
	return ((value * sign) / pow(10, powa));
}

int	main(int ac, char **av)
{
	t_fruct	fs;

	if ((ac < 2) || (ac > 3))
	{
		system("leaks -q fractol");
		return (display_options(0), 1);
	}
	ini_struct(&fs, av, ac);
	fs.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fs.mlx)
		exit(EXIT_FAILURE);
	fs.g_img = mlx_new_image(fs.mlx, WIDTH, HEIGHT);
	if (!fs.g_img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(fs.mlx, fs.g_img, 0, 0);
	system("leaks -q fractol");
	if (display_options(generate_fractal(&fs)) != 0)
	{
		mlx_key_hook(fs.mlx, &my_keyhook, (void *)&fs);
		mlx_scroll_hook(fs.mlx, &my_scrollhook, (void *)&fs);
		mlx_loop(fs.mlx);
	}
	mlx_terminate(fs.mlx);
	system("leaks -q fractol");
	return (EXIT_SUCCESS);
}
