/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:45:49 by sbart             #+#    #+#             */
/*   Updated: 2022/07/08 20:00:36 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1000 + now.tv_usec / 1000);
}

void	show_info(char *string, t_philo *philo, long long time, sem_t *sem)
{
	sem_wait(sem);
	if (string[0] == '0')
	{
		printf("%lld %i died\n", time, philo->id);
		return ;
	}
	else
		printf("%lld %i %s\n", time, philo->id, string);
	sem_post(sem);
}

void	my_sleep(int time)
{
	long long	end;

	end = current_time() + time;
	while (current_time() < end)
		usleep(time);
}

void	create_semaphore(t_data *data)
{
	sem_unlink("forks");
	data->sem_for_forks = sem_open("forks", O_CREAT | O_EXCL, 0777, \
			data->numb_philo);
	if (data->sem_for_forks == SEM_FAILED || !data->sem_for_forks)
		exit(1);
	sem_unlink("print");
	data->sem_for_print = sem_open("print", O_CREAT | O_EXCL, 0777, 1);
	if (data->sem_for_print == SEM_FAILED || !data->sem_for_print)
		exit(1);
	sem_unlink("time");
	data->sem_for_time = sem_open("time", O_CREAT | O_EXCL, 0777, 1);
	if (data->sem_for_time == SEM_FAILED || !data->sem_for_time)
		exit(1);
}

void	destroy_semaphore(t_data *data)
{
	if (sem_close(data->sem_for_forks) == -1)
		exit(1);
	if (sem_unlink("forks") == -1)
		exit(1);
	if (sem_close(data->sem_for_print) == -1)
		exit(1);
	if (sem_unlink("print") == -1)
		exit(1);
	if (sem_close(data->sem_for_time) == -1)
		exit(1);
	if (sem_unlink("time") == -1)
		exit(1);
}
