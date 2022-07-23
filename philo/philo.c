/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/07/23 15:35:22 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int manager(t_philo *philos)
{
	t_philo *ptr;

	ptr = philos;
	while (1)
	{
		if (get_time() - ptr->time >= ptr->args->t_die)
		{
			printf("%lld Ms : Philosopher %d take a fork\n",\
			(get_time() - ptr->args->time), ptr->index);
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
	if (ac < 5 || ac > 6)
		return (printf("error args\n"), FAILDE);
	t_philo *philos;
	if (inistialize_philos(&philos, av, ac) != SUCCESS)
		return (free_philos(philos), FAILDE);
	if (creat_threads(&philos) != SUCCESS)
		return (FAILDE);
	if (manager(philos) != SUCCESS)
		return (FAILDE);
	
	
}