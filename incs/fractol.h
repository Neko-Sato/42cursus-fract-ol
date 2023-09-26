/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:51:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/26 22:24:28 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_fractol
{
	char	*title;
	int		width;
	int		height;
}			t_fractol;

typedef struct s_fractol_local
{
	void	*mlx;
	void	*win;
	void	*img;
	int		width;
	int		height;
	int		zoom;
}			t_fractol_local;

void	fractol(t_fractol *var);

#endif