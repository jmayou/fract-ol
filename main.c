/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:28:13 by jmayou            #+#    #+#             */
/*   Updated: 2024/05/30 13:58:22 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fract-ol.h"

void  ft_copmlexe(t_complexe *z,t_complexe c)
{
    double tmp;
    
    tmp = (z->re * z->re) - (z->im * z->im) + c.re;
    z->im = (2 * z->re * z->im) + c.im;
    z->re = tmp;
}

int main ()
{
    void *ptr;
    int i ;
    int j ;
    t_complexe c;
    t_complexe z;
    void *wind;
    int fin;
    int color;
    double zoom;

    zoom = 400.0;
    ptr = mlx_init();
    wind = mlx_new_window(ptr , WIDTH, HEIGHT, "jailla");
    i = - WIDTH / 2;
    while (i <= WIDTH / 2)
    {
        j = - HEIGHT / 2;
        while (j <= HEIGHT / 2)
        {
            z.re = 0;
            z.im = 0; 
            c.re = (2 * i) / zoom;
            c.im = (2 * j) / zoom;  
            fin = 0;
            while((z.re * z.re) + (z.im * z.im) <= 4 && fin <= MAX_FIN)
            {
                ft_copmlexe(&z,c);
                fin++;
            }
            if(fin == MAX_FIN)
                color = 0;
            else
                color = fin * 0Xffffff;
            mlx_pixel_put(ptr, wind, (WIDTH / 2) + i, (HEIGHT / 2) - j, color);
            j++;
        }
        i++;        
    }
    mlx_loop(ptr);
}