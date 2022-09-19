/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_die.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:33:56 by yogun             #+#    #+#             */
/*   Updated: 2022/09/19 18:49:30 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
	This function loop thorough all the philosophers infinitely
	unless fifth parameter has given. In this case it will loop
	thorough untill philosophers complete their total must_eat times.
	Whenever a philosopher's last_eat time become bigger than die_time,
	it means our philosopher died out of starving. In this case,
	we lock our funeral mutex for other philosophers not to race to die.
	We lock the funeral mutex in printf function.
*/
void	ft_die(t_phi_data *data)
{
	t_phi_data				*tmp;
	int						j;
	long unsigned int		i;

	tmp = data;
	while (*data->done < data->total_philo)
	{
		j = ft_time(data->last_eat);
		if (j >= data->die_time)
		{
			*data->did_die = 1;
			i = ft_time(data->time);
			printf("%lums - The philo number %i, died!💀\n", i, data->index);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}
