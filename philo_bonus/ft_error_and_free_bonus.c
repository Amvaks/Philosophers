/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:17:25 by sbart             #+#    #+#             */
/*   Updated: 2022/07/08 19:20:38 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_print_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

// void	free_data(t_data *data)
// {
// 	free(data->p_id);
// 	free(data);
// }

int	free_data(t_data *data)
{
	free(data->p_id);
	free(data);
	return (-1);
}
