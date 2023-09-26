/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:09:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/26 01:05:40 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "ft_complex.h"
# include "plot.h"
#include <stddef.h>

typedef int				(*t_plot_cds_formula)(t_complex c, void *args,
					size_t max_iter);

typedef struct s_plot_cds_args
{
	t_plot_cds_formula	formula;
	size_t				max_inter;
	void				*args;
}						t_plot_cds_args;

int	plot_cds(t_data_addr *data_addr, t_plot_var *var);
void	mandelbrot(void);
void	julia(void);

#endif
