/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:49:38 by yogun             #+#    #+#             */
/*   Updated: 2022/09/17 15:59:21 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// This function make necessary checks for the given arguments.
// If there is no negative numbers, it converts them to integer in first if condition.
// Second if checks whether the optional argument is given and positive.
// Third if checks if second parameter(time to die) is zero. If so, philosopher will die right away.
// Last if checks if there is only 1 philosopher. In this condition he will also die right away since
// there isn't enough fork on the table.
int	ft_check(int argc, char **argv)
{
	if (ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0
		|| ft_atoi(argv[1]) < 0)
	{
		printf("Wrong input parameters!\n");
		return (0);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
		return (0);
	if (ft_atoi(argv[1]) > 0 && ft_atoi(argv[2]) == 0)
	{
		printf("0ms 1 died!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0ms 1 has taken a fork\n");
		printf("%ims 1 died!\n", ft_atoi(argv[2]));
		return (0);
	}
	return (ft_atoi(argv[1]));
}

	// Bu fonksiyonun içindeki döngüde saat yönünde tek tek filozoflar dönülüyor. Ve her birisinin çatal atamaları yapılıyor. Sağ ve sol çatallar hayali olarak tanıtılıyor. Aynı zamanda bazı veriler initialize ediliyor.
int	ft_initialize_sub2(int argc, char **argv, t_data *data)
{
	t_data			*tmp;
	t_data			*tmp2;

	tmp2 = data;
	// bu döngüde saat yönünde tek tek filozoflar dönülüyor. Ve her birisinin çatal atamaları yapılıyor.
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

// create fork right as much as philo number create data set as the number of philosopher
int	ft_initialize_sub(t_data *data, int k, int *die)
{
	t_data				*tmp;
	int					i;

	i = 0;
	while (k > i++)
	{
		data->tot_ph = k;
		data->die = die;
		data->phn = i;
		data->next = NULL;
		data->fork_r = malloc(sizeof(pthread_mutex_t) * 1);
	// filozof sayısı kadar mutex başlatılıyor , fork_r için
		if (!data->fork_r || pthread_mutex_init(data->fork_r, 0))
			return (1);
		if (k == i)
			break ;
		tmp = malloc(sizeof(t_data) * 1);
		if (!tmp)
			return (1);
		data->next = tmp;
		data = tmp;
	}
	return (0);
}

// Here created two mutexes.
int	ft_initialize_sub3(t_data *data)
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

// this function is a main function where I call three other functions from above.
t_data	*ft_initialize(int argc, char **argv, int *die)
{
	int		k;
	t_data	*data;

	k = ft_check(argc, argv);
	if (k < 1)
		return (NULL);
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	if (ft_initialize_sub(data, k, die))
	{
		ft_free(data);
		return (NULL);
	}
	if (ft_initialize_sub2(argc, argv, data))
	{
		ft_free(data);
		return (NULL);
	}
	if (ft_initialize_sub3(data))
	{
		ft_free(data);
		return (NULL);
	}
	return (data);
}
