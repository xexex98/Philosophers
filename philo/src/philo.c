/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/03/02 18:58:28 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	ft_dead(t_p	*philos)
{
	while (philos->all->f && philos->pe != philos->all->pme)
	{
		usleep(100);
		pthread_mutex_lock(&philos->all->dead);
		if (philos->all->ttd < ft_time() - philos->lm)
		{
			ft_printf(philos->all, ft_timestamp(philos), philos->pid, DIED);
			philos->all->f = TIME_TO_DIE;
		}
		pthread_mutex_unlock(&philos->all->dead);
	}
}

void	ft_meal(t_p	*philos)
{
	philos->lm = ft_time();
	pthread_create(&philos->death, NULL, (void *)ft_dead, philos);
	ft_printf(philos->all, ft_timestamp(philos), philos->pid, THINK);
	while (philos->all->f == 1 && philos->pe != philos->all->pme)
	{
		pthread_mutex_lock(&philos->all->forks[philos->lf]);
		ft_printf(philos->all, ft_timestamp(philos), philos->pid, FORK);
		if (philos->all->nop == 1)
			break ;
		pthread_mutex_lock(&philos->all->forks[philos->rf]);
		ft_printf(philos->all, ft_timestamp(philos), philos->pid, FORK);
		ft_printf(philos->all, ft_timestamp(philos), philos->pid, EAT);
		philos->pe++;
		philos->lm = ft_time();
		ft_usleep(philos->all->tte);
		pthread_mutex_unlock(&philos->all->forks[philos->lf]);
		pthread_mutex_unlock(&philos->all->forks[philos->rf]);
		ft_printf(philos->all, ft_timestamp(philos), philos->pid, SLEEP);
		ft_usleep(philos->all->tts);
		ft_printf(philos->all, ft_timestamp(philos), philos->pid, THINK);
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
	if (ft_argv_is_num(argc, argv) < 0)
		return (-1);
	if (ft_init_all(&all, argv) < 0)
		return (-1);
	philos = malloc(sizeof(*philos) * all.nop);
	if (!philos)
	{
		ft_free(philos, &all, 0);
		return (ft_error(2));
	}
	create_philos(philos, &all);
	ft_philo_is_thread(&all, philos);
	ft_free(philos, &all, 1);
	return (0);
}
