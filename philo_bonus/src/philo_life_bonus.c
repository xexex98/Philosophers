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

#include "../inc/philo_bonus.h"

void	ft_forks_in_hand(t_p *philos)
{
	sem_wait(philos->all->forks);
	ft_printf(philos->all, ft_timestamp(philos),
		philos->pid, FORK);
	sem_wait(philos->all->forks);
	ft_printf(philos->all, ft_timestamp(philos),
		philos->pid, FORK);
}

void	ft_eat(t_p *philos)
{
	ft_forks_in_hand(philos);
	ft_printf(philos->all, ft_timestamp(philos), philos->pid, EAT);
	philos->pe++;
	philos->lm = ft_time();
	ft_usleep(philos->all->tte);
	ft_forks_on_the_table(philos);
}

void	ft_forks_on_the_table(t_p *philos)
{
	sem_post(philos->all->forks);
	sem_post(philos->all->forks);
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
