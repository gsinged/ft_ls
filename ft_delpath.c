/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:45:27 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:45:37 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "fillit_gsinged.h"

static void		ft_delmask(unsigned long long **mask)
{
	int		i;

	i = 0;
	while (i < 16)
		free(mask[i++]);
	free(mask);
}

void			ft_delpath(t_path *path)
{
	free(path->xy0);
	ft_delmask(path->mask);
	ft_delt_comb(&path->t);
	free(path->field);
	free(path->trmino);
	free(path);
}
