/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/07/26 00:37:34 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		;
}

int	manager(t_philo *philos)
{
	t_philo	*ptr;
	int		global_key;

	global_key = 0;
	ptr = philos;
	while (1)
	{
		if (ptr->key == 0 && get_time() - ptr->time >= ptr->args->t_die * 1000)
		{
			ft_print(ptr, -1);
			return (FAILDE);
		}
		if (ptr->key == 1)
			global_key++;
		if (global_key == ptr->args->n_philo)
			break ;
		ptr = ptr->next;
	}
	return (SUCCESS);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	main(int ac, char **av)
{
	t_philo	*philos;

	if (ac < 5 || ac > 6)
		return (printf("error args\n"), FAILDE);
	philos = NULL;
	if (inistialize_philos(&philos, av, ac) != SUCCESS)
		return (FAILDE);
	if (creat_threads(&philos) != SUCCESS)
		return (free_philos(philos), FAILDE);
	ft_usleep((philos->args->t_die / 2) * 1000);
	if (manager(philos) != SUCCESS)
		return (free_philos(philos), FAILDE);
	return (SUCCESS);
}
