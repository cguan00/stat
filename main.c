#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

// Write a program that uses stat to display the following information about a file:
  // file size
  // mode (permissions)
  // time of last access (displayed in the following format: Fri Oct 28 09:03:01 2016

// Once you have that, try the following:
// Modify the size so it is printed out in human readable form (that is using B, KB, MB, GB).
  // You may want to look into the sprintf function to help.
// Attempt to print out the permissions in ls -l form, ignoring the early bits that include the file type information
  // Permissions are of type mode_t, which is an integer type.
  // The permissions section of the mode is stored in the last 9 bits of the mode_t data type.

int main(){
  struct stat file;
  int error = stat("main.c", &file);
  if (error == -1) {
    printf("Error: %s", strerror(errno));
    return 0;
  }

  printf("File size: %lld \n", file.st_size);
  printf("Mode (permissions): %o\n", file.st_mode);
  time_t accessTime = file.st_atime;
  printf("Time of last access: %s\n", ctime(&accessTime));

  char p[100];
  sprintf(p, "%o", file.st_mode & 511);


    long fSize = file.st_size;
    int x = 0;
    while(fSize >= 1024){
      fSize /= 1024;
      x += 1;
      if(x == 3){
        break;
      }
    }

    char * sizeStr;
    if(x == 0){
      sizeStr = "B";
    }
    if(x == 1){
      sizeStr = "KB";
    }
    if(x == 2){
      sizeStr = "MB";
    }
    if(x == 3){
      sizeStr = "GB";
    }

    printf("File size in readable human form: %ld %s\n", fSize , sizeStr);




  printf("Mode (permissions) in human readable form: ");
  int i = 0;
  for (; i < 3; i++) {
    if (p[i] == '0') {
      printf("---");
    } else if (p[i] == '1') {
      printf("--x");
    } else if (p[i] == '2') {
      printf("-w-");
    } else if (p[i] == '3') {
      printf("-wx");
    } else if (p[i] == '4') {
      printf("r--");
    } else if (p[i] == '5') {
      printf("r-x");
    } else if (p[i] == '6') {
      printf("rw-");
    } else {
      printf("rwx");
    }
  }
  printf("\n");


  return 0;
}
