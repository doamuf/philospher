/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doqahtan <doqahtan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:13:49 by doqahtan          #+#    #+#             */
/*   Updated: 2024/09/09 10:13:51 by doqahtan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 5 && ac != 6)
		return (printf("Args should be like: ./philo 5 800 200 200.\n"));
	if (checking_ar(av))
		return (printf("Invalid Args!\n"));
	data = ft_calloc(1, sizeof(t_data));
	if (data_init(data, ac, av))
		return (1);
	create_philo(data);
	destroy(data);
	return (0);
}
