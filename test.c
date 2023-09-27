#include "fractol.h"
#include "formula.h"
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	fractol(&(t_fractol){
		.title = "test",
		.size = (t_size){.width = 800, .height = 600},
		.max_iter = 70,
		.position = (t_position){.x = -0.0, .y = .0},
		.scale = 0.01,
		.plot_func = mandelbrot,
		.plot_args = NULL,
	});
}
