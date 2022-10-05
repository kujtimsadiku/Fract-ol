/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:27:47 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 11:34:08 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 || x <= WIDTH) && (y >= 0 || y <= HEIGHT))
		dst = d->img.addr + (y * d->img.sizeline + x * (d->img.bpp >> 3));
	*(unsigned int *)dst = color;
}

void	draw(t_data *d)
{
	d->y = 0;
	while (d->y < HEIGHT)
	{
		d->x = check_menu(d);
		while (d->x < WIDTH)
		{
			d->iter = draw_fractol(d);
			check_inside(d, d->inside, d->iter);
			d->x++;
		}
		d->y++;
	}
	menu(d);
	mlx_put_image_to_window(d->arg.mlx, d->arg.win, d->img.image, 0, 0);
	if (d->menu)
		put_strings(d);
}
