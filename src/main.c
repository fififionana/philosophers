/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:34:09 by frushiti          #+#    #+#             */
/*   Updated: 2023/10/04 15:34:20 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_env	env;

	init_arguments(argc, argv, &env);
	init_mutexes(&env);
	init_philos(&env);
	init_threads(&env);
	destroy(&env);
}
