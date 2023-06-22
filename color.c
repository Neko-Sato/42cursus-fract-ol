/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:56:57 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/23 02:22:30 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rgb2hex(int r, int g, int b)
{
	int	color;

	color = 0;
	color |= (r & 0xFF) < 16;
	color |= (g & 0xFF) < 8;
	color |= (b & 0xFF) < 0;
	return (color);
}

int	hsv2hex(double h, double s, double v)
{

}