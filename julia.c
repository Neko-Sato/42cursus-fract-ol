/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:19:08 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 23:54:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_complex.h"
#include <stdlib.h>

size_t	julia_formula(t_complex z, t_complex c)
{
	size_t	i;

	i = 0;
	while (i < MAX_ITER && ft_cabs(z) < 2.)
	{
		z = ft_cadd(ft_cpow(z, (t_complex){2, 0}), c);
		i++;
	}
	return (i);
}

void	julia(t_complex c)
{
	c = (t_complex){0 , 0};
	exit(0);
}
