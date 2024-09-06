#include "philo.h"

int	parse_input(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			printf("No negative values admited\n");
			return (1);
		}
		if ((argv[i][j] == '+' && argv[i][j + 1] == '0') || argv[i][j] == '0')
		{
			printf("+0... and 0123... Is not a valid format\n");
			return (1);
		}
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
		       j++;
		if (argv[i][j])
		{
			printf("Non numeric value inside the argvs\n");
			return (1);
		}
	i++;
	}
	return (0);	
}

void	atoi_argv(t_philo *philo, char *argv[])
{
	philo->data_table->number_of_philos  = ft_atoi(argv[1]);
	philo->data_table->time_to_die = ft_atoi(argv[2]) * 1e3;
	philo->data_table->time_to_eat = ft_atoi(argv[3]) * 1e3;
	philo->data_table->time_to_sleep = ft_atoi(argv[4]) * 1e3;
	if (argv[5])
		philo->data_table->number_of_meals = ft_atoi(argv[5]);
	else
		philo->data_table->number_of_meals = -1;

}
