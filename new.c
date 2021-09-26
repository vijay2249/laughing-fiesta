#include<stdio.h>     //Standard Library
#include<stdlib.h>    //Standard Library
#include<string.h>    //To perform string operations
#include<sys/types.h> //for fork()
#include<unistd.h>    //for fork()
#include <stdbool.h>  // for boolean variable usage
#include<sys/wait.h>  // for wait() function
#include<sys/stat.h>  
#include<fcntl.h>     //pipe() function call

#define SIZE 256
#define prompt "STRESS >>>"

// pipe commands execution
int pipeManage(char **inputCommands, int n){
  char *first[SIZE], *second[SIZE];
  memset(first, "\0", SIZE);
  memset(second, '\0', SIZE);
  int i=0;
  for(i=0;i<n;i++){
    if(strcmp(inputCommands[i], "|")==0){i++;break;}
    first[i] = inputCommands[i];
  }
  int j=0;
  for(;i<n;i++)second[j++]=inputCommands[i];
  int pipefd[2];
  pid_t p1, p2;
  if(pipe(pipefd) < 0){
    printf("Pipe creation failed \n");
    return -1;
  }
  p1 = fork();
  if(p1 < 0){
    printf("Couldnt fork the process\n");
    return -1;
  }
  if(p1 == 0){
    close(pipefd[0]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
    if(execvp(first[0], first) < 0){
      printf("Not executed the first section of command\n");
      return -1;
    }
  }
  else{
    p2 = fork();
    if(p2 < 0){
      printf("unable to fork process\n");
      return -1;
    }
    if(p2 == 0){
      close(pipefd[1]);
      dup2(pipefd[0], STDIN_FILENO);
      close(pipefd[0]);
      if(execvp(second[0], second)<0){
        printf("unable to execute command\n");
        return -1;
      }
    }
    else wait(NULL);
  }
}

// executing the commands return value is int => int function
int executeCommands(char **inputCommands, int n, bool isPipePresent){
  if(strcmp(inputCommands[0],"clear")==0)system("clear"),printf("%s", prompt);
  else if(strcmp(inputCommands[0],"exit")==0)exit(0);
  else if(strcmp(inputCommands[0]. "cd")==0) chdir(inputCommands[1]);
  else if (isPipePresent) pipeManage(inputCommands, n);
}


// input args catch
int main(int *argc, char *argv[]){
  char inputstring[SIZE];
  char *inputCommands[SIZE];
  while(1){
    print("%s", prompt);
    memset(inputstring, "\0", SIZE);
    fgets(inputstring, SIZE, stdin);
    if((inputCommands[0] = strtok(inputstring, "\n"))==NULL)continue;
    int n=1;
    bool isPipeIncluded = false;
    while((inputCommands[n] = strtok(NULL, "\n")) != NULL){
      if(strcmp(inputCommands[n], "|")==0)isPipeIncluded=true;
      n++;
    }
    executeCommands(inputCommands, n, isPipeIncluded);
  }
  exit(0);
}