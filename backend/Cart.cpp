#include "Cart.hpp"
#include <iostream>
#include <iomanip>

Cart::Cart() {
  rootBook = nullptr;
 // rootBook->nextGClass = new Book(CallNumber("ZZZZZ", 99999, "Z9999", 99999), "NULL", "NULL");
}

Cart::~Cart() {}
/*
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
*/

void Cart::addBook(Book* newBook) {
  if (rootBook) {
    if (!rootBook) {
        rootBook = newBook;
        return;
    }

    // STEP 1: GCLASS LEVEL
    Book* gPrev = nullptr;
    Book* gCurr = rootBook;

    while (gCurr && newBook->getCallNumber().getGClass() > gCurr->getCallNumber().getGClass()) {
        gPrev = gCurr;
        gCurr = gCurr->nextGClass;
    }

    // GClass match found
    if (gCurr && newBook->getCallNumber().getGClass() == gCurr->getCallNumber().getGClass()) {
        // Proceed down into subject level
    } else {
        // Insert new gClass node
        if (gPrev) {
            gPrev->nextGClass = newBook;
            newBook->nextGClass = gCurr;
        } else {
            newBook->nextGClass = rootBook;
            rootBook = newBook;
        }
        return; // No need to go further; no sublists yet
    }

    // STEP 2: SUBJECT LEVEL
    Book* subjectHead = gCurr;
    Book* sPrev = nullptr;
    Book* sCurr = subjectHead->nextSubject;

    while (sCurr && newBook->getCallNumber().getSubject() > sCurr->getCallNumber().getSubject()) {
        sPrev = sCurr;
        sCurr = sCurr->nextSubject;
    }

    if (sCurr && newBook->getCallNumber().getSubject() == sCurr->getCallNumber().getSubject()) {
        // Proceed down into cutter level
    } else {
        // Insert new subject node
        if (sPrev) {
            sPrev->nextSubject = newBook;
            newBook->nextSubject = sCurr;
        } else {
            subjectHead->nextSubject = newBook;
            newBook->nextSubject = sCurr;
        }
        return;
    }

    // STEP 3: CUTTER LEVEL
    Book* cutterHead = sCurr;
    Book* cPrev = nullptr;
    Book* cCurr = cutterHead->nextCutter;

    while (cCurr && newBook->getCallNumber().getCutter() > cCurr->getCallNumber().getCutter()) {
        cPrev = cCurr;
        cCurr = cCurr->nextCutter;
    }

    if (cCurr && newBook->getCallNumber().getCutter() == cCurr->getCallNumber().getCutter()) {
        // Proceed down into copy level
    } else {
        if (cPrev) {
            cPrev->nextCutter = newBook;
            newBook->nextCutter = cCurr;
        } else {
            cutterHead->nextCutter = newBook;
            newBook->nextCutter = cCurr;
        }
        return;
    }

    // STEP 4: COPY LEVEL
    Book* copyHead = cCurr;
    Book* copyPrev = nullptr;
    Book* copyCurr = copyHead->nextCopy;

    while (copyCurr && newBook->getCallNumber().getCopy() > copyCurr->getCallNumber().getCopy()) {
        copyPrev = copyCurr;
        copyCurr = copyCurr->nextCopy;
    }

    // Final insert in copy level
    if (copyPrev) {
        copyPrev->nextCopy = newBook;
        newBook->nextCopy = copyCurr;
    } else {
        copyHead->nextCopy = newBook;
        newBook->nextCopy = copyCurr;
    }
  }
  else {
    rootBook = newBook;
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
