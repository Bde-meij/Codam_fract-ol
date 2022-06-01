/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:35:42 by bde-meij          #+#    #+#             */
/*   Updated: 2022/06/01 12:40:39 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct a_struct
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	unsigned	colpal[10];
	double		xtmp;
	double		ytmp;
	double		movx;
	double		movy;
	double		zum;
	double		xp;
	double		yp;
	double		x;
	double		y;
	double		v;
	char		**arg;
	int			arc;
	int			mousy;
	int			mousx;
	int			i;
}	t_fruct;

double	ft_atof(const char *str);
void	my_scrollhook(double xdelta, double ydelta, void *fs);
void	my_keyhook(mlx_key_data_t keydata, void *fs);
void	julias(t_fruct *fs, double xco, double yco);
void	shiftcol(t_fruct *fs, int keyval);
void	burningship(t_fruct *fs);
void	mandelbrot(t_fruct *fs);
void	ini_struct(t_fruct *fs, char **av, int ac);
int		display_options(int gen_value);
int		generate_fractal(t_fruct *fs);
int		checkiftof(const char *str);
int		main(int ac, char **av);

#endif