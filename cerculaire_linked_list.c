/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:25:01 by hameur            #+#    #+#             */
/*   Updated: 2022/07/26 00:45:53 by hameur           ###   ########.fr       */
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
