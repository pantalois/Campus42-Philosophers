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
	//Ultimo dia 16/09
	//Tareas a hacer:
	//1. Asignar a cada pos del array una posicion en el index de la estructura philo
	//2. Asegurarme de que el parseo es efectivo, para ello checkeamos si en el 
	//proceso de inicializacion de la estructura se puede comprobar mas cosas
	//
	//
	//if (ft_atoi(argv[i]) % 2 == 0))
	//		TENEMOS UN NUMERO PAR DE PHILOS
	//		EL philo[0, 2, 4, 6] haran mutex a los tenedores la primera ronda,
	//		es decir, if(philo[i++] % 2 == 0)
	//
	//if (ft_atoi(argv[0]) % 2 != 0)
	//		TENEMOS UN NUMERO IMPAR DE PHILOS
	//		el philo[1, 2,"3"] haran mutex a los tenedores la primera ronda,
	//		es decir, if(philo[i++] % 2 != 0)
	//
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
	if (ft_check_atoi(table) == 1)//Revisar el MAX_INT
		return (1);
	//Proceso de mutex e hilos en un while i < ft_atoi[1]?
	//asignar_forks
	print_array(table, argv);
	grab_forks(table);
	pthread_create(&thread, NULL, ft_eat, &table->philos);
	my_func();
	pthread_join(thread, NULL);
	printf("%i\n", table->number_of_philos[1]);

	//Asignar tenedores y hacer mutex.
	
	ft_free_data(table);
	return (0);
}
