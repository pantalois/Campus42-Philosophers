/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:38:53 by loigonza          #+#    #+#             */
/*   Updated: 2024/10/29 16:33:37 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_food_or_not(t_data *data, int i)
{
	if (data->total_eaten == data->num_philosophers)
		is_death(data, 2);
	else
	{
		is_death(data, 1);
		pthread_mutex_lock(&data->print_lock);
		printf("%lld %d died\n", current_time() - data->start_time,
			data->philosophers[i].id);
		pthread_mutex_unlock(&data->print_lock);
	}
}

void	check_eaten_times(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers && is_death(data, 0))
	{
		if (data->philosophers[i].times_eaten == data->must_eat_count)
			data->total_eaten++;
		i++;
	}
}

void	*monitor_philosophers(void *data_void)
{
	t_data		*data;
	int			i;

	data = (t_data *)data_void;
	while (is_death(data, 0))
	{
		pthread_mutex_lock(&data->stop);
		i = 0;
		while (i < data->num_philosophers && is_death(data, 0))
		{
			pthread_mutex_lock(&data->meal_time_lock);
			if ((current_time() - data->philosophers[i].last_meal_time)
				>= data->time_to_die)
			{
				check_eaten_times(data);
				check_food_or_not(data, i);
			}
			pthread_mutex_unlock(&data->meal_time_lock);
			i++;
		}
		pthread_mutex_unlock(&data->stop);
		usleep(50);
	}
	return (NULL);
}

int	is_death(t_data *data, int flag)
{
	pthread_mutex_lock(&data->died);
	if (flag)
		data->all_alive = 0;
	if (data->all_alive)
	{
		pthread_mutex_unlock(&data->died);
		return (1);
	}
	pthread_mutex_unlock(&data->died);
	return (0);
}

void	print_error(void)
{
	printf("--------------------------------------\n\n");
	printf("All the arguments must be at least 1\n");
	printf("'+' is not accepted\n");
	printf("Example of argumets accepted by the program:\n\n");
	printf("./philo [Nbr of philos] [Time to die] [Time to eat] [Time to sleep]"
		" [Times_philos_must_eat](Optional)\n\n");
	printf("./philo 1 800 200 200\n");
	printf("./philo 5 800 200 200\n");
	printf("./philo 4 410 200 200\n");
	printf("./philo 4 310 200 100\n\n");
	printf("In case of argument [Times_philos_must_eat]:\n");
	printf("./philo 5 800 200 200 7\n\n");
	printf("--------------------------------------------------\n");
}
