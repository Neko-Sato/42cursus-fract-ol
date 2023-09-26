#include "fractol.h"
#include <libft.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	fractol(&(t_fractol){.title = "test", .height = 300, .width = 400});
}
