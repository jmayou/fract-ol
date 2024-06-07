/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:33:19 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/07 17:10:16 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void    julia(t_data *data)
{
    data->z.re = data->i / data->zoom;
    data->z.im = data->j / data->zoom;
    data->fin = 1;
    while((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4 && data->fin < MAX_FIN)
    {
        ft_complexe(&data->z,data->c);
            data->fin++;
    }
    if(data->fin == MAX_FIN)
        data->color = 0;
    else
        data->color = data->fin * 0X0000ff;
}

void    julia_set(t_data *data)
{
    data->zoom = 200.0;
    data->mlx.ptr = mlx_init();
    data->mlx.wind = mlx_new_window(data->mlx.ptr, WIDTH, HEIGHT, "Julia");
    data->i = - WIDTH / 2;
    while (data->i <= WIDTH / 2)
    {
        data->j = - HEIGHT / 2;
        while (data->j <= HEIGHT / 2)
        {
            julia(data);
            mlx_pixel_put(data->mlx.ptr, data->mlx.wind, (WIDTH / 2) + data->i, (HEIGHT / 2) - data->j, data->color);
            data->j++;
        }
        data->i++;        
    }
    mlx_loop(data->mlx.ptr);
}
