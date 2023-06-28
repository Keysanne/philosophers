/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:08:40 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/28 16:58:11 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_philo *info, int l_fork, int r_fork, int time)
{
	pthread_mutex_lock(&info->fork[l_fork]);
	if (is_u_dead(info, time) == -1)
	{
		pthread_mutex_unlock(&info->fork[l_fork]);
		return (-1);
	}
	print_msg(info, r_fork, 1);
	pthread_mutex_lock(&info->fork[r_fork]);
	if (is_u_dead(info, time) == -1)
	{
		pthread_mutex_unlock(&info->fork[l_fork]);
		pthread_mutex_unlock(&info->fork[r_fork]);
		return (-1);
	}
	print_msg(info, r_fork, 1);
	return (0);
}

int	eat(t_philo *info, int l_fork, int r_fork, int *time)
{
	if (is_u_dead(info, *time) == -1)
	{
		pthread_mutex_unlock(&info->fork[l_fork]);
		pthread_mutex_unlock(&info->fork[r_fork]);
		return (-1);
	}
	print_msg(info, r_fork, 2);
	usleep(info->eat * 1000);
	*time = timer(info);
	pthread_mutex_unlock(&info->fork[l_fork]);
	pthread_mutex_unlock(&info->fork[r_fork]);
	return (0);
}

int	sleep(t_philo *info, int time)
{
	if (is_u_dead(info, time) == -1)
		return (-1);
}

void	start(t_philo *info, int x)
{
	int	time;

	time = 0;
	while (1)
	{
		if (take_fork(info, left_fork(info, x), x, time)== -1)
			break ;
		if (eat(info, left_fork(info, x), x, &time) == -1)
			break ;
		if (sleep(info, time) == -1)
			break ;
	//	if (think(info, time) == -1)
	//		break ;
	}
}
