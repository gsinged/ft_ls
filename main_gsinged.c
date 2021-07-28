/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gsinged.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:59:58 by gsinged           #+#    #+#             */
/*   Updated: 2019/12/12 16:29:54 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_gsinged.h"

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "usage: ./fillit [input_file]\n", 29);
		return (0);
	}
	ft_inputvalid(argv[1]);
	return (0);
}
