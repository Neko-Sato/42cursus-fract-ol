/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:17:15 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/23 01:06:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "fractol.h"
#include <mlx.h>

void	fractol_mlx_init(void *_vars)
{
	t_vars	*vars;

	vars = _vars;
	vars->mlx = mlx_init();
	if (!vars->mlx)
		malloc_error();
}

void	fractol_win_init(void *_vars, char *title)
{
	t_vars	*vars;
	t_win	*win;

	vars = _vars;
	win = &vars->win;
	win->mlx_win = mlx_new_window(vars->mlx, WIN_SIZE_X, WIN_SIZE_Y, title);
	if (!win->mlx_win)
		malloc_error();
	win->point_x = 0;
	win->point_y = 0;
	win->magnification = 1;
}
