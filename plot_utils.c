/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:22:13 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/24 18:51:46 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plot.h"

double	i2x(int i, t_plot_var *plot_var)
{
	return (plot_var->x + (i - plot_var->width / 2) * plot_var->scale);
}

double	j2y(int j, t_plot_var *plot_var)
{
	return (plot_var->y + (plot_var->height / 2 - j) * plot_var->scale);
}

int	x2i(double x, t_plot_var *plot_var)
{
	return ((x - plot_var->x) / plot_var->scale + plot_var->width / 2);
}

int	y2j(double y, t_plot_var *plot_var)
{
	return ((plot_var->y - y) / plot_var->scale + plot_var->height / 2);
}
