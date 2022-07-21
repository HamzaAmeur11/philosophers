/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:27:30 by hameur            #+#    #+#             */
/*   Updated: 2022/07/22 00:45:40 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_forks(t_philo *th, int x)
{
	if (x == 0)
	{
		if (th->index % 2 == 1)
			pthread_mutex_lock(&th->next->fork);
		else
			pthread_mutex_lock(&th->previous->fork);
		printf("%lld Ms : Philosopher %d take a fork\n",\
			(get_time() - th->args->time), th->index);
		pthread_mutex_lock(&th->fork);
		usleep(th->args->t_eat);
		printf("%lld Ms : Philosopher %d is eating\n",\
			(get_time() - th->args->time), th->index);
	}
	else
	{
		if (th->index % 2 == 1)
			pthread_mutex_unlock(&th->next->fork);
		else
			pthread_mutex_unlock(&th->previous->fork);
		pthread_mutex_unlock(&th->fork);
	}
}

void *routine(void *arg)
{
	t_philo *th;

	th = (t_philo *)arg;
	if (th->index % 2 == 1)
		usleep(th->args->t_eat / 2);
	while(1)
	{
		set_forks(th, 0);
		set_forks(th, 1);
		printf("%lld Ms : Philosopher %d is sleeping\n",\
			(get_time() - th->args->time), th->index);
		usleep(th->args->t_sleep);
		printf("%lld Ms : Philosopher %d is thinking\n",\
			(get_time() - th->args->time), th->index);
	}
	return(NULL);
}

int creat_threads(t_philo **philos)
{
	t_philo *ptr;
	
	ptr = *philos;
	while (ptr->index < ptr->args->n_philo)
	{
		pthread_mutex_init(&ptr->fork, NULL);
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