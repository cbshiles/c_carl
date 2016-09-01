//# well this i shit isnt it....

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
  Root(): Level(cV("\t\n \"\'()[]`{}"), {spacer,newline,spacer, opening,
	opening, opening, closing, opening, closing, opening, opening, closing} , 0)
  {

  }
  
};
