/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:51:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 19:16:45 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "renderer.h"
# include "types.h"
# include <stddef.h>

typedef struct s_plot_var
{
	int					*index;
	t_position			position;
	int					max_iter;
	int					iter;
}						t_plot_var;

typedef unsigned int	(*t_plot_func)(t_plot_var *var, void *args_ptr);

typedef struct s_fractol
{
	char				*title;
	t_size				size;
	int					max_iter;
	t_position			position;
	double				scale;
	t_plot_func			plot_func;
	void				*plot_args;
}						t_fractol;

typedef struct s_fractol_local
{
	t_fractol			*var;
	t_renderer			*renderer;
	int					iter;
}						t_fractol_local;

void					fractol(t_fractol *var);

#endif