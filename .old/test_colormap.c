#include "color.h"
#include "plot.h"
#include <mlx.h>
#include <math.h>

void	test_hsv_color(t_data_addr *data_addr, t_plot_var *var)
{
	int				i;
	int				j;
	unsigned int	*addr;

	i = 0;
	while (i < var->width)
	{
		j = 0;
		while (j < var->height)
		{
			addr = (unsigned int *)(data_addr->addr + (j * data_addr->size_line
						+ i * (data_addr->bits_per_pixel / 8)));
				*addr = colormap(i2x(i, var));
			j++;
		}
		i++;
	}
}

void	test_colormap(t_data_addr *data_addr, t_plot_var *var)
{
	int				i;
	int				j;
	unsigned int	*addr;

	i = 0;
	while (i < var->width)
	{
		j = 0;
		while (j < var->height)
		{
			addr = (unsigned int *)(data_addr->addr + (j * data_addr->size_line
						+ i * (data_addr->bits_per_pixel / 8)));
				*addr = colormap(i2x(i, var));
			j++;
		}
		i++;
	}
}

int	main(void)
{
	t_plot_var	var;
	void		*mlx;

	mlx = mlx_init();
	var.width = 500;
	var.height = 500;
	var.scale = 1./500;
	var.x = 0.5;
	var.y = 0.5;
	plot(mlx, "test_colormap", &var, test_colormap);
	mlx_loop(mlx);
}
