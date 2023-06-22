/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_basic_func.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:29:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 19:06:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

double	ft_cabs(t_complex c)
{
	return (sqrt(pow(c.real, 2) + pow(c.imag, 2)));
}

t_complex	ft_conj(t_complex c)
{
	c.imag *= -1;
	return (c);
}

double	ft_carg(t_complex c)
{
	return (atan2(c.imag, c.real));
}
