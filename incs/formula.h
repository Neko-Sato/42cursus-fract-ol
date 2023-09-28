/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:38:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 17:34:11 by hshimizu         ###   ########.fr       */
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

unsigned int	mandelbrot(int index[2], t_position position, int iter[2],
					void *var);

#endif
