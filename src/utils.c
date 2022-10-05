/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:17 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/16 16:11:09 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	menu(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data->win.width = 0;
	if (data->menu)
	{
		while (y < HEIGHT)
		{
			x = 0;
			data->win.width = MENU_WIDTH;
			while (x < data->win.width)
			{
				my_mlx_pixel_put(data, x, y, 0x808080);
				x++;
			}
			y++;
		}
	}
}

void	check_inside(t_data *d, bool inside, unsigned int iteratio)
{
	d->color = 0;
	if (inside)
		my_mlx_pixel_put(d, d->x, d->y, 0);
	else
	{
		d->color = d->color + MAX_ITER / 2 + iteratio;
		my_mlx_pixel_put(d, d->x, d->y, d->color << d->bit_shift);
	}
}

int	check_menu(t_data *data)
{
	if (data->menu)
		data->win.width = 200;
	else
		data->win.width = 0;
	return (data->win.width);
}

double	zoom(int x, int y, t_data *data, double scaling)
{
	double	h;
	double	w;
	double	nw;
	double	nh;

	w = (data->fr.max_re - data->fr.min_re) * data->zoom;
	h = (data->fr.max_im - data->fr.min_im) * data->zoom;
	nw = (data->fr.max_re - data->fr.min_re) * (data->zoom * scaling);
	nh = (data->fr.max_im - data->fr.min_im) * (data->zoom * scaling);
	data->offset_x -= ((double)x / WIDTH) * (nw - w);
	data->offset_y -= ((double)y / HEIGHT) * (nh - h);
	return (scaling);
}
