/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:48:04 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/27 13:27:36 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *data)
{
	t_philo	*info;
	int		x;

	info = (t_philo *)data;
	pthread_mutex_lock(&info->lock);
	x = info->x;
	(info->x)++;
	pthread_mutex_unlock(&info->lock);
	start(info, x);
	return (NULL);
}

void	free_all(t_philo *info)
{
	int	x;

	x = -1;
	while (++x < info->nb)
		pthread_mutex_destroy(&info->fork[x]);
	pthread_mutex_destroy(&info->lock);
	pthread_mutex_destroy(&info->over);
	free(info->philo);
	free(info->fork);
}

void	philosophers(t_philo *info)
{
	int	x;

	info->x = 1;
	info->philo = malloc((info->nb) * sizeof(pthread_t));
	if (!(info->philo))
		return ;
	info->fork = malloc((info->nb + 1) * sizeof(pthread_mutex_t));
	if (!(info->fork))
		return ;
	x = -1;
	while (++x < info->nb)
		pthread_mutex_init(&info->fork[x], NULL);
	pthread_mutex_init(&info->lock, NULL);
	pthread_mutex_init(&info->over, NULL);
	x = -1;
	while (++x < info->nb)
		pthread_create(&info->philo[x], NULL, routine, info);
	x = -1;
	while (++x < info->nb)
		pthread_join(info->philo[x], NULL);
	free_all(info);
}

int	main(int argc, char **argv)
{
	t_philo	info;
	struct timeval	value;	

	if (argc == 6 || argc == 5)
	{
		info.nb = ft_atoi(argv[1]);
		info.die = ft_atoi(argv[2]);
		info.eat = ft_atoi(argv[3]);
		info.sleep = ft_atoi(argv[4]);
		info.is_dead = 0;
		if (argc == 6)
			info.nb_eat = ft_atoi(argv[5]);
		else
			info.nb_eat = -1;
		gettimeofday(&value, NULL);
		info.time_sec = value.tv_sec;
		info.time_usec = value.tv_usec;
		philosophers(&info);
	}
	else
		return (0);
}
