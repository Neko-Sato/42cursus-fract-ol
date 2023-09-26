/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:42:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/27 01:02:02 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <libft.h>
#include <mlx.h>
#include <unistd.h>

static int	init(t_fractol_local *local, t_fractol *var);
static int	keyevent(int keycode, t_fractol_local *local);
static int	mouseevent(int button, int x, int y, t_fractol_local *local);
static int	plot(t_fractol_local *local);

void	fractol(t_fractol *var)
{
	t_fractol_local	local;

	if (init(&local, var))
		return ;
	local.width = var->width;
	local.height = var->height;
	mlx_hook(local.win, DestroyNotify, NoEventMask, mlx_loop_end, local.mlx);
	mlx_key_hook(local.win, keyevent, &local);
	mlx_mouse_hook(local.win, mouseevent, &local);
	mlx_loop_hook(local.mlx, plot, &local);
	mlx_loop(local.mlx);
	mlx_destroy_image(local.mlx, local.img);
	mlx_destroy_window(local.mlx, local.win);
	mlx_destroy_display(local.mlx);
	ft_putendl_fd("exit", STDOUT_FILENO);
}

static int	keyevent(int keycode, t_fractol_local *local)
{
	if (keycode == XK_Escape)
		mlx_loop_end(local->mlx);
	else
		return (1);
	return (0);
}

static int	mouseevent(int button, int x, int y, t_fractol_local *local)
{
	(void)button;
	(void)x;
	(void)y;
	(void)local;
	return (0);
}

static int	plot(t_fractol_local *local)
{
	mlx_put_image_to_window(local->mlx, local->win, local->img, 0, 0);
	return (0);
}

static int	init(t_fractol_local *local, t_fractol *var)
{
	local->mlx = mlx_init();
	if (local->mlx)
	{
		local->win = mlx_new_window(local->mlx, var->width, var->height,
				var->title);
		if (local->win)
		{
			local->img = mlx_new_image(local->mlx, var->width, var->height);
			if (local->img)
				return (0);
		}
		mlx_destroy_window(local->mlx, local->win);
	}
	mlx_destroy_display(local->mlx);
	peeror("mlx");
	return (-1);
}
