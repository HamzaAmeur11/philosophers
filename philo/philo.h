/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:43:04 by hameur            #+#    #+#             */
/*   Updated: 2022/07/13 11:58:35 by hameur           ###   ########.fr       */
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

typedef	struct s_philo
{
	int	n_philo;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	n_eat;
}	t_philo;



//________read_arguments_______//
void args_err(int i);
int	ft_atoi(char *str);
int	read_args(t_philo *philos, char **av, int ac);

#endif