/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:15:44 by hameur            #+#    #+#             */
/*   Updated: 2022/07/16 19:27:06 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("error args\n"), FAILDE);
	t_philo *philos;
	if (inistialize_philos(&philos, av, ac) != 0)
		return (FAILDE);
	//________tal hna kolxi nadi________//
	
	
}