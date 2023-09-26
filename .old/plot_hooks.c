/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:31:29 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/26 02:06:36 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	mouse_hook(int button, int x, int y, void *param)
{
	ft_printf("button: %d, x: %d, y: %d\n", button, x, y);
	if (!param)
		return (1);
	return (0);
}

static int	key_hook(int keycode, void *param)
{
	if(keycode == )
	{
mlx_
	}
}