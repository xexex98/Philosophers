/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarra <mbarra@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:50:05 by mbarra            #+#    #+#             */
/*   Updated: 2022/01/31 20:53:48 by mbarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	ft_atoi(const char *nptr)
{
	long	minus;
	long	i;
	long	num;

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

void	ft_error(int err)
{
	if (err == 1)
		printf("Run as: NOP, TTD(ms), TTE(ms), TTS(ms), PME(optional)\n");
	exit(0);
}

void	ft_init_t_p(t_p *p, char **argv)
{
	p->nop = ft_atoi(argv[1]);
	p->ttd = ft_atoi(argv[2]);
	p->tte = ft_atoi(argv[3]);
	p->tts = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		p->pme = ft_atoi(argv[5]);
	else
		p->pme = 0;
}

int main(int argc, char **argv)
{
	t_p p;

	if (argc > 6)
		ft_error(1);
	ft_init_t_p(&p, argv);
	// ft_parce(&p);
	printf ("%d\n", p.pme);
	return (0);
}
