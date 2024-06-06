/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:36:56 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/06 20:15:51 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract-ol.h"

void  ft_complexe(t_complexe *z,t_complexe c)
{
    double tmp;
    
    tmp = (z->re * z->re) - (z->im * z->im) + c.re;
    z->im = (2 * z->re * z->im) + c.im;
    z->re = tmp;
}

int ft_kayena(char *str,char c)
{
    int i;
    int count;
    int len;

    i = 0;
    count = 0;
    len = ft_strlen(str);
    if(str[0] == '.' || str[len - 1] == '.')
        return(5);
    while(str[i])
    {
        if(str[i] == '.')
            count++;
        i++;
    }
    return(count);
}
void    ft_check_error(char **str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if((str[i] <= '9' && str[i] >= '0') || (str[i] == '.' && ft_kayena(str,'.') == 1))
            i++;
        else
        {
            ft_error();
            exit(1);
        }
    }
}

float   ft_atof(char *str)
{
    int i;
    int sing;
    int n1;
    float n2;
    int k;
    
    i = 0;
    n1 = 0;
    n2 = 0;
    sing = 1;
    k = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sing = -1;
        i++;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        n1 = (n1 * 10) + (str[i] - '0');
        i++;
    }
    if(str[i] == '.')
    {
        i++;
        while (str[i] && str[i] >= '0' && str[i] <= '9')
        {
            n2 = (n2 * 10) + (str[i] - '0');
            i++;
            k++;
        }
    }
    while(k > 0)
    {
      n2 = n2 / 10;
      k--;
    }
    return ((n1 + n2)* sing);
}
