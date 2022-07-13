/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:52 by hameur            #+#    #+#             */
/*   Updated: 2022/07/13 11:58:13 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void args_err(int i)
{
	if (i == 1)
		printf("error f les arguments\n");
}

int	ft_atoi(char *str)
{
	int	resultat;
	int	signe;
	int	i;

	resultat = 0;
	signe = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == ' '))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			signe = -signe;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		resultat = (resultat * 10) + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}

int	check_args(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i] != NULL)
	{
		while (av[i][j] != 0 && av[i][j] >= '0' && av[i][j] <= '9')
			j++;
		if (av[i][j] != 0)
			return (1);
		i++;
	}
	return (0);
}

int	read_args(t_philo *philos, char **av, int ac)
{
	if (check_args(av) != 0)
		return (1);
	philos->n_philo = ft_atoi(av[1]);
	philos->t_die = ft_atoi(av[2]);
	philos->t_eat = ft_atoi(av[3]);
	philos->t_sleep = ft_atoi(av[4]);
	philos->n_eat = -1;
	if (ac == 6)
		philos->n_eat = ft_atoi(av[5]);
	return (0);
}