/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:11:46 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/14 11:23:44 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
int	is_u_dead(t_philo *info, int time, int x)
{
	pthread_mutex_lock(&info->over);
	if (info->is_dead == 1)
		return (-1);
	pthread_mutex_unlock(&info->over);
	if (timer(info) - time > info->die)
	{
		pthread_mutex_lock(&info->over);
		info->is_dead = 1;
		print_msg(info, x, 5);
		pthread_mutex_unlock(&info->over);
		return (-1);
	}
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	rst;
	int	cpt;

	i = 0;
	rst = 0;
	cpt = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			cpt = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		rst = rst * 10 + (nptr[i++] - '0');
	if (cpt == 1)
		rst = -rst;
	return (rst);
}

int	left_fork(t_philo *info, int x)
{
	if (x == 1)
		return (info->nb);
	else
		return (x - 1);
}

void	print_msg(t_philo *info, int x, int msg)
{
	pthread_mutex_lock(&info->lock);
	if (msg == 1)
		printf("%d : %d has taken a fork\n", timer(info), x);
	if (msg == 2)
		printf("%d : %d is eating\n", timer(info), x);
	if (msg == 3)
		printf("%d : %d is sleeping\n", timer(info), x);
	if (msg == 4)
		printf("%d : %d is thinking\n", timer(info), x);
	if (msg == 5)
		printf("%d : %d died\n", timer(info), x);
	pthread_mutex_unlock(&info->lock);
}

int	timer(t_philo *info)
{
	struct	timeval	test;
	int	sec;
	int	milli;
	
	
	gettimeofday(&test, NULL);
	sec = (test.tv_sec - info->time_sec) * 1000;
	milli = (test.tv_usec - info->time_usec) / 1000;
	return (sec + milli);
}
