/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/02 20:30:22 by mbarra           ###   ########.fr       */
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

void	*potok(void *argv)
{
	printf("he\n");
	// pthread_exit(0);
	return NULL;
}

void	*potok2(void *argv)
{
	printf("da\n");
	// pthread_exit(0);
	return NULL;
}

void	*eat(void *all)
{
	// pthread_mutex_lock(&all->philos[0]->left_fork);
	printf("tata\n");
	return NULL;
}

void	*ft_sleep(void *all)
{
	// pthread_mutex_lock(&all->philos[0]->left_fork);
	printf("sleep\n");
	return NULL;
}

void	*ft_dead(void *all)
{
	// pthread_mutex_lock(&all->philos[0]->left_fork);
	printf("dead\n");
	return NULL;
}
void	ft_philo_is_thread(t_all *all)
{
	pthread_t	tid[all->nop];
	int	i;
	i = -1;
	// while (++i < all->nop)
		// pthread_create(&tid[i], NULL, eat, NULL);
	pthread_create(&tid[0], NULL, eat, NULL);
	pthread_create(&tid[1], NULL, ft_sleep, NULL);
	pthread_create(&tid[2], NULL, ft_dead, NULL);

	
	i = -1;
	// while (++i < all->nop)
		// pthread_join(tid[i], NULL);
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);


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
	ft_philo_is_thread(&all);
	
	
	
	// pthread_create(&tid1, NULL, potok, argv[1]);
	// pthread_create(&tid2, NULL, potok2, argv[2]);

	// pthread_join(tid1, NULL);
	// pthread_join(tid2, NULL);
	return (0);
}
