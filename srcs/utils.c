/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:22:13 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 21:19:54 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

unsigned int	*index2addr(t_data_addr *data_addr, int index[2])
{
	char	*addr;

	addr = (data_addr->addr);
	addr += index[0] * data_addr->bits_per_pixel / 8;
	addr += index[1] * data_addr->size_line;
	return ((unsigned int *)addr);
}

t_position	index2position(int index[2], t_position center, t_size size,
		double scale)
{
	return ((t_position){
		.x = center.x + (index[0] - size.width / 2.) * scale,
		.y = center.y + (index[1] - size.height / 2.) * scale});
}
