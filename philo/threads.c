/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:19:46 by loigonza          #+#    #+#             */
/*   Updated: 2024/09/10 18:28:25 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat(void* arg)
{
	(void)arg;
	for (int i = 0; i < 10; i++)
	{
		sleep(1);
		printf("hola edmumdo %i\n", i);
	}
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
