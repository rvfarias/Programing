/*
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#define TRUE 1

int main(int argc, char const *argv[]) {

  while (TRUE) {
    type_prompt();
  }

  return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRUE 1

int n = 0;
int pid;
char *argv[];
char temp[256];
int argc;

void type_prompt()
{
   printf("[shell-PID=%i]$ ", getpid());
}

void read_command(char *argv[])
{
   n = 0;
   gets(temp);
   argv[n++] = strtok (temp," ");
   while (argv[n-1] != NULL)
   argv[n++] = strtok (NULL, " ");

}

int main(){

   int status;
   argv[0] = NULL;
   while (TRUE) {
                                                                    //repeat forever
      type_prompt();                                                            // display prompt on screen
      read_command(argv);
                                                        // read input from terminal
      if ((pid = fork()) != 0) {                                                // fork off child process
         printf("Esperando o filho: pid = %i\n", pid);
         waitpid(-1, &status, 0);                                               // wait for child to exit
         printf("Waiting finished");
      }
      else {
         if (execvp(argv[0], argv) == -1)                                        // execute command
            printf("Não executou. Erro: %s\n", strerror(errno));
      }
   }
   return 0;
}


/*  A simple shell, assuming commands are in /bin
 *  @Author: T.L. Yu
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void read_command ( char cmd[], char *par[] )
{
  char line[1024];
  int count = 0, i = 0, j = 0;
  char *array[100], *pch;

  // Read one line
  for ( ;; ) {
    int c = fgetc ( stdin );
    line[count++] = (char) c;
    if ( c == '\n' ) break;
  }
  if ( count == 1 ) return;
  pch = strtok ( line, " \n" );

  // parse the line into words
  while ( pch != NULL ) {
    array[i++] = strdup ( pch );
    pch = strtok ( NULL, " \n");
  }
  // first word is the command
  strcpy ( cmd, array[0] );

  // others are parameters
  for ( int j = 0; j < i; j++ )
    par[j] = array[j];
  par[i] = NULL;  // NULL-terminate the parameter list
}

void type_prompt()
{
  static int first_time = 1;
  if ( first_time ) {   //clear screen for the first time
    const char* CLEAR_SCREE_ANSI = " \e[1;1H\e[2J";
    write(STDOUT_FILENO,CLEAR_SCREE_ANSI,12);
    first_time = 0;
  }

  printf("#");   // display prompt
}

int main()
{
  char cmd[100], command[100], *parameters[20];
  // environment variable
  char *envp[] = { (char *) "PATH=/bin", 0 };
  while ( 1 ) {                 //repeat forever
    type_prompt();              //display prompt on screen
    read_command ( command, parameters ); // read input from terminal
    if ( fork() != 0 )          // parent
      wait ( NULL );            //wait for child
    else{
      strcpy ( cmd, "/bin/" );
      strcat ( cmd, command );
      execve ( cmd, parameters, envp ); // execute command
    }
  }
}
*/
