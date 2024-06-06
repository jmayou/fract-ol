/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 19:33:19 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/06 18:01:09 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void    julia(t_data *data,double c_reel,double c_image)
{
    data->c.re = c_reel;
    data->c.im = c_image;
    data->z.re = data->i / data->zoom;
    data->z.im = data->j / data->zoom;
    data->fin = 1;
    while((data->z.re * data->z.re) + (data->z.im * data->z.im) <= 4 && data->fin <= MAX_FIN)
    {
        ft_copmlexe(&data->z,data->c);
            data->fin++;
    }
    if(data->fin == MAX_FIN)
        data->color = 0Xff00ff;
    else
        data->color = data->fin * 0Xffffff;
}