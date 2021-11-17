/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 23:35:32 by lfranca-          #+#    #+#             */
/*   Updated: 2021/11/17 19:11:50 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void ft_error (char **to_free)
{
	free (*to_free);
	exit(EXIT_FAILURE);
}

static int str_to_bit (char *pid, char *str)
{
	static char *msg;
	static int pid_s;
	static size_t i;
	static int j;
	static int no_invert;
	//no_invert = 1 << 7; //NAO É AQUI QUE EU DECLARO O NO_INVERT --> ele precisa "renovar" o valor A CADA BIT, pra se "mover"
	if (pid)				//pelos BITS e assim traduzir CADA UM CORRETAMENTE, nao é "sempre << 7", é "<< variavel"
		pid_s = ft_atoi(pid);
	if (str)
	{
		i = 0;
		j = -1;
		msg = ft_strdup(str);
	}
	while (msg[i] != '\0')
	{
		//printf("%ld\n", i);
		while (++j < 8)
		{
			//printf("%c\n", msg[i]);
			no_invert = 7 - j;
			//printf("%d\n", no_invert);
			if (msg[i] & 1 << no_invert) //e se em vez de "msg[i] & no_invert (esse, valor fixo)" for: "msg[i] & 1 << no_invert (no_invert sendo de 7 - j"?
			{
				if (kill(pid_s, SIGUSR1) == -1)
					ft_error(&msg);
				else
					printf("sucesso: 1\n");
			}
			else
			{
				if (kill(pid_s, SIGUSR2) == -1)
					ft_error(&msg);
				else
					printf("sucesso: 0\n");
			}
			//printf("estamos pra retornar e esperar\n");
			return (0); //termina o flow do processo (vai pro pause()) a cada envio de sinal
		}
		//é como se ele nem entrasse aqui depois que passa o primeiro caracter... ele não reseta, portanto, e só envia o primeiro
		i++;
		j = -1;
		//return(0); //só colocou o return(0) aqui pra interromper ANTES de chegar ao free e ao return(1)??
		//podia em vez disso colocar embaixo: if (msg[i] == '\0' daí dar free e retornar 1)
	}
	//enviar os 8 bits de \0 (SIGUSR2)
	//printf("%ld\n", i);
	//printf("%c\n", msg[1]);
	free(msg);
	return (1);
}
//SÓ FALTA INSERIR O CARACTER NULO PRO SERVER AO FINAL DA STRING ENVIADA!!!!!!!!!!!!!!!!
static void handler_sig(int signum)
{
	int ret;

	ret = 0;
	//printf("O sinal recebido agora para o PROXIMO BIT eh %d\n", signum);
	if (signum == SIGUSR1)
		ret = str_to_bit(0, 0);
	else if (signum == SIGUSR2)
	{
		ft_putstr_fd("Sinal de erro\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ret == 1) //mandou a mensagem toda
	{
		//printf("terminou\n");
		exit(EXIT_SUCCESS);
	}
}

int main(int argc, char *argv[])
{
	struct sigaction act;
	sigset_t block_mask;
	sigemptyset(&block_mask);
	act.sa_handler = &handler_sig;
	act.sa_mask = block_mask;
	act.sa_flags = 0;
	
	if ((argc != 3) || (!ft_atoi(argv[1])))
	{
		ft_putstr_fd("Erro: qtdade de argumentos errada ou falha no PID\n", 2);
		exit(EXIT_FAILURE);
	}
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	str_to_bit(argv[1], argv[2]);
	printf("agora fiquemos no aguardo do sinal do server\n");
	while(1)
		pause();
}