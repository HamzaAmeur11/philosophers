/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hameur <hameur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:43:04 by hameur            #+#    #+#             */
/*   Updated: 2022/08/05 20:34:22 by hameur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>

# define SUCCESS 0
# define FAILDE 1

typedef struct t_args
{
	int				n_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	long long		time;
	pthread_mutex_t	print;
}	t_args;

typedef struct t_philo
{
	t_args			*args;
	pthread_t		th;
	pthread_mutex_t	fork;
	int				n_eating;
	int				index;
	long long		time;
	int				key;
	struct t_philo	*next;
}	t_philo;

/*________read_arguments_______*/
long		ft_atoi(char *str);
int			read_args(t_args **args, char **av, int ac);

/*_______doubly_linked_List_____*/
t_philo		*new_node(t_philo *node, int index, t_args *args);
void		add_front(t_philo **philos, t_philo *philo);
void		free_philos(t_philo *philos, int x);

/*_________Creat_Philosophers___________*/
int			inistialize_philos(t_philo**philos, char **av, int ac);
int			creat_threads(t_philo **philos);

/*___________OTHER_____________*/
long long	get_time(void);
int			manager(t_philo *philos);
void		destroy_mutex(t_philo *philos);
void		ft_usleep(long long time);
void		ft_print(t_philo *th, int x);

#endif