#include "Book.hpp"
#include "CallNumber.hpp"
#include <string>

Book::Book(const CallNumber cn, const std::string t, const std::string a) {
  callnum = cn;
  title = t;
  author = a;
}

Book::~Book() {}



