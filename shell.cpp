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

			/* TODO: Error check to make sure the child was successfully created */
			if (pid < 0) {
				/*** TODO: If I am child, I will do this: ****/

				perror("fork");
				exit(-1);
			}
				/*** TODO: If I am a parent, I will do the following ***?
				/* Wait for the child process to terminate */
			if (pid == 0) {
				string cmdb = cmdBuff.substr(0,cmdBuff.find(' '));

				if (execlp(cmdb.c_str(),cmdBuff.c_str(), NULL)<0)
				{
					perror(cmdb.c_str());
					exit(-1);
				}
			}

			if (pid > 0)
			{
				if (wait(NULL)<0){
					perror("Wait failure");
					exit(-1);
				}
			}



		}
	} while (cmdBuff != "exit");

	return 0;
}
