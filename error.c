/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 23:28:14 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 23:55:47 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

void	malloc_error(void)
{
	ft_printf("malloc error.\n");
	exit(1);
}

void	bad_argment_error(void)
{
	ft_printf("bad argement error.\n");
	exit(1);
}
