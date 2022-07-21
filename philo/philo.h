/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:43:04 by hameur            #+#    #+#             */
/*   Updated: 2022/07/21 15:42:02 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

#define	PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <stdlib.h>

#define FAILDE 1
#define SUCCESS 0

typedef	struct t_args
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
	long long time;
}	t_args;

typedef struct t_philo
{
	t_args *args;
	pthread_t th;
	pthread_mutex_t lock;
	pthread_mutex_t *forks;
	int n_eating;
	int	index;
	struct t_philo *next;
	struct t_philo *previous;
}	t_philo;


//________read_arguments_______//
void args_err(int i);
long	ft_atoi(char *str);
int	read_args(t_args **args, char **av, int ac);

//_______doubly_linked_List_____//
t_philo *new_node(t_philo *node, int index, t_args *args)
void add_front(t_philo **philos, t_philo *philo);
void add_back(t_philo **philos, t_philo *philo);

//_________Creat_Philosophers___________//
int inistialize_philos(t_philo**philos, char **av, int ac);
int creat_threads(t_philo **philos);

#endif