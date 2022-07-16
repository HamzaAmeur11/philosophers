/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:06:47 by hameur            #+#    #+#             */
/*   Updated: 2022/07/16 17:54:59 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int list_philos(t_philo **philos, int n_philos, t_args *args)
{
	t_philo *ptr;
	int i;

	if (n_philos < 2)
		return (FAILDE);
	i = n_philos;
	ptr = NULL;
	*philos = new_node(*philos, 0);
	while (i > 0)
		add_back(philos, new_node(ptr, i--));
	ptr = (*philos)->next;
	(*philos)->args = args;
	while (ptr->index != (*philos)->index)
	{
		ptr->args = args;
		ptr = ptr->next;
	}
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