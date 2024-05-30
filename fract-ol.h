/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 13:26:01 by jmayou            #+#    #+#             */
/*   Updated: 2024/05/30 12:37:07 by jmayou           ###   ########.fr       */
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

#endif