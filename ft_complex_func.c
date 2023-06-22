/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:29:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 22:16:37 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

t_complex	ft_cexp(t_complex c)
{
	t_complex	ret;
	double		exp_real;

	exp_real = exp(c.real);
	ret.real = exp_real * cos(c.imag);
	ret.imag = exp_real * sin(c.imag);
	return (ret);
}

t_complex	ft_cln(t_complex c)
{
	t_complex	ret;

	ret.imag = ft_carg(c);
	ret.real = log(c.real / cos(ret.imag));
	return (ret);
}

t_complex	ft_cpow(t_complex a, t_complex b)
{
	return (ft_cexp(ft_cmul(b, ft_cln(a))));
}

t_complex	ft_clog(t_complex a, t_complex b)
{
	return (ft_cdiv(ft_cln(a), ft_cln(b)));
}
