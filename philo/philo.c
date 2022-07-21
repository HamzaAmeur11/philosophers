/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/07/21 15:46:21 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		return (FAILDE);
	if (creat_threads(&philos) != SUCCESS)
		return (FAILDE);
	
	
}