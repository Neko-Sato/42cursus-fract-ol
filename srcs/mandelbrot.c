/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 21:26:38 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "formula.h"
#include "fractol.h"
#include "ft_complex.h"
#include "types.h"
#include <math.h>
#include <stddef.h>

unsigned int	mandelbrot(t_plot_var *var, void *__args)
{
	t_mandelbrot	*args;
	unsigned int	ret;
	t_complex		*buff_addr;

	args = (t_mandelbrot *)__args;
	buff_addr = &args->buff[var->index[0]][var->index[1]];
	if (var->iter <= 1)
		*buff_addr = (t_complex){0, 0};
	*buff_addr = ft_cadd(ft_cpow(*buff_addr, (t_complex){args->exp, 0}),
			(t_complex){var->position.x, var->position.y});
	if (2. < ft_cabs(*buff_addr))
		ret = colormap(sqrt(var->iter / (double)var->max_iter));
	else
		ret = rgba2hex(0, 0, 0, 0xFF);
	return (ret);
}
