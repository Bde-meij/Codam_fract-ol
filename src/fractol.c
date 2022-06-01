/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:21:19 by bde-meij          #+#    #+#             */
/*   Updated: 2022/06/01 10:58:51 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fruct *fs)
{
	while (fs->y < HEIGHT)
	{
		while (fs->x < WIDTH)
		{
			fs->xtmp = fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
			fs->ytmp = fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
			while (hypot(fs->xtmp, fs->ytmp) <= 2 && fs->i < 50)
			{
				fs->xp = fs->xtmp;
				fs->yp = fs->ytmp;
				fs->xtmp = (fs->xp * fs->xp) - (fs->yp * fs->yp) + \
					fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
				fs->ytmp = 2 * fs->xp * fs->yp + \
					fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
				fs->i++;
			}
			mlx_put_pixel(fs->g_img, fs->x, fs->y, fs->colpal[fs->i % 10]);
			if (fs->i == 50)
				mlx_put_pixel(fs->g_img, fs->x, fs->y, 0x00000000);
			fs->i = 0;
			fs->x++;
		}
		fs->x = 0;
		fs->y++;
	}
}

void	julias(t_fruct *fs, double xco, double yco)
{
	while (fs->y < HEIGHT)
	{
		while (fs->x < WIDTH)
		{
			fs->xtmp = fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
			fs->ytmp = fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
			while (hypot(fs->xtmp, fs->ytmp) <= 2 && fs->i < 200)
			{
				fs->xp = fs->xtmp;
				fs->yp = fs->ytmp;
				fs->xtmp = (fs->xp * fs->xp) - (fs->yp * fs->yp) + xco + fs->v;
				fs->ytmp = 2 * fs->xp * fs->yp + yco + fs->v;
				fs->i++;
			}
			mlx_put_pixel(fs->g_img, fs->x, fs->y, \
				fs->colpal[fs->i / 6 % 4 + 4]);
			if (fs->i < 16)
				mlx_put_pixel(fs->g_img, fs->x, fs->y, 0x00000000);
			fs->i = 0;
			fs->x++;
		}
		fs->x = 0;
		fs->y++;
	}
}

void	burningship(t_fruct *fs)
{
	while (fs->y < HEIGHT)
	{
		while (fs->x < WIDTH)
		{
			fs->xtmp = fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
			fs->ytmp = fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
			while (hypot(fs->xtmp, fs->ytmp) <= 2 && fs->i < 80)
			{
				fs->xp = fs->xtmp;
				fs->yp = fs->ytmp;
				fs->xtmp = (fs->xp * fs->xp) - (fs->yp * fs->yp) + fs->x * \
					fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx - fs->v);
				fs->ytmp = fabs(2 * fs->xp * fs->yp) + fs->y * fs->zum * \
					4 / HEIGHT - (2 * fs->zum - fs->movy - fs->v);
				fs->i++;
			}
			mlx_put_pixel(fs->g_img, fs->x, fs->y, fs->colpal[fs->i / 8 % 3]);
			if ((fs->i == 80) || (fs->i < 5))
				mlx_put_pixel(fs->g_img, fs->x, fs->y, 0x00000000);
			fs->i = 0;
			fs->x++;
		}
		fs->x = 0;
		fs->y++;
	}
}

int	generate_fractal(t_fruct *fs)
{
	fs->x = 0;
	fs->y = 0;
	if (ft_strncmp(fs->arg[1], "mandelbrot", 100) == 0)
		mandelbrot(fs);
	else if (ft_strncmp(fs->arg[1], "julia_one", 100) == 0)
		julias(fs, 0.355, -0.355);
	else if (ft_strncmp(fs->arg[1], "julia_two", 100) == 0)
		julias(fs, 0, 0.8);
	else if (ft_strncmp(fs->arg[1], "julia_three", 100) == 0)
		julias(fs, 0.4, -0.59);
	else if ((fs->arc == 3) && (checkiftof(fs->arg[1]) != -2) \
		&& (checkiftof(fs->arg[2]) != -2))
		julias(fs, ft_atof(fs->arg[1]), ft_atof(fs->arg[2]));
	else if (ft_strncmp(fs->arg[1], "burningship", 100) == 0)
		burningship(fs);
	else
		return (0);
	return (-2);
}
