#include "philo.h"

int	ft_check_atoi(t_data_table *table)
{
	if ((table->number_of_philos == 0) ||
			(table->time_to_die == 0) ||
			(table->time_to_eat == 0) ||
			(table->time_to_sleep) == 0)
	{
		ft_free_data(table);
		printf("All the values must be at least 1");
		return (1);
	}
	//Cantrolar aqui si me dan times to eat 0?
	return (0);
}

void	ft_free_data(t_data_table *table)
{
	if (table->philos)
	{
		free(table->philos);
		free(table->number_of_philos);
	}
	free(table);
}

int	main(int argc, char *argv[])
{
	t_data_table	*table;
	pthread_t		thread;

	if (argc != 5 && argc != 6)
	{
		printf("The arguments need to be [number_of_philos]"
				"[time_to_die] [time_to_eat] [time_to_sleep]"
				"[number_of_meals]");
		return (1);
	}
	if (parse_input(argv) == 1)
		return (1);
	table = ft_init_data();//Inicializo las estructuras a 0, para evitarme problemas
	ft_struct_data(argv, table);
	if (!table)
		return (1);
	if (ft_check_atoi(table) == 1)
		return (1);	
	pthread_create(&thread, NULL, ft_eat, NULL);
	my_func();
	pthread_join(thread, NULL);
	
	ft_free_data(table);
	return (0);
}
