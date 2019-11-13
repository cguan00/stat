#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// Write a program that uses stat to display the following information about a file:
// file size
// mode (permissions)
// time of last access (displayed in the following format: Fri Oct 28 09:03:01 2016

int main(){
  struct stat sb;
  stat("README.md", &sb);

  return 0;
}
