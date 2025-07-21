#include "Book.hpp"
#include "CallNumber.hpp"
#include <string>

Book::Book(const CallNumber cn, const std::string t, const std::string a) {
  callnum = cn;
  title = t;
  author = a;
  nextGClass = nullptr;
  nextSubject = nullptr;
  nextCutter = nullptr;
  nextCopy = nullptr;
}

Book::~Book() {}

CallNumber Book::getCallNumber() const {
  return callnum;
}

std::string Book::getTitle() const {
  return title;
}

std::string Book::getAuthor() const {
  return author;
}
