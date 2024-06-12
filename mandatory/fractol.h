/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:26:01 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/12 17:56:14 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../Libft/libft.h"
# include <mlx.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_FIN 100
# define MANDLEBROT 0
# define JULIA 1

typedef struct s_complexe
{
	double		re;
	double		im;
}				t_complexe;

typedef struct s_mlx
{
	void		*ptr;
	void		*wind;
}				t_mlx;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_data
{
	int			i;
	int			j;
	int			fin;
	int			color;
	double		zoom;
	int			set;
	t_complexe	z;
	t_complexe	c;
	t_mlx		mlx;
	t_image		image;
}				t_data;

typedef struct s_atof
{
	int			i;
	int			sing;
	int			n1;
	float		n2;
	int			k;
}				t_atof;

void			ft_complexe(t_complexe *z, t_complexe c);
void			mandelbrot(t_data *data);
void			julia(t_data *data);
void			ft_set(t_data *data, char *str);
void			error(void);
int				check_error(char *str);
int				ft_kayena(char *str, char c);
float			ft_atof(char *str);
void			my_mlx_pixel_put(t_image *image, int x, int y, int color);
int				mouse_hook(int keycode, int x, int y, t_data *data);
int				key_hook(int key, t_data *data);
int				cllose(t_data *data);

#endif
