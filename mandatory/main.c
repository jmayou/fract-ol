/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <jmayou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:28:13 by jmayou            #+#    #+#             */
/*   Updated: 2024/06/26 13:00:18 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error(void)
{
	write(1, "the information is incorrect\n", 30);
	exit(1);
}

int	check_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		error();
	while (str[i])
	{
		if ((str[i] <= '9' && str[i] >= '0') || (str[i] == '.' && ft_kayena(str,
					'.') == 1))
			i++;
		else
			error();
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && ft_strcmp(av[1], "Mandelbrot") == 0)
	{
		data.set = MANDLEBROT;
		ft_set(&data, av[1]);
	}
	else if (ac == 4 && ft_strcmp(av[1], "Julia") == 0
		&& check_error(av[2]) == 0 && check_error(av[3]) == 0)
	{
		data.c.re = ft_atof(av[2]);
		data.c.im = ft_atof(av[3]);
		if ((data.c.re <= 2 && data.c.re >= -2) && (data.c.im <= 2
				&& data.c.im >= -2))
		{
			data.set = JULIA;
			ft_set(&data, av[1]);
		}
		else
			error();
	}
	else
		error();
}
