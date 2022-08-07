/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:06:47 by hameur            #+#    #+#             */
/*   Updated: 2022/08/07 15:19:52 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long long time)
{
	long long	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

int	manager(t_philo *philos)
{
	t_philo	*ptr;
	int		global_key;

	global_key = 0;
	ptr = philos;
	ft_usleep((philos->args->t_die / 2) * 1000);
	while (1)
	{
		if (ptr->key == 1)
			global_key++;
		if (global_key == ptr->args->n_philo)
			break ;
		if (ptr->key == 0 && get_time() - ptr->time > ptr->args->t_die * 1000)
		{
			ft_print(ptr, -1);
			return (FAILDE);
		}
		ptr = ptr->next;
	}
	usleep(ptr->args->t_die * 1000);
	return (SUCCESS);
}

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	list_philos(t_philo **philos, int n_philos, t_args *args)
{
	t_philo	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	while (i < n_philos)
		add_front(philos, new_node(ptr, i++, args));
	return (SUCCESS);
}

int	inistialize_philos(t_philo**philos, char **av, int ac)
{
	t_args	*args;

	args = NULL;
	if (read_args(&args, av, ac) != SUCCESS)
		return (printf("error arguments\n"), FAILDE);
	if (list_philos(philos, args->n_philo, args) != SUCCESS)
		return (free_philos(*philos, 0), FAILDE);
	return (SUCCESS);
}
