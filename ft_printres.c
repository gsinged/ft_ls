/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:48:00 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:48:02 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static char		*ft_crfield(int size)
{
	char	*field;
	int		i;

	if (!(field = (char *)malloc(sizeof(char) * (size * (size + 2) + 1))))
		return (NULL);
	i = 0;
	while (i < (size * (size + 2) + 1))
		field[i++] = '\0';
	i = 0;
	while (i < size * (size + 1))
	{
		if (!i || (i + 1) % (size + 1))
			field[i] = '.';
		else
			field[i] = '\n';
		++i;
	}
	return (field);
}

static void		ft_write_dna(unsigned long long dna, char *pos, t_comb **ans,
								int i)
{
	unsigned long long	rna;
	int					bit;

	bit = 0;
	rna = 1ULL << 63ULL;
	pos = pos + (*(ans + i))->y * ((*ans)->y + 1) + (*(ans + i))->x;
	while (pos && *pos && dna)
	{
		while (++bit < 5 && dna)
		{
			if (dna & rna)
				*pos = (*(ans + i))->place;
			dna = dna << 1ULL;
			++pos;
		}
		pos += (*ans)->y - 3;
		dna = dna << 12ULL;
		bit = 0;
	}
}

static void		ft_writemino(char **field, t_comb **ans,
								unsigned long long *trmino, int stop)
{
	unsigned long long	dna;
	int					i;

	i = 1;
	while (i <= (*ans)->trmino && (!stop || i <= stop))
	{
		dna = trmino[(*(ans + i))->trmino];
		ft_write_dna(dna, *field, ans, i);
		++i;
	}
}

int				ft_printres(t_path *p, int stop)
{
	char	*field;

	field = ft_crfield((*p->t)->y);
	ft_writemino(&field, p->t, p->trmino, stop);
	write(1, field, (*p->t)->y * ((*p->t)->y + 1));
	free(field);
	return (0);
}
