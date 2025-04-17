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

int CallNumber::compare(CallNumber cn) {
  if (this.genclass > cn.genclass) {
    return true
  } else if (this.genclass < cn.genclass) {
    false;
  }
  else {
     if (this.subject > cn.subject) {
      return 1;
    } else if (this.genclass < cn.genclass) {
      return -1;
    }
    else {
      if (this.cutter > cn.cutter) {
        return 1;
      } else if (this.cutter < cn.cutter) {
        return -1;
      }
      else {
        if (this.year > cn.year) {
          reutrn 1;
        }
        else if (this.year < cn.year) {
          return -1;
        }
        else {
          if (this.volume > cn.volume) {
            return 1;
          }
          else if (this.volume < cn.volume) {
            return -1;
          }
          else {
            if (this.copy > cn.copy) {
              return 1;
            }
            else if (this.copy < cn.copy) {
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
  rhs << lhs.genclass + "." + lhs.subject + "." + lhs.cutter;
  return rhs;
}
