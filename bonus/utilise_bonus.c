/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilise_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 17:36:56 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/15 14:04:08 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_complexe(t_complexe *z, t_complexe c, int set)
{
	double	tmp;

	if (set == TRICORN)
	{
		tmp = (z->re * z->re) - (z->im * z->im) + c.re;
		z->im = (-2 * z->re * z->im) + c.im;
		z->re = tmp;
	}
	else
	{
		tmp = (z->re * z->re) - (z->im * z->im) + c.re;
		z->im = (2 * z->re * z->im) + c.im;
		z->re = tmp;
	}
}

int	ft_kayena(char *str, char c)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	if (str[0] == c || str[len - 1] == c)
		return (5);
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	ft_fill(t_atof *var)
{
	var->i = 0;
	var->n1 = 0;
	var->n2 = 0;
	var->sing = 1;
	var->k = 1;
}

float	ft_atof(char *str)
{
	t_atof	var;

	ft_fill(&var);
	if (str[var.i] == '-' || str[var.i] == '+')
	{
		if (str[var.i] == '-')
			var.sing = -1;
		var.i++;
	}
	while (str[var.i] && str[var.i] >= '0' && str[var.i] <= '9')
	{
		var.n1 = (var.n1 * 10) + (str[var.i] - '0');
		var.i++;
	}
	if (str[var.i] == '.')
	{
		while (str[++var.i] && str[var.i] >= '0' && str[var.i] <= '9')
		{
			var.n2 = (var.n2 * 10) + (str[var.i] - '0');
			var.k++;
		}
	}
	while (--var.k > 0)
		var.n2 = var.n2 / 10;
	return ((var.n1 + var.n2) * var.sing);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel
				/ 8));
	*(int *)dst = color;
}
