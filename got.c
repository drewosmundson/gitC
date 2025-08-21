// Drew Osmundson

#include <stdio.h>
#include <string.h>
#include <sys/stat.h> // Required for mkdir
#include <sys/types.h> // Required for mkdir mode_t parameter 
// The mode argument is typically a bitwise OR combination of constants representing various permissions for the owner, group, and others. 
// S_IRUSR: Read permission for the owner.
// S_IWUSR: Write permission for the owner.
// S_IXUSR: Execute/search permission for the owner.
// S_IRGRP: Read permission for the group.
// S_IWGRP: Write permission for the group.
// S_IXGRP: Execute/search permission for the group.
// S_IROTH: Read permission for others.
// S_IWOTH: Write permission for others.
// S_IXOTH: Execute/search permission for others.

#include <errno.h> // After a failed system call or library function, errno can be checked to determine the specific error that occurred.



// there can be just one stash
// is local to own machine
int stash(char* name){return 0;}



// pull from specified branch 
// if there are new changes then 
int pull(){ return 0;

}


// read from file where the current head is pointing
// must be the most recent commit otherwise will warn user
// then create a temp branch at the commit then prompt the user
// to open the GUI if they want to merge with the most current
// branch end
int commit(char* message){



}


int addFilesToVCS() {
  return 0;
}

 
int createConfigFile(){
  FILE *fp;
  fp = fopen("vcs/HEAD.conf", "w");
  if(fp == NULL){
    printf("Error Config file not initalized");
  }
  fprintf(fp, "currentBranch=main");
}

// creates an empty directory and checks for success;
// returns 0 on success, 1 on directory already exists, -1 on fail
int createEmptyDirectory(char* dirname){
  mode_t permissions = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP;
  errno = 0;
  int directorySuccess  = mkdir(dirname, permissions);
  if(errno == EEXIST){
    printf("directory already exists\n");
    return 1;
  }
  else if (directorySuccess != 0) {
    printf("error creating directory\n");
    return 1;
  }
  else {
    return 0;
  }
}
// this funciton will be more important in the future but currently is a glorified wrapper for 
// create empty directroy once ive implemented add and commit then i will work with branches
int newBranch(char* dirname, char* branchName) {
  int pathStringLength = sizeof(dirname) + sizeof(branchName) + sizeof("/");
  char branchPath[pathStringLength];
  printf("%s\n", branchPath);
  if(createEmptyDirectory(branchPath) == 1) {
    return 1;
  }
  return 0;
}

int init(){
  char* dirname = "vcs"; 
  if(createEmptyDirectory(dirname) == 1) {
    printf("failed vcs directory creation\n");
    return 1;
  }
  char* mainBranch = "vcs/main0";
  if(createEmptyDirectory(mainBranch) == 1){
    printf("failed initalizing main branch dir\n");
    return 1;
  }
  createConfigFile();
}

// string comparison, this function returns 0 if the same, 1 if not the same
int stringComparison(char* string1, char* string2){
  int lexographicComparison = strcmp(string1, string2);
  if (lexographicComparison == 0){
    return 0;
  }
  return 1;
}

// returns 0 to for matching corisiponding commandArray location to a certain one on the command list
// returns -1 if command not found
int findTheMatchingCommand(char* userCommand, char** commandArray){
  for(int i = 0; i < sizeof(commandArray); i++){
    printf("%s\n", commandArray[i]);
    if (stringComparison(userCommand, commandArray[i]) == 0) {
      return i;
    }
  }
  return -1;
}


int protocol(char* userCommand, char** commandArray) {

  int expression = findTheMatchingCommand(userCommand, commandArray);

  switch (expression) {
    case 0: // init
      init();
      break;
    case 1: // add
      break;
    case 2: // commit
      break;
    default:
      break;
  }
  return 0;
}

int main(int argc, char** argv) {
  printf("Hello World\n");
  char* commandArray[] = { "init", "add", "commit", "push" };
  printf("you typed %s\n", argv[1]);
  protocol(argv[1], commandArray);
  return 0;
}

