/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:56:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/11/04 23:32:51 by hshimizu         ###   ########.fr       */
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

	h = fmod(1 + fmod(h, 1), 1) * 6;
	c = s * v;
	x = c * (1 - fabs(fmod(h, 2) - 1));
	m = v - c;
	if (0. <= h && h < 1.)
		ret = rgba2hex((m + c) * 0xFF, (m + x) * 0xFF, m * 0xFF, t * 0xFF);
	else if (1. <= h && h < 2.)
		ret = rgba2hex((m + x) * 0xFF, (m + c) * 0xFF, m * 0xFF, t * 0xFF);
	else if (2. <= h && h < 3.)
		ret = rgba2hex(m * 0xFF, (m + c) * 0xFF, (m + x) * 0xFF, t * 0xFF);
	else if (3. <= h && h < 4.)
		ret = rgba2hex(m * 0xFF, (m + x) * 0xFF, (m + c) * 0xFF, t * 0xFF);
	else if (4. <= h && h < 5.)
		ret = rgba2hex((m + x) * 0xFF, m * 0xFF, (m + c) * 0xFF, t * 0xFF);
	else if (5. <= h && h < 6.)
		ret = rgba2hex((m + c) * 0xFF, m * 0xFF, (m + x) * 0xFF, t * 0xFF);
	else
		ret = rgba2hex(m * 0xFF, m * 0xFF, m * 0xFF, t * 0xFF);
	return (ret);
}

int	colormap(double n)
{
	double	t[2];

	t[0] = 1.;
	t[1] = 2. * n;
	if (1. < t[1])
	{
		t[0] = 1. - t[1];
		t[1] = 1.;
	}
	return (hsvt2hex((5. / 6. - n)*100.2684, t[0], t[1], 0.));
}
