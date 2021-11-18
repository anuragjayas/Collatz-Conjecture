
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	int k=0;	//Initializing the number
	
	pid_t pid;

	        while(k<=0)	
		{
			printf("\nPlease enter a number greater than 0\nNmuber:"); 
  			scanf("%d", &k);		//Taking input for the number to form collatz conjecture 
			if(k<=0)			//If the number is negative or zero, then it doesn't satisfy the condition for the conjecture 
				printf("\nInavlid Entry... Try again");

		}

		pid = fork();		//Creating the child process

		if (pid<0)		//If the child process is not created then the value of pid is negative
		{
			printf("Child process was not created");
			return 0;
		}

		else if (pid == 0)	//If the child process is created and running then the value of pid will be zero
		{
			printf("Child has started to create the collatz conjecture\n");
			printf("%d\n",k);
			while (k!=1)		//Algorithm for conjecture series starts. The loop will run until the value of k reaches one.
			{
				if (k%2 == 0)	//If the number is even
				{
					k = k/2;
				}
				else if (k%2 == 1)	//If the number is odd
				{
					k = 3 * (k) + 1;
				}	
			
				printf("%d\n",k);
			}
		
			printf("Child process is completed.\n");
		}

		else		//If the child process is created but the parent process is running
		{
			printf("Parent is waitingfor the child process to end\n");
			wait(NULL);		//To check wheteher the child process has ended
			printf("Parent process is completed\n");
		}
	return 0; 
}
