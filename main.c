#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

// Write a program that uses stat to display the following information about a file:
// file size
// mode (permissions)
// time of last access (displayed in the following format: Fri Oct 28 09:03:01 2016

int main(){
  struct stat file;
  stat("main.c", &file);

  printf("File size: %lld \n", file.st_size);
  printf("Mode (permissions): %o\n", file.st_mode);
  time_t accessTime = file.st_atime;
  printf("Time of last access: %s\n", ctime(&accessTime));

  return 0;
}
