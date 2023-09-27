/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 04:17:25 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 04:19:03 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_size
{
	int		width;
	int		height;
}			t_size;

typedef struct s_position
{
	double	x;
	double	y;
}			t_position;

#endif
