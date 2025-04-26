#include "CallNumber.hpp"
#include <string>
#include <iostream>
#include <ostream>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

CallNumber::CallNumber(string g, float s, string c) {
  genclass = g;
  subject = s;
  cutter = c;
}

CallNumber::CallNumber() {
  genclass = "\0";
  subject = 0;
  cutter = "\0";
}

CallNumber::~CallNumber() {
  cout << "@CallNumber Object Deleted" << endl;
}

string CallNumber::getClass() {
  return genclass;
}

float CallNumber::getSubject() {
  return subject;
}

string CallNumber::getCutter() {
  return cutter;
}

int CallNumber::getYear() {
  return year;
}

int CallNumber::getVolume() {
  return volume;
}

int CallNumber::getCopy() {
  return copy;
}

int CallNumber::compare(CallNumber cn) {
  if (this->genclass > cn.getClass()) {
    return true;
  } else if (this->genclass < cn.getClass()) {
    return false;
  }
  else {
     if (this->subject > cn.getSubject()) {
      return 1;
    } else if (this->subject < cn.getSubject()) {
      return -1;
    } else {
      if (this->cutter > cn.getCutter()) {
        return 1;
      } else if (this->cutter < cn.getCutter()) {
        return -1;
      }
      else {
        if (this->year > cn.getYear()) {
          return 1;
        }
        else if (this->year < cn.getYear()) {
          return -1;
        }
        else {
          if (this->volume > cn.getVolume()) {
            return 1;
          }
          else if (this->volume < cn.getVolume()) {
            return -1;
          }
          else {
            if (this->copy > cn.getCopy()) {
              return 1;
            }
            else if (this->copy < cn.getCopy()) {
              return -1;
            }
            else {
              return 0;
            }
          }
        }
      }
    }
  }
}

ostream& operator<<(ostream& rhs, CallNumber lhs) {
  rhs << lhs.getClass() + "." + std::to_string(lhs.getSubject()) + "." + lhs.getCutter();
  return rhs;
}
