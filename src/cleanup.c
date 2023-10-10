/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:19:32 by frushiti          #+#    #+#             */
/*   Updated: 2023/10/04 15:20:08 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_threads(t_env *env)
{
	int	index;

	index = -1;
	while (++index < env->n_philo)
		pthread_detach(env->philos[index].thread_id);
}

void	destroy(t_env *env)
{
	int	index;

	destroy_threads(env);
	index = -1;
	while (++index < env->n_philo)
		pthread_mutex_destroy(&env->forks[index]);
	pthread_mutex_destroy(&env->write);
	free(env->philos);
	free(env->forks);
}
