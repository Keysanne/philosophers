/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 13:08:40 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/29 12:38:06 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_philo *info, int l_fork, int r_fork, int time)
{
	pthread_mutex_lock(&info->fork[l_fork]);
	if (is_u_dead(info, time, r_fork) == -1)
	{
		pthread_mutex_unlock(&info->fork[l_fork]);
		return (-1);
	}
	print_msg(info, r_fork, 1);
	pthread_mutex_lock(&info->fork[r_fork]);
	if (is_u_dead(info, time, r_fork) == -1)
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
	if (is_u_dead(info, *time, r_fork) == -1)
	{
		pthread_mutex_unlock(&info->fork[l_fork]);
		pthread_mutex_unlock(&info->fork[r_fork]);
		return (-1);
	}
	print_msg(info, r_fork, 2);
	*time = timer(info);
	usleep(info->eat * 1000);
	pthread_mutex_unlock(&info->fork[l_fork]);
	pthread_mutex_unlock(&info->fork[r_fork]);
	return (0);
}

int	sleep_think(t_philo *info, int time, int x)
{
	if (is_u_dead(info, time, x) == -1)
		return (-1);
	print_msg(info, x, 3);
	if (is_u_dead(info, time, x) == -1)
		return (-1);
	usleep(info->sleep * 1000);
	if (is_u_dead(info, time, x) == -1)
		return (-1);
	print_msg(info, x, 4);
	return (0);
}

void	nb_de_repas(t_philo *info, int time, int i, int x)
{
	while (1)
	{
		if (take_fork(info, left_fork(info, x), x, time)== -1)
			break ;
		if (eat(info, left_fork(info, x), x, &time) == -1)
			break ;
		if (++i == info->nb_eat)
		{
			pthread_mutex_lock(&info->over);
			(info->eaten)++;
			pthread_mutex_unlock(&info->over);
		}
		if (sleep_think(info, time, x) == -1)
			break ;
	}
}

void	start(t_philo *info, int x)
{
	int	time;
	int	i;

	i = 0;
	time = 0;
	if (info->nb_eat == -1)
	{
		while (1)
		{
			if (take_fork(info, left_fork(info, x), x, time)== -1)
				break ;
			if (eat(info, left_fork(info, x), x, &time) == -1)
				break ;
			if (sleep_think(info, time, x) == -1)
				break ;
		}
	}
	else
		nb_de_repas(info, time, i, x);
}
