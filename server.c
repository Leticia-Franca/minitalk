/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:18:58 by lfranca-          #+#    #+#             */
/*   Updated: 2021/11/30 20:56:37 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/server.h"

void	ft_putchar_adapt(char a)
{
	if (a == 0)
		a = '\n';
	write(1, &a, 1);
}

void	hand_sigs(int signo, siginfo_t *info, void *context)
{
	static char	caract;
	static int	multiple;
	static int	pid_client;

	(void)context;
	if (!pid_client)
	{
		pid_client = info->si_pid;
		caract = 0;
		multiple = 0;
	}
	if (signo == SIGUSR1)
		caract += 1 << (7 - multiple);
	multiple++;
	if (multiple == 8)
	{
		ft_putchar_adapt(caract);
		multiple = 0;
		caract = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		kill(info->si_pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa2;
	int					pid;
	sigset_t			block_mask;

	sa2.sa_flags = SA_SIGINFO;
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa2.sa_sigaction = &hand_sigs;
	sa2.sa_mask = block_mask;
	sigaction(SIGUSR1, &sa2, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
}
