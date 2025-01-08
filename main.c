/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:50:23 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/01/08 14:41:23 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	writestr(int fd, const char *str)
// {
// 	write(fd, str, strlen(str));
// }

// int	main(void)
// {
// 	int	pipefd[2];
// 	pid_t	pid;
// 	char	buf;
	
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0)
// 	{
// 		close(pipefd[1]);
// 		writestr(STDOUT_FILENO, "Child: What is the secret in this pipe?\n");
// 		writestr(STDOUT_FILENO, "Child: \"");

// 		while (read(pipefd[0], &buf, 1) > 0)
// 			write(STDOUT_FILENO, &buf, 1);
		
// 		writestr(STDOUT_FILENO, "\"\n");
// 		writestr(STDOUT_FILENO, "Child: Wow! I must go see my father.\n");

// 		close(pipefd[0]);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(pipefd[0]);
// 		writestr(STDOUT_FILENO, "Parent: I'm writing a secret in this pipe...\n");
// 		writestr(pipefd[1], "\e[33mI am your father mwahahaha!\e[0m");
// 		close(pipefd[1]);
// 		wait(NULL);
// 		writestr(STDOUT_FILENO, "Parent: Hello child\n");
// 		exit(EXIT_SUCCESS);
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	int	fd;

// 	fd = open("does not exist", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("open");
// 		return (EXIT_FAILURE);
// 	}
// 	close(fd);
// 	return (0);
// }

// Simulating the pipe "|" operator in C 

int	main(void)
{
	int fd[2];
	int	pid1;
	int	pid2; 

	if (pipe(fd) == -1)
		return (1);
	pid1 = fork();
	if (pid1 == -1)
		return 2;
	if (pid1 == 0)
	{	// Child process 1 (ping)
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execlp("ping", "ping", "-c", "5", "google.com", NULL);
	}

	pid2 = fork();
	if (pid2 == -1)
		return (3);

	if (pid2 == 0)
	{	// Child process 2 (grep)
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		execlp("grep", "grep", "rtt", NULL);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}