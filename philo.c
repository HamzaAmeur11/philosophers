/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/07/25 20:02:17 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long start = get_time();
	while (get_time() - start < time);
}

int manager(t_philo *philos)
{
	t_philo *ptr;

	ptr = philos;
	while (1)
	{
		if (get_time() - ptr->time >= ptr->args->t_die * 1000)
		{
			printf("%lld Ms : Philosopher %d died | last eat : %lld\n",\
			(get_time() - ptr->args->time) / 1000, ptr->index,  (get_time() - ptr->time)/1000);
			return (FAILDE);
		}
		ptr = ptr->next;
	}
	return (SUCCESS);
}

long long get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int main(int ac, char **av)
{
	t_philo *philos;
	
	if (ac < 5 || ac > 6)
		return (printf("error args\n"), FAILDE);
	philos = NULL;
	if (inistialize_philos(&philos, av, ac) != SUCCESS)
		return (free_philos(philos), FAILDE);
	if (creat_threads(&philos) != SUCCESS)
		return (FAILDE);
	ft_usleep((philos->args->t_die / 2) * 1000);
	if (manager(philos) != SUCCESS)
		return (FAILDE);
	return (SUCCESS);
}