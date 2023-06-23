/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:16:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/24 06:19:31 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H

# define BASE_SCALE 500

typedef int		(*t_plot_func)(double x, double y, void *args);

typedef struct s_plot_args
{
	t_plot_func	plot_func;
	void		*args;
	int			width;
	int			height;
	double		scale;
	double		x;
	double		y;
}				t_plot_args;

typedef struct s_plot_func_args
{
	void		*mlx;
	void		*mlx_win;
	t_plot_args	*plot_args;
}				t_plot_func_args;

typedef struct s_data_addr
{
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_data_addr;

void			*plot(void *mlx, char *title, t_plot_args *args);

#endif
