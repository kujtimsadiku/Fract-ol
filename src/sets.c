/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:07 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 10:31:27 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_burningship(t_complex *z)
{
	z->i = fabs(z->i);
	z->r = fabs(z->r);
}

int	draw_tricorn(t_data *data, unsigned int iteration)
{
	t_complex	c;
	t_complex	z;
	t_complex	temp;

	data->inside = true;
	c = set_complex(data);
	z = set_complex(data);
	while (iteration < MAX_ITER)
	{
		temp.r = z.r * z.r;
		temp.i = z.i * z.i;
		if (temp.r + temp.i > 4)
		{
			data->inside = false;
			break ;
		}
		z.i = -2 * z.r * z.i + c.i;
		z.r = temp.r - temp.i + c.r;
		iteration++;
	}
	return (iteration);
}

int	draw_mandelbrot(t_data *data, unsigned int iteration)
{
	t_complex	c;
	t_complex	z;
	t_complex	temp;

	data->inside = true;
	c = set_complex(data);
	z = set_complex(data);
	while (iteration < MAX_ITER)
	{
		if (data->fr.burningship)
			draw_burningship(&z);
		temp.r = z.r * z.r;
		temp.i = z.i * z.i;
		if (temp.r + temp.i > 4)
		{
			data->inside = false;
			break ;
		}
		z.i = 2 * z.r * z.i + c.i;
		z.r = temp.r - temp.i + c.r;
		iteration++;
	}
	return (iteration);
}

int	draw_julia_set(t_data *data)
{
	t_complex		z;
	t_complex		temp;

	data->iter = 0;
	data->inside = true;
	z = set_complex(data);
	while (data->iter < MAX_ITER)
	{
		temp.r = z.r * z.r;
		temp.i = z.i * z.i;
		if (temp.r + temp.i > 4)
		{
			data->inside = false;
			break ;
		}
		z.i = 2 * z.r * z.i + data->c.i;
		z.r = temp.r - temp.i + data->c.r;
		data->iter++;
	}
	return (data->iter);
}
