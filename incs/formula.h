/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:38:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 22:05:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_H
# define FORMULA_H

# include "fractol.h"
# include "ft_complex.h"

typedef struct s_mandelbrot
{
	double		exp;
	t_complex	**buff;
}				t_mandelbrot;

unsigned int	plot_mandelbrot(t_plot_var *var, void *args);

typedef struct s_julia
{
	double		exp;
	t_complex	point;
	t_complex	**buff;
}				t_julia;

unsigned int	plot_julia(t_plot_var *var, void *args);

#endif
