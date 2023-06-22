/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/23 02:59:44 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

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
	t_mandelbrot	config;

	fractol_mlx_init(&config);
	fractol_win_init(&config, "mandelbrot");
	for (int i = -200; i < 200; i++)
		for (int j = -150; j < 150; j++)
	{	
		mlx_pixel_put(
				((t_vars *)&config)->mlx,
				((t_vars *)&config)->win.mlx_win,
				i,
				j,
				mandelbrot_formula((t_complex){i/100., j/100.}));
	}
	mlx_loop(((t_vars *)&config)->mlx);
}
