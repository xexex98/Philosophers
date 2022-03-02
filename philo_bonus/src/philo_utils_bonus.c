/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:29:58 by mbarra            #+#    #+#             */
/*   Updated: 2022/03/02 19:54:52 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

int	ft_error(int err)
{
	if (err == 1)
		printf(START);
	else if (err == 2)
		printf("Malloc error!\n");
	else if (err == 3)
		printf("Incorrect args!\n");
	else if (err == 4)
		printf("Semaphore init error!\n");
	else if (err == 5)
		printf("Fork error!\n");
	exit(EXIT_SUCCESS);
}

long long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_printf(t_all *all, int pid, char *str)
{
	sem_wait(all->print);
	if (!all->stop)
		printf("%lli %i %s\n", ft_time() - all->start, pid, str);
	sem_post(all->print);
}

void	ft_usleep(t_all *all, long long argv)
{
	long long	time;

	time = ft_time();
	while (!all->stop)
	{
		if (ft_time() - time >= argv)
			break ;
		usleep(500);
	}
}

void	ft_exit(t_all *all)
{
	int	status;
	int	i;

	status = 0;
	i = -1;
	while (++i < all->nop)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < all->nop)
				kill(all->f_philo[i], SIGKILL);
			break ;
		}
	}	
	sem_close(all->forks);
	sem_close(all->print);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PRINT);
	free(all->f_philo);
}
