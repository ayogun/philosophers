/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:00 by yogun             #+#    #+#             */
/*   Updated: 2022/09/14 13:40:48 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


void	ft_die(t_info *data)
{
	t_info				*tmp;
	int					j;
	long unsigned int	i;

	tmp = data;
	while (*data->done < data->total_philo)
	{
		j = ft_time(data->last_eat);
		if (j >= data->t2d)
		{
			*data->die = 1;
			pthread_mutex_lock(data->in);
			i = ft_time(data->time);
			printf("%lums %i died!\n", i, data->philo_N);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}
