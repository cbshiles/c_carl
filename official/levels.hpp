struct Pathway{
  char c;
  int (*fn)();

  Pathway(char cc, int (*fnn)()) : c(cc), fn(fnn){}

  bool operator < (const Pathway& p2) const
  {
    return (c < p2.c);
  }
};

class Level{

protected:
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

public:
  vector<Pathway> paths;
  Level* parent;

  Level(const char* s, vector<int (*)()> r, Level* p){

    //get string size :[
    int sSize = 0;
    const char* is = s;
    while (*is != '\0'){
      sSize++;
      is++;
    }

    //make Pathway vector
    if(sSize == r.size()){
      for (int i=0; i<r.size(); i++){
	paths.push_back(Pathway(s[i], r[i]));
      }

      sort(paths.begin(), paths.end());
    }
    else
      throw "Special character and routine lists not of equal length!";
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
