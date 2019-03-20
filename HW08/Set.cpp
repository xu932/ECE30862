//
// Created by alex on 3/19/19.
//

#include "Set.h"

Set::Set(int n) : n_copy(0) {
    size = n / 32 + 1;
    arr = new uint32_t[size];
    for (int i = 0; i < size; i++)
        arr[i] = 0x0;
}

Set::Set(const Set& s) {
    size = s.size;
    n_copy = s.n_copy + 1;
    arr = new uint32_t[size];
    for (int i = 0; i < size; i++)
        arr[i] = s.arr[i];
}

Set::~Set() {
    if (arr)
        delete[] arr;
}

int Set::getCopyCount() {
    return n_copy;
}

void Set::operator=(const Set& s) {
    n_copy = s.n_copy;

    if (size != s.size) {
        size = s.size;
        delete arr;
        arr = new uint32_t[size];
    }

    for (int i = 0; i < size; i++)
        arr[i] = s.arr[i];
}

std::ostream& operator<<(std::ostream& os, const Set& s) {
    int last = -1;
    for (int i = 0; i < s.size; i++) {
        if (s.arr[i] != 0) {
            for (int j = 0; j < 32; j++) {
                if (s.arr[i] & (0x1 << j)) {
                    if (last != -1)
                        os << last << ", ";
                    last = i * 32 + j;
                }
            }
        }
    }
    os << last;
    return os;
}

#ifdef PARTA
Set Set::operator+(int n) {
    Set ret = Set(*this);
    if (n < ret.size * 32)
        ret.arr[n / 32] |= 0x1 << (n % 32);
    return ret;
}

Set Set::operator-(int n) {
    Set ret = Set(*this);
    if (n < ret.size * 32)
        ret.arr[n / 32] &= ~(0x1 << (n % 32));
    return ret;
}

Set Set::operator&(const Set& s) {
    Set ret = Set(*this);
    for (int i = 0; i < std::min(size, s.size); i++)
        ret.arr[i] = arr[i] & s.arr[i];
    return ret;
}

Set Set::operator~() {
    Set ret = Set(*this);
    for (int i = 0; i < size; i++)
        ret.arr[i] = ~arr[i];
    return ret;
}

Set Set::operator/(const Set& s) {
    Set ret = Set(*this);
    for (int i = 0; i < size; i++) {
        ret.arr[i] = arr[i] ^ (arr[i] & s.arr[i]);
    }
    return ret;
}
#endif

#ifdef PARTB

Set operator+(const Set& s, int n) {
    Set ret = Set(s);
    if (n < ret.size * 32)
        ret.arr[n / 32] |= 0x1 << (n % 32);
    return ret;
}

Set operator-(const Set& s, int n) {
    Set ret = Set(s);
    if (n < ret.size * 32)
        ret.arr[n / 32] &= ~(0x1 << (n % 32));
    return ret;
}

Set operator&(const Set& s1, const Set& s2){
    Set ret = Set(s1);
    for (int i = 0; i < std::min(s1.size, s2.size); i++)
        ret.arr[i] = s1.arr[i] & s2.arr[i];
    return ret;
}

Set operator~(const Set& s) {
    Set ret = Set(s);
    for (int i = 0; i < s.size; i++)
        ret.arr[i] = ~s.arr[i];
    return ret;
}

Set operator/(const Set& s1, const Set& s2) {
    Set ret = Set(s1);
    for (int i = 0; i < s1.size; i++) {
        ret.arr[i] = s1.arr[i] ^ (s1.arr[i] & s2.arr[i]);
    }
    return ret;
}

#endif