/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:37:07 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/15 14:46:20 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	mouse_hook(int keycode, int x, int y, t_data *data)
{
	double	x_zoom;
	double	y_zoom;
	double	factor_zoom;

	factor_zoom = 1.3;
	if (keycode == 4 && data->zoom > 0)
		data->zoom = data->zoom / factor_zoom;
	else if (keycode == 5)
	{
		x_zoom = (x - (WIDTH / 2)) / data->zoom;
		y_zoom = ((HEIGHT / 2) - y) / data->zoom;
		data->zoom *= factor_zoom;
		data->horizontal += x_zoom * (factor_zoom - 1);
		data->verticat += y_zoom * (factor_zoom - 1);
	}
	if (data->set == MANDLEBROT)
		mandelbrot(data);
	else if (data->set == JULIA)
		julia(data);
	else if (data->set == TRICORN)
		my_tricorn(data);
	return (0);
}

int	key_hook(int key, t_data *data)
{
	(void)data;
	if (key == 53)
	{
		mlx_destroy_image(data->mlx.ptr, data->image.img);
		mlx_destroy_window(data->mlx.ptr, data->mlx.wind);
		exit(0);
	}
	else if (key == 38)
		data->fix_color = data->fix_color - 3;
	else if (key == 123)
		data->horizontal -= 0.1;
	else if (key == 124)
		data->horizontal += 0.1;
	else if (key == 125)
		data->verticat -= 0.1;
	else if (key == 126)
		data->verticat += 0.1;
	if (data->set == MANDLEBROT)
		mandelbrot(data);
	else if (data->set == JULIA)
		julia(data);
	else if (data->set == TRICORN)
		my_tricorn(data);
	return (0);
}

int	cllose(t_data *data)
{
	mlx_destroy_image(data->mlx.ptr, data->image.img);
	mlx_destroy_window(data->mlx.ptr, data->mlx.wind);
	exit(0);
	return (0);
}
