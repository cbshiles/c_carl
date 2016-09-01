struct State {
  struct State* (*routes[12])();
  int (*regular)(char c);
  int norm(char c);
  //other stuff for handling ops!

  int spec(char c){return 0;};
};

struct State states[30];

struct State* curr_state;

char curr_char; //being read 

struct State init, di_str;

#include "routines.h"

struct State* (*init_r[12])() = {&nada, &nada, &nada,	\
		       &v_str_a, &l_str_a,	\
		       &phr_a, &erra,		\
		       &loop_a, &erra,		\
		       &b_str_a, &def_a, &erra};

struct State* (*di_r[12])() = {&acc_r, &acc_r, &acc_r,	\
			       &acc_r, &acc_r, &acc_r,	\
			       &acc_r, &acc_r, &acc_r,	\
			       &b_str_z, &acc_r, &acc_r};

void assign (struct State* st, struct State* (**roots)(), int (*reg)(char)){
  for (int i=0; i<12; i++){
    (*st).routes[i] = *(roots+i);
  }
  (*st).regular = (*reg);
  return;
}

void begin(){
  assign(&init, &init_r[0], &nado);
  assign(&di_str, &di_r[0], &acc_add);
  curr_state = &init;
  acc_ptr = &acc[0];
  c_ptr = &c_file[0];
}
