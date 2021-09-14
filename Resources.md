 **************  fork()  ********************************
 creates a new child process, takes no parameters and returns integer
 -ve return value = creation of child process is unsuccessful
 0 return value = returns the new child process
 +ve return value = returns the process id of new child process created

********************* strtok()  ***********************
 splits the given string based on the second parameter that is passed into the function

************************************************
strcmp() -> returns 0 if both the parameters passed are same else return something else

****************** chdir() ************************
chdir() -> changes the working directory with the path mentioned to it as a parameter
0 return value if the command is successful
-1 return value if the command execution fails

********************  execvp(1,2) **********************
int execvp(const char* command, char *argv[])
this takes unix command as the first argument to execute the command
the second command represents the arguments to the command in the first argument
represents NULL as the termination argument of the command
if this function execution fails, then it returns -1 as return value

The main problem with this function usage is that,
  once this function is called, then the execution of the c program gets halt and 
  the command runs as the normal command as typed in terminal, 
  and thereafter the remaining part of the c program gets halt and will not be compiled

  so we need to fork the c program part and the call the function execvp() to continue both processes


**********************  perror(const char* str)  *******************
  prints the error message (str) to the output


*---- SIGTERM => termination request sent to the program
*---- SIGINT => Interactive attention signal
*---- SIG_IGN => ignore the signal

************************  getpid() ****************
  getpid -> get - process - id
  this returns the process id that is created when the process is forked in this process

**************************  waitpid()  **************************
 suspends the calling process until the system gets status information on the child

*----  pid_t => integer number of the process id type

************************** pipe()  ***********************
 pipe is a connection between two processes 
  -> so that output of one process becomes input of other process
 If a process tries to read before something is written to the pipe, the process is suspended until something is written.
 this takes an array of size two as parameter, -> 
  1st to read data in the pipe
  2nd to write data in the pipe
  and if anything goes wrong, then returns -1 and if all good then returns 0

**********************  dup2()  ******************************
 uses the file descriptior number specified by user
 int dup2(int old, int new)
 old -> old file descriptor
 new -> new file descriptor
 if old == new => just returns the new and does nothing
 if any error with old => call fails
 this new one is actually the copy of the old file
 after return these file descriptors can be used interchangebly as they are just copies of each other to same pointer
 for input -> int value is 0
 for output -> int value is 1
 any error case -> int value is 2

**********************************
command in the middle: use two pipes for standard input and output (for even and odd number of commands)
aux2 = commands_count-1 in pipemanager, dup2 function call




deleted txt file and added md file




