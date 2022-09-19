/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 22:49:38 by yogun             #+#    #+#             */
/*   Updated: 2022/09/19 18:49:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	This function make necessary checks for the given arguments.
	If there is no negative numbers, it converts them to integer in first 
	if condition. Second if checks whether the optional argument is given
	and positive. Third if checks if second parameter(time to did_die) is zero. 
	If so, philosopher will did_die right away. Last if checks if there is 
	only 1 philosopher. In this condition he will also did_die right away since
	there isn't enough fork on the table.
*/
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
		printf("0ms 1 did_died!\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0ms 1 has taken a fork\n");
		printf("%ims 1 did_died!\n", ft_atoi(argv[2]));
		return (0);
	}
	return (ft_atoi(argv[1]));
}

/*	
	In this function, one while loop has been used to loop thorough philosophers
	and tell introduce them leftFork. The methos of introducing them is;
	the philosopher who sits next to you has a fork on his left hand side and
	this fork will be your leftFork. This while loop turn around the table kind of
	like clockwise. Besides of that some values has been initialized
	while looping thorough philosophers.
*/
int	ft_initialize_sub2(int argc, char **argv, t_phi_data *data)
{
	t_phi_data			*tmp;
	t_phi_data			*tmp2;

	tmp2 = data;
	while (tmp2)
	{
		tmp = tmp2->next;
		tmp2->die_time = ft_atoi(argv[2]);
		tmp2->eat_time = ft_atoi(argv[3]);
		tmp2->sleep_time = ft_atoi(argv[4]);
		tmp2->must_eat = 0;
		if (argc == 6)
			tmp2->must_eat = ft_atoi(argv[5]);
		if (tmp == NULL)
			tmp2->fork_l = data->fork_r;
		else
			tmp2->fork_l = tmp->fork_r;
		tmp2 = tmp2->next;
	}
	return (0);
}

/*
	This function creates rightFork as much as the philosopher number. 
	The rightFork has been created as a mutex since it will be a shared
	resource. Besides of that some values has been initialized
	while looping thorough philosophers.
*/
int	ft_initialize_sub(t_phi_data *data, int k, int *did_die)
{
	t_phi_data				*tmp;
	int						i;

	i = 0;
	while (k > i++)
	{
		data->total_philo = k;
		data->did_die = did_die;
		data->index = i;
		data->next = NULL;
		data->fork_r = malloc(sizeof(pthread_mutex_t) * 1);
		if (!data->fork_r || pthread_mutex_init(data->fork_r, 0))
			return (1);
		if (k == i)
			break ;
		tmp = malloc(sizeof(t_phi_data) * 1);
		if (!tmp)
			return (1);
		data->next = tmp;
		data = tmp;
	}
	return (0);
}

/* 
	In this function, two mutex have been created.
	One is for tmp pointer to carry the funeral pointer
	to the next node. On the other hand, funeral pointer
	points the funeral mutex. It is created as mutex because
	it will be shared in between philosophers. Philosophers
	use it stop the program and tell the others that there
	is going to be a funeral and stop working. Without him
	there would be a data race and some messages still would
	be printed out to the terminal after somebody died.
*/
int	ft_initialize_sub3(t_phi_data *data)
{
	pthread_mutex_t		*funeral;
	pthread_mutex_t		*tmp;

	funeral = malloc(sizeof(pthread_mutex_t) * 1);
	if (!funeral || pthread_mutex_init(funeral, 0))
		return (1);
	tmp = malloc(sizeof(pthread_mutex_t) * 1);
	if (!tmp || pthread_mutex_init(tmp, 0))
		return (1);
	while (data)
	{
		data->done_eat = tmp;
		data->funeral = funeral;
		data = data->next;
	}
	return (0);
}

/*
	This function is a main function where I call three other 
	functions from above. The reason of that is to follow dictated
	42 norms.
*/
t_phi_data	*ft_start(int argc, char **argv, int *did_die)
{
	int			k;
	t_phi_data	*data;

	k = ft_check(argc, argv);
	if (k < 1)
		return (NULL);
	data = malloc(sizeof(t_phi_data) * 1);
	if (!data)
		return (NULL);
	if (ft_initialize_sub(data, k, did_die))
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
