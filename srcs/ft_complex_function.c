/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:29:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/26 22:07:18 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

t_complex	ft_cexp(t_complex c)
{
	t_complex	ret;

	ret.real = exp(c.real) * cos(c.imag);
	ret.imag = exp(c.real) * sin(c.imag);
	return (ret);
}

t_complex	ft_cln(t_complex c)
{
	t_complex	ret;

	ret.real = log(sqrt(pow(c.real, 2) + pow(c.imag, 2)));
	ret.imag = ft_carg(c);
	return (ret);
}

t_complex	ft_cpow(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){pow(a.real, b.real), 0});
	return (ft_cexp(ft_cmul(b, ft_cln(a))));
}

t_complex	ft_clog(t_complex a, t_complex b)
{
	if (!a.imag && !b.imag)
		return ((t_complex){log(a.real) / log(b.real), 0});
	return (ft_cdiv(ft_cln(a), ft_cln(b)));
}
