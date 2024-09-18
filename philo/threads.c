/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:19:46 by loigonza          #+#    #+#             */
/*   Updated: 2024/09/18 12:30:24 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_data_table *table)
{
	printf("hola\n");
	pthread_mutex_init (&table->philos->right_fork->fork_mtx, NULL);
	pthread_mutex_init (&table->philos->left_fork->fork_mtx, NULL);
	printf("adios\n");
	
}

void	*ft_eat(void* arg)
{
	t_philo*	philos;

	philos = (t_philo *)arg;
	

	pthread_mutex_lock(&philos->right_fork->fork_mtx);

	//Codigo aqui.

	pthread_mutex_unlock(&philos->left_fork->fork_mtx);
	

	//Para comer tienen que cojer los tenedores
	(void)arg;

	return (NULL);
}

void	my_func()
{
	for (int i = 0; i < 10; i++)
	{
		sleep(1);
		printf("my turno %i\n", i);
	}
	return ;
}
