/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_gsinged.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:37:22 by gsinged           #+#    #+#             */
/*   Updated: 2020/01/14 13:06:37 by gsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_GSINGED_H
# define FILLIT_GSINGED_H
# include "libft/libft.h"
# include "fillit.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 550

int			ft_printerror(int fd, char **buf);
t_comb		**ft_printerror_tcomb(t_comb ***tcomb, int quant, char **line);
int			ft_inputvalid(char *file);
int			ft_openfile(char *file, char **line);
t_comb		**ft_separate(int quant, char **line, unsigned long long **trmino);
void		ft_delt_comb(t_comb ***t);

#endif
