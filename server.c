/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:35:41 by lfranca-          #+#    #+#             */
/*   Updated: 2021/11/11 22:19:38 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void ft_putchar_adapt(char a)
{
	if (a == 0)
		a = '\n';
	write(1, &a, 1);
}

void hand_sigs(int signo, siginfo_t *info, void *context)
{
	//static char *msg;
	static int counter;
	static char caract;
	static int multiple;

	//counter = -1;
	//msg = malloc(sizeof(char) * 8 + 1); //caracter '\0'
	caract = 0;
	multiple = 0;
	if (signo == SIGUSR1)
		caract += 1 << (7 - multiple);
	multiple++;
	/*while (counter++ < 8)
	{
		if (signo == SIGUSR1)
			msg[counter] = '1';
		else if (signo == SIGUSR2)
			msg[counter] = '0';
	}
	if (counter == 8)
	{
		msg[counter] = '\0';
		//funcao pra converter pra int que vai levar à outra pra printar em char
		//essa funcao de conversao vai ter um retorno ESPECIFICO pra quando imprimir o '\0',
		//e dai a gente para baseado nisso!
		counter = -1;
	}*/
	if (multiple == 8)
	{
		ft_putchar_adapt(caract);
		multiple = 0;
		caract = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		//funcao pra erro (pra enviar de volta SIGUSR2 e exitar (1))
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
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
}
