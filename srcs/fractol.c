/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:42:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 06:10:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

static int	fractol_plot(t_fractol_local *local);
static int	keyevent(int keycode, t_fractol_local *local);
static int	mouseevent(int button, int x, int y, t_fractol_local *local);

void	fractol(t_fractol *var)
{
	t_fractol_local	local;

	local.var = var;
	local.iter = 0;
	local.renderer = new_renderer(var->title, var->size);
	if (!local.renderer)
		return ;
	mlx_hook(local.renderer->win, DestroyNotify, NoEventMask, mlx_loop_end,
		local.renderer->mlx);
	mlx_key_hook(local.renderer->win, keyevent, &local);
	mlx_mouse_hook(local.renderer->win, mouseevent, &local);
	mlx_loop_hook(local.renderer->mlx, fractol_plot, &local);
	mlx_loop(local.renderer->mlx);
	del_renderer(local.renderer);
	ft_putendl_fd("exit", STDOUT_FILENO);
}

static int	fractol_plot(t_fractol_local *local)
{
	if (local->iter < local->var->max_iter)
	{
		local->iter++;
		plot(local);
		mlx_do_sync(local->renderer->mlx);
	}
	return (0);
}

static int	keyevent(int keycode, t_fractol_local *local)
{
	if (keycode == XK_Left)
	{
		local->var->position.x -= local->var->scale;
		local->iter = 0;
	}
	else if (keycode == XK_Right)
	{
		local->var->position.x += local->var->scale;
		local->iter = 0;
	}
	else if (keycode == XK_Up)
	{
		local->var->position.y += local->var->scale;
		local->iter = 0;
	}
	else if (keycode == XK_Down)
	{
		local->var->position.y -= local->var->scale;
		local->iter = 0;
	}
	else if (keycode == XK_Escape)
		mlx_loop_end(local->renderer->mlx);
	else
		return (1);
	return (0);
}

static int	mouseevent(int button, int x, int y, t_fractol_local *local)
{
	if (button == 4)
	{
		local->var->position.x += (x - local->var->size.width / 2.)
			* (local->var->scale * 0.1);
		local->var->position.y += (local->var->size.height / 2 - y)
			* (local->var->scale * 0.1);
		local->var->scale *= 0.9;
		local->iter = 0;
	}
	else if (button == 5)
	{
		local->var->position.x += (x - local->var->size.width / 2.)
			* (local->var->scale / -9.);
		local->var->position.y += (local->var->size.height / 2 - y)
			* (local->var->scale / -9.);
		local->var->scale /= 0.9;
		local->iter = 0;
	}
	return (0);
}
