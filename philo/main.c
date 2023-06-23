/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:48:04 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/23 17:40:15 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *data)
{
	t_philo	*info;
	int	x;

	info = (t_philo *)data;
	pthread_mutex_lock(&info->fork[0]);
	x = info->x;
	(info->x)++;
	pthread_mutex_unlock(&info->fork[0]);
	printf("%d\n", x);
	return (NULL);
}

void	philosophers(t_philo *info)
{
	int	x;

	info->x = 1;
	info->philo = malloc((info->nb + 1) * sizeof(pthread_t));
	info->fork = malloc((info->nb + 1) * sizeof(pthread_mutex_t));
	x = 0;
	while (++x <= info->nb)
		pthread_mutex_init(&info->fork[x], NULL);
	x = 0;
	while (++x <= info->nb)
		pthread_create(&info->philo[x], NULL, routine, info);
	x = 0;
	while (++x <= info->nb)
		pthread_join(info->philo[x], NULL);
	x = 0;
	while (++x <= info->nb)
		pthread_mutex_destroy(&info->fork[x]);
	free(info->philo);
	free(info->fork);
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
		if (argc == 6)
			info.nb_eat = ft_atoi(argv[5]);
		else
			info.nb_eat = 0;
		gettimeofday(&value, NULL);
		info.time_sec = value.tv_usec;
		philosophers(&info);
	}
	else
		return (0);
}
