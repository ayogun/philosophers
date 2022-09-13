/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yogun <yogun@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 21:04:51 by yogun             #+#    #+#             */
/*   Updated: 2022/09/13 18:44:54 by yogun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_check(int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0 || ft_atoi(argv[4]) < 0)
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


int	main(int argc, char **argv)
{	
	t_info	*info;
	
	if (argc == 5 || argc == 6)
	{
		info = ft_start(argc,argv);
		if (info == NULL)
			return (1);
	}
	else
		wrong_input();
	return (0);
}