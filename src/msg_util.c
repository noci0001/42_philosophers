/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:31:45 by snocita           #+#    #+#             */
/*   Updated: 2023/05/04 15:56:50 by snocita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_atoi(char *str)
{
	int	val;
	int	sign;

	val = 0;
	sign = 1;
	if (!str)
		return (0);
	while (*str && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		val = val * 10 + *str - '0';
		str++;
	}
	return (sign * val);
}

void	msg(char *str)
{
	printf("%s\n", str);
}

void	msg_err(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	error_manager(int error)
{
	if (error == 1)
		msg_err("At least one wrong argument");
	if (error == 2)
		msg_err("Fatal error when intializing mutex");
	return (1);
}
