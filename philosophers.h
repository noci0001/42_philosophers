/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:22:03 by snocita           #+#    #+#             */
/*   Updated: 2023/05/05 15:57:00 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define FORK "\033[0;32mhas taken a fork\033[0m"
# define EAT "\033[0;33mis eating\033[0m"
# define SLEEP "\033[0;35mis sleeping\033[0m"
# define THINK "\033[0;34mis thinking\033[0m"
# define DEAD "\033[0;31mdied\033[0m"

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>

typedef struct s_phil
{
	int					id;
	int					x_ate;
	int					left_fork_id;
	int					right_fork_id;
	long long			t_last_meal;
	struct s_gen		*gen;
	pthread_t			thread_id;
}	t_phil;

typedef struct s_table
{
	int				members;
	int				repas;
	int				t_eat;
	int				all_ate;
	int				t_sleep;
	int				died;
	long long		first_timestamp;
	pthread_mutex_t	forks[250];
	t_phil			philosophers[250];
	pthread_mutex_t	meal_check;
	pthread_mutex_t	writing;
}	t_table;

typedef struct s_gen
{
	int		t_death;
	t_table	*table;
	t_phil	*phil;
}	t_gen;

void			msg_err(char *str);
void			msg(char *str);
void			parsing(char *av, int ac, t_gen *gen);
int				ft_atoi(char *str);
int				catalysis(t_gen *gen, char **av);
unsigned long	get_timestamp(void);
void			start_table(t_gen	*gen);
void			print_status(t_gen *gen, int id, int strnum);
int				init_mutex(t_gen *gen);
int				error_manager(int error);
int				starter(t_gen *gen);
void			*p_thread(void *void_philosopher);
void			smart_sleep(long long time, t_gen	*gen);
long long		time_diff(long long past, long long pres);
void			death_checker(t_gen *r, t_phil *p);
void			exit_starter(t_gen *gen, t_phil *philos);

#endif