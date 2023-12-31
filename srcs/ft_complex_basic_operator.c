/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex_basic_operator.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:29:19 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/26 20:37:53 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"
#include <math.h>

t_complex	ft_cadd(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real + b.real;
	ret.imag = a.imag + b.imag;
	return (ret);
}

t_complex	ft_csub(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real - b.real;
	ret.imag = a.imag - b.imag;
	return (ret);
}

t_complex	ft_cmul(t_complex a, t_complex b)
{
	t_complex	ret;

	ret.real = a.real * b.real - a.imag * b.imag;
	ret.imag = a.real * b.imag + a.imag * b.real;
	return (ret);
}

t_complex	ft_cdiv(t_complex a, t_complex b)
{
	t_complex	ret;
	double		pow2_abs_b;

	ret = ft_cmul(a, ft_conj(b));
	pow2_abs_b = pow(b.real, 2) + pow(b.imag, 2);
	ret.real /= pow2_abs_b;
	ret.imag /= pow2_abs_b;
	return (ret);
}
