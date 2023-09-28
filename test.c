#include "fractol.h"
#include "formula.h"
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_complex **buff;
	
	buff = malloc(sizeof(t_complex) * 800);
	for (int i = 0; i < 800; i++)
		buff[i] = malloc(sizeof(t_complex) * 600);
	fractol(&(t_fractol){
		.title = "test",
		.size = (t_size){.width = 800, .height = 600},
		.max_iter = 1000,
		.position = (t_position){.x = -0.0, .y = .0},
		.scale = 0.01,
		.plot_func = mandelbrot,
		.plot_args = &(t_mandelbrot){.exp = 2, .buff = buff},
	});
}
