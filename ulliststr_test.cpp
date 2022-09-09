//* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_back("0");
  dat.push_back("1");
  dat.push_back("2");
  dat.push_back("3");
  dat.push_back("4");
  dat.push_back("5");
  dat.push_back("6");
  dat.push_back("7");
  dat.push_back("8");
  dat.push_back("9");
  dat.push_back("10");
  dat.push_back("11");
  dat.push_back("12");
  dat.push_back("13");
  dat.push_back("14");
  dat.push_back("15");
  dat.push_back("16");
  dat.push_back("17");
  dat.push_back("18");
  dat.push_back("19");
  dat.push_back("20");
  dat.push_back("21");
  dat.push_back("22");
  dat.push_back("23");
  dat.push_back("24");
  dat.push_back("25");
  cout << dat.front() << endl;
  cout << dat.back() << endl;
  cout << "first test" << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << " " << dat.get(4) << " " << dat.get(5) << " " << endl;
  cout << "second test" << dat.get(6) << " " << dat.get(7) << " " << dat.get(8) << " " << dat.get(9) << " " << dat.get(10) << " " << dat.get(11) << " " << endl;
  cout << dat.size() << endl; 
  dat.pop_front();
  dat.pop_back();
  cout << dat.front() << endl;
  cout << dat.back() << endl;
  dat.pop_back();
  
  return 0;
}
