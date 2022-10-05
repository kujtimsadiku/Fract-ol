/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:13 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/07 11:47:52 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	mouse move will help us to scale the motion of the (x,y) and 
	1.2 will center it on middle if the menu is on. 
	d->c.i is default 2.
*/

int	mouse_move(int x, int y, t_data *d)
{
	if (d->julia_lock == 1 && x < WIDTH && x > MENU_WIDTH
		&& y < HEIGHT && y > 0 && d->menu)
	{
		d->c.r = 1.2 * ((double)x / (WIDTH - 200)) - 1;
		d->c.i = 2 * ((double)y / HEIGHT) - 1;
		if (d->thread)
			multi_thread(d);
		else
			draw(d);
	}
	else if (d->julia_lock == 1 && x < WIDTH && x > 0
		&& y < HEIGHT && y > 0 && !d->menu)
	{
		d->c.r = 2 * ((double)x / WIDTH) - 1;
		d->c.i = 2 * ((double)y / HEIGHT) - 1;
		if (d->thread)
			multi_thread(d);
		else
			draw(d);
	}
	return (0);
}

int	mouse_hook(int key, int x, int y, t_data *data)
{
	double	scaling;

	scaling = 0;
	if (x >= check_menu(data) && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (key == 4 || key == 5)
		{
			if ((key == 4) && data->zoom != 0)
				scaling = zoom(x, y, data, (0.9));
			else if (key == 5)
				scaling = zoom(x, y, data, (1.1));
			data->zoom *= scaling;
			if (data->thread)
				multi_thread(data);
			else
				draw(data);
		}
		if (key == 1)
			data->julia_lock = 1;
		else if (key == 2)
			data->julia_lock = 0;
	}
	return (0);
}
