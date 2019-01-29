#include "Base.h"

Base::Base( ) : privB(1), protB(2), publicB(3) {  }

Base::~Base( ) { }

void Base::print( ) {
   cout << "Base" << endl;
   cout << "privB: " << privB;
   cout << ", protB: " << protB;
   cout << ", publicB: " << publicB; 
   cout << endl << endl;
}


int Base::getPrivB() {
    return privB;
}

void Base::setPrivB(int val) {
    privB = val;
}

int Base::getProtB() {
    return protB;
}

void Base::setProtB(int val) {
    protB = val;
}
