#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>

static int str_to_bit (pid_t pid, char *str) //criar string static pra conter a mensagem da PRIMEIRA VEZ, e NAS PROXIMAS, só ir alterando
{
	static char *msg;
	static pid_t pid_s;
	static int i;
	static int j;
	int no_invert;

	i = -1;
	j = -1;
	no_invert = 1 << 7;
	pid_s = pid;
	if (str)
		msg = ft_strdup(str);
	//dar return(0) quando terminar de enviar um bit;
	while (i++ < (ft_strlen(msg) - 1)
	{
		while (++j < 8)
		{
			if (msg[i] & no_invert)
			{
				kill(pid_s, SIGUSR1); //tem que dar erro se o resultado for -1
			}
			else
				kill(pid_s, SIGUSR2); //tem que dar erro se o resultado for -1
		}
		j = -1;
		return (0); //mandou 8 bits (1 caracter) // retorna 1 quando MANDAR TODA A MENSAGEM
	}
	//enviar os 8 bits de \0 (SIGUSR2)
	//esvaziar msg
	//retornar 1
}

static void handler_sig(int signum)
{
	int ret;

	ret = 0;
	if (signum == SIGUSR1) //quer dizer que deve mandar o proximo bit (foi bem sucedido)
	{
		ret = str_to_bit(0, 0);
	}
	else if (signum == SIGUSR2) //deu erro, tem que terminar o processo e esvaziar a string??
	{

	}
	if (ret == 1) //mandou a mensagem toda, daí tem que mandar os 8 '0' de bit do caracter \0
	{

	}
	//if ret == 1 --> quando terminar de enviar tudo... exit(SUCESS);
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
		//mensagem de erro e exit(1) --> (função pra isso?)
	}
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	str_to_bit(argv[1], argv[2]);
	while(1)
		pause();
}