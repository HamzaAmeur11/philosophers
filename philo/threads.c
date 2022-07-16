/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:27:30 by hameur            #+#    #+#             */
/*   Updated: 2022/07/16 19:33:34 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int creat_threads(t_philo **philos)
{
	t_philo *ptr;
	
	ptr = *philos;
	while (ptr->index <= ptr->args->n_philo)
	{
		
		ptr = ptr->next;
	}
}