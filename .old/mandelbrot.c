/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/26 17:40:05 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "plot.h"
#include <mlx.h>
#include <stddef.h>

int	mandelbrot_formula(t_complex c, void *args, size_t max_iter)
{
	size_t		i;
	t_complex	z;

	args = NULL;
	i = 0;
	z = (t_complex){0, 0};
	while (i < max_iter)
	{
		z = ft_cadd(ft_cmul(z, z), c);
		if (2. < ft_cabs(z))
			return (i);
		i++;
	}
	return (-1);
}

void	
mandelbrot(void)
{
	t_plot_cds_args	args;
	t_plot_var		var;
	void			*mlx;
	void			*win;

	mlx = mlx_init();
	var.x = -0;
	var.y = -0;
	var.width = 1000;
	var.height = 740;
	var.scale = 1. / 200;
	var.args = &args;
	args.formula = mandelbrot_formula;
	args.max_inter = 5;
	win = mlx_new_window(mlx, var.width, var.height, "mandelbrot");
	plot(mlx, win, plot_cds, &var);
	mlx_loop(mlx);
}
