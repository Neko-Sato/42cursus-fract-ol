/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:17:15 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/26 01:19:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "fractol.h"
#include "ft_complex.h"
#include "plot.h"

//	complex_divergent_set
int	plot_cds(t_data_addr *data_addr, t_plot_var *var)
{
	int				i;
	int				j;
	int				temp;
	unsigned int	*addr;
	t_plot_cds_args	*args;

	args = var->args;
	i = 0;
	while (i < var->width)
	{
		j = 0;
		while (j < var->height)
		{
			addr = (unsigned int *)(data_addr->addr + (j * data_addr->size_line
						+ i * (data_addr->bits_per_pixel / 8)));
			temp = args->formula((t_complex){i2x(i, var), j2y(j, var)},
									args->args,
									args->max_inter);
			if (temp != -1)
				*addr = colormap(temp / (double)args->max_inter);
			else
				*addr = 0;
			j++;
		}
		i++;
	}
	return (0);
}
