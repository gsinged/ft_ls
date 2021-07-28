/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inputvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:40:38 by gsinged           #+#    #+#             */
/*   Updated: 2020/01/07 14:59:55 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit_gsinged.h"

int				ft_inputvalid(char *file)
{
	char	*line;
	int		quant;
	t_path	*p;

	if (!(quant = ft_openfile(file, &line)))
		return (0);
	if (!(p = ft_getpath()))
		return (ft_printerror(-1, NULL));
	if (!(p->t = ft_separate(quant, &line, &(p->trmino))))
	{
		ft_delpath(p);
		return (0);
	}
	ft_fcomb_start(p);
	ft_printres(p, 0);
	ft_delpath(p);
	return (0);
}
