/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:23 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/09 17:44:42 by mbarra           ###   ########.fr       */
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
	pthread_t		death;
	struct s_all	*all;
}				t_p;

typedef struct s_all
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	int				nop;
	int				ttd;
	int				tte;
	int				tts;
	int				pme;
	int				f;
	long long		start;
	t_p				*philos;
}				t_all;

int			ft_error(int err);
long		ft_atoi(const char *nptr);
int			ft_argv_is_num(char	**argv);
int			create_philos(t_all	*all);
void		ft_init_all(t_all *all, char **argv);
void		ft_init_p(t_p	*p);
long long	ft_time(void);
void		*ft_meal(void *arg);
void		ft_philo_is_thread(t_all *all);
long long	ft_timestamp(t_all *all);
void		ft_eat(t_p *philos);
void		ft_sleep(t_p *philos);
void		ft_think(t_p *philos);
void		*ft_dead(void *arg);
void	ft_printf(t_all *all, long long time, int pid, char *str);



// void	ft_printf(t_p *philos, long long time, int pid, char *str);

#endif