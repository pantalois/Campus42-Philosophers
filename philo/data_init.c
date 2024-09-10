/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:39:56 by loigonza          #+#    #+#             */
/*   Updated: 2024/09/10 16:14:39 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data_table	*ft_init_data()
{
	t_data_table *table;

	table = (t_data_table *)malloc(sizeof(t_data_table));
	if (!table)
		return (NULL);
	memset(table, 0, sizeof(t_data_table));
	//Pensar como inializar los datos del philo

	//Darle la vuelta
	table->philos = (t_philo *)malloc(sizeof(t_philo));
	if (!table->philos)
	{
		ft_free_data(table);
		return (NULL);
	}
	memset(table->philos, 0, sizeof(t_philo));
	return (table);
}

void	ft_struct_data(char *argv[], t_data_table *table)
{
	//Para el numero de philos hare un array de ints
	int	i;

	i = 0;
	table->number_of_philos = malloc(sizeof(int *) * ft_atoi(argv[1]));
	if (!table->number_of_philos)
	{
		ft_free_data(table);
		return ;
	}
	while (++i <= ft_atoi(argv[1]))
		table->number_of_philos[i] = i;
	int a = 0;
	while (a <= ft_atoi(argv[1]))
	{	printf("posicion %i de number of philos = %i\n", a, table->number_of_philos[a]);
		a++;
	}	
	table->time_to_die = ft_atoi(argv[2]) * 1e3;
	table->time_to_eat = ft_atoi(argv[3]) * 1e3;
	table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (argv[5])
		table->number_of_meals = ft_atoi(argv[5]);
	else
		table->number_of_meals = -1;
}
