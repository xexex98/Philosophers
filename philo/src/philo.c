/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/13 01:35:13 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_dead(t_p	*philos)
{
	while (philos->all->f && philos->pe != philos->all->pme && philos->all->ttd)
	{
		pthread_mutex_lock(&philos->all->dead);
		if (philos->all->ttd < (ft_time() - philos->lm) && philos->all->f)
		{
			ft_printf(philos->all, ft_timestamp(philos),
				philos->pid, DIED);
			philos->all->f = TIME_TO_DIE;
		}
		pthread_mutex_unlock(&philos->all->dead);
		usleep(100);
	}
}

void	ft_forks_in_hand(t_p *philos)
{
	pthread_mutex_lock(&philos->all->forks[philos->lf]);
	ft_printf(philos->all, ft_timestamp(philos),
			philos->pid, FORK);
	pthread_mutex_lock(&philos->all->forks[philos->rf]);
	ft_printf(philos->all, ft_timestamp(philos),
			philos->pid, FORK);
}

void	ft_eat(t_p *philos)
{
	ft_forks_in_hand(philos);
	ft_printf(philos->all, ft_timestamp(philos), philos->pid, EAT);
	philos->pe++;
	philos->lm = ft_time();
	usleep(philos->all->tte * 1000 - 10000);
	// while (philos->all->tte > ft_time() - philos->lm)
	// 	continue ;
	ft_forks_on_the_table(philos);
}

void	ft_forks_on_the_table(t_p *philos)
{
	pthread_mutex_unlock(&philos->all->forks[philos->lf]);
	pthread_mutex_unlock(&philos->all->forks[philos->rf]);
}

void	ft_sleep(t_p *philos)
{
	// long long	start_sleep;

	ft_printf(philos->all, ft_timestamp(philos),
			philos->pid, SLEEP);
	usleep(philos->all->tts * 1000 - 10000);
	// start_sleep = ft_time();
	// while (philos->all->tts > ft_time() - start_sleep)
	// 	continue ;
}

void	ft_think(t_p *philos)
{
	ft_printf(philos->all, ft_timestamp(philos),
			philos->pid, THINK);
}


void	ft_meal(t_p	*philos)
{
	philos->lm = ft_time();
	pthread_create(&philos->death, NULL, (void *)ft_dead, philos);
	while (philos->all->f == 1 && philos->pe != philos->all->pme && philos->all->f)
	{
		ft_eat(philos);
		// if (philos->pe == philos->all->pme)
		// 	break ;
		ft_sleep(philos);
		ft_think(philos);
	}
	pthread_join(philos->death, NULL);
}

int	ft_philo_is_thread(t_all *all, t_p *philos)
{
	int	i;

	i = -1;
	while (++i < all->nop)
	{
		philos->all->start = ft_time();
		usleep(100);
		pthread_create(&philos[i].tid, NULL, (void *)ft_meal, &philos[i]);
	}
	i = -1;
	while (++i < all->nop)
		pthread_join(philos[i].tid, NULL);
	return (0);
}

int	main(int argc, char **argv)
{
	t_p		*philos;
	t_all	all;

	philos = NULL;
	if (argc < 5 || argc > 6)
		return (ft_error(1));
	if (ft_argv_is_num(argv) < 0)
		return (ft_error(3));
	ft_init_all(&all, argv);
	philos = malloc(sizeof(*philos) * all.nop);
	create_philos(philos, &all);
	ft_philo_is_thread(&all, philos);
	free(philos);
	free(philos->all->forks);
	return (0);
}
