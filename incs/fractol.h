/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:51:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 05:56:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "types.h"
# include <stddef.h>

typedef struct s_render
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_renderer;

typedef int		(*t_plot_func)(t_position, void *, int, int);

typedef struct s_fractol
{
	char		*title;
	t_size		size;
	int			max_iter;
	t_position	position;
	double		scale;
	t_plot_func	plot_func;
	void		*plot_args;
}				t_fractol;

typedef struct s_fractol_local
{
	t_renderer	*renderer;
	t_fractol	*var;
	int			iter;
}				t_fractol_local;

typedef struct s_data_addr
{
	char		*addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_data_addr;

void			fractol(t_fractol *var);

void			plot(t_fractol_local *local);

double			**new_space(t_size size);
void			del_space(double **space, t_size size);

t_renderer		*new_renderer(char *title, t_size size);
void			del_renderer(t_renderer *renderer);

int				get_data_addr(void *img, t_data_addr *data_addr);
unsigned int	*index2addr(t_data_addr *data_addr, int index[2]);
t_position		index2position(int index[2], t_position center, t_size size,
					double scale);

#endif