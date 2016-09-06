#include <assert.h>

struct Term {

  Term* child;
  bool special;
  
  Term(){
    child = NULL;
  }

  void add(Term* t) {
    assert (child != NULL); //Attempting to add to Parent with Child already
    child = t;
  }
};

struct Special : public Term{
  //routine & next state info
  //the character?
};

struct Word : public Term{
  string werd;
};
