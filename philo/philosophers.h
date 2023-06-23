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
	int	time_sec;
	int	time_usec;
	pthread_t		*philo;
	pthread_mutex_t	*fork;	
}		t_philo;


/*utils*/

int	ft_atoi(const char *nptr);
void	timer(t_philo *info);

#endif
