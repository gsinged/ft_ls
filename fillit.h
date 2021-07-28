/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayako <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 18:47:42 by cayako            #+#    #+#             */
/*   Updated: 2020/01/19 18:47:44 by cayako           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

/*
** t_comb	- набор массивов вначале хранения ввода, затем промежуточных
** 			вычислений и в конце ответа. (Первая строка содержит в первом
** 			элементе - количество фигурок, последняя - выполняет роль указателя
** 			на конец массива для адресной арифметики.
** 		trmino	- интдекс фигурки в массиве t_trmino->f
** 		place	- буквенный индекс порядка ввода фигурки (A, B...)
** 		x, y	- координаты фигурки на поле
*/

typedef struct			s_comb	{
	int					trmino;
	char				place;
	char				place2;
	int					x;
	int					y;
}						t_comb;

/*
** t_path	- набор массивов различных шаблонов.
** 			xy		- массив координат пути обхода при поиске свободного места
** 			path	- массив указателей на xy для каждого значения размера
** 					квадрата поиска
** 			minsq	- минимальный квадрат в который могли бы вписаться фигурки
** 					для каждого их количества
** 			inc		- переменная, для отступа/приращения размера квадрата поиска
** 			mask	- массив масок квадратов поиска, индекс - размер квадрата
** 			field	- поле разметки и поска свободных мест
** 					первые 4 элемента		- поле с наложенной маской
** 					5 элемент				- поле чтения
** 					последние 4 элемента	- поле без маски
*/

typedef struct			s_path	{
	int					*xy;
	int					*xy0;
	int					minsq;
	int					inc;
	t_comb				**t;
	unsigned long long	**mask;
	unsigned long long	*field;
	unsigned long long	*trmino;
}						t_path;

/*
** ft_fcomb		- основная функция нахождения положения для каждой тетроминки
**				её вызывает функция ft_fcomb_start(t_path *p)
*/
void					ft_fcomb_start(t_path *p);
/*
** ft_printres	- функция вывода конечного ответа
*/
int						ft_printres(t_path *p, int stop);
/*
** ft_getfield	- создаёт массив с полем поиска, выделяя память
**
** ft_getmask	- создаёт массив масок, выделяя память
**
** ft_getpath	- выделяет память под структуру массивов, хранения и работы
** 				основного алгоритма (ft_fcomb)
**
** ft_getminsq	- создаёт массив размеров минимальных квадратов в зависимости
** 				от количества фигурок (выделяет память)
*/
unsigned long long		*ft_getfield(void);
void					ft_field_to_null(t_path *path);
unsigned long long		**ft_getmask(void);
t_path					*ft_getpath(void);
int						ft_getminsq(int j);
/*
** ft_addmask	- фунция наложения маски
**
** ft_addinc	- функция увеличения квадрата поиска при достижения границ
**
** ft_delpath	- очистка памаяти, занимаемой массивами структуры t_path
*/
void					ft_addmask(t_path *path, int size);
void					ft_addinc(t_path *p);
void					ft_delpath(t_path *path);
int						ft_setline(t_path *p, unsigned long long trmino,
								t_comb	*cur);
unsigned long long		ft_getline(t_path *path, int line);
int						ft_find_place(t_path *p, t_comb *cur);
int						ft_rm_trmino(t_path *p, unsigned long long trmino,
								t_comb *cur);
int						ft_move_trmino(t_path *p, t_comb *cur);
int						*ft_find_xy(int *xy, int x, int y);

#endif
