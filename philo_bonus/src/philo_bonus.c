/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/03/02 19:56:28 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_init_all(t_all *all, char **argv)
{
	all->nop = ft_atoi(argv[1]);
	all->ttd = ft_atoi(argv[2]);
	all->tte = ft_atoi(argv[3]);
	all->tts = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		all->pme = ft_atoi(argv[5]);
	else
		all->pme = -1;
	all->f = 0;
	all->stop = 0;
	all->pe = 0;
	all->f_philo = malloc(sizeof(pid_t) * all->nop);
	if (!all->f_philo)
		ft_error(2);
	sem_unlink(SEM_FORKS);
	all->forks = sem_open(SEM_FORKS, O_CREAT, 0644, all->nop);
	sem_unlink(SEM_PRINT);
	all->print = sem_open(SEM_PRINT, O_CREAT, 0644, 1);
	if (all->forks == SEM_FAILED || all->print == SEM_FAILED)
		ft_error(4);
}

void	ft_dead(t_all *all)
{
	while (1)
	{
		usleep(100);
		if (ft_time() - all->lm > all->ttd)
		{
			all->f = TIME_TO_DIE;
			sem_wait(all->print);
			printf("%lli %i %s\n", ft_time() - all->start, all->pid, DIED);
			all->stop = TIME_TO_DIE;
			break ;
		}
		if (all->pme != -1 && all->pe >= all->pme)
		{
			all->stop = TIME_TO_DIE;
			break ;
		}
	}
	if (all->f)
		exit(1);
	else
		exit(0);
}

void	ft_meal(t_all	*all)
{
	pthread_create(&all->death, NULL, (void *)ft_dead, all);
	while (1)
	{
		ft_printf(all, all->pid, THINK);
		sem_wait(all->forks);
		ft_printf(all, all->pid, FORK);
		sem_wait(all->forks);
		ft_printf(all, all->pid, FORK);
		ft_printf(all, all->pid, EAT);
		ft_usleep(all, all->tte);
		all->lm = ft_time();
		sem_post(all->forks);
		sem_post(all->forks);
		all->pe += 1;
		ft_printf(all, all->pid, SLEEP);
		ft_usleep(all, all->tts);
	}
	pthread_join(all->death, NULL);
}

void	ft_philo_is_thread(t_all *all)
{
	int	i;

	i = -1;
	all->start = ft_time();
	while (++i < all->nop)
	{
		all->f_philo[i] = fork();
		if (all->f_philo[i] == -1)
			ft_error(5);
		if (all->f_philo[i] == 0)
		{
			all->pid = i + 1;
			all->lm = ft_time();
			ft_meal(all);
		}
	}
	ft_exit(all);
}

int	main(int argc, char **argv)
{
	t_all	all;

	memset(&all, 0, sizeof(t_all));
	ft_argv_is_num(argc, argv);
	ft_init_all(&all, argv);
	ft_philo_is_thread(&all);
	return (EXIT_SUCCESS);
}
