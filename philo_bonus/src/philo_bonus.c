/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/24 18:44:20 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo_bonus.h"

void	ft_dead(t_p	*philos)
{
	while (1)
	{
		sem_wait(philos->all->dead);
		usleep(100);
		if (philos->all->ttd < ft_time() - philos->lm)
		{
			ft_printf(philos->all, ft_timestamp(philos),
				philos->pid, DIED);
			philos->all->f = TIME_TO_DIE;
			exit(EXIT_SUCCESS);
		}
		if (philos->all->pme != -1 && philos->pe >= philos->all->pme)
		{
			philos->all->f = TIME_TO_DIE;
			exit(EXIT_SUCCESS);

		}
		sem_post(philos->all->dead);
	}
}

void	ft_meal(t_p	*philos)
{
	pthread_create(&philos->all->death, NULL, (void *)ft_dead, philos);
	while (1)
	{
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
	}
	pthread_join(philos->all->death, NULL);
}

void	ft_philo_is_thread(t_all *all)
{
	t_p	philos;
	int	i;

	i = -1;
	all->start = ft_time();
	while (++i < all->nop)
	{
		all->f_philo[i] = fork();
		if (all->f_philo[i] == -1)
		{
			while (--i >= 0)
				kill(all->f_philo[i], SIGKILL);
			ft_error(5);
		}
		if (all->f_philo[i] == 0)
		{
			philos.pid = i + 1;
			philos.lm = ft_time();
			philos.pe = 0;
			philos.all = all;
			ft_meal(&philos);
		}
		usleep(100);
	}
}

void ft_exit(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->nop)
		kill(all->f_philo[i], SIGKILL);
}

int	main(int argc, char **argv)
{
	t_all	all;

	ft_argv_is_num(argc, argv);
	ft_init_all(&all, argv);
	ft_philo_is_thread(&all);
	ft_exit(&all);
	return (EXIT_SUCCESS);
}

// ft_free(philos, &all, 1);