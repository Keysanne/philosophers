/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 14:07:17 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/22 15:07:34 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

typedef	struct	s_counter
{
	pthread_mutex_t	mutex;
	int		x;
}		t_counter;

void	*thread_routine(void *data)
{
	int	i = 0;
	t_counter	*new_struc;
	
	new_struc = (t_counter *)data;
	while (i < 1000000)
	{
		pthread_mutex_lock(&new_struc->mutex);
		(new_struc->x)++;
		pthread_mutex_unlock(&new_struc->mutex);
		i++;
	}
	return (NULL);
}

int	main()
{
	t_counter	struc;
	pthread_t	test[10];

	struc.x = 0;
	pthread_mutex_init(&struc.mutex, NULL);
	pthread_create(&test[1], NULL, thread_routine, &struc);
	pthread_create(&test[2], NULL, thread_routine, &struc);
	pthread_join(test[1], NULL);
	pthread_join(test[2], NULL);
	pthread_mutex_destroy(&struc.mutex);
	printf("%d\n", struc.x);
	return (0);
}
