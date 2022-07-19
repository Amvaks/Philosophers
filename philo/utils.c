/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:45:49 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 18:08:57 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	show_info(char *string, t_philo *philo, long long time, \
		pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	if (string[0] == '0')
	{
		usleep(500);
		printf("%lld %i died\n", time, philo->id);
		return ;
	}
	else if (string[3] == 'e')
	{
		usleep(500);
		printf("%lld %i %s\n", time, philo->id, string);
	}
	else
		printf("%lld %i %s\n", time, philo->id, string);
	pthread_mutex_unlock(&mutex);
}

void	my_sleep(int time)
{
	long long	end;

	end = current_time() + time;
	while (current_time() < end)
		usleep(time);
}
