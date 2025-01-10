/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l < tjorge-l@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:50:23 by tjorge-l          #+#    #+#             */
/*   Updated: 2025/01/09 19:43:43 by tjorge-l         ###   ########.fr       */
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

//////////////////////////////////////////
// Simulating the pipe "|" operator in C 
//////////////////////////////////////////
// int	main(void)
// {
// 	int fd[2];
// 	int	pid1;
// 	int	pid2; 

// 	if (pipe(fd) == -1)
// 		return (1);
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return 2;
// 	if (pid1 == 0)
// 	{	// Child process 1 (ping)
// 		close(fd[0]);
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[1]);
// 		execlp("ping", "ping", "-c", "5", "google.com", NULL);
// 	}

// 	pid2 = fork();
// 	if (pid2 == -1)
// 		return (3);

// 	if (pid2 == 0)
// 	{	// Child process 2 (grep)
// 		close(fd[1]);
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		execlp("grep", "grep", "rtt", NULL);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }


//////////////////////////////////////////
// The fork() function in C
//////////////////////////////////////////

// int	main(void)
// {
// 	// int	id;
// 	// id = fork();

// 	// 4 end processes:
// 	// fork();
// 	// Parent and child process is created.
// 	// fork();
// 	// Original process generates a second child process
// 	// Original child generates a child process
// 	// Original Parent + Original Child + Second Child + Original child's child

// 	// 3 end processes
// 	int	id;

// 	id = fork();
// 	if (id != 0)
// 		fork();
// 	printf("Hello world!\n");
	
// 	// n times fork = 2^n processes "

// 	// printf("Hello world from id: %d\n", id);
// 	// if (id == 0)
// 	// 	printf("Hello from the child process.\n");
// 	// else
// 	// 	printf("Hello from the main process.\n");


// 	return (0);
// }

//////////////////////////////////////////
// Waiting for processes to finish 
// (using the wait function) in C
//////////////////////////////////////////

// int main(void)
// {
// 	int	id;
// 	int	n;
// 	int	i;

// 	id = fork();
// 	if (id == 0)
// 		n = 1;
// 	else
// 		n = 6;
// 	if (id != 0)
// 		wait(NULL);
// 	i = n;
// 	while (i < n + 5)
// 	{
// 		printf("%d ", i);
// 		fflush(stdout);
// 		i++;
// 	}
// 	if (id != 0)
// 		printf("\n");
// 	return (0);
// }

//////////////////////////////////////////
// Process IDs in C 
//////////////////////////////////////////

// int main(void)
// {
// 	int	id;
// 	// int	n;
// 	// int	i;
// 	int	res;

// 	id = fork();

// 	if (id == 0)
// 		sleep(1);
	
// 	printf("Fork ID: %d; Current ID: %d; Parent ID: %d\n",
// 			id, getpid(), getppid());

// 	res = wait(NULL);
// 	if (res == -1)
// 		printf("No children to wait for.\n");
// 	else
// 		printf("%d finished execution\n", res);

// 	return (0);
// }


//////////////////////////////////////////
// Calling fork multiple times
//////////////////////////////////////////

// int main(void)
// {
// 	int	id1;
// 	int	id2;

// 	id1 = fork();
// 	id2 = fork();

// 	if (id1 == 0)
// 	{
// 		if (id2 == 0)
// 			printf("We are process y.\n");
// 		else
// 			printf("We are process x.\n");
// 	}
// 	else
// 	{
// 		if (id2 == 0)
// 			printf("We are process z.\n");
// 		else
// 			printf("We are the parent process.\n");
// 	}

// 	while (wait(NULL) != -1 || errno != ECHILD)
// 		printf("Waited for a child to finish.\n");
			
// 	return (0);
// }

//    ECHILD (for wait()) The calling process does not  have  any  unwaited-for
//           children.
// Probably best practice to generate all processes from the parent process.


//////////////////////////////////////////
// Communicating between processes 
// (using pipes) in C
//////////////////////////////////////////

// int main(void)
// {
// 	int	fd[2];
// 	int	id;
// 	int	x;
// 	int	y;

// 	if (pipe(fd) == -1)
// 	{
// 		printf("An error occurred with opening the pipe.\n");
// 		return (1);
// 	}
// 	id = fork();
// 	if (id == -1)
// 	{
// 		printf("An error occurred with fork.\n");
// 		return (4);
// 	}
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		printf("Input a number: ");
// 		scanf("%d", &x);
// 		if (write(fd[1], &x, sizeof(int)) == -1)
// 		{
// 			printf("An error occurred with writing to the pipe. \n");
// 			return (2);
// 		}
// 		close (fd[1]);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		close(fd[1]);
// 		if (read(fd[0], &y, sizeof(int)) == -1)
// 		{
// 			printf("An error occurred with reading to the pipe. \n");
// 			return (3);
// 		}
// 		close(fd[0]);
// 		y = y * 3;
// 		printf("Got from the child process: %d\n", y);
// 	}


