/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:09:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/23 16:31:20 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_complex.h"
# include <mlx_int.h>

# define MAX_ITER 20
# define WIN_SIZE_X 1000
# define WIN_SIZE_Y 720

typedef struct s_win
{
	t_win_list	*mlx_win;
	double		point_x;
	double		point_y;
	double		magnification;
}				t_win;

typedef struct s_vars
{
	t_xvar		*mlx;
	t_win		win;
}				t_vars;

typedef struct s_mandelbrot
{
	t_vars		vars;
}				t_mandelbrot;

typedef struct s_julia
{
	t_vars		vars;
	t_complex	c;
}				t_julia;

void			fractol_mlx_init(void *vars);
void			fractol_win_init(void *vars, char *title);
void			mandelbrot(void);
void			julia(t_complex c);

#endif
