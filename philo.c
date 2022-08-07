/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/08/01 16:44:24 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philos;

	if (ac < 5 || ac > 6)
		return (printf("error args\n"), FAILDE);
	philos = NULL;
	if (inistialize_philos(&philos, av, ac) != SUCCESS)
		return (FAILDE);
	if (creat_threads(&philos) != SUCCESS)
		return (free_philos(philos, 1), FAILDE);
	if (manager(philos) != SUCCESS)
		return (free_philos(philos, 1), FAILDE);
	return (SUCCESS);
}
