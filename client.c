/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 18:20:10 by lfranca-          #+#    #+#             */
/*   Updated: 2021/11/30 20:31:58 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/client.h"

void	ft_error(char **to_free)
{
	free (*to_free);
	exit(EXIT_FAILURE);
}

static int	send_signal(int pid, char **msg, int desl, int *x)
{
	if ((*msg)[*x] & 1 << desl)
	{
		if (kill(pid, SIGUSR1) == -1)
			ft_error(msg);
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error(msg);
	}
	return (0);
}

static int	str_to_bit(char *pid, char *str)
{
	static char		*msg;
	static int		pid_s;
	static int		i;
	static int		j;

	if (str && pid)
	{
		pid_s = ft_atoi(pid);
		i = 0;
		j = -1;
		msg = ft_strdup(str);
	}
	while (msg[i] != '\0')
	{
		while (++j < 8)
		{
			send_signal(pid_s, &msg, (7 - j), &i);
			return (0);
		}
		j = -1;
		i++;
	}
	free(msg);
	return (1);
}

static void	handler_sig(int signum)
{
	int	ret;

	ret = 0;
	if (signum == SIGUSR1)
		ret = str_to_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("Erro: Client interrompido por server\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ret == 1)
		exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	act.sa_handler = &handler_sig;
	act.sa_mask = block_mask;
	act.sa_flags = 0;
	if ((argc != 3) || (!ft_atoi(argv[1])))
	{
		ft_putstr_fd("Erro! Tente: [executavel] [número PID] [string]\n", 2);
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	str_to_bit(argv[1], argv[2]);
	while (1)
		pause();
}
