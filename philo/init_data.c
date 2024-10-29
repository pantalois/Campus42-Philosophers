/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:38:29 by loigonza          #+#    #+#             */
/*   Updated: 2024/10/29 17:08:19 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL))
		return (-1);
	if (pthread_mutex_init(&data->eat_count_lock, NULL))
		return (-1);
	if (pthread_mutex_init(&data->died, NULL))
		return (-1);
	if (pthread_mutex_init(&data->stop, NULL))
		return (-1);
	if (pthread_mutex_init(&data->meal_time_lock, NULL))
		return (-1);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (validate_args(argc, argv) == -1)
		return (-1);
	data->num_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->must_eat_count = ft_atoi(argv[5]);
	else
		data->must_eat_count = -1;
	data->all_alive = 1;
	data->total_eaten = 0;
	data->start_time = current_time();
	if (init_forks(data) == -1 || init_philosophers(data) == -1)
		return (-1);
	if (init_data_mutex(data))
		return (-1);
	return (0);
}

int	init_philosophers(t_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philosopher) * data->num_philosophers);
	if (!data->philosophers)
		return (-1);
	i = 0;
	while (i < data->num_philosophers)
	{
		data->philosophers[i].id = i + 1;
		data->philosophers[i].times_eaten = 0;
		data->philosophers[i].left_fork = &data->forks[i];
		data->philosophers[i].right_fork = &data->forks[(i + 1)
			% data->num_philosophers];
		data->philosophers[i].last_meal_time = data->start_time;
		data->philosophers[i].data = data;
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
	if (!data->forks)
		return (-1);
	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	create_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		if (pthread_create(&data->philosophers[i].thread, NULL,
				philosopher_routine, &data->philosophers[i]))
			return (-1);
		i++;
	}
	pthread_create(&data->monitoring, NULL, monitor_philosophers, data);
	return (0);
}
