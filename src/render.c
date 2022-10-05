/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:15 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 11:27:07 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*render(void *arg)
{
	t_data	*d;

	d = (t_data *)arg;
	d->y = HEIGHT / THREAD * d->id;
	while (d->y < HEIGHT / THREAD * (d->id + 1) && d->y < HEIGHT)
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
	return (NULL);
}

void	multi_thread(t_data *d)
{
	pthread_t	thread[THREAD];
	t_data		d2[THREAD];
	int			i;

	i = 0;
	while (i < THREAD)
	{
		d2[i] = *d;
		d2[i].id = i;
		pthread_create(&thread[i], NULL, render, &d2[i]);
		i++;
	}
	i = 0;
	while (i < THREAD)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	menu(d);
	mlx_put_image_to_window(d->arg.mlx, d->arg.win, d->img.image, 0, 0);
	if (d->menu)
		put_strings(d);
}
