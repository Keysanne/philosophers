/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_solo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:53:36 by tbatteux          #+#    #+#             */
/*   Updated: 2023/06/29 12:55:40 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine_solo(void *data)
{
	t_philo	*info;

	info = (t_philo *)data;
	printf("%d : %d has taken a fork\n", timer(info), 1);
	usleep(info->die * 1000);
	printf("%d : %d died\n", timer(info), 1);
	return (NULL);
}
