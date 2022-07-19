/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbart <sbart@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:07:05 by sbart             #+#    #+#             */
/*   Updated: 2022/07/09 18:18:55 by sbart            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	set_input_args(t_data *data, int argc, char **argv)
{
	data->numb_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->times_must_eat = ft_atoi(argv[5]);
	else
		data->times_must_eat = -1;
	if (data->numb_philo < 1 || data->time_to_die < 1 \
			|| data->time_to_eat < 1 || data->time_to_sleep < 1 \
			|| (argc == 6 && data->times_must_eat < 1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	if (argc != 5 && argc != 6)
		return (ft_print_error("Incorrect number of arguments."));
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_print_error("Memory allocation error."));
	if (set_input_args(data, argc, argv))
	{
		free(data);
		return (ft_print_error("Incorrect arguments."));
	}
	data->p_id = malloc(sizeof(pid_t) * data->numb_philo);
	if (init_structures(data) < 0)
		return (free_data(data));
	while (i < data->numb_philo)
		kill(data->p_id[i++], 9);
	i = 0;
	while (i++ < data->numb_philo)
		waitpid(data->p_id[i], NULL, 0);
	free_data(data);
	return (0);
}
