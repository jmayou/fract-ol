/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:23:02 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/06 18:01:32 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void    mandelbrot(t_data *data)
{
    data->z.re = 0;
    data->z.im = 0; 
    data->c.re = (2 * data->i) / data->zoom;
    data->c.im = (2 * data->j) / data->zoom;  
    data->fin = 0;
    while((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4 && data->fin <= MAX_FIN)
    {
        ft_complexe(&data->z,data->c);
            data->fin++;
    }
    if(data->fin == MAX_FIN)
        data->color = 0;
    else
        data->color = data->fin * 0Xffffff;
}