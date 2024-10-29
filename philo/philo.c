/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:37:40 by loigonza          #+#    #+#             */
/*   Updated: 2024/10/24 13:30:46 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	usleep_ms(int ms)
{
	long long	start;
	long long	now;

	start = current_time();
	while (1)
	{
		now = current_time();
		if ((now - start) >= ms)
			break ;
		usleep(100);
	}
}

void	print_action(t_philosopher *philo, const char *action)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (is_death(philo->data, 0))
		printf("%lld %d %s\n", current_time() - philo->data->start_time,
			philo->id, action);
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (init_data(&data, argc, argv) == -1)
	{
		print_error();
		return (1);
	}
	if (start_simulation(&data) == -1)
	{
		cleanup(&data);
		return (1);
	}
	pthread_join(data.monitoring, NULL);
	cleanup(&data);
	return (0);
}
