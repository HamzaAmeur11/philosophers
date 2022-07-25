/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:06:47 by hameur            #+#    #+#             */
/*   Updated: 2022/07/23 18:22:22 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_philos(t_philo *philos)
{
	int i = 0;
	t_philo *ptr = philos;

	free(philos->args);
	while (i <= philos->args->n_eat)
	{
		philos = philos->next;
		free(ptr);
		ptr = philos;
	}
}

int list_philos(t_philo **philos, int n_philos, t_args *args)
{
	t_philo *ptr;
	int i;

	if (n_philos < 2)
		return (FAILDE);
	i = 0;
	ptr = NULL;
	while (i < n_philos)
		add_front(philos, new_node(ptr, i++, args));
	return (SUCCESS);
}

int inistialize_philos(t_philo**philos, char **av, int ac)
{
	t_args *args;
	
	args = NULL;

	if (read_args(&args, av, ac)!= 0)
		return (printf("error arguments\n"), FAILDE);
	if (list_philos(philos, args->n_philo, args) != 0)
		return (printf("error value of number of philosophers\n"), FAILDE);
	return (SUCCESS);
}