/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/03/01 21:23:58 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define START "Run as: NOP[max 200], TTD(ms)[min 60], TTE(ms)[min 60],\
	TTS(ms)[min 60], PME(optional)[min 1]\n"
# define FORK "\e[33mhas taken a fork\e[0m"
# define EAT "\e[32mis eating\e[0m"
# define SLEEP "\e[35mis sleeping\e[0m"
# define THINK "\e[34mis thinking\e[0m"
# define DIED "\e[31mis died\e[0m"
# define TIME_TO_DIE 1

# define SEM_PHILOS "/philos"
# define SEM_FORKS "/fork"
# define SEM_PRINT "/print"
# define SEM_DEAD "/dead"

typedef struct s_all
{
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				pe;
	int				pme;
	int				stop;
	int				f;
	pid_t			*f_philo;
	sem_t			*forks;
	sem_t			*print;
	long long		start;
	int				pid;
	long long		lm;
	pthread_t		death;

}				t_all;

long		ft_atoi(const char *nptr);
int			ft_argv_is_num(int argc, char	**argv);

void		ft_init_all(t_all *all, char **argv);
void		ft_dead(t_all *all);
void		ft_meal(t_all *all);
void		ft_philo_is_thread(t_all *all);

int			ft_error(int err);
long long	ft_time(void);
void		ft_printf(t_all *all, int pid, char *str);
void		ft_usleep(t_all *all, long long argv);
void		ft_exit(t_all *all);

#endif