#include "Book.hpp"

Book::Book() {

}

Book::Book(CallNumber cn, int b) {
  callnumber = cn;
  barcode = b;
}

Book::~Book() {

}

CallNumber Book::getCallNumber() {
  return callnumber;
}

int Book::getBarcode() {
  return barcode;
}
