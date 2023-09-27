/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 02:42:44 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 00:54:35 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

static int	init(t_fractol_local *local);
static int	keyevent(int keycode, t_fractol_local *local);
static int	mouseevent(int button, int x, int y, t_fractol_local *local);
static int	fractol_plot(t_fractol_local *local);

void	fractol(t_fractol *var)
{
	t_fractol_local	local;

	local.var = var;
	if (init(&local))
		return ;
	mlx_hook(local.win, DestroyNotify, NoEventMask, mlx_loop_end, local.mlx);
	mlx_key_hook(local.win, keyevent, &local);
	mlx_mouse_hook(local.win, mouseevent, &local);
	mlx_loop_hook(local.mlx, fractol_plot, &local);
	mlx_loop(local.mlx);
	mlx_destroy_image(local.mlx, local.img);
	mlx_destroy_window(local.mlx, local.win);
	mlx_destroy_display(local.mlx);
	ft_putendl_fd("exit", STDOUT_FILENO);
}

static int	keyevent(int keycode, t_fractol_local *local)
{
	if (keycode == XK_Left)
	{
		local->var->plot_var->x -= local->var->plot_var->scale;
		local->count_event++;
		local->writed = 0;
	}
	else if (keycode == XK_Right)
	{
		local->var->plot_var->x += local->var->plot_var->scale;
		local->count_event++;
		local->writed = 0;
	}
	else if (keycode == XK_Up)
	{
		local->var->plot_var->y += local->var->plot_var->scale;
		local->count_event++;
		local->writed = 0;
	}
	else if (keycode == XK_Down)
	{
		local->var->plot_var->y -= local->var->plot_var->scale;
		local->count_event++;
		local->writed = 0;
	}
	else if (keycode == XK_Escape)
		mlx_loop_end(local->mlx);
	else
		return (1);
	return (0);
}

static int	mouseevent(int button, int x, int y, t_fractol_local *local)
{
	if (button == 4)
	{
		local->var->plot_var->x += (x - local->var->width / 2.)
			* (local->var->plot_var->scale * 0.1);
		local->var->plot_var->y += (local->var->height / 2 - y)
			* (local->var->plot_var->scale * 0.1);
		local->var->plot_var->scale *= 0.9;
		local->count_event++;
		local->writed = 0;
	}
	else if (button == 5)
	{
		local->var->plot_var->x += (x - local->var->width / 2.)
			* (local->var->plot_var->scale / -9.);
		local->var->plot_var->y += (local->var->height / 2 - y)
			* (local->var->plot_var->scale / -9.);
		local->var->plot_var->scale /= 0.9;
		local->count_event++;
		local->writed = 0;
	}
	return (0);
}


static int	plot(t_fractol_local *local)
{
	unsigned int	*addr;
	int				i;
	int				j;
	double			x;
	double			y;

	i = 0;
	while (i < local->var->width)
	{
		j = 0;
		while (j < local->var->height)
		{
			addr = (unsigned int *)(local->data_addr.addr + (j * local->data_addr.size_line + i
						* (local->data_addr.bits_per_pixel / 8)));
			x = local->var->plot_var->x + (i - local->var->width / 2)
				* local->var->plot_var->scale;
			y = local->var->plot_var->y + (local->var->height / 2 - j)
				* local->var->plot_var->scale;
			*addr = local->var->plot_func(x, y, local->var->plot_args);
			j++;
		}
		i++;
	}
	return (0);
}

static int	fractol_plot(t_fractol_local *local)
{
	if (!local->writed && local->pre_count_event == local->count_event)
	{
		plot(local);
		mlx_put_image_to_window(local->mlx, local->win, local->img, 0, 0);
		local->count_event = 0;
		mlx_do_sync(local->mlx);
		local->writed = 1;
	}
	local->pre_count_event = local->count_event;
	local->count_event = 0;
	return (0);
}

static int	init(t_fractol_local *local)
{
	local->writed = 0;
	local->pre_count_event = 0;
	local->count_event = 0;
	local->mlx = mlx_init();
	if (local->mlx)
	{
		local->win = mlx_new_window(local->mlx, local->var->width,
				local->var->height, local->var->title);
		if (local->win)
		{
			local->img = mlx_new_image(local->mlx, local->var->width,
					local->var->height);
			if (local->img)
			{
				local->data_addr.addr = mlx_get_data_addr(
						local->img, &local->data_addr.bits_per_pixel,
						&local->data_addr.size_line, &local->data_addr.endian);
				if (local->data_addr.addr)
					return (0);
				mlx_destroy_image(local->mlx, local->img);
			}
		}
		mlx_destroy_window(local->mlx, local->win);
	}
	mlx_destroy_display(local->mlx);
	perror("mlx");
	return (-1);
}
