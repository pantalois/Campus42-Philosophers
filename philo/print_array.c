/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:49:39 by loigonza          #+#    #+#             */
/*   Updated: 2024/09/16 17:03:18 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_array(t_data_table *table, char *argv[])
{
	int a = 0;

	while (a < atoi(argv[1]))
	{	printf("posicion %i de number of philos = %i\n", a, table->number_of_philos[a]);
		a++;
	}	
}
