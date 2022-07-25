/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:27:30 by hameur            #+#    #+#             */
/*   Updated: 2022/07/25 19:54:54 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_print(t_philo *th, int x)
{
	pthread_mutex_lock(&th->args->print);
	if (x == 0)
		printf("%lld Ms : Philosopher %d take a fork dyal %d last eat : %lld\n",\
			(get_time() - th->args->time)  / 1000, th->index, th->index, (get_time() - th->time)/1000);
	else if(x == 10)
	printf("%lld Ms : Philosopher %d take a fork dyal %d last eat : %lld\n",\
			(get_time() - th->args->time)  / 1000, th->index, th->next->index, (get_time() - th->time)/1000);
	else if (x == 1)
		printf("%lld Ms : Philosopher %d is eating %d time | last eat : %lld\n\n",\
			(get_time() - th->args->time) / 1000, th->index, th->n_eating + 1, (get_time() - th->time)/1000);
	else if (x == 2)
		printf("%lld Ms : Philosopher %d is sleeping d last eat : %lld\n\n",\
			(get_time() - th->args->time) / 1000, th->index, (get_time() - th->time) /1000);
	else if (x == 3)
		printf("%lld Ms : Philosopher %d is thinking d last eat : %lld\n\n",\
			(get_time() - th->args->time) / 1000, th->index, (get_time() - th->time) / 1000);
	pthread_mutex_unlock(&th->args->print);
}

void set_forks(t_philo *th, int x)
{
	if (x == 0)
	{
		pthread_mutex_lock(&th->next->fork);
		ft_print(th, 10);
		pthread_mutex_lock(&th->fork);
		ft_print(th, 0);
		ft_print(th, 1);
		ft_usleep(th->args->t_eat * 1000);
	}
	else
	{
		pthread_mutex_unlock(&th->next->fork);
		pthread_mutex_unlock(&th->fork);
	}
}

void *routine(void *arg)
{
	t_philo *th;

	th = (t_philo *)arg;
	th->n_eating = 0;
	th->key = 0;
	th->time = get_time();
	if (th->index % 2 == 1)
		ft_usleep((th->args->t_eat / 2) * 1000);
	while(th->key == 0)
	{
		if (th->n_eating == th->args->n_eat - 1)
			th->key = 1 ;
		set_forks(th, 0);
		set_forks(th, 1);
		th->time = get_time();
		ft_print(th, 2);
		ft_usleep(th->args->t_sleep * 1000);
		ft_print(th, 3);
		th->n_eating++;
	}
	return(NULL);
}

int creat_threads(t_philo **philos)
{
	t_philo *ptr;
	
	ptr = *philos;
	pthread_mutex_init(&ptr->args->print, NULL);
	while (1)
	{
		pthread_mutex_init(&ptr->fork, NULL);
		if (ptr->index == ptr->args->n_philo)
			break;
		ptr = ptr->next;
	}
	ptr = *philos;
	while (1)
	{
		if (pthread_create(&ptr->th, NULL, &routine, (void *)ptr) != 0)
			return (FAILDE);
		if (pthread_detach(ptr->th) != 0)
			return(FAILDE);
		if (ptr->index == ptr->args->n_philo)
			break;
		ptr = ptr->next;
	}
	return(SUCCESS);
}