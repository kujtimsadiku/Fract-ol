/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:27:23 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 10:43:21 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	hot_key4(int key, t_data *data)
{
	if (key == 8)
	{
		if (data->bit_shift++ == 23)
			data->bit_shift = 3;
	}
	else if (key == 48 && data->menu)
	{
		data->menu = 0;
		init_frac(data);
	}
	else if (key == 48 && !data->menu)
	{
		data->menu = 1;
		init_frac(data);
	}
	else if (key == 34)
	{
		data->fr.julia = 0;
		data->fr.mandelbrot = 0;
		data->fr.burningship = 0;
		data->zoom = 1.1;
		check_fractol(data, "Tricorn");
	}
}

static void	hot_key3(int key, t_data *data)
{
	if (key == 11)
	{
		data->fr.julia = 0;
		data->fr.mandelbrot = 0;
		data->fr.tricorn = 0;
		data->zoom = 1.1;
		check_fractol(data, "Burningship");
	}
	else if (key == 38)
	{
		data->fr.tricorn = 0;
		data->fr.mandelbrot = 0;
		data->fr.burningship = 0;
		data->zoom = 1.1;
		check_fractol(data, "Julia");
	}
	else if (key == 17)
		data->thread = 1;
	else if (key == 16)
		data->thread = 0;
	hot_key4(key, data);
}

static void	hot_key2(int key, t_data *data)
{
	if (key == 125)
	{
		data->fr.max_im -= 0.05;
		data->fr.min_im -= 0.05;
	}
	else if (key == 126)
	{
		data->fr.max_im += 0.05;
		data->fr.min_im += 0.05;
	}
	else if (key == 46)
	{
		data->fr.tricorn = 0;
		data->fr.julia = 0;
		data->fr.burningship = 0;
		data->zoom = 1.1;
		check_fractol(data, "Mandelbrot");
	}
	else if (key == 15)
	{
		init_frac(data);
	}
	hot_key3(key, data);
}

int	hot_key(int key, t_data *data)
{
	if (key == 53)
	{
		ft_putendl("You have exit the program succesfully.");
		exit(EXIT_SUCCESS);
	}
	else if (key == 123)
	{
		data->fr.max_re += 0.05;
		data->fr.min_re += 0.05;
	}
	else if (key == 124)
	{
		data->fr.max_re -= 0.05;
		data->fr.min_re -= 0.05;
	}
	hot_key2(key, data);
	mlx_clear_window(data->arg.mlx, data->arg.win);
	if (data->thread)
		multi_thread(data);
	else
		draw(data);
	return (0);
}
