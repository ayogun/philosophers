/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:26:43 by yogun             #+#    #+#             */
/*   Updated: 2022/09/18 10:15:16 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_eat(t_data *data)
{
	if (*data->die)
		return ;
	pthread_mutex_lock(data->fork_r);
	ft_printf("\033[1;30mhas taken a fork\033[0m 🍴(from his right side)", data);
	if (*data->die)
	{
		pthread_mutex_unlock(data->fork_r);
		return ;
	}
	pthread_mutex_lock(data->fork_l);
	ft_printf("\033[1;30mhas taken a fork\033[0m 🍴(from his left side)", data);
	if (gettimeofday(data->last_eat, 0))
		return ;
	if (*data->die)
	{
		pthread_mutex_unlock(data->fork_l);
		pthread_mutex_unlock(data->fork_r);
		return ;
	}
	ft_printf("\033[0;32mis eating\033[0m 🍔", data);
	ft_sleep(data->eatTime);
	pthread_mutex_unlock(data->fork_l);
	pthread_mutex_unlock(data->fork_r);
}

void	ft_musteat(t_data *data)
{
	while (data->mustEat)
	{
		ft_eat(data);
		if (*data->die)
			return ;
		data->mustEat--;
		if (data->mustEat == 0)
		{
			pthread_mutex_lock(data->done_eat);
			*data->done += 1;
			pthread_mutex_unlock(data->done_eat);
			return ;
		}
		ft_printf("\033[34;1mis sleeping\033[0m 😴", data);
		ft_sleep(data->sleepTime);
		ft_printf("\033[0;33mis thinking\033[0m 🤔", data);
	}
}

void	ft_eat_forever(t_data *data)
{
	while (*data->die == 0)
	{
		ft_eat(data);
		ft_printf("\033[34;1mis sleeping\033[0m 😴", data);
		if (*data->die)
			return ;
		ft_sleep(data->sleepTime);
		ft_printf("\033[0;33mis thinking\033[0m 🤔", data);
	}
}

void	ft_thread(t_data *data)
{
	if (data->index_philo % 2 != 0)
		usleep(data->eatTime * 100);
	if (data->mustEat)
		ft_musteat(data);
	else
		ft_eat_forever(data);
}

void	ft_thread_create(t_data *data, int	*done)
{
	t_data				*tmp;
	struct timeval		*time1;

	time1 = malloc(sizeof(struct timeval) * 1);
	if (!time1 || gettimeofday(time1, 0) == -1)
		return ;
	tmp = data;
	while (tmp)
	{
		tmp->done = done;
		tmp->time = time1;
		tmp->last_eat = malloc(sizeof(struct timeval) * 1);
		if (!tmp->last_eat || gettimeofday(tmp->last_eat, 0) == -1)
			return ;
		tmp->tid = malloc(sizeof(pthread_t) * 1);
		if (!tmp->tid)
			return ;
		if (pthread_create(tmp->tid, 0, (void *)&ft_thread, (void *)tmp))
			return ;
		tmp = tmp->next;
	}
	ft_die(data);
}