/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:38:21 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 04:52:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMULA_H
# define FORMULA_H

# include "fractol.h"

int	mandelbrot(t_position position, void *var, int max_iter, int iter);

#endif
