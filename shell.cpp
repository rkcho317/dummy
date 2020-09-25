#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	/* The command buffer */
	string cmdBuff;

	/* The ID of the child process */
	pid_t pid;

	/* Keep running until the user has typed "exit" */
	do
	{
		/* Prompt the user to enter the command */
		cerr << "cmd>";
		cin >> cmdBuff;

		/* If the user wants to exit */
		if (cmdBuff != "exit")
		{
			/* TODO: Create a child */

			pid = fork();

			if (pid < 0) {
				perror("fork ");
				exit(-1);
			}

			else if (pid == 0) {


				if (execlp(cmdBuff.c_str(),cmdBuff.c_str(), NULL)<0)
				{
					perror(cmdBuff.c_str());
					exit(-1);
				}
			}

			else if (pid > 0)
			{
				if (wait(NULL)<0){
					perror("Wait failure ");
					exit(-1);
				}
			}



		}
	} while (cmdBuff != "exit");

	return 0;
}
