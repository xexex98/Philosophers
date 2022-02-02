/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/02 16:09:47 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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

// External functs:
// memset, 
// printf, 
// malloc, 
// free, 
// write,

// usleep, 
// gettimeofday, 

// pthread_create,
// pthread_detach, 
// pthread_join, 
// pthread_mutex_init,
// pthread_mutex_destroy,

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
}

void ft_init_p(t_p	*p)
{
	p->left_fork = 3;
	p->right_fork = 0;

}

int	create_philos(t_all	*all)
{
	t_p		*p;
	int		i;

	all->philos = (t_p **)malloc(sizeof(t_p) * all->nop);
	p = (t_p *)malloc(sizeof(t_p));
	if (!p || !all->philos)
		return (-1);
	ft_init_p(p);
	i = -1;
	while (++i < all->nop)
		all->philos[i] = p;
	free(p);
	return (0);
}

int main(int argc, char **argv)
{
	// pthread_t	tid;
	t_all	all;

	if (argc < 5 || argc > 6)
		return (ft_error(1));
	if (ft_argv_is_num(argv) < 0)
		return (ft_error(3));
	ft_init_all(&all, argv);
	if (create_philos(&all) < 0)
		return (ft_error(2));

	// int i = 3;
	// printf ("%i", i);


	// for (int i = 0; i < 0; i++)
	// printf("%d\n", all.pme);

	// printf("%d\n", all.philos[3]->left_fork);

	// pthread_create(&tid1, NULL, potok, argv[1]);
	// pthread_create(&tid2, NULL, potok2, argv[2]);

	// pthread_join(tid1, NULL);
	// pthread_join(tid2, NULL);


	// if (argc > 6)
	// 	ft_error(1);
	// // ft_parce(&p);
	// printf ("%d\n", p.pme);
	return (0);
}
