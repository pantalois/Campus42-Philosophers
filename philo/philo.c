#include "philo.h"

void	ft_free_data(t_philo *philo)
{
	if (t_philo)
	{}

}
int	main(int argc, char *argv[])
{
	t_philo *philo;
	int i;

	i = 0;
	//Control de número de argv válidos.
	if (argc != 5 && argc != 6)
	{
		printf("The arguments need to be 5 200 200 200 [5]");
		return (1);
	}
	/*
	 La función PARSE_INPUT me hace el atoi de los argv,
	 al mismo tiempo que me comprueba si son valores válidos.
	  */
	if (parse_input(argv) == 1)
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (1);
	memset(philo, 0, sizeof(t_philo));
	philo->data_table = (t_data_table *)malloc(sizeof(t_data_table));
	if (!philo->data_table)
	{
		//ft_free_data(philo);
		return (1);
	}
	memset(philo->data_table, 0, sizeof(t_data_table));
	while (argv[i])
	{
		atoi_argv(philo, argv);
		i++;
	}

	if (philo->data_table->philos <= 0) //number_of_philos
	{
		printf("At least one philo please");
		return (1);
	}
	if (philo->data_table->time_to_die <= 0)//time_to_die tiempo que tiene el philo para empezar a comer desde su última comida.
	{
		printf("At least one, so we give the philos the chance to eat");
		return (1);
	}
	if (philo->data_table->time_to_eat <= 0)//time_to_eat tiempo que tiene para comer, durante ese tiempo tendrá los 2 tenedores ocupados.
	{
		printf("At least one, so we give him some time to eat");
		return (1);
	}
	if (philo->data_table->time_to_sleep <= 0)//time_to_sleep tiempo que tiene un philo para dormir.
	{
		printf("Let the philos sleep");
		return (1);
	}
	if (philo->data_table->number_of_meals)
	{
		if (philo->data_table->number_of_meals <= 0)//number_of_times_each_philo_must_eat. si los filósofos comen todas las veces especificadas en este argv la simulación de detendra, sino cuando uno muera.
		{
			printf("At least let them eat once");
			return (1);
		}
	}
	//set table
 
/**/
//De principio no necesaria e inicializar, pues no hay ningun char * dentro de mi t_data_table struct.
	//vamos a sentar los filosofos en la mesa.
	//while (argv[1] != 1)
	return (0);
}

