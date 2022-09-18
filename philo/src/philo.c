/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:04:51 by yogun             #+#    #+#             */
/*   Updated: 2022/09/18 12:12:10 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	philoData	*data;
	int		did_die;
	int		done;

	if (argc == 5 || argc == 6)
	{
		did_die = 0;
		done = 0;
		data = ft_start(argc, argv, &did_die);
		if (data == NULL)
			return (1);
		ft_thread_create(data, &done);
		ft_free(data);
	}
	else
		wrong_input();
	return (0);
}
