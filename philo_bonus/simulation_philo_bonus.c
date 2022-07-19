/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_philo_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:19:43 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 17:18:24 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_eat(t_philo	*philo)
{
	sem_wait(philo->link->sem_for_forks);
	show_info("has taken a fork", philo, current_time() - \
			philo->link->time_start, philo->link->sem_for_print);
	sem_wait(philo->link->sem_for_forks);
	show_info("has taken a fork", philo, current_time() - \
			philo->link->time_start, philo->link->sem_for_print);
	show_info("is eating", philo, current_time() - \
			philo->link->time_start, philo->link->sem_for_print);
	sem_wait(philo->link->sem_for_time);
	philo->time_last_eat = current_time();
	sem_post(philo->link->sem_for_time);
	my_sleep(philo->link->time_to_eat);
	sem_post(philo->link->sem_for_forks);
	sem_post(philo->link->sem_for_forks);
	if (philo->link->times_must_eat != -1 && philo->link->times_must_eat != 0)
		philo->link->times_must_eat--;
}

void	*philo_begin(void *philo_data)
{
	t_philo	*philo;

	philo = (t_philo *)philo_data;
	philo->time_last_eat = current_time();
	while (philo->link->times_must_eat)
	{
		philo_eat(philo);
		if (philo->link->times_must_eat == 0)
			exit (0);
		show_info("is sleeping", philo, current_time() - \
				philo->link->time_start, philo->link->sem_for_print);
		my_sleep(philo->link->time_to_sleep);
		show_info("is thinking", philo, current_time() - \
				philo->link->time_start, philo->link->sem_for_print);
	}
	exit (0);
}
