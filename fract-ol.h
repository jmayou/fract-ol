/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:26:01 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/07 17:03:44 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H
#include <unistd.h>
#include <mlx.h>
#include "Libft/libft.h"
#define WIDTH 800
#define HEIGHT 800
#define MAX_FIN 100


typedef struct s_complexe
{
    double re;
    double im;
} t_complexe;

typedef struct s_mlx
{
    void *ptr;
    void *wind;
} t_mlx;

typedef struct s_data
{
    int i;
    int j;
    int fin;
    int color;
    double zoom;
    t_complexe z;
    t_complexe c;
    t_mlx   mlx;
} t_data;

typedef struct s_atof
{
    int i;
    int sing;
    int n1;
    float n2;
    int k;
} t_atof;

void  ft_complexe(t_complexe *z,t_complexe c);
void    mandelbrot(t_data *data);
void    mandelbrot_set(t_data *data);
void    julia(t_data *data);
void    julia_set(t_data *data);
void    error();
int    check_error(char *str);
int ft_kayena(char *str,char c);
float   ft_atof(char *str);
#endif