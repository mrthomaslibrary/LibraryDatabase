#include <iostream>
#include <string>
#include <ostream>
using std::string;
using std::ostream;

class CallNumber {
private:
  string genclass;
  float subject;
  string cutter;
  int year;
  int volume;
  int copy;
public:
  CallNumber();
  CallNumber(string g, float s, string c);
  ~CallNumber();
  string getClass();
  float getSubject();
  string getCutter();
  int getYear();
  int getVolume();
  int getCopy();
  int compare(CallNumber cn);
};

ostream& operator<<(ostream &rhs, CallNumber lhs);