// 	return (0);
// }


//////////////////////////////////////////
// Practical use case for fork and pipe
// in C
//////////////////////////////////////////

// int main(void)
// {
// 	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
// 	int arr_size;
// 	int	start;
// 	int i;
// 	int sum;
// 	int end;
// 	int	fd[2];
// 	int	id1;
// 	int	id2;
// 	int	sum_child_a;
// 	int	sum_child_b;

// 	arr_size = sizeof(arr) / sizeof(int);
// 	if (pipe(fd) == -1)
// 		return (1);
// 	id1 = fork();
// 	if (id1 == -1)
// 		return (2);
// 	if (id1 == 0)
// 	{
// 		start = 0;
// 		end = arr_size / 2;
// 	}
// 	else
// 	{
// 		id2 = fork();
// 		if (id2 == -1)
// 			return (3);
// 		if (id2 == 0)
// 		{
// 			start = arr_size - 1;
// 			end = arr_size;
// 		}
// 		else
// 		{
// 			start = arr_size / 2;
// 			end = arr_size - 1;
// 		}
// 	}

// 	sum = 0;
// 	i = start;
// 	while (i < end)
// 	{
// 		sum += arr[i];
// 		i++;
// 	}

// 	printf("Calculated partial sum: %d\n", sum);
	
// 	if (id1 == 0)
// 	{
// 		close(fd[0]);
// 		write(fd[1], &sum, sizeof(sum));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		if (id2 == 0)
// 		{
// 			close(fd[0]);
// 			write(fd[1], &sum, sizeof(sum));
// 			close(fd[1]);
// 			return (0);
// 		}
// 		close(fd[1]);
// 		read(fd[0], &sum_child_a, sizeof(int));
// 		read(fd[0], &sum_child_b, sizeof(int));
// 		close(fd[0]);

// 		printf("Total sum: %d\n", sum_child_a + sum_child_b + sum);
// 		while (wait(NULL) != -1 || errno != ECHILD)
// 			printf("Waited for a child to finish.\n");
// 	}

// 	return (0);
// }

//////////////////////////////////////////
//  How to execute another program in C
// (using exec)
//////////////////////////////////////////

// int main(void)
// {
// 	char *str;

// 	str = malloc(5);
// 	// char *arr[] = {"ping", "google.com", NULL};
// 	// char *env[] = {"TEST=environment variable", NULL};
// 	free(str);
// 	execl("/usr/bin/ls", "/", NULL);
// 	printf("Ping finished executing \n");
// 	return (0);
// }

//////////////////////////////////////////
//  How to execute commands in C
//////////////////////////////////////////

// int main(void)
// {
// 	int	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 		execlp("ping", "ping", "google.com", "-c", "3", NULL);
// 	else
// 		wait(NULL);
// 	printf("Success!\n");
// 	return (0);
// }

//////////////////////////////////////////
//  Getting exit status code in C
//////////////////////////////////////////

// int main(void)
// {
// 	int	pid;
// 	int	err;
// 	int	wstatus;
// 	int	status_code;

// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 	{
// 		err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
// 		if (err == -1)
// 		{
// 			printf("Could not find program to execute!\n");
// 			return (2);
// 		}
// 	}
// 	else
// 	{
// 		wait(&wstatus);
// 		if (WIFEXITED(wstatus))
// 		{
// 			status_code = WEXITSTATUS(wstatus);
// 			if (status_code == 0)
// 				printf("Success!\n");
// 			else
// 				printf("Failure with status code %d!\n", status_code);

// 		}
// 	}
// 	return (0);
// }

//////////////////////////////////////////
//  Redirecting standard output in C 
//////////////////////////////////////////

// int main(void)
// {
// 	int	pid;
// 	int	err;
// 	int	wstatus;
// 	int	status_code;
// 	int	file;
// 	int	file2;

// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 	{
// 		file = open("pingresults.txt", O_WRONLY | O_CREAT, 0777);
// 		if (file == -1)
// 			return (2);
// 		printf("The fd to pingresults.txt: %d\n", file);
// 		file2 = dup2(file, STDOUT_FILENO);
// 		printf("The duplicated fd: %d\n", file2);
// 		close(file);
// 		err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
// 		if (err == -1)
// 		{
// 			printf("Could not find program to execute!\n");
// 			return (2);
// 		}
// 	}
// 	else
// 	{
// 		wait(&wstatus);
// 		if (WIFEXITED(wstatus))
// 		{
// 			status_code = WEXITSTATUS(wstatus);
// 			if (status_code == 0)
// 				printf("Success!\n");
// 			else
// 				printf("Failure with status code %d!\n", status_code);

