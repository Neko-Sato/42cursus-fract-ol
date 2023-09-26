/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 02:27:32 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/26 22:09:52 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <mlx.h>
#include <stddef.h>

int	mandelbrot_formula(t_complex c, void *args, size_t max_iter)
{
	size_t		i;
	t_complex	z;

	args = NULL;
	i = 0;
	z = (t_complex){0, 0};
	while (i < max_iter)
	{
		z = ft_cadd(ft_cmul(z, z), c);
		if (2. < ft_cabs(z))
			return (i);
		i++;
	}
	return (-1);
}
