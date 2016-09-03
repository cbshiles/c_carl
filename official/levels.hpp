struct Pathway{
  char c;
  int (*fn)();

  Pathway(char cc, int (*fnn)()) : c(cc), fn(fnn){}
};


bool comparePaths(const Pathway *p1, const Pathway *p2){
  return p1->c < p2->c;
}


class Level{

// protected:
//   vector<char> cV(const char* c){ // turns a c-style string into a character vector
//     vector<char> cv;

//     while (*c != '\0'){
//       cv.push_back(*(c++)); //would this work w/o parens?
//     }
//     return cv;
//   }

public:
  vector<Pathway> paths;
  // vector<char> spec;
  // vector<int (*)()> routes;
  Level* parent;

  Level(const char* s, vector<int (*)()> r, Level* p){
    //    vector<char> spec = cV(s);

    int sSize = 0;
    const char* is = s;
    while (*is != '\0'){
      sSize++;
      is++;
    }
    
    if(sSize == r.size()){

      for (int i=0; i<r.size(); i++){
	paths.push_back(Pathway(s[i], r[i]));
      }
      
      // routes = r;
      // parent = p;
    }
    else
      throw "Special character and routine lists not of equal length!";
  }

  int isSpec(char c){
    //checks if c is a special char
    //returns its index in spec[] if so, -1 otherwise

    int mid, low = 0, high = paths.size()-1;

    int ans;
    
    while (high > low){
      mid = (high+low)/2;

      if (c <= paths[low].c)
	return c == paths[low].c ? low : -1;
  
      else if (c >= paths[high].c)
	return c == paths[high].c ? high : -1;

      else {
	char diff = c - paths[mid].c;
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
      (*(paths[x].fn))();
    return x;
  }


};

int spacer(){
  //if length >= 1, throw current word to next dimension
  return 1;
}

int opening(){
  //switch to new level depending on char?
  return 1;
}

int newline(){
  throw "Haven't got around to the newline yet.";
}

int closing(){
  throw "Closing bracket called without preceding opening bracket.";
}


class Root: public Level{

public:
  Root(): Level("\t\n \"\'()[]`{}", {spacer,newline,spacer, opening,
	opening, opening, closing, opening, closing, opening, opening, closing} , NULL)
  {

  }
  
};
