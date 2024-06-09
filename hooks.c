/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:37:07 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/09 15:38:21 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 4 && data->zoom > 0)
		data->zoom = data->zoom - 10;
	else if (keycode == 5)
		data->zoom = data->zoom + 10;
	if (data->set == MANDLEBROT)
		mandelbrot(data);
	else if (data->set == JULIA)
		julia(data);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	(void)data;
	if (key == 53)
		exit(0);
	return (0);
}

int	cllose(void)
{
	exit(0);
	return (0);
}
