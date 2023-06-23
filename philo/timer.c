/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:24:49 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/23 17:38:22 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	timer(t_philo *info)
{
	struct	timeval	test;

	gettimeofday(&test, NULL);
	printf("[%ld:%ld] = \n", test.tv_sec - info->time_sec, test.tv_usec / 1000);
}
