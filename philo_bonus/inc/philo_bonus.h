/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/24 18:32:54 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# include <fcntl.h> /* константы O_* */
# include <sys/stat.h> /* константы для mode */
# include <semaphore.h>
#include <sys/types.h>
#include <signal.h>

# define FORK "\e[33mhas taken a fork\e[0m"
# define EAT "\e[32mis eating\e[0m"
# define SLEEP "\e[35mis sleeping\e[0m"
# define THINK "\e[34mis thinking\e[0m"
# define DIED "\e[31mis died\e[0m"
# define TIME_TO_DIE 0

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
	int				pme;
	long long		start;
	int				f;
	pid_t			*f_philo;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*dead;
	pthread_t		death;

}				t_all;

typedef struct s_p
{
	int				pid;
	long long		lm;
	int				pe;
	t_all			*all;
}				t_p;

long		ft_atoi(const char *nptr);
int			ft_argv_is_num(int argc, char	**argv);

void			ft_init_all(t_all *all, char **argv);

void		ft_forks_in_hand(t_p *philos);
void		ft_eat(t_p *philos);
void		ft_forks_on_the_table(t_p *philos);
void		ft_sleep(t_p *philos);
void		ft_think(t_p *philos);

int			ft_error(int err);
long long	ft_time(void);
long long	ft_timestamp(t_p *philos);
void		ft_printf(t_all *all, long long time, int pid, char *str);
void		ft_free(t_p *philos, t_all *all, int flag);
void		ft_usleep(long long argv);
void 		ft_exit(t_all *all	);

void		ft_dead(t_p	*philos);
void		ft_meal(t_p	*philos);
void		ft_philo_is_thread(t_all *all);

#endif