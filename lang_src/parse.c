#include <stdio.h>
#include <string.h>
#include "state.h"
#include "compiler.hpp"

char spec[] = "\t\n \"\'()[]`{}"; //special characters in ascii order
char spec_len = 12;

int sp_search(char c){
  //checks if c is a special char
  //returns its index in spec[] if so, -1 otherwise

  int mid, low = 0, high = spec_len-1;

  while (high > low){
    mid = (high+low)/2;

    if (c <= spec[low])
      return c == spec[low] ? low : -1;
  
    else if (c >= spec[high])
      return c == spec[high] ? high : -1;

    else {
      char diff = c - spec[mid];
      if (diff < 0) high = mid-1;
      else if (diff > 0) low = mid+1;
      else return mid;
    }
  }
  return -1;
}

struct State* bead(char c){ //like on a rosary
  curr_char = c;
  
  //check if special
  int s = sp_search(c);
  if (s >= 0) { //if is a special...
    return (*curr_state).routes[s]();
  }
  else {//add to the currently accumulating word
    //the definitions for ops  get bootstrapped in by special characters
    (*curr_state).regular(c);
    return curr_state;
  }
}

int main(int argc, char *argv[]){
  FILE *fptr;
  
  if (!(fptr = fopen(argv[1], "r"))){
    printf("Couldn't open file.");
    return 1;
  }

  char buf[1000]; //line size limitation, lame

  begin();
  
  char * ip;
  while (fgets(buf,1000, fptr)!=NULL){
    ip = buf;
    while (*ip){
      curr_state = bead(*ip++);
    }
  }

  printf("%s\n", c_file);
  
  fclose(fptr);
  return 0;
}
