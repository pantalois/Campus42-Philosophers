/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loigonza <loigonza@42.barcel>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:41:27 by loigonza          #+#    #+#             */
/*   Updated: 2024/10/29 17:07:00 by loigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>  //Para hilos y mutex			   
# include <stdio.h>    // Para printf
# include <stdlib.h>   // Para malloc y free
# include <unistd.h>   // Para usleep
# include <sys/time.h> // Para gettimeofday

// Estructura para almacenar datos de cada filósofo

typedef struct s_philosopher
{
	int					id;
	int					times_eaten;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long long			last_meal_time;
	struct s_data		*data;
}				t_philosopher;
// Estructura para datos generales
typedef struct s_data
{
	int					num_philosophers;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					must_eat_count;
	int					all_alive;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print_lock;
	long long			start_time;
	t_philosopher		*philosophers;
	pthread_mutex_t		eat_count_lock;
	pthread_mutex_t		died;
	pthread_mutex_t		stop;
	pthread_mutex_t		meal_time_lock;
	pthread_t			monitoring;
	int					total_eaten;
}				t_data;

int			init_data(t_data *data, int argc, char **argv);
int			start_simulation(t_data *data);
long long	current_time(void);
void		usleep_ms(int ms);
void		cleanup(t_data *data);
int			validate_args(int argc, char **argv);
int			ft_atoi(const char *str);
void		*philosopher_routine(void *arg);
void		syncro(t_philosopher *philo);
void		one_philo_actions(t_philosopher *philo);
void		philos_actions(t_philosopher	*philo);
void		print_action(t_philosopher *philo, const char *action);
int			init_forks(t_data *data);
int			init_philosophers(t_data *data);
int			join_threads(t_data *data);
void		*monitor_philosophers(void *data_void);
int			create_threads(t_data *data);
int			check_eat_count(t_data *data);
int			is_death(t_data *data, int flag);
void		take_forks(t_philosopher *philo);
void		release_forks(t_philosopher *philo);
void		check_eaten_times(t_data *data);
void		print_error(void);
int			init_data_mutex(t_data *data);

#endif
