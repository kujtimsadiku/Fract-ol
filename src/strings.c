/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:57:52 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 10:56:36 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	put_strings3(t_data *d)
{
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 380, 0xFFFFFF, "T  - Threads");
	mlx_string_put(d->arg.mlx, d->arg.win,
		140, 380, 0x00FF00, "ON");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 395, 0xFFFFFF, "Y  - Threads");
	mlx_string_put(d->arg.mlx, d->arg.win,
		140, 395, 0xFF0000, "OFF");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 420, 0, "TAB - MENU");
	mlx_string_put(d->arg.mlx, d->arg.win,
		130, 420, 0x00FF00, "ON");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 435, 0, "TAB - MENU");
	mlx_string_put(d->arg.mlx, d->arg.win,
		130, 435, 0xFF0000, "OFF");
}

static void	put_strings2(t_data *d)
{
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 175, 0, "MOUSE TO WORK WITH");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 192, 0xFFFFFF, "(mw = mousewheel)");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 210, 0xFFFFFF, "Zoom in   - mw up");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 225, 0xFFFFFF, "Zoom out  - mw down");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 285, 0, "Julia Open/Lock");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 302, 0, "motion:");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 320, 0xFFFFFF, "Left button - Open");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 335, 0xFFFFFF, "Right button - Lock");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, HEIGHT - 50, 0xFFFFFF, "ESC - QUIT");
	put_strings3(d);
}

void	put_strings(t_data *d)
{
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 10, 0, "KEYS TO WORK WITH");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 35, 0xFFFFFF, "To move it press");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 47, 0xFFFFFF, "arrow keys");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 68, 0xFFFFFF, "You can choose:");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 85, 0xFFFFFF, "J  -    Julia set");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 100, 0xFFFFFF, "M  -    Mandelbrot");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 115, 0xFFFFFF, "B  -    Burningship");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 130, 0xFFFFFF, "I  -    Tricorn");
	mlx_string_put(d->arg.mlx, d->arg.win,
		5, 145, 0xFFFFFF, "R  -   reset values");
	put_strings2(d);
}
