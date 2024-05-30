/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:28:13 by jmayou            #+#    #+#             */
/*   Updated: 2024/05/30 13:00:50 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fract-ol.h"
#include <stdio.h>

void  ft_copmlexe(t_complexe *z,t_complexe c)
{
    z->re = (z->re * z->re) - (z->im * z->im) + c.re;
    z->im = (2 * z->re * z->im) + c.im;
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
            c.re = (2 * i) / 100;
            c.im = (2 * j) / 100;  
            fin = 0;
            while((z.re * z.re) + (z.im * z.im) <= 4 && fin < MAX_FIN)
            {
                z.re = (z.re * z.re) - (z.im * z.im) + c.re;
                z.im = (2 * z.re * z.im) + c.im;
                // ft_copmlexe(&z,c);
                //printf ("%d\n", fin);
                fin++;
            }
            if(fin == MAX_FIN)
                color = 0;
            else
                color = fin * 0Xffffff;
            mlx_pixel_put(ptr, wind, (WIDTH / 2) + i, (HEIGHT / 2) - j, color);
            //rintf ("%d_______%d\n", i,j);
            j++;
        }
        i++;        
    }
    mlx_loop(ptr);
}