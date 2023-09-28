/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 18:03:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "formula.h"
#include "ft_complex.h"
#include "types.h"
#include <mlx.h>
#include <libft.h>
#include <math.h>
#include <stddef.h>

unsigned int	mandelbrot(int index[2], t_position position, int iter[2],
		void *var)
{
	unsigned int	ret;
	t_complex		*buff_addr;

	buff_addr = &((t_mandelbrot *)var)->buff[index[0]][index[1]];
	if (iter[0] <= 1)
		*buff_addr = (t_complex){0, 0};
	*buff_addr = ft_cadd(ft_cpow(*buff_addr, (t_complex){((t_mandelbrot *)var)->exp, 0}),
			(t_complex){position.x, position.y});
	if (2. < ft_cabs(*buff_addr))
		ret = colormap(sqrt(iter[0] / (double)iter[1]));
	else
		ret = rgba2hex(0, 0, 0, 0xFF);
	return (ret);
}
