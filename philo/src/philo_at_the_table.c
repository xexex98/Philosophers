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

int	ft_forks_in_hand(t_p *philos)
{
	int	check;

	check = pthread_mutex_lock(&philos->all->forks[philos->lf]);
	if (check != 0)
		return (ft_error(9));
	check = ft_printf(philos->all, ft_timestamp(philos->all),
			philos->pid, FORK);
	if (check != 0)
		return (ft_error(11));
	check = pthread_mutex_lock(&philos->all->forks[philos->rf]);
	if (check != 0)
		return (ft_error(10));
	check = ft_printf(philos->all, ft_timestamp(philos->all),
			philos->pid, FORK);
	if (check != 0)
		return (ft_error(11));
	return (0);
}

int	ft_eat(t_p *philos)
{
	int	check;

	check = ft_forks_in_hand(philos);
	if (check != 0)
		return (ft_error(12));
	check = pthread_mutex_lock(&philos->eating);
	if (check != 0)
		return (ft_error(13));
	check = ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, EAT);
	if (check != 0)
		return (ft_error(11));
	philos->lm = ft_time();
	philos->pe++;
	usleep(philos->all->tte * 1000 - 16000);
	while (philos->all->tte > ft_time() - philos->lm)
		continue ;
	check = pthread_mutex_unlock(&philos->eating);
	if (check != 0)
		return (ft_error(14));
	check = ft_forks_on_the_table(philos);
	if (check != 0)
		return (ft_error(15));
	return (0);
}

int	ft_forks_on_the_table(t_p *philos)
{
	int	check;

	check = pthread_mutex_unlock(&philos->all->forks[philos->lf]);
	if (check != 0)
		return (ft_error(16));
	check = pthread_mutex_unlock(&philos->all->forks[philos->rf]);
	if (check != 0)
		return (ft_error(17));
	return (0);
}

int	ft_sleep(t_p *philos)
{
	long long	start_sleep;
	int			check;

	check = ft_printf(philos->all, ft_timestamp(philos->all),
			philos->pid, SLEEP);
	if (check != 0)
		return (ft_error(11));
	start_sleep = ft_time();
	usleep(philos->all->tts * 1000 - 16000);
	while (philos->all->tts > ft_time() - start_sleep)
		continue ;
	return (0);
}

int	ft_think(t_p *philos)
{
	int	check;

	check = ft_printf(philos->all, ft_timestamp(philos->all),
			philos->pid, THINK);
	if (check != 0)
		return (ft_error(11));
	return (0);
}
