#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    char command[30];
    pid_t child;
    int status;
    while (1)
    {
        printf("#cisfun$ ");
        if (fgets(command, sizeof (command), stdin) == NULL)
        {
            break;
        }
        /**string compare**/

        child = fork();
        if (child == -1)
        {
            printf("fork failed");
        }
        if (child == 0)
        {
            int ret = 0;
            ret = execve(command, NULL, NULL);
            if (ret == -1)
            {
                printf("\n%s: No such file or directory\n", argv[0]);

            }
        }
        else
        {
            wait(&status); /** ngoja child aexecute before uexecute**/

        }

    }

    return 0;
}
