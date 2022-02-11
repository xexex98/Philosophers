/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/11 19:22:16 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
# define FORK "\e[33mhas taken a fork\e[0m"
# define EAT "\e[32mis eating\e[0m"
# define SLEEP "\e[35mis sleeping\e[0m"
# define THINK "\e[34mis thinking\e[0m"
# define DIED "\e[31mis died\e[0m"
# define TIME_TO_DIE 1


pthread_mutex_t	deadman;


void	ft_forks_in_hand(t_p *philos)
{
	pthread_mutex_lock(&philos->all->forks[philos->lf]);
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, FORK);
	pthread_mutex_lock(&philos->all->forks[philos->rf]);
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, FORK);
	return ;
}

void	ft_forks_on_the_table(t_p *philos)
{
	pthread_mutex_unlock(&philos->all->forks[philos->lf]);
	pthread_mutex_unlock(&philos->all->forks[philos->rf]);
	return ;
}

void	ft_think(t_p *philos)
{
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, THINK);
	return ;
}

void	ft_sleep(t_p *philos)
{
	long long start_sleep;

	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, SLEEP);
	start_sleep = ft_time();
	usleep(philos->all->tts * 1000);
	// while (philos->all->tts > ft_time() - start_sleep)
		// continue;
	return ;
}

void	ft_eat(t_p *philos)
{
	ft_forks_in_hand(philos);
	// pthread_mutex_lock(&philos->eating);
	ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, EAT);
	usleep(philos->all->tte * 1000);
	philos->lm = ft_time();
	// while (philos->all->tte > ft_time() - philos->lm)
	// 	continue;
	// printf("|%lli|\n", philos->lm);
	// pthread_mutex_unlock(&philos->eating);
	ft_forks_on_the_table(philos);
	return ;
}

void	*ft_dead(void *arg)
{
	t_p *philos;

	philos = (t_p *)arg;
	while (philos->all->f != TIME_TO_DIE)
	{
		pthread_mutex_lock(&deadman);
		if (philos->all->ttd < ft_time() - philos->lm)
		{
			ft_printf(philos->all, ft_timestamp(philos->all), philos->pid, DIED);
			philos->all->f = TIME_TO_DIE;
			// break ;
			// exit(0);
		}
		pthread_mutex_unlock(&deadman);
		usleep(100);
	}
	return (NULL);
}

void	*ft_meal(void *arg)
{
	t_p	*philos;

	philos = (t_p *)arg;
	philos->lm = ft_time();
	// pthread_mutex_init(&philos->all->dead, NULL);
	pthread_create(&philos->death, NULL, ft_dead, (void *)philos);
	while (philos->all->f != TIME_TO_DIE)
	{
		ft_eat(philos);
		ft_sleep(philos);
		ft_think(philos);
		usleep(100);
	}
	pthread_join(philos->death, NULL);

	return (NULL);
}

void	ft_philo_is_thread(t_all *all)
{
	int	i;

	i = -1;

	while (++i < all->nop)
		pthread_mutex_init(&all->forks[i], NULL);
	all->start = ft_time();
	i = -1;
	while (++i < all->nop)
	{
		pthread_create(&all->philos[i].tid, NULL, ft_meal, (void *)&all->philos[i]);
		usleep(100);
	}
	i = -1;
	// while (++i < all->nop)
	// {
	// 	pthread_create(&all->philos[i].death, NULL, ft_dead, (void *)&all->philos[i]);
	// 	usleep(100);
	// }
	i = -1;
	while (++i < all->nop)
		pthread_join(all->philos[i].tid, NULL);
	// i = -1;
	// while (++i < all->nop)
	// 	pthread_join(all->philos[i].death, NULL);
	// while (all->f != TIME_TO_DIE)
	// 	;
	return ;

}

// void	ft_wait_threads(t_all *all)
// {
// 	int	i;

// 	i = 0;
// 	while (i < all->nop)
// 	{
// 		pthread_join(all->philos[i].tid, NULL);
// 		i++;
// 	}
// }

int main(int argc, char **argv)
{
	t_all	all;

	if (argc < 5 || argc > 6)
		return (ft_error(1));
	if (ft_argv_is_num(argv) < 0)
		return (ft_error(3));
	ft_init_all(&all, argv);
	if (create_philos(&all) < 0)
		return (ft_error(2));
	ft_philo_is_thread(&all);
	// ft_wait_threads(&all);
	return (0);
}
