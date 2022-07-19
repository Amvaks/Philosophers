/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:19:43 by sbart             #+#    #+#             */
/*   Updated: 2022/07/08 19:13:04 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	show_info("has taken a fork", philo, current_time() - \
			philo->link->time_start, philo->link->mutex_for_printf);
	pthread_mutex_lock(philo->right_fork);
	show_info("has taken a fork", philo, current_time() - \
			philo->link->time_start, philo->link->mutex_for_printf);
	show_info("is eating", philo, current_time() - \
			philo->link->time_start, philo->link->mutex_for_printf);
	pthread_mutex_lock(&philo->link->mutex_for_check_dead);
	if (philo->link->times_must_eat > 0)
	{
		philo->count_eat++;
		if (philo->count_eat == philo->link->times_must_eat)
			philo->complete = 1;
	}
	philo->time_last_eat = current_time();
	pthread_mutex_unlock(&philo->link->mutex_for_check_dead);
	my_sleep(philo->link->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_begin(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	pthread_mutex_lock(&philo->link->mutex_for_check_dead);
	philo->time_last_eat = current_time();
	pthread_mutex_unlock(&philo->link->mutex_for_check_dead);
	if (philo->id % 2)
		usleep(1500);
	while (1)
	{
		philo_eat(philo);
		show_info("is sleeping", philo, current_time() - \
				philo->link->time_start, philo->link->mutex_for_printf);
		my_sleep(philo->link->time_to_sleep);
		show_info("is thinking", philo, current_time() - \
				philo->link->time_start, philo->link->mutex_for_printf);
	}
}
