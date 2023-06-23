/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:56:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/23 16:02:27 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	rgba2hex(int r, int g, int b, int a)
{
	int	color;

	color = 0;
	color |= (a & 0xFF) << (8 * 3);
	color |= (r & 0xFF) << (8 * 2);
	color |= (g & 0xFF) << (8 * 1);
	color |= (b & 0xFF) << (8 * 0);
	return (color);
}

int	hsvt2hex(double h, double s, double v, double t)
{
	int		ret;
	double	c;
	double	x;
	double	m;

	h *= 6;
	c = v * s;
	x = c * (1 - fabs(fmod(h, 2) - 1));
	m = v - c;
	if (h <= 0. && h < 1.)
		ret = rgb2hex((m + c) * 0xFF, (m + x) * 0xFF, (m + 0) * 0xFF, t * 0xFF);
	else if (h <= 1. && h < 2.)
		ret = rgb2hex((m + x) * 0xFF, (m + c) * 0xFF, (m + 0) * 0xFF, t * 0xFF);
	else if (h <= 2. && h < 3.)
		ret = rgb2hex((m + 0) * 0xFF, (m + c) * 0xFF, (m + x) * 0xFF, t * 0xFF);
	else if (h <= 3. && h < 4.)
		ret = rgb2hex((m + 0) * 0xFF, (m + x) * 0xFF, (m + c) * 0xFF, t * 0xFF);
	else if (h <= 4. && h < 5.)
		ret = rgb2hex((m + x) * 0xFF, (m + 0) * 0xFF, (m + c) * 0xFF, t * 0xFF);
	else if (h <= 5. && h < 6.)
		ret = rgb2hex((m + c) * 0xFF, (m + 0) * 0xFF, (m + x) * 0xFF, t * 0xFF);
	else
		ret = rgb2hex((m + 0) * 0xFF, (m + 0) * 0xFF, (m + 0) * 0xFF, t * 0xFF);
	return (ret);
}
