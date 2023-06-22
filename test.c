#include "fractol.h"
#include "ft_complex.h"
#include "utils.h"
#include <stdlib.h>

# define FT_COMPLEX(x, y) (t_complex){x, y}

int main(void)
{
	mandelbrot();
	return (0);
}