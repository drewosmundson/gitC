// Drew Osmundson

#include <stdio.h>
#include <string.h>

int init(){
  printf("Initializing Repo");
    
}


// string comparison, this function returns 0 if the same, 1 if not the same
int stringComparison(const char* string1, const char* string2){
  int lexographicComparison = strcmp(string1, string2);
  if (lexographicComparison == 0){
    return 0;
  }
  return 1;
}

// returns 0 to for matching corisiponding commandArray location to a certain one on the command list
// returns -1 if command not found
int findTheMatchingCommand(char* command, char** commandArray){
  for(int i = 0; i < sizeof(commandArray); i++){
    if (stringComparison(command, commandArray[i]) == 0) {
      return i;
    }
  }
  return -1;
}

int protocol(char* command, char** commandArray) {

  int expression = findTheMatchingCommand(command, commandArray);

  switch (expression) {

  case 0: // init
    
    break;
  case 1: // add

    break;
  
  case 2: // commit

  default:
    break;
  }
  return 0;
}

int main(int argc, char** argv) {
  printf("Hello World\n");
  const char* commandArray[] = { "init", "add", "commit", "push" };
  printf("you typed %s\n", argv[1]);
  protocol(argv[1], commandArray);
  return 0;
}

