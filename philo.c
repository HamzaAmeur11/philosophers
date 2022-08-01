/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/08/01 13:19:34 by hameur           ###   ########.fr       */
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
	ft_usleep((philos->args->t_die / 2) * 1000);
	if (manager(philos) != SUCCESS)
		return (free_philos(philos, 1), FAILDE);
	return (SUCCESS);
}
