/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:34:32 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/22 14:12:01 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	x;
	int	nb;
	int	die;
	int	eat;
	int	sleep;
	int	nb_eat;
	int	is_dead;
	long int	time_sec;
	long int	time_usec;
	pthread_t		*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	lock;
	pthread_mutex_t	over;
}		t_philo;


/*utils*/

int	ft_atoi(const char *nptr);
int	timer(t_philo *info);
int	left_fork(t_philo *info, int x);
int	is_u_dead(t_philo *info, int time);
void	start(t_philo *info, int x);
void	print_msg(t_philo *info, int x, int msg);

#endif
