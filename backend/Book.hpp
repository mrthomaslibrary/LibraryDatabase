#include "CallNumber.hpp"

class Book {
private:
  CallNumber callnumber;
  int barcode;
public:
  Book();
  Book(CallNumber cn, int b);
  ~Book();
  CallNumber getCallNumber();
  int getBarcode();
};
