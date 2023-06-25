/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:19:08 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/25 17:51:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "plot.h"
#include <mlx.h>
#include <stddef.h>

int	julia_formula(t_complex z, void *args, size_t max_iter)
{
	size_t	i;

	i = 0;
	while (i < max_iter)
	{
		z = ft_cadd(ft_cmul(z, z), *(t_complex *)args);
		if (2. < ft_cabs(z))
			return (i);
		i++;
	}
	return (-1);
}

void	julia(void)
{
	t_complex			a;
	t_plot_cds_args		args;
	t_plot_var			var;
	void				*mlx;

	a = (t_complex){-0.3, 0.63};
	mlx = mlx_init();
	var.x = 0.;
	var.y = 0.;
	var.width = 1000;
	var.height = 740;
	var.scale = 1. / 250;
	var.args = &args;
	args.args = &a;
	args.formula = julia_formula;
	args.max_inter = 20;
	plot(mlx, "julia", &var, plot_cds);
	mlx_loop(mlx);
}
