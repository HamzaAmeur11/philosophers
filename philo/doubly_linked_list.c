/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 12:25:01 by hameur            #+#    #+#             */
/*   Updated: 2022/07/16 14:19:54 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo *new_node(t_philo *node, int index)
{
	node = (t_philo *)malloc(sizeof(t_philo));
	node->index = index;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

static void incrementation(t_philo **philos)
{
	t_philo *first;
	t_philo *ptr;

	first = *philos;
	ptr = (*philos)->next;
	first->index++;
	while (ptr != first)
	{
		ptr->index++;
		ptr = ptr->next;
	}
}

void add_front(t_philo **philos, t_philo *philo)
{
	struct t_philo *front;
	struct t_philo *back;

	if (!(*philos))
		*philos = philo;
	else if(!(*philos)->next && !(*philos)->previous)
	{
		(*philos)->next = philo;
		(*philos)->previous = philo;
		philo->next = *philos;
		philo->previous = *philos;
	} 
	else
	{
		front = *philos;
		back = (*philos)->previous;
		incrementation(philos);
		back->next = philo;
		front->previous = philo;
		philo->next = front;
		philo->previous = back;	
	}
}

void add_back(t_philo **philos, t_philo *philo)
{
	t_philo *front;
	t_philo *back;

	if (!(*philos))
		*philos = philo;
	else if(!(*philos)->next && !(*philos)->previous)
	{
		(*philos)->next = philo;
		(*philos)->previous = philo;
		philo->next = *philos;
		philo->previous = *philos;
		philo->index = 1;
	} 
	else
	{	
		front = *philos;
		back = (*philos)->previous;
		back->next = philo;
		front->previous = philo;
		philo->next = front;
		philo->previous = back;
		philo->index = back->index + 1;
	}
}