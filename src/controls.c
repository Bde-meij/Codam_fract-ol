/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:48:02 by bde-meij          #+#    #+#             */
/*   Updated: 2022/06/01 12:12:23 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shiftcolpos(t_fruct *fs, int keyval)
{
	int	i;

	i = 0;
	if (keyval == MLX_KEY_C)
	{
		while (i < 9)
		{
			fs->colpal[i] += i * 55673;
			i++;
		}
	}
	else if (keyval == MLX_KEY_V)
		fs->v -= 0.03;
	else if (keyval == MLX_KEY_B)
		fs->v += 0.03;
}

void	my_scrollhook(double xdelta, double ydelta, void *fs)
{
	double	xmous;
	double	ymous;

	mlx_get_mouse_pos(((t_fruct *)fs)->mlx, &((t_fruct *)fs)->mousx, \
		&((t_fruct *)fs)->mousy);
	xmous = ((t_fruct *)fs)->mousx;
	ymous = ((t_fruct *)fs)->mousy;
	xdelta = 0;
	if (ydelta > 0)
	{
		((t_fruct *)fs)->zum *= 0.8;
		((t_fruct *)fs)->movx += ((xmous / WIDTH) - .5) * ((t_fruct *)fs)->zum;
		((t_fruct *)fs)->movy += ((ymous / HEIGHT) - .5) * ((t_fruct *)fs)->zum;
	}
	else if (ydelta < 0)
	{
		((t_fruct *)fs)->movx -= ((xmous / WIDTH) - .5) * ((t_fruct *)fs)->zum;
		((t_fruct *)fs)->movy -= ((ymous / HEIGHT) - .5) * ((t_fruct *)fs)->zum;
		((t_fruct *)fs)->zum /= 0.8;
	}
	generate_fractal((t_fruct *)fs);
}

void	my_keyhook(mlx_key_data_t keydata, void *fs)
{
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		((t_fruct *)fs)->movx += .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		((t_fruct *)fs)->movx -= .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		((t_fruct *)fs)->movy += .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		((t_fruct *)fs)->movy -= .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
		((t_fruct *)fs)->zum *= .8;
	else if (keydata.key == MLX_KEY_X && keydata.action == MLX_PRESS)
		((t_fruct *)fs)->zum /= .8;
	else if (keydata.key == MLX_KEY_R && keydata.action == MLX_PRESS)
		ini_struct(((t_fruct *)fs), ((t_fruct *)fs)->arg, ((t_fruct *)fs)->arc);
	else if ((keydata.key == MLX_KEY_C || keydata.key == MLX_KEY_V || \
		keydata.key == MLX_KEY_B) && keydata.action == MLX_PRESS)
		shiftcolpos(((t_fruct *)fs), keydata.key);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_close_window(((t_fruct *)fs)->mlx);
		return ;
	}
	else
		return ;
	generate_fractal((t_fruct *)fs);
}
