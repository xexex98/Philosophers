/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/03/02 20:05:59 by mbarra           ###   ########.fr       */
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

# define START "Run as: NOP[max 200], TTD(ms)[min 60], TTE(ms)[min 60],\
	TTS(ms)[min 60], PME(optional)[min 1]\n"
# define FORK "\e[33mhas taken a fork\e[0m"
# define EAT "\e[32mis eating\e[0m"
# define SLEEP "\e[35mis sleeping\e[0m"
# define THINK "\e[34mis thinking\e[0m"
# define DIED "\e[31mis died\e[0m"
# define TIME_TO_DIE 0

typedef struct s_all
{
	int				nop;
	int				ttd;
	int				tts;
	int				tte;
	int				pme;
	long long		start;
	int				f;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	dead;
}				t_all;

typedef struct s_p
{
	int				pe;
	int				pid;
	int				lf;
	int				rf;
	pthread_t		tid;
	pthread_t		death;
	t_all			*all;
	long long		lm;
}				t_p;

long		ft_atoi(const char *nptr);
int			ft_argv_is_num(int argc, char	**argv);
int			ft_error(int err);

int			ft_init_all(t_all *all, char **argv);
int			create_philos(t_p *philos, t_all *all);

long long	ft_time(void);
long long	ft_timestamp(t_p *philos);
void		ft_printf(t_all *all, long long time, int pid, char *str);
void		ft_usleep(long long argv);
void		ft_free(t_p *philos, t_all *all, int flag);

void		ft_dead(t_p	*philos);
void		ft_meal(t_p	*philos);
int			ft_philo_is_thread(t_all *all, t_p *philos);

#endif