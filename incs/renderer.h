/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:51:02 by hshimizu          #+#    #+#             */
/*   Updated: 2023/09/28 18:48:08 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "types.h"

typedef struct s_renderer
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_renderer;

typedef struct s_data_addr
{
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_data_addr;

t_renderer				*new_renderer(char *title, t_size size);
void					del_renderer(t_renderer *renderer);

int						get_data_addr(void *img, t_data_addr *data_addr);

#endif