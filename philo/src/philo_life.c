/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:25:27 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/12 13:25:27 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
	usleep(philos->all->tte * 1000 - 100);
	ft_forks_on_the_table(philos);
}

void	ft_forks_on_the_table(t_p *philos)
{
	pthread_mutex_unlock(&philos->all->forks[philos->lf]);
	pthread_mutex_unlock(&philos->all->forks[philos->rf]);
}

void	ft_sleep(t_p *philos)
{
	ft_printf(philos->all, ft_timestamp(philos),
		philos->pid, SLEEP);
	usleep(philos->all->tts * 1000 - 100);
}

void	ft_think(t_p *philos)
{
	ft_printf(philos->all, ft_timestamp(philos),
		philos->pid, THINK);
}
