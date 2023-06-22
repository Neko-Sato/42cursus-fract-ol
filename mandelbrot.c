/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 22:11:34 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

size_t	mandelbrot_formula(t_complex c)
{
	size_t		i;
	t_complex	z;

	i = 0;
	z = (t_complex){0, 0};
	while (i < MAX_ITER && ft_cabs(z) < 2.)
	{
		z = ft_cadd(ft_cpow(z, (t_complex){2, 0}), c);
		i++;
	}
	return (i);
}

void	mandelbrot(void)
{
	exit(0);
}
