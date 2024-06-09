/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmayou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:27:41 by jmayou            #+#    #+#             */
/*   Updated: 2024/01/08 16:20:15 by jmayou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sing;

	i = 0;
	nb = 0;
	sing = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sing = -1;
		nb = -nb;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * sing);
}
//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	const char *str = "-+123";
//	int num = atoi(str);
//	int num2 = ft_atoi(str);
//
//	printf("%d ;;; %d\n", num, num2);
//	return (0);
//}
