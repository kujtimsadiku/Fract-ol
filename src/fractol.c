/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:27:55 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 10:41:38 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	draw_fractol(t_data *data)
{
	int	iter;

	iter = 0;
	if (data->fr.burningship)
		iter = draw_mandelbrot(data, 0);
	else if (data->fr.mandelbrot)
		iter = draw_mandelbrot(data, 0);
	else if (data->fr.julia)
		iter = draw_julia_set(data);
	else if (data->fr.tricorn)
		iter = draw_tricorn(data, 0);
	return (iter);
}

void	thread_on_off(t_data *data)
{
	if (data->thread)
		multi_thread(data);
	else
		draw(data);
}

void	init_frac(t_data *data)
{
	if (data->menu)
	{
		data->fr.min_re = data->win.width / WIDTH - 3;
		data->fr.max_re = data->win.width / WIDTH + 1;
	}
	else
	{
		data->fr.min_re = -2;
		data->fr.max_re = 2;
	}
	data->fr.min_im = -2;
	data->fr.max_im = 2;
	data->offset_x = 0;
	data->offset_y = 0;
	data->c.i = 0;
	data->c.r = 0;
	data->julia_lock = 0;
	data->zoom = 1.1;
	data->x = data->win.width;
	data->bit_shift = 3;
}

void	check_fractol(t_data *data, char *name)
{
	if (!ft_strcmp(name, "Mandelbrot"))
		data->fr.mandelbrot = 1;
	else if (!ft_strcmp(name, "Julia"))
		data->fr.julia = 1;
	else if (!ft_strcmp(name, "Burningship"))
		data->fr.burningship = 1;
	else if (!ft_strcmp(name, "Tricorn"))
		data->fr.tricorn = 1;
	else
		error("The name wasn't correct.\nExample ./fractol Julia");
	init_frac(data);
	thread_on_off(data);
}
