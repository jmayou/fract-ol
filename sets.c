/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:23:02 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/08 19:37:38 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void    mandelbrot(t_data *data)
{
    data->i = - WIDTH / 2;
    while (data->i <= WIDTH / 2)
    {
        data->j = - HEIGHT / 2;
        while (data->j <= HEIGHT / 2)
        {
            data->z.re = 0;
            data->z.im = 0; 
            data->c.re = (2 * data->i) / data->zoom;
            data->c.im = (2 * data->j) / data->zoom;  
            data->fin = 0;
            while((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4 && data->fin < MAX_FIN)
            {
                ft_complexe(&data->z,data->c);
                    data->fin++;
            }
            data->color = data->fin * 0Xfff0f0;
            if(data->fin == MAX_FIN)
                data->color = 0;
            my_mlx_pixel_put(&data->image, (WIDTH / 2) + data->i, (HEIGHT / 2) - data->j, data->color);
            data->j++;
        }
        data->i++;        
    }
    mlx_put_image_to_window(data->mlx.ptr,data->mlx.wind,data->image.img,0,0);
}
void    julia(t_data *data)
{
    data->i = - WIDTH / 2;
    while (data->i <= WIDTH / 2)
    {
        data->j = - HEIGHT / 2;
        while (data->j <= HEIGHT / 2)
        {
            data->z.re = data->i / data->zoom;
            data->z.im = data->j / data->zoom;
            data->fin = 1;
            while((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4 && data->fin < MAX_FIN)
            {
                ft_complexe(&data->z,data->c);
                data->fin++;
            }
            data->color = data->fin * 0Xfff0f0;
            if(data->fin == MAX_FIN)
                data->color = 0;
            my_mlx_pixel_put(&data->image, (WIDTH / 2) + data->i, (HEIGHT / 2) - data->j, data->color);
            data->j++;
        }
        data->i++;        
    }
    mlx_put_image_to_window(data->mlx.ptr,data->mlx.wind,data->image.img,0,0);
}
void    ft_set(t_data *data,char *str)
{
    data->mlx.ptr = mlx_init();
    data->mlx.wind = mlx_new_window(data->mlx.ptr, WIDTH, HEIGHT, str);
    data->image.img = mlx_new_image(data->mlx.ptr,1920,1080);
    data->image.addr = mlx_get_data_addr(data->image.img,&data->image.bits_per_pixel,&data->image.line_length,&data->image.endian);
    if(data->set == MANDLEBROT)
    {
        data->zoom = 400.0;
        mandelbrot(data);
    }
    else if(data->set == JULIA)
    {
        data->zoom = 200.0;
        julia(data);
    }
    mlx_mouse_hook(data->mlx.wind, mouse_hook,data);
    mlx_hook(data->mlx.wind, 17, 0, cllose, data);
    mlx_key_hook(data->mlx.wind, key_hook, data);
    mlx_loop(data->mlx.ptr);
}
