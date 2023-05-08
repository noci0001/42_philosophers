/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:35:40 by snocita           #+#    #+#             */
/*   Updated: 2023/05/05 15:12:10 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	init_mutex(t_gen *gen)
{
	int	i;

	i = gen->table->members;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(gen->table->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(gen->table->writing), NULL))
		return (1);
	if (pthread_mutex_init(&(gen->table->meal_check), NULL))
		return (1);
	return (0);
}

int	init_philosophers(t_gen *gen)
{
	int	i;

	i = gen->table->members;
	while (--i >= 0)
	{
		gen->table->philosophers[i].id = i;
		gen->table->philosophers[i].x_ate = 0;
		gen->table->philosophers[i].left_fork_id = i;
		gen->table->philosophers[i].right_fork_id = (i + 1)
			% gen->table->members;
		gen->table->philosophers[i].t_last_meal = 0;
		gen->table->philosophers[i].gen = gen;
	}
	return (0);
}

int	catalysis(t_gen *gen, char **av)
{
	int	i;
	int	val;

	i = 1;
	while (av[i])
	{
		val = ft_atoi(av[i++]);
		if (INT_MIN > val || val > INT_MAX)
			msg_err("The inputs are outside of the range of acceptable ints");
	}
	gen->table->members = ft_atoi(av[1]);
	gen->t_death = ft_atoi(av[2]);
	gen->table->t_eat = ft_atoi(av[3]);
	gen->table->t_sleep = ft_atoi(av[4]);
	gen->table->all_ate = 0;
	gen->table->died = 0;
	if (gen->table->members < 2 || gen->t_death < 0 || gen->table->t_eat < 0
		|| gen->table->t_sleep < 0 || gen->table->members > 250)
		return (1);
	if (av[5])
	{
		gen->table->repas = ft_atoi(av[5]);
		if (gen->table->repas <= 0)
			return (1);
	}
	else
		gen->table->repas = -1;
	if (init_mutex(gen))
		return (2);
	init_philosophers(gen);
	return (0);
}

unsigned long	get_timestamp(void)
{
	struct timeval	current_time;
	unsigned long	milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = (unsigned long)(current_time.tv_sec)*1000
		+ (unsigned long)(current_time.tv_usec) / 1000;
	return (milliseconds);
}
