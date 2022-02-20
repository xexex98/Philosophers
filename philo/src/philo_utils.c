/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:29:58 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/20 15:20:27 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_error(int err)
{
	if (err == 1)
		printf("Run as: NOP, TTD(ms), TTE(ms), TTS(ms), PME(optional)\n");
	else if (err == 2)
		printf("Malloc error!\n");
	else if (err == 3)
		printf("Incorrect args!\n");
	return (-1);
}

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

int	ft_printf(t_all *all, long long time, int pid, char *str)
{
	pthread_mutex_lock(&all->print);
	if (all->f)
		printf("%lli %i %s\n", time, pid, str);
	pthread_mutex_unlock(&all->print);
	return (0);
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
