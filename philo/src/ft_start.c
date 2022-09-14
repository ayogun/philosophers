/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:49:38 by yogun             #+#    #+#             */
/*   Updated: 2022/09/14 12:53:41 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// last two data has been initialized.
int	ft_initialize_sub3(t_info *data)
{
	pthread_mutex_t		*in;
	pthread_mutex_t		*tmp;

	in = malloc(sizeof(pthread_mutex_t) * 1);
	if (!in || pthread_mutex_init(in, 0))
		return (1);
	tmp = malloc(sizeof(pthread_mutex_t) * 1);
	if (!tmp || pthread_mutex_init(tmp, 0))
		return (1);
	while (data)
	{
		data->done_eat = tmp;
		data->in = in;
		data = data->next;
	}
	return (0);
}

	// Bu fonksiyonun içindeki döngüde saat yönünde tek tek filozoflar dönülüyor. Ve her birisinin çatal atamaları yapılıyor. Sağ ve sol çatallar hayali olarak tanıtılıyor.
int	ft_initialize_sub2(int argc, char **argv, t_info *data)
{
	t_info			*tmp;
	t_info			*tmp2;

	tmp2 = data;
	while (tmp2)
	{
		tmp = tmp2->next;
		tmp2->t2d = ft_atoi(argv[2]);
		tmp2->t2e = ft_atoi(argv[3]);
		tmp2->t2s = ft_atoi(argv[4]);
		tmp2->t2em = 0;
		if (argc == 6)
			tmp2->t2em = ft_atoi(argv[5]);
		if (tmp == NULL)
			tmp2->fork_l = data->fork_r;
		else
			tmp2->fork_l = tmp->fork_r;
		tmp2 = tmp2->next;
	}
	return (0);
}

// bu fonksiyon right fork yaratmak için kullanılıyor. Filozof sayısı kadar olması için while döngüsü kullanılıyor.
int	ft_initialize_sub(t_info *data)
{
	t_info				*tmp;
	int					i;

	i = 0;
	while (data->total_philo > i++)
	{
		data->done = 0;
		data->die = 0;
		data->philo_N = i;
		data->next = NULL;
		data->fork_r = malloc(sizeof(pthread_mutex_t) * 1);
		if (!data->fork_r || pthread_mutex_init(data->fork_r, 0))
			return (1);
		if (data->total_philo == i)
			break ;
		tmp = malloc(sizeof(t_info) * 1);
		if (!tmp)
			return (1);
		data->next = tmp;
		data = tmp;
	}
	return (0);
}

t_info *ft_start(int argc, char **argv)
{
		t_info	*info;

		ft_start(argc,argv);
		info = malloc(sizeof(t_info) * 1);
		if (!info)
			return (NULL);
		info->total_philo = ft_check(argc, argv);
		if (info->total_philo < 1)
			return (NULL);
		if (ft_initialize_sub(info))
		{
			free(info);
			return (NULL);
		}
		if (ft_initialize_sub2(argc, argv, info))
		{
			ft_free(info);
			return (NULL);
		}
		if (ft_initialize_sub3(info))
		{
			ft_free(info);
			return (NULL);
		}
		return (info);
}