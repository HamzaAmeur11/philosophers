/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:06:47 by hameur            #+#    #+#             */
/*   Updated: 2022/07/26 00:39:29 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philos)
{
	t_philo *ptr;

	ptr = philos;
	while (ptr->index != ptr->args->n_philo)
	{
		pthread_mutex_destroy(&ptr->fork);
		ptr = ptr->next;
	}
	pthread_mutex_destroy(&ptr->fork);
	pthread_mutex_destroy(&philos->args->print);

}

void	free_philos(t_philo *philos, int x)
{
	t_philo	*ptr;
	int		i;

	ptr = philos;
	i = 0;
	if (x == 1)
		destroy_mutex(philos);
	while (1)
	{
		if (i == ptr->args->n_philo - 1)
		{
			free(ptr->args);
			free(ptr);
			return ;
		}
		philos = philos->next;
		free(ptr);
		ptr = philos;
		i++;
	}
}

int	list_philos(t_philo **philos, int n_philos, t_args *args)
{
	t_philo	*ptr;
	int		i;

	if (n_philos < 2)
		return (FAILDE);
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
		return (printf("error value of number of philosophers\n") \
			,free_philos(*philos, 0), FAILDE);
	return (SUCCESS);
}
