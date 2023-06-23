#include "color.h"
#include "fractol.h"
#include "ft_complex.h"
#include "libmlx/mlx.h"
#include "plot.h"
#include "utils.h"
#include <stdlib.h>

static int	fun(double x, double y, void *args)
{
	args = NULL;
	return (hsvt2hex(x, y, 1, 0));
}

int	main(void)
{
	void *mlx = mlx_init();
	t_plot_args plot_args;
	plot_args.args = NULL;
	plot_args.width = 1000;
	plot_args.height = 1000;
	plot_args.plot_func = fun;
	plot_args.scale = 1./1000.;
	plot_args.x = 0.5;
	plot_args.y = 0.5;
	plot(mlx, "test", &plot_args);
	mlx_loop(mlx);
}
