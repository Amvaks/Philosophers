/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:17:25 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 17:45:32 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_error(char *str)
{
	printf("%s\n", str);
	return (-1);
}

void	free_philos(t_philo *philo, pthread_mutex_t *mutex_for_philo)
{
	if (philo)
		free(philo);
	if (mutex_for_philo)
		free(mutex_for_philo);
}

int	program_fail(t_data *data)
{
	free(data);
	return (-1);
}

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->numb_philo)
	{
		pthread_mutex_destroy(&data->mutex_for_philo[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_for_printf);
	pthread_mutex_destroy(&data->mutex_for_show_info);
	pthread_mutex_destroy(&data->mutex_for_check_dead);
}
