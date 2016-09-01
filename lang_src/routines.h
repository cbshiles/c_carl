struct State* nada(){ //do nothing
  return curr_state;
}

int nado(char c){ //do nothing
  return 1;
}

struct State* erra(){ //illegal call
  return curr_state; //#soon make this error state
}

struct State* loop_a(){
  return curr_state;
}

struct State* def_a(){
  return curr_state;
}

struct State* phr_a(){
  return curr_state;
}

struct State* l_str_a(){
  return curr_state;
}

struct State* v_str_a(){
  return curr_state;
}

char acc[1000];
char* acc_ptr;

int acc_clear(){
  acc[0] = '\0';
  acc_ptr = &acc[0];
}

int acc_add(char c){//add a character to the accumulator string
  *acc_ptr = c;
  *(++acc_ptr) = '\0';
  return acc_ptr < &acc[1000];
}

struct State* acc_r(){
  acc_add(curr_char);
  return curr_state;
}

char c_file[10000]; //string for holding the c code that the carl code is translaed into
char* c_ptr;

void add_cf(char* str){
  while (*str != '\0'){
    *c_ptr++ = *str++;
  }
  return;
}

struct State* b_str_a(){ //thiis the thingy, but meybe do nothin
  return &di_str;
}

struct State* b_str_z(){ //unload direct insertion string into c_file
  add_cf(&acc[0]);
  acc_clear();
  return &init;
}
