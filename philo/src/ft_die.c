/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:40:00 by yogun             #+#    #+#             */
/*   Updated: 2022/09/14 20:48:15 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_die(t_data *data)
{
	t_data				*tmp;
	int					j;
	long unsigned int	i;

	tmp = data;
	while (*data->done < data->tot_ph)
	{
		j = ft_time(data->last_eat);
		if (j >= data->t2d)
		{
			*data->die = 1;
			pthread_mutex_lock(data->in);
			i = ft_time(data->time);
			printf("%lums %i died!\n", i, data->phn);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}