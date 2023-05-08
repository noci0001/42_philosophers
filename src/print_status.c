/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:58:17 by snocita           #+#    #+#             */
/*   Updated: 2023/05/05 15:52:20 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	print_status(t_gen *gen, int id, int strnum)
{
	pthread_mutex_lock(&(gen->table->writing));
	if (!(gen->table->died))
	{
		printf("%lli ", get_timestamp() - gen->table->first_timestamp);
		printf("%i ", id + 1);
	}
	if (gen->table->died != 1)
	{
		if (strnum == 1)
			printf(" \033[0;36m%s\033[0m\n", FORK);
		if (strnum == 2)
			printf(" \033[0;36m%s\033[0m\n", EAT);
		if (strnum == 3)
			printf(" \033[0;36m%s\033[0m\n", SLEEP);
		if (strnum == 4)
			printf(" \033[0;36m%s\033[0m\n", THINK);
		if (strnum == 5)
		{
			printf(" \033[0;36m%s\033[0m\n", DEAD);
			exit(1);
		}
	}
	pthread_mutex_unlock(&(gen->table->writing));
	return ;
}
