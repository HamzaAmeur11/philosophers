/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cerculaire_linked_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:25:01 by hameur            #+#    #+#             */
/*   Updated: 2022/08/03 11:37:27 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_node(t_philo *node, int index, t_args *args)
{
	node = (t_philo *)malloc(sizeof(t_philo));
	node->index = index + 1;
	node->args = args;
	node->next = NULL;
	return (node);
}

void	add_front(t_philo **philos, t_philo *philo)
{
	struct t_philo	*back;

	if ((*philos) == NULL)
		*philos = philo;
	if ((*philos)->next == NULL)
	{
		(*philos)->next = philo;
		philo->next = *philos;
	}
	else
	{
		back = (*philos)->next;
		while (back->next != *philos)
			back = back->next;
		back->next = philo;
		philo->next = (*philos);
	}
}

void	free_philos(t_philo *philos, int x)
{
	t_philo	*ptr;
	int		i;

	ptr = philos;
	i = 0;
	if (x == 1)
		destroy_mutex(philos);
	if (!philos)
		return ;
	while (1)
	{
		if (i == ptr->args->n_philo - 1)
		{
			free(ptr->args);
			free(ptr);
			return ;
		}
		philos = philos->next;
		free(ptr);
		ptr = philos;
		i++;
	}
}

void	destroy_mutex(t_philo *philos)
{
	t_philo	*ptr;

	ptr = philos;
	while (ptr->index != ptr->args->n_philo)
	{
		usleep(50);
		pthread_mutex_destroy(&ptr->fork);
		ptr = ptr->next;
	}
	pthread_mutex_destroy(&ptr->fork);
	pthread_mutex_destroy(&philos->args->print);
}
