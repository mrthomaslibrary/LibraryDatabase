#pragma once
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
  Book *nextGClass;
  Book *nextSubject;
  Book *nextCutter;
  Book *nextCopy;

  CallNumber getCallNumber() const;
  std::string getTitle() const;
  std::string getAuthor() const;
};
