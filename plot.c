/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:26:55 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/24 18:05:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plot.h"
#include <mlx.h>

//	Set data in the image
static int	__plot_func(t___plot_func_args args)
{
	void		*imge;
	t_data_addr	data_addr;

	imge = mlx_new_image(args.mlx, args.var->width, args.var->height);
	data_addr.addr = mlx_get_data_addr(imge, &data_addr.bits_per_pixel,
			&data_addr.size_line, &data_addr.endian);
	args.plot_func(&data_addr, args.var);
	mlx_put_image_to_window(args.mlx, args.mlx_win, imge, 0, 0);
	mlx_destroy_image(args.mlx, imge);
	return (0);
}

//	Generates and plots window
void	*plot(void *mlx, char *title, t_plot_var *var, t_plot_func plot_func)
{
	void				*mlx_win;
	t___plot_func_args	__plot_func_args;

	mlx_win = mlx_new_window(mlx, var->width, var->height, title);
	__plot_func_args = (t___plot_func_args){mlx, mlx_win, var, plot_func};
	__plot_func(__plot_func_args);
	return (mlx_win);
}
