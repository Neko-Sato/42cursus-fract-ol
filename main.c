/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:25:11 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 06:27:56 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	if(!(1 < argc))
	{
		ft_printf("bad argument.\n");
		exit(1);
	}
	argv = argv;
	// pars_args(argc, argv);
	return (0);
}