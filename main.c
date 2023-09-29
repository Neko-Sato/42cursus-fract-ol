/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:30:51 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/29 17:03:23 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "formula.h"
#include "fractol.h"
#include <libft.h>

#define MAX_ITER 1000
#define WIDTH_SIZE 800
#define HEIGHT_SIZE 600

int	mandelbrot(double exp);
int	julia(double exp, t_complex point);

int	main(int argc, char *argv[])
{
	double	exp;

	exp = 2.;
	if (1 < argc)
	{
		if (!ft_strcmp(argv[1], "M"))
		{
			if (2 < argc)
				exp = ft_atof(argv[2]);
			return (mandelbrot(2));
		}
		else if (!ft_strcmp(argv[1], "J"))
		{
			if (4 < argc)
				exp = ft_atof(argv[4]);
			if (3 < argc)
				return (julia(exp, (t_complex){ft_atof(argv[2]),
						ft_atof(argv[3])}));
		}
	}
	ft_putendl_fd("error", 2);
	return (-1);
}

int	mandelbrot(double exp)
{
	t_complex	**buff;

	buff = ft_2darraynew(sizeof(t_complex), WIDTH_SIZE, HEIGHT_SIZE);
	if (!buff)
		return (-1);
	fractol(&(t_fractol){
		.size = (t_size){.width = WIDTH_SIZE, .height = HEIGHT_SIZE},
		.max_iter = MAX_ITER,
		.position = (t_position){.x = 0., .y = 0.},
		.scale = 0.01,
		.title = "mandelbrot",
		.plot_func = plot_mandelbrot,
		.plot_args = &(t_mandelbrot){.exp = exp, .buff = buff},
	});
	ft_2darraydel(buff);
	return (0);
}

int	julia(double exp, t_complex point)
{
	t_complex	**buff;

	buff = ft_2darraynew(sizeof(t_complex), WIDTH_SIZE, HEIGHT_SIZE);
	if (!buff)
		return (-1);
	fractol(&(t_fractol){
		.size = (t_size){.width = WIDTH_SIZE, .height = HEIGHT_SIZE},
		.max_iter = MAX_ITER,
		.position = (t_position){.x = 0., .y = 0.},
		.scale = 0.01,
		.title = "julia",
		.plot_func = plot_julia,
		.plot_args = &(t_julia){.exp = exp, .point = point, .buff = buff},
	});
	ft_2darraydel(buff);
	return (0);
}
