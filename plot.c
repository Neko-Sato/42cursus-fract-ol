/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:26:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/24 06:59:29 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plot.h"
#include <mlx.h>

static void	set_data(t_data_addr *data_addr, t_plot_args *plot_args)
{
	unsigned int	*addr;
	int				i;
	int				j;
	double			x;
	double			y;

	i = 0;
	while (i < plot_args->width)
	{
		j = 0;
		while (j < plot_args->height)
		{
			addr = (unsigned int *)(data_addr->addr + (j * data_addr->size_line
						+ i * (data_addr->bits_per_pixel / 8)));
			x = plot_args->x + (i - plot_args->width / 2) * plot_args->scale;
			y = plot_args->y + (plot_args->height/2 - j) * plot_args->scale;
			*addr = plot_args->plot_func(x, y, plot_args->args);
			j++;
		}
		i++;
	}
}

//	Set data in the image
static int	plot_func(t_plot_func_args args)
{
	void		*imge;
	t_data_addr	data_addr;

	imge = mlx_new_image(args.mlx, args.plot_args->width,
			args.plot_args->height);
	data_addr.addr = mlx_get_data_addr(imge, &data_addr.bits_per_pixel,
			&data_addr.size_line, &data_addr.endian);
	set_data(&data_addr, args.plot_args);
	mlx_put_image_to_window(args.mlx, args.mlx_win, imge, 0, 0);
	mlx_destroy_image(args.mlx, imge);
	return (0);
}

//	Generates and plots window
void	*plot(void *mlx, char *title, t_plot_args *args)
{
	void				*mlx_win;
	t_plot_func_args	plot_func_args;

	mlx_win = mlx_new_window(mlx, args->width, args->height, title);
	plot_func_args = (t_plot_func_args){mlx, mlx_win, args};
	plot_func(plot_func_args);
	return (mlx_win);
}
