/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 03:05:39 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 05:56:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdio.h>

void	plot(t_fractol_local *local)
{
	t_data_addr		data_addr;
	unsigned int	*addr;
	int				index[2];

	get_data_addr(local->renderer->img, &data_addr);
	index[0] = 0;
	while (index[0] < local->var->size.width)
	{
		index[1] = 0;
		while (index[1] < local->var->size.height)
		{
			addr = index2addr(&data_addr, index);
			if (local->iter <= 1 || *addr & 0xFF000000)
				*addr = local->var->plot_func(
						index2position(index, local->var->position,
							local->var->size, local->var->scale),
						local->var->plot_args,
						local->var->max_iter,
						local->iter);
			index[1]++;
		}
		index[0]++;
	}
	mlx_put_image_to_window(local->renderer->mlx, local->renderer->win,
		local->renderer->img, 0, 0);
}
