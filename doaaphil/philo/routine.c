/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doqahtan <doqahtan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:14:13 by doqahtan          #+#    #+#             */
/*   Updated: 2024/09/09 10:14:15 by doqahtan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philoso)
{
	t_philo	*philo;

	philo = (t_philo *)philoso;
	if (philo->data->philo_no == 1)
		one_philo(philo);
	pthread_mutex_lock(&philo->data->ending);
	while (philo->data->finish == 0)
	{
		pthread_mutex_unlock(&philo->data->ending);
		eating(philo);
		sleeping(philo);
		thinking(philo);
		pthread_mutex_lock(&philo->data->ending);
	}
	pthread_mutex_unlock(&philo->data->ending);
	return (NULL);
}
