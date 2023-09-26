/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:26:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/26 00:56:15 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plot.h"
#include <ft_printf.h>
#include <mlx.h>
#include <stdlib.h>

//	Set data in the image
static int	__plot_func(t_plot_args *args)
{
	void		*imge;
	t_data_addr	data_addr;

	imge = mlx_new_image(args->mlx, args->var->width, args->var->height);
	data_addr.addr = mlx_get_data_addr(imge, &data_addr.bits_per_pixel,
			&data_addr.size_line, &data_addr.endian);
	args->plot_func(&data_addr, args->var);
	mlx_put_image_to_window(args->mlx, args->mlx_win, imge, 0, 0);
	mlx_destroy_image(args->mlx, imge);
	return (0);
}

void	zoom(int x, int y, double scale, t_plot_args *args)
{
	args->var->x += (x - args->var->width / 2) * (args->var->scale - scale);
	args->var->y += (args->var->height / 2 - y) * (args->var->scale - scale);
	args->var->scale = scale;
}

int mouse_hook(int button,int x,int y, t_plot_args *args)
{
	if(button == 4)
		zoom(x, y, args->var->scale*150./100., args);
	else if(button == 5)
		zoom(x, y, args->var->scale*50./100., args);
	else
		return (1);
	__plot_func(args);
	return (0);
}

//	Generates and plots window
void	*plot(void *mlx, void *mlx_win, t_plot_func plot_func, t_plot_var *var)
{
	t_plot_args	*plot_args;

	plot_args = malloc(sizeof(t_plot_args));
	if (!plot_args)
		return (NULL);
	*plot_args = (t_plot_args){mlx, mlx_win, plot_func, var};
	__plot_func(plot_args);
	mlx_mouse_hook(mlx_win, mouse_hook, plot_args);
	return (plot_args);
}
