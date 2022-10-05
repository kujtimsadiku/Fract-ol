/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksadiku <ksadiku@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:46:52 by ksadiku           #+#    #+#             */
/*   Updated: 2022/09/13 11:29:44 by ksadiku          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200
# define THREAD 20
# define MENU_WIDTH 200

# include <stdbool.h>
# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

typedef struct s_mlx
{
	void	*win;
	void	*mlx;
}				t_mlx;

typedef struct s_win
{
	int	width;
}				t_win;

typedef struct s_img
{
	char	*addr;
	int		*image;
	int		bpp;
	int		sizeline;
	int		endian;
}			t_img;

typedef struct s_fractol
{
	int		burningship;
	int		mandelbrot;
	int		julia;
	int		tricorn;
	double	max_im;
	double	max_re;
	double	min_im;
	double	min_re;
}				t_fractol;

typedef struct s_complex
{
	double	i;
	double	r;
}				t_complex;

typedef struct s_data
{
	t_fractol		fr;
	t_mlx			arg;
	t_img			img;
	t_complex		c;
	t_win			win;
	int				id;
	unsigned int	iter;
	int				iterin;
	double			zoom;
	double			offset_x;
	double			offset_y;
	int				x;
	int				y;
	int				bit_shift;
	int				julia_lock;
	int				menu;
	int				color;
	int				thread;
	int				menu_width;
	bool			inside;
}				t_data;

t_complex	set_complex(t_data *data);

void		init_img(t_data *d);
void		init_frac(t_data *data);
void		menu(t_data *data);
int			check_menu(t_data *data);

void		my_mlx_pixel_put(t_data *d, int x, int y, int color);
void		check_fractol(t_data *data, char *name);

void		draw(t_data *d);
int			draw_fractol(t_data *data);

int			draw_julia_set(t_data *data);
void		draw_burningship(t_complex *z);
int			draw_mandelbrot(t_data *data, unsigned int iteration);
int			draw_tricorn(t_data *data, unsigned int iteration);

void		thread_on_off(t_data *data);
void		error(char *message);
void		put_strings(t_data *d);

int			hot_key(int key, t_data *data);
int			mouse_hook(int key, int x, int y, t_data *data);
int			mouse_move(int x, int y, t_data *d);

double		zoom(int x, int y, t_data *data, double scaling);

void		multi_thread(t_data *d);
void		*render(void *arg);

void		check_inside(t_data *d, bool inside, unsigned int iteratio);

#endif