/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:27:30 by hameur            #+#    #+#             */
/*   Updated: 2022/07/21 15:14:12 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine(void *arg)
{
	t_philo *thread;

	thread = (t_philo *)arg;
	printf("philos := %d\n", thread->index);
	return(NULL);
}

int creat_threads(t_philo **philos)
{
	t_philo *ptr;
	
	ptr = *philos;
	while (ptr->index < ptr->args->n_philo)
	{
		if (pthread_create(&ptr->th, NULL, &routine, (void *)ptr) != 0)
			return (FAILDE);
		ptr = ptr->next;
	}
	ptr = *philos;
	while (ptr->index < ptr->args->n_philo)
	{
		if (pthread_detach(ptr->th) != 0)
			return(FAILDE);
		ptr = ptr->next;
	}
	return(SUCCESS);
}