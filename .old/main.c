/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:25:11 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 23:33:01 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_complex.h"
#include "utils.h"
#include "errors.h"

int	main(int argc, char *argv[])
{
	if (2 < argc)
	{
		if (*argv[1] == 'M')
			mandelbrot();
		else if (*argv[1] == 'J' && 3 < argc)
			julia((t_complex){ft_atof(argv[2]), ft_atof(argv[3])});
		else 
			bad_argment_error();
	}
	else
		bad_argment_error();
	return (0);
}
