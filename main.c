/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:28:13 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/06 18:19:19 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int main (int ac, char **av)
{
    t_data  data;
    
    if(ac == 2 && ft_strcmp(av[1],"Mandelbrot") == 0)
        data.set = 1;
    else if(ac == 4 && ft_strcmp(av[1],"Julia") == 0,)
    data.zoom = 400.0;
    data.mlx.ptr = mlx_init();
    data.mlx.wind = mlx_new_window(data.mlx.ptr, WIDTH, HEIGHT, "jailla");
    data.i = - WIDTH / 2;
    while (data.i <= WIDTH / 2)
    {
        data.j = - HEIGHT / 2;
        while (data.j <= HEIGHT / 2)
        {
            mandelbrot(&data);
            // data.z.re = 0;
            // data.z.im = 0; 
            // data.c.re = (2 * data.i) / data.zoom;
            // data.c.im = (2 * data.j) / data.zoom;  
            // data.fin = 0;
            // while((data.z.re * data.z.re) + (data.z.im * data.z.im) <= 4 && data.fin <= MAX_FIN)
            // {
            //     ft_complexe(&data.z,data.c);
            //     data.fin++;
            // }
            // if(data.fin == MAX_FIN)
            //     data.color = 0;
            // else
            //     data.color = data.fin * 0Xffffff;
            mlx_pixel_put(data.mlx.ptr, data.mlx.wind, (WIDTH / 2) + data.i, (HEIGHT / 2) - data.j, data.color);
            data.j++;
        }
        data.i++;        
    }
    mlx_loop(data.mlx.ptr);
}