/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:13:22 by sbart             #+#    #+#             */
/*   Updated: 2022/06/29 18:11:48 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int a)
{
	if (a > 47 && a < 58)
		return (1);
	return (0);
}

int	ft_isspace(int ch)
{
	if (ch == ' ' || ch == '\f' || ch == '\t')
		return (1);
	else if (ch == '\r' || ch == '\n' || ch == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *string)
{
	long	i;
	long	res;
	int		neg;

	neg = 1;
	res = 0;
	i = 0;
	while (ft_isspace(*string))
		string++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			neg = -1;
		i++;
	}
	while (string[i] != '\0' && ft_isdigit(string[i]))
		res = (res * 10) + (string[i++] - '0');
	return (res * neg);
}