// 		}
// 	}
// 	return (0);
// }

//////////////////////////////////////////
//  Redirecting standard output in C 
//////////////////////////////////////////

// int main(void)
// {
// 	int	pid;
// 	int	err;
// 	int	wstatus;
// 	int	status_code;

// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 	{
// 		err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
// 		if (err == -1)
// 		{
// 			printf("Could not find program to execute!\n");
// 			return (2);
// 		}
// 	}
// 	else
// 	{
// 		wait(&wstatus);
// 		if (WIFEXITED(wstatus))
// 		{
// 			status_code = WEXITSTATUS(wstatus);
// 			if (status_code == 0)
// 				printf("Success!\n");
// 			else
// 				printf("Failure with status code %d!\n", status_code);

// 		}
// 	}
// 	return (0);
// }

// //////////////////////////////////////////
// //   How to send an array through a pipe 
// //////////////////////////////////////////

// // Working alternative:
// int main(void)
// {
// 	int fd[2];
// 	int	pid;
// 	int	arr[10];
// 	int n;
// 	int	i;
// 	int	sum;

// 	sum = 0;
// 	if (pipe(fd) == -1)
// 		return (EXIT_FAILURE);
// 	pid = fork();
// 	if (pid == -1)
// 		return (EXIT_FAILURE);
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		i = 0;
// 		n = 10;
// 		write(fd[1], &n, sizeof(int));
// 		while (i < 10)
// 		{
// 			arr[i] = rand() % 11;
// 			printf("Sending: %d\n", arr[i]);
// 			write(fd[1], &arr[i], sizeof(int));
// 			i++;
// 		}
// 		// if (write(fd[1], arr, sizeof(int) * n) == -1)
// 		// {
// 		// 	printf("Error.\n");
// 		// 	return (EXIT_FAILURE);
// 		// }
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		close(fd[1]);
// 		if (read(fd[0], &n, sizeof(int)) == -1)
// 			return (EXIT_FAILURE);
// 		printf("%d\n", n);
// 		i = 0;
// 		while (i < 10)
// 		{
// 			read(fd[0], &arr[i], sizeof(int));
// 			printf("Received: %d\n", arr[i]);
// 			sum += arr[i];
// 			i++;
// 		}
// 		printf("Sum: %d\n", sum);
// 		close(fd[0]);
// 	}
// 	return (0);
// }

//////////////////////////////////////////
//   How to send a string through a pipe 
//////////////////////////////////////////

// int main(void)
// {
// 	int	fd[2];
// 	int	pid;
// 	char str[200];
// 	int	n;


// 	if (pipe(fd) == -1)
// 		return (EXIT_FAILURE);
// 	pid = fork();
// 	if (pid == -1)
// 		return (EXIT_FAILURE);
// 	if (pid == 0)
// 	{
// 		close(fd[0]);
// 		printf("Enter message: ");
// 		fgets(str, 25, stdin);
// 		str[strlen(str) - 1] = '\0';
// 		n = strlen(str) + 1;
// 		write(fd[1], &n, sizeof(int));
// 		write(fd[1], str, n);
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		read(fd[0], &n, sizeof(int));
// 		read(fd[0], str, sizeof(char) * n);
// 		printf("%s\n", str);
// 		close(fd[0]);
// 		wait(NULL);
// 	}
// 	return (0);
// }

//////////////////////////////////////////
//    Working with multiple pipes
//////////////////////////////////////////

// int main(void)
// {
// 	int fd[3][2];
// 	int	i;
// 	int pid1;
// 	int	pid2;

// 	for (i = 0; i < 3; i++)
// 	{
// 		if (pipe(fd[i])== -1)
// 			return 1;
// 	}
// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return 2;
// 	if (pid1 == 0)
// 	{
// 		// Child process 1
// 		close(fd[0][1]);
// 		close(fd[1][0]);
// 		close(fd[2][0]);
// 		close(fd[2][1]);
// 		int	x;
// 		read(fd[0][0], &x, sizeof(int));
// 		close(fd[0][0]);
// 		x += 5;
// 		write(fd[1][1], &x, sizeof(int));
// 		close(fd[1][1]);
// 		return (0);
// 	}

// 	pid2 = fork();
// 	if (pid2 == -1)
// 		return 5;
// 	if (pid2 == 0)
// 	{
// 		// Child process 2
// 		close(fd[1][1]);
// 		close(fd[2][0]);
// 		close(fd[0][0]);
// 		close(fd[0][1]);

