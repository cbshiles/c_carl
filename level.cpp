#include <vector>
#include <iostream>

using namespace std;


/* DIS DA COMPILA
   mainly an assortment of tools for the levels (or levels) to use
   has all the capabilities, but none of the drive
   levels take over and make use of it */

class Level{
public:
  vector<char> spec;
  vector<int (*)()> routes;
  Level* parent;

  Level(vector<char> s, vector<int (*)()> r, Level* p){
    if(s.size()==r.size()){
      spec = s;
      routes = r;
      parent = p;
    }
    else
      throw "Special character and routine lists not of equal length!";
  }

  int isSpec(char c){
    //checks if c is a special char
    //returns its index in spec[] if so, -1 otherwise

    int mid, low = 0, high = spec.size()-1;

    int ans;
    
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

  int checkSpec(char c){
    int x = isSpec(c);
    if (x != -1)
      (*routes[x])();
    return x;
  }
};


#define MAXWL 100 //max word length: 100

Level* clevel;
char wuff[MAXWL]; //word buffer
int wptr = 0; //pointer to current position in word
  
int add(char c){
  //returns 1 for a sucessful add, 0 if the buffer is full  or some other fail
  if (wptr < MAXWL){
    wuff[wptr++] = c;
    return 1;
  } else return 0;
}

void bead(char c){
  if (! clevel->checkSpec(c))
    add(c);
}

vector<char> cV(const char* c){
  vector<char> cv;

  while (*c != '\0'){
    cv.push_back(*(c++)); //would this work w/o parens?
  }
  return cv;
}

#include "levels.hpp"

int main(int argc, char *argv[]){
  try
    {
      clevel = new Root;
    } catch (const char* s) {
    cout << s << "\n";
    }
  return 0;
}



  //this is it, a fresh start

  //  int bead(char c)

  // sigh, ok major decision here. need to not rush, but come to a final conclusion
  //   so this wont be a constant nagging question
  //   do i want each level to simply have a giant function? so easy to do...
  // 	 might not be as fast, but gets rid of ridiculous libraries of functions
  // 	   is more free in the sense that the levels have no requirements besides have that one function that takes a char

  // 	   or is it better to have the structure of words and special characters?
  // 	   its a great way to have a very simple unobtrusive level of comprehension
  // 	   all code will have variable names which will have no inherent meaning to the compiler
  // 	   this stuff, if nothing else, is the words, and all else special characters [this is the way to do it, winner]

  // so, nothing should have to be done in terms of a 'normal function' (for handling non-special characters)
  //   it should be standard, regardless of level, because it is simply making a word, and finding spec chars should be standardized,
  //   so it is easy to ooptimize (without changing a bunch of code)

  //   so yeah, as we know, a level needs a list of special chars and a list of equal length containing functions defining behavior when a special character is called or hit or whatever. [ok, sidenote: there should be a variable in the compiler that is the current character being dealt with. this way spec char funks can refernce this char and be the same funk while storing character specific info. (whew)]

  //   the end result of this level of parsing is going to be very simple it is words and directions to other levels
  //   pop + soda -> drank (simply a chain of words)
  //   ( po + p ) + soda -> drank   (enter sublevel (words) exit sublevel) words

  //   it can be expressed as a list of objects that are either a word or a direction to another level
  //   the next (separate) level of operation is the compiler starting at root level as current level, switcching whenever it comes upon those pobjects, and feeding th ewords from the other objects into whatever the current level is

  //   it seems like that level will require functors or for each level to be a subclass of level (making them subclasses would be better)
