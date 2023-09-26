/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:16:45 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/26 00:46:04 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLOT_H
# define PLOT_H

typedef struct s_data_addr
{
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_data_addr;

typedef struct s_plot_var
{
	int			width;
	int			height;
	double		scale;
	double		x;
	double		y;
	void		*args;
}				t_plot_var;

typedef int	(*t_plot_func)(t_data_addr *data_addr, t_plot_var *var);

typedef struct s_plot_args
{
	void		*mlx;
	void		*mlx_win;
	t_plot_func	plot_func;
	t_plot_var	*var;
}				t_plot_args;

void			*plot(void *mlx, void *mlx_win, t_plot_func plot_func,
					t_plot_var *var);
double			i2x(int i, t_plot_var *plot_var);
double			j2y(int j, t_plot_var *plot_var);
int				x2i(double x, t_plot_var *plot_var);
int				y2j(double y, t_plot_var *plot_var);

#endif
