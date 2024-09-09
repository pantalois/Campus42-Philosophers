#include "philo.h"

int	ft_check_atoi(char*argv[], t_philo *philo)
{
	int i;

	i = 0;
	while (argv[i])
	{
		atoi_argv(philo, argv);
		i++;
	}
	if ((philo->data_table->number_of_philos == 0) ||
			(philo->data_table->time_to_die == 0) ||
			(philo->data_table->time_to_eat == 0) ||
			(philo->data_table->time_to_sleep) == 0)
	{
		ft_free_data(philo);
		printf("All the values must be at least 1");
		return (1);
	}
	return (0);
}

t_philo	*ft_init_data()
{
	t_data_table *table;

	table = (t_data_table *)malloc(sizeof(t_data_table));
	if (!table)
		return (NULL);
	memset(table, 0, sizeof(t_data_table));
	//Pensar como inializar los datos del philo

	//Darle la vuelta
	philo->data_table = (t_data_table *)malloc(sizeof(t_data_table));
	if (!philo->data_table)
	{
		ft_free_data(philo);
		return (NULL);
	}
	memset(philo->data_table, 0, sizeof(t_data_table));
	return (philo);
}

void	ft_free_data(t_philo *philo)
{
	if (philo->data_table)
		free(philo->data_table);
	free(philo);
}

int	main(int argc, char *argv[])
{
	t_philo	*philo;

	if (argc != 5 && argc != 6)
	{
		printf("The arguments need to be [number_of_philos]  [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals]");
		return (1);
	}
	if (parse_input(argv) == 1)
		return (1);
	philo = ft_init_data();
	if (!philo)
		return (1);
	if (ft_check_atoi(argv, philo) == 1)
		return (1);	

	return (0);
}
