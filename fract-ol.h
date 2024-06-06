/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:26:01 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/06 18:15:55 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
#define FRACT_OL_H
#include <unistd.h>
#include <mlx.h>
#define WIDTH 800
#define HEIGHT 800
#define MAX_FIN 500


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
    int set;
    int fin;
    int color;
    double zoom;
    t_complexe z;
    t_complexe c;
    t_mlx   mlx;
} t_data;

void  ft_complexe(t_complexe *z,t_complexe c);
void    mandelbrot(t_data *data);
void    julia(t_data *data,double c_reel,double c_image);

#endif