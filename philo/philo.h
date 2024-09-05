#ifndef PHILO_H 
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef pthread_mutex_t t_mtx;

typedef struct s_fork
{
	t_mtx	fork;
	int	fork_id;
}	t_fork;

typedef struct s_table_data
{
	int	philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_meals;
	int	start_simulation;
	int	end_simulation; //Cuando sea 1 será que un filo muere or all full
	t_fork	*forks;
	t_philo	*philos;
}	t_data_table;

typedef struct s_philo
{
	int		index;
	t_fork		*right_fork;
	t_fork		*left_fork;
	int		last_meal_time; //tiempo desde la última comida.
	int		full;
	t_data_table	*data_table;
	pthread_t	thread_id;
}	t_philo;

int	ft_atoi(const char *str);
int	parse_input(char *argv[]);
void	atoi_argv(t_philo *philo, char *argv[]);

#endif
