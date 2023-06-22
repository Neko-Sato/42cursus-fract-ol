/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:48:59 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 21:51:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

double	ft_atof(const char *str)
{
	double	ret;
	int		rank;

	ret = 0;
	rank = 1;
	while (*str && ft_isdigit(*str))
	{
		ret *= 10;
		ret += *str++ - '0';
	}
	if (*str == '.')
		str++;
	while (*str && ft_isdigit(*str))
	{
		rank *= 10;
		ret += (*str++ - '0') / (double)rank;
	}
	return (ret);
}
