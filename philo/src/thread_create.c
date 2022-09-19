/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:26:43 by yogun             #+#    #+#             */
/*   Updated: 2022/09/19 18:49:12 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	This function locks the forkRight and forkLeft mutexes.
	After philosopher picked up both of the forks, he prints out
	eating message and then eats(ft_sleep) as long as it has defined
	by user and used in this program as eat_time.
*/
void	ft_eat(t_phi_data *data)
{
	if (*data->did_die)
		return ;
	pthread_mutex_lock(data->fork_r);
	ft_printf("\033[1;30mhas taken a fork\033[0m 🍴(from his right side)", data);
	if (*data->did_die)
	{
		pthread_mutex_unlock(data->fork_r);
		return ;
	}
	pthread_mutex_lock(data->fork_l);
	ft_printf("\033[1;30mhas taken a fork\033[0m 🍴(from his left side)", data);
	if (gettimeofday(data->last_eat, 0))
		return ;
	if (*data->did_die)
	{
		pthread_mutex_unlock(data->fork_l);
		pthread_mutex_unlock(data->fork_r);
		return ;
	}
	ft_printf("\033[0;32mis eating\033[0m 🍔", data);
	ft_sleep(data->eat_time);
	pthread_mutex_unlock(data->fork_l);
	pthread_mutex_unlock(data->fork_r);
}

/*
	This function works while the must_eat value is greater 
	than zero. Hence, we make sure that each philosopher eats
	as much as must_eat parameters  which is given by user as 
	optional parameter. Whenever this value reaches the zero,
	we lock the done_eat mutex and increase it by one. Done
	vakue is initialized with zero and every philosopher increase
	it only once wheen they are done with eating. In the final moment,
	the done value will be equal to the total number of philosophers.
*/
void	ft_must_eat(t_phi_data *data)
{
	while (data->must_eat)
	{
		ft_eat(data);
		if (*data->did_die)
			return ;
		data->must_eat--;
		if (data->must_eat == 0)
		{
			pthread_mutex_lock(data->done_eat);
			*data->done += 1;
			pthread_mutex_unlock(data->done_eat);
			return ;
		}
		ft_printf("\033[34;1mis sleeping\033[0m 😴", data);
		ft_sleep(data->sleep_time);
		ft_printf("\033[0;33mis thinking\033[0m 🤔", data);
	}
}

/*
	This function works forever as the name specifies. Unless
	one of philosophers die out of hunger. In other words, whenever
	one of the philosophers' did_die value become 1. In this case,
	while loop stops and function ends with void return.
*/
void	ft_eat_forever(t_phi_data *data)
{
	while (*data->did_die == 0)
	{
		ft_eat(data);
		ft_printf("\033[34;1mis sleeping\033[0m 😴", data);
		if (*data->did_die)
			return ;
		ft_sleep(data->sleep_time);
		ft_printf("\033[0;33mis thinking\033[0m 🤔", data);
	}
}

/*
	This function is the place where ODD/EVEN solution
	has been used in order to solve the philosophers
	problem. It checks whether pihlosopher number is odd
	or even. If it is odd, philosopher is being slept as
	much as eat_time. Why? Because the reason, we try to
	create enough time for even number philosophers to
	complete eating. When even numbers completed eating,
	odd numbers will continue to thread and forks will be
	free since even numbers have already completed eating
	and put back the forks on the table. By this way, now 
	even numbers will be able to pick up free forks and 
	eat their meal in peace.
	
*/
void	ft_thread(t_phi_data *data)
{
	if (data->index % 2 != 0)
		usleep(data->eat_time * 100);
	if (data->must_eat)
		ft_must_eat(data);
	else
		ft_eat_forever(data);
}

/*
	This function initialize some values and timeval structs.
	But most importantly, here in this function we create 
	threads as many as the total number of philosophers.
*/
void	ft_thread_create(t_phi_data *data, int	*done)
{
	t_phi_data				*tmp;
	struct timeval			*time1;

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
