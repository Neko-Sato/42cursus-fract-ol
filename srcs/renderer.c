/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 00:20:01 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 04:45:11 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

t_renderer	*new_renderer(char *title, t_size size)
{
	t_renderer	*ret;

	ret = (t_renderer *)malloc(sizeof(t_renderer));
	if (ret)
	{
		ret->mlx = mlx_init();
		if (ret->mlx)
		{
			ret->win = mlx_new_window(ret->mlx, size.width, size.height, title);
			if (ret->win)
			{
				ret->img = mlx_new_image(ret->mlx, size.width, size.height);
				if (ret->img)
					return (ret);
			}
			mlx_destroy_window(ret->mlx, ret->win);
		}
		free(ret->mlx);
	}
	free(ret);
	return (NULL);
}

void	del_renderer(t_renderer *renderer)
{
	mlx_destroy_image(renderer->mlx, renderer->img);
	mlx_destroy_window(renderer->mlx, renderer->win);
	free(renderer->mlx);
	free(renderer);
}
