/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/08 17:33:53 by mbarra           ###   ########.fr       */
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
	int				lf;
	int				rf;
	long long		lm;
	pthread_t		tid;
}				t_p;
// у тебя тут 5 не забудь при запуске
typedef struct s_all
{
	pthread_mutex_t	*forks;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				pme;
	int				f;
	long long		start;
	long long		timestamp;
	t_p				*philos;
}				t_all;

int			ft_error(int err);
long		ft_atoi(const char *nptr);
int			ft_argv_is_num(char	**argv);
int			create_philos(t_all	*all);
void		ft_init_all(t_all *all, char **argv);
void		ft_init_p(t_p	*p);
long long	ft_time(void);
void		*philo(void *arg);
void		ft_philo_is_thread(t_all *all);
long long	ft_timestamp(t_all *all);
void	ft_eat(t_p *philos);
void	ft_sleep(int philosophernum, t_all *all);
void	ft_think(int philosophernum, t_all *all);

#endif