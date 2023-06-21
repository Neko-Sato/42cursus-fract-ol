/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hshimizu <hshimizu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:25:11 by hshimizu          #+#    #+#             */
/*   Updated: 2023/06/22 03:41:13 by hshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_fractol_type
{
} s_fractol_type;

typedef struct s_fractol_args
{
	s_fractol_type	type;

}	s_fractol_args;

int	main(int argc, char *argv[])
{
	if(argc < 1)
		exit(1);	
	pars_args(argc, argv);
	return (0);
}