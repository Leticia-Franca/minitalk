/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:35:41 by lfranca-          #+#    #+#             */
/*   Updated: 2021/11/17 19:08:44 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void ft_putchar_adapt(unsigned char a)
{
	if (a == 0)
		a = '\n';
	write(1, &a, 1);
}

void hand_sigs(int signo, siginfo_t *info, void *context)
{
	//static char *msg;
	//static int counter;
	static char caract;
	static int multiple;
	static int pid_client;

	//counter = -1;
	//msg = malloc(sizeof(char) * 8 + 1); //caracter '\0'
	(void)context;
	//arranjar algum jeito de ele só inicializar caract e  multiple UMA VEZ!!! (uma outra variavel como criterio?)
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
		//printf("%c\n", caract);
		multiple = 0;
		caract = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		kill(info->si_pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
	else
		return ;
}

int main(void)
{
	struct sigaction sa2;
	//sigset_t block_mask;
	int pid; //muda pra tipo pid_t?
	
	sa2.sa_flags = SA_SIGINFO;
	sa2.sa_sigaction = &hand_sigs;
	//sigaddset(&block_mask, SIGINT); //procurar saber esse sinal
	//sigaddset(&block_mask, SIGQUIT); //procurar saber esse sinal
	//sa2.sa_mask = block_mask;
	sigaction(SIGUSR1, &sa2, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
}
