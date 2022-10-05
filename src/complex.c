/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:27:34 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/07 10:56:26 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	set_complex(t_data *data)
{
	t_complex	cmplx;

	cmplx.i = ((double)data->y / HEIGHT) * (data->fr.max_im - data->fr.min_im)
		* data->zoom + (data->offset_y + data->fr.min_im);
	cmplx.r = ((double)data->x / WIDTH) * (data->fr.max_re - data->fr.min_re)
		* data->zoom + (data->offset_x + data->fr.min_re);
	return (cmplx);
}
