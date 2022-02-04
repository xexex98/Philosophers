/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/04 12:30:19 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_p
{
	int				pid;
	pthread_t		tid;
}				t_p;

typedef struct s_all
{
	pthread_mutex_t	forks[5];
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				pme;

	t_p				*philos;
}				t_all;

int		ft_error(int err);
long	ft_atoi(const char *nptr);
int		ft_argv_is_num(char	**argv);
int		create_philos(t_all	*all);
void	ft_init_all(t_all *all, char **argv);
void	ft_init_p(t_p	*p);


#endif