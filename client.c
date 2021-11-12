/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:35:32 by lfranca-          #+#    #+#             */
/*   Updated: 2021/11/11 21:55:32 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

static int str_to_bit (char *pid, char *str)
{
	static char *msg;
	static pid_t pid_s;
	static int i;
	static int j;
	int no_invert;

	i = -1;
	j = -1;
	no_invert = 1 << 7;
	pid_s = ft_itoa(pid);
	if (str)
		msg = ft_strdup(str);
	while (i++ < (ft_strlen(msg) - 1)
	{
		while (++j < 8)
		{
			if (msg[i] & no_invert)
			{
				if (kill(pid_s, SIGUSR1) == -1)
					ft_error(&msg); //esvaziar msg e exitar com FAILURE (1?)
			}
			else
				if (kill(pid_s, SIGUSR2) == -1)
					ft_error(&msg);
		}
		if (j == 8)
			j = -1;
	}
	//enviar os 8 bits de \0 (SIGUSR2)
	free(msg);
	return (1);
}

static void handler_sig(int signum)
{
	int ret;

	ret = 0;
	if (signum == SIGUSR1)
		ret = str_to_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr("mensagem de erro blablabla");
		exit(1);
	}
	if (ret == 1) //mandou a mensagem toda
		exit(0);
}

int main(int argc, char *argv[])
{
	struct sigaction sa;
	sigset_t block_mask;
	sigemptyset(&block_mask);
	sa.sa_handler = &handler_sig;
	sa.sa_mask = block_mask;
	sa.sa_flags = 0;
	
	if (argc != 3) || (argv[1] != )//str nao for numerico
	{
		ft_putstr("mensagem de erro\n");
		exit(1);
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	str_to_bit(argv[1], argv[2]);
	while(1)
		pause();
}