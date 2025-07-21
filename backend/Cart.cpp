#include "Cart.hpp"
#include <iostream>
#include <iomanip>

Cart::Cart() {
  rootBook = new Book(CallNumber("A", 0, "\0", 0), "NULL", "NULL");
 // rootBook->nextGClass = new Book(CallNumber("ZZZZZ", 99999, "Z9999", 99999), "NULL", "NULL");
}

Cart::~Cart() {}

void Cart::addBook(Book *newBook) {
  Book *currentBook = rootBook;
  while (currentBook) {
    if (newBook->getCallNumber().getGClass() == currentBook->getCallNumber().getGClass()) {
      break;
    }
    else if (newBook->getCallNumber().getGClass() < currentBook->getCallNumber().getGClass()) {
      newBook->nextGClass = currentBook->nextGClass;
      currentBook->nextGClass = newBook;
    }
    else if (currentBook->nextGClass){
      currentBook = currentBook->nextGClass;
    }
    else {
      currentBook->nextGClass = newBook;
      break;
    }
  }
  while (currentBook) {
    if (newBook->getCallNumber().getSubject() == currentBook->getCallNumber().getSubject()) {
      break;
    }
    else if (newBook->getCallNumber().getSubject() > currentBook->getCallNumber().getSubject()) {
      newBook->nextSubject = currentBook->nextSubject;
      currentBook->nextSubject = newBook;
    }
    if (currentBook->nextSubject) {
      currentBook = currentBook->nextSubject;
    }
    else {
      currentBook->nextSubject = newBook;
      break;
    }
  }
  while (currentBook) {
    if (newBook->getCallNumber().getCutter() == currentBook->getCallNumber().getCutter()) {
      break;
    }
    else if (newBook->getCallNumber().getCutter() > currentBook->getCallNumber().getCutter()) {
      newBook->nextCutter = currentBook->nextCutter;
      currentBook->nextCutter = newBook;
    }
    if (currentBook->nextCutter) {
      currentBook = currentBook->nextCutter;
    }
    else {
      currentBook->nextCutter = newBook;
      break;
    }
  }
  while (currentBook) {
    if (newBook->getCallNumber().getGClass() == currentBook->getCallNumber().getGClass()) {
      break;
    }
    else if (newBook->getCallNumber().getGClass() > currentBook->getCallNumber().getGClass()) {
      newBook->nextGClass = currentBook->nextGClass;
      currentBook->nextGClass = newBook;
    }
    if (currentBook->nextSubject) {
      currentBook = currentBook->nextGClass;
    }
    else {
      currentBook->nextCopy = newBook;
      break;
    }
  }
}

void Cart::displayCart() {
  int count = 0;
  Book *genBook = rootBook;
  std::cout << "|\tCallNum\t\t|\tTitle\t\t|\tAuthor\t\t|" << std::endl;
  while(genBook) {
    Book *subBook = genBook;
    while (subBook) {
      Book *cutBook = subBook;
      while (cutBook) {
        Book *copyBook = cutBook;
        while (copyBook) {
          std::cout << "|\t" + copyBook->getTitle() + "\t\t\t|\t" + copyBook->getAuthor() + "\t\t\t|\t" + copyBook->getCallNumber().getFullCallNumber() << std::endl;
          count++;
          copyBook = copyBook->nextCopy;
        }
        cutBook = cutBook->nextCutter;
      }
      subBook = subBook->nextSubject;
    }
    genBook = genBook->nextGClass;
  } 
  std::cout << count << std::endl;
}
