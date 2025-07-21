#include "CallNumber.hpp"
#include <string>

class Book {
private:
  CallNumber callnum;
  std::string title;
  std::string author;

public:
  Book(const CallNumber cn, const std::string t, const std::string a);
  ~Book();
  CallNumber *nextGClass;
  CallNumber *nextSubject;
  CallNumber *nextCutter;
  CallNumber *nextCopy;
};
