/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:29:58 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/24 16:44:16 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	ft_error(int err)
{
	if (err == 1)
		printf("Run as: NOP, TTD(ms), TTE(ms), TTS(ms), PME(optional)\n");
	else if (err == 2)
		printf("Malloc error!\n");
	else if (err == 3)
		printf("Incorrect args!\n");
	else if (err == 4)
		printf("Semaphore init error!\n");
	else if (err == 5)
		printf("Fork error!\n");
	exit(EXIT_FAILURE);
}

long long	ft_time(void)
{
	struct timeval	time;
	long long		millisec;

	gettimeofday(&time, NULL);
	millisec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (millisec);
}

long long	ft_timestamp(t_p *philos)
{
	return (ft_time() - philos->all->start);
}

void	ft_printf(t_all *all, long long time, int pid, char *str)
{
	sem_wait(all->print);
	if (all->f)
		printf("%lli %i %s\n", time, pid, str);
	sem_post(all->print);
}

void	ft_usleep(long long argv)
{
	long long	time;

	time = ft_time();
	while (argv > ft_time() - time)
		usleep(100);
}

void	ft_free(t_p *philos, t_all *all, int flag)
{
	int	i;

	i = -1;

	// free(philos->all->forks);
	// free(philos);
}
