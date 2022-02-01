/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/02/01 20:57:52 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	ft_atoi(const char *nptr)
{
	long	minus;
	long	i;
	long	num;


	if (nptr == NULL)
		return (0); //exit (0);

	i = 0;
	minus = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + nptr[i++] - '0';
	if (num < 0)
	{
		if (minus == 1)
			return (-1);
		else if (minus == -1)
			return (0);
	}
	return (num * minus);
}


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

typedef struct s_p
{
	int		left_fork;
	int		right_fork;
}				t_p;


typedef struct s_all
{
	int		nop;
	int		ttd;
	int		tte;
	int		tts;
	int		pme;

	t_p		**philos;
}				t_all;




void	ft_error(int err)
{
	if (err == 1)
		printf("Run as: NOP, TTD(ms), TTE(ms), TTS(ms), PME(optional)\n");
	if (err == 2)
		printf("Malloc error!\n");
	exit(0);
}


void	ft_init_all(t_all *all, char **argv)
{
	all->nop = ft_atoi(argv[1]);
	all->ttd = ft_atoi(argv[2]);
	all->tte = ft_atoi(argv[3]);
	all->tts = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		all->pme = ft_atoi(argv[5]);
	else
		all->pme = 0;
}



void	create_philos(t_all	*all)
{
	t_p		*p;
	int		i;

	i = -1;
	all->philos = (t_p **)malloc(sizeof(t_p));
	p = (t_p *)malloc(sizeof(t_p));
	if (p == NULL || all->philos == NULL)
		ft_error(2);
	while (++i < all->nop)
	{
		
	}
	
}

int main(int argc, char **argv)
{
	// pthread_t	tid;
	t_all	all;



	if (argc < 5 || argc > 6)
		ft_error(1);

	ft_init_all(&all, argv);

	int i = 0;
	while (i < 5)
	{
		all.philos[i] = p;
		i++;
	}

	printf("%d\n", all.philos[1]->left_fork);
	// printf("%d\n", all->philos[0]->ttd);

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
