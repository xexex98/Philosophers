/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:29:58 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/12 16:32:05 by mbarra           ###   ########.fr       */
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
	else if (err == 4)
		printf("Ptread error!\n");
	else if (err == 6)
		printf("Pthread_mutex_init forks error!\n");
	else if (err == 7)
		printf("Pthread_create all->philos[i].tid error!\n");
	else if (err == 8)
		printf("Pthread_join all->philos[i].death error!\n");
	else if (err == 9)
		printf("Pthread_mutex_lock philos->all->forks[philos->lf] error!\n");
	else if (err == 10)
		printf("Pthread_mutex_lock philos->all->forks[philos->rf] error!\n");
	else if (err == 11)
		printf("ft_printf(..., STATUS) error!\n");
	ft_error_2(err);
	return (-1);
}

int	ft_error_2(int err)
{
	if (err == 12)
		printf("ft_forks_in_hand(philos) error!\n");
	else if (err == 13)
		printf("pthread_mutex_lock(&philos->eating) error!\n");
	else if (err == 14)
		printf("pthread_mutex_unlock(&philos->eating) error!\n");
	else if (err == 15)
		printf("ft_forks_on_the_table(philos) error!\n");
	else if (err == 16)
		printf("pthread_mutex_unlock(&philos->all->forks[philos->lf]) error!\n");
	else if (err == 17)
		printf("pthread_mutex_unlock(&philos->all->forks[philos->rf]) error!\n");
	return (-1);
}

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	ft_timestamp(t_all *all)
{
	return (ft_time() - all->start);
}
