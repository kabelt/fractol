/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaneera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:43:14 by kmaneera          #+#    #+#             */
/*   Updated: 2020/02/27 20:44:08 by kmaneera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define THREADS        8
# define WIDTH			1200
# define HEIGHT			1200
# define MANDELBROT     1
# define JULIA          2
# define BURNINGSHIP    3
# define MANDELBAR      4
# define MP_R           15
# define MP_T           17
# define MP_J           38
# define MP_ESC		    53
# define NP_PLUS		69
# define NP_MINUS		78
# define ARW_UP			126
# define ARW_DOWN		125
# define ARW_LEFT		123
# define ARW_RIGHT		124

typedef	struct	s_color
{
	int8_t		channel[4];
}				t_color;

typedef struct	s_cn
{
	double		rp;
	double		ip;
}				t_cn;

typedef struct	s_sto
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	int			img_bpp;
	int			img_sl;
	int			img_edn;
	int			typeindex;
	double		zoom;
	double		j_re;
	double		j_img;
	int			colorthemeindex;
	int			firstline;
	int			lastline;
	int			max_iteration;
	t_cn		cur;
	t_cn		factor;
	int			juliamodeindex;
	double		max_real;
	double		min_real;
	double		max_imag;
	double		min_imag;
}				t_sto;

t_cn			cre_comnum(double real, double imaginary);
void			makeart(t_sto *inf);
t_cn			make_cn(double real, double imaginary);
int				fractols(t_sto *inf);
int				mandelbrot(t_sto *inf);
int				burningship(t_sto *inf);
int				julia(t_sto *inf);
t_color			get_color(int iteration, t_sto *inf);
void			putmenu(t_sto *inf);
void			putmenu2(t_sto *inf);
void			errexit(char *str);
void			resetscreen(t_sto *inf);
void			iteration_adj(t_sto *inf, int key);
void			move(t_sto *inf, int key);
void			changecolortheme(t_sto *inf);
void			control(t_sto *inf);
int				mouse(int button, int x, int y, t_sto *inf);

#endif