// 		int	x;
// 		read(fd[1][0], &x, sizeof(int));
// 		close(fd[1][0]);
// 		x += 5;
// 		write(fd[2][1], &x, sizeof(int));
// 		close(fd[2][1]);
// 		return (0);
// 	}

// 	// Parent process
// 	close(fd[0][0]);
// 	close(fd[2][1]);
// 	close(fd[1][0]);
// 	close(fd[1][1]);

// 	int	x;
// 	x = 0;
// 	write(fd[0][1], &x, sizeof(int));
// 	close(fd[0][1]);

// 	read(fd[2][0], &x, sizeof(int));
// 	close(fd[2][0]);

// 	printf("Result is %d\n", x);
// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
// }

//////////////////////////////////////////
//    What is waitpid?
//////////////////////////////////////////

// int main(void)
// {
// 	int	pid1;
// 	int	pid2;
// 	int	res1;
// 	int	res2;

// 	pid1 = fork();
// 	if (pid1 == -1)
// 		return (EXIT_FAILURE);
// 	if (pid1 == 0)
// 	{
// 		sleep(4);
// 		printf("Finished execution (%d)\n", getpid());
// 		return (0);
// 	}

// 	pid2 = fork();
// 	if (pid2 == -1)
// 		return (EXIT_FAILURE);
// 	if (pid2 == 0)
// 	{
// 		sleep(1);
// 		printf("Finished execution (%d)\n", getpid());
// 		return (0);
// 	}
// 	res1 = waitpid(pid1, NULL, WNOHANG);
// 	printf("Waited for %d\n", res1);
// 	res2 = waitpid(pid2, NULL, WNOHANG);
// 	printf("Waited for %d\n", res2);

// 	return (0);
// }

//////////////////////////////////////////
//  Calling fork multiple times (part 2) 
//  (With a practical example) 
//////////////////////////////////////////
// # define PROCESS_NUM 3

// int main(void)
// {
// 	int pids[PROCESS_NUM];
// 	int	pipes[PROCESS_NUM + 1][2];
// 	int	i;

// 	for (i = 0; i < PROCESS_NUM + 1; i++)
// 	{
// 		if (pipe(pipes[i]) == -1)
// 			return (1);
// 	}

// 	for (i = 0; i < PROCESS_NUM; i++)
// 	{
// 		pids[i] = fork();
// 		if (pids[i] == -1)
// 			return (1);
// 		if (pids[i] == 0)
// 		{
// 			// Child process
// 			int j;
// 			for (j = 0; j < PROCESS_NUM + 1; j++)
// 			{
// 				if (j != i)
// 					close(pipes[j][0]);
// 				if (j != i + 1)
// 					close(pipes[j][1]);
// 			}

// 			int x;
// 			read(pipes[i][0], &x, sizeof(int));
// 			close(pipes[i][0]);
// 			printf("(%d) Got %d\n", i, x);
// 			x++;
// 			printf("(%d) Sent %d\n", i, x);
// 			write(pipes[i + 1][1], &x, sizeof(int));
// 			close(pipes[i + 1][1]);

// 			return 0;
// 		}
// 	}

// 	// Main process

// 	int j;
// 	for (j = 0; j < PROCESS_NUM + 1; j++)
// 	{
// 		if (j != PROCESS_NUM)
// 			close(pipes[j][0]);
// 		if (j != 0)
// 			close(pipes[j][1]);
// 	}

// 	int	y = 5;
// 	printf("Main process sent %d\n", y);
// 	write(pipes[0][1], &y, sizeof(int));
// 	close(pipes[0][1]);

// 	read(pipes[PROCESS_NUM][0], &y, sizeof(int));
// 	close(pipes[PROCESS_NUM][0]);

// 	printf("Final esult: %d\n", y);

// 	for (i = 0; i < PROCESS_NUM + 1; i++)
// 		wait(NULL);
// 	return (0);
// }

// when I run valgrind --track-fds=yes ./a.out with the code there are open file descriptors specifically for this line;


// for(int i = 0; i < PROCESS_NUM + 1; i++) // Create pipes for processes 
//     {
//         if(pipe(pipes[i]) == -1){
//             perror("pipes");
//             exit(1);
//         }
//     }

// Do you know why this happens? If so How can I get rid of them?

// I did omit a few issues with resource management regarding this code so as to not make it too complex. Basically, what can happen there is the creation of a pipe could occur after some pipes have already been created. Because of that, you will need another for loop in that if block closing all the other pipes that have been opened before so as to not create a resource leak

//////////////////////////////////////////
//  What does fork() actually return?
//////////////////////////////////////////

int main(void)
{

	return (0);
}