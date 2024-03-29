/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frushiti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:17:42 by frushiti          #+#    #+#             */
/*   Updated: 2023/10/04 15:17:54 by frushiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo, uint64_t timestamp)
{
	pthread_mutex_lock(&philo->env->forks[philo->l_fork]);
	print_state(philo, TOOK_FORK, timestamp);
	pthread_mutex_lock(&philo->env->forks[philo->r_fork]);
	print_state(philo, TOOK_FORK, timestamp);
}

void	leave_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->env->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->env->forks[philo->r_fork]);
}

void	philo_eat(t_philo *philo, uint64_t timestamp)
{
	print_state(philo, EATING, timestamp);
	philo->eat_count++;
	philo->last_eat = timestamp;
	usleep(philo->env->tt_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	print_state(philo, SLEEPING, get_time_ms());
	usleep(philo->env->tt_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	print_state(philo, THINKING, get_time_ms());
}
