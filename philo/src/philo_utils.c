/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:29:58 by mbarra            #+#    #+#             */
/*   Updated: 2022/03/02 16:35:10 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long long	ft_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

long long	ft_timestamp(t_p *philos)
{
	return (ft_time() - philos->all->start);
}

void	ft_printf(t_all *all, long long time, int pid, char *str)
{
	pthread_mutex_lock(&all->print);
	if (all->f)
		printf("%lli %i %s\n", time, pid, str);
	pthread_mutex_unlock(&all->print);
}

void	ft_usleep(long long argv)
{
	long long	time;

	time = ft_time();
	while (argv > ft_time() - time)
		usleep(500);
}

void	ft_free(t_p *philos, t_all *all, int flag)
{
	int	i;

	i = -1;
	if (flag == 1)
	{
		pthread_mutex_destroy(&all->print);
		pthread_mutex_destroy(&all->dead);
		while (++i < all->nop)
			pthread_mutex_destroy(&all->forks[i]);
	}
	free(philos->all->forks);
	free(philos);
}
