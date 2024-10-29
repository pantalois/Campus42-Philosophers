/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:41:51 by loigonza          #+#    #+#             */
/*   Updated: 2024/10/29 16:29:40 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->data->num_philosophers == 1)
	{
		one_philo_actions(philo);
		return (NULL);
	}
	while (is_death(philo->data, 0))
	{
		syncro(philo);
		philos_actions(philo);
		if (philo->times_eaten == philo->data->must_eat_count)
			return (NULL);
	}
	return (NULL);
}

void	syncro(t_philosopher *philo)
{
	if (philo->id % 2 == 0 && !philo->times_eaten)
		usleep_ms(philo->data->time_to_eat);
	else
	{
		if (philo->id == philo->data->num_philosophers
			&& !philo->times_eaten)
			usleep_ms(philo->data->time_to_eat * 2);
	}
	if (philo->data->num_philosophers % 2 != 0 && philo->times_eaten)
		usleep_ms(philo->data->time_to_eat);
}

void	take_forks(t_philosopher *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_action(philo, "has taken a fork");
	}
}

void	one_philo_actions(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action(philo, "has taken a fork");
	usleep_ms(philo->data->time_to_die);
	print_action(philo, "died");
	pthread_mutex_unlock(philo->left_fork);
	is_death(philo->data, 1);
}

void	philos_actions(t_philosopher *philo)
{
	take_forks(philo);
	print_action(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_time_lock);
	philo->last_meal_time = current_time();
	philo->times_eaten++;
	pthread_mutex_unlock(&philo->data->meal_time_lock);
	usleep_ms(philo->data->time_to_eat);
	release_forks(philo);
	print_action(philo, "is sleeping");
	usleep_ms(philo->data->time_to_sleep);
	print_action(philo, "is thinking");
}
