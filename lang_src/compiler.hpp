/* DIS DA COMPILA
   mainly an assortment of tools for the states (or levels) to use
   has all the capabilities, but none of the drive
   states take over and make use of it */

#define MAXWL 100 //max word length: 100

class Compiler{

  State* cstate;

  void bead(char c){
    if (! cstate->spec(c))
      cstate->norm(c);
  }

public:
  
  char wuff[MAXWL]; //word buffer
  int wptr; //pointer to current position in word



  Compiler(){
    wptr = 0;
  }
  
  int add(char c){
    //returns 1 for a sucessful add, 0 if the buffer is full  or some other fail
    if (wptr < MAXWL){
      wuff[wptr++] = c;
      return 1;
    } else return 0;
  }
  
};
  
