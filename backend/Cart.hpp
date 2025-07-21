#pragma once
#include "Book.hpp"

class Cart {
  private:
  //Book *rootBook;

public:
  Book *rootBook;
  Cart();
  ~Cart();
  void addBook(Book *newBook);
  void displayCart();
};
