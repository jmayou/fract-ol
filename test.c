/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:09:04 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/07 17:07:08 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

int main (int ac, char **av)
{
    t_data  data;
    
    data.zoom = 100.0;
    data.mlx.ptr = mlx_init();
    data.mlx.wind = mlx_new_window(data.mlx.ptr, WIDTH, HEIGHT, "jailla");
    data.i = - WIDTH / 2;
    while (data.i <= WIDTH / 2)
    {
        data.j = - HEIGHT / 2;
        while (data.j <= HEIGHT / 2)
        {
            data.c.re = 0.1 * 10;
            data.c.im = 0.1 * 10;
            data.z.re = data.i / data.zoom;
            data.z.im = data.j / data.zoom;
            data.fin = 0;
            while( data.fin < MAX_FIN)
            {
                ft_complexe(&data.z,data.c);
                    data.fin++;
                if((data.z.re * data.z.re) + (data.z.im * data.z.im) >= 4)
                    break;
            }
            if(data.fin == MAX_FIN)
                data.color = 0;
            else
                data.color = data.fin * 0Xffffff;
            mlx_pixel_put(data.mlx.ptr, data.mlx.wind, (WIDTH / 2) + data.i, (HEIGHT / 2) - data.j, data.color);
            data.j++;
        }
        data.i++;        
    }
    mlx_loop(data.mlx.ptr);
}