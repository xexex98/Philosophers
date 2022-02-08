/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/08 17:53:11 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
// memset, 
// usleep, 
// gettimeofday, 
// pthread_create,
// pthread_detach, 
// pthread_join, 
// pthread_mutex_init,
// pthread_mutex_destroy,
// pthread_mutex_lock,
// pthread_mutex_unlock,
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIED "died\n"


pthread_mutex_t	print;
pthread_mutex_t	queue;

void	ft_printf(long long time, int philosophernum, char *str)
{
	pthread_mutex_lock(&print);
	printf("%lli %i %s\n", time, philosophernum, str);
	pthread_mutex_unlock(&print);
}

void	ft_eat(t_p *philos)
{
	t_all	all;
	// printf("lf %i pid %i\n", philo->lf, philo->pid);
	// printf("rf %i pid %i\n", philo->rf, philo->pid);
	all.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all.nop);

	// all->f = -1;
	pthread_mutex_lock(&all.forks[philos->lf]);
	ft_printf(all.philos->pid, philos->lf, "lf");
	pthread_mutex_lock(&all.forks[philos->rf]);
	ft_printf(all.philos->pid, philos->rf, "rf");
	pthread_mutex_unlock(&all.forks[philos->lf]);
	pthread_mutex_unlock(&all.forks[philos->rf]);


	// ft_printf(timsestamp(all), philosophernum, FORK);
	// pthread_mutex_lock(&all->forks[right]);
	// ft_printf(timsestamp(all), philosophernum, FORK);
	// pthread_mutex_lock(&queue);
	// ft_printf(timsestamp(all), philosophernum, EAT);
	// all->philos[philosophernum].lm = ft_time();
	// while (all->tte > timsestamp(all))
	// 	;
	// pthread_mutex_unlock(&queue);
	// pthread_mutex_unlock(&all->forks[left]);
	// pthread_mutex_unlock(&all->forks[right]);
	// if (ft_time() - all->philos[philosophernum].lm < all->ttd)
	// {
	// 	all->f = -1;
	// 	ft_printf(timsestamp(all), philosophernum, DIED);
	// }

}

// void	ft_sleep(int philosophernum, t_all *all)
// {
// 	ft_printf(timsestamp(all), philosophernum, SLEEP);
// 	while (all->tts > ft_time() - all->philos[philosophernum].lm)
// 		;
// 	return	;
// }

// void	ft_think(int philosophernum, t_all *all)
// {
// 	ft_printf(timsestamp(all), philosophernum, THINK);
// 	return ;
// }

void	*philo(void *arg)
{
	t_p	*philos;

	philos = (t_p *)arg;
	int i = 5;
	while (i-- > 0)
	{
		ft_eat(philos);
		// ft_sleep(all);
		// ft_think(all);

	}
	return (NULL);
}

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
	all.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all.nop);
	ft_philo_is_thread(&all);
	return (0);
}
