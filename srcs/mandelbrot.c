/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 05:15:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "ft_complex.h"
#include "types.h"
#include <mlx.h>
#include <stddef.h>

int	mandelbrot_formula(t_complex c, double n, size_t max_iter)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z = (t_complex){0, 0};
	while (i < max_iter)
	{
		z = ft_cadd(ft_cpow(z, (t_complex){n, 0}), c);
		if (10. < ft_cabs(z))
			return (i);
		i++;
	}
	return (-1);
}

int	mandelbrot(t_position position, void *var, int max_iter, int iter)
{
	int	result;

	(void)var;
	result = mandelbrot_formula((t_complex){position.x, position.y}, 2, iter);
	if (result == -1)
		return (rgba2hex(0, 0, 0, 0xFF));
	return (colormap(result / (double)max_iter));
}
