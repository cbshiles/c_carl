#define test(s) ut.call(s, #s) 

//call your unit test 'ut' due to the macro above

struct UnitTest {

  UnitTest(){
    valid = 1;
  }

  int valid;
  
  void call(int truth, string str){
    valid &= truth;
    if (!truth){
      cout << "Test failed: "+str+"\n";
    }
  }

  void finish(){
    printf("All the tests were%s passed\n", valid?"":" not");
  }
};
