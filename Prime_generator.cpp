//
//  Prime_generator.cpp
//  RSA
//
//  Created by shuster on 2018/5/27.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "Prime_generator.h"
#include "bigint.h"
#include "encryption.hpp"
using namespace Dodecahedron;
using namespace std;

Bigint divide(Bigint numerator, Bigint denominator) {
    Bigint remainder = numerator;
    Bigint quotient = 0;
    while (remainder >= denominator) {
        int y = remainder.digits() - denominator.digits();
        if (y > 2) {
            Bigint backup = denominator;
            Bigint ten = 10;
            Bigint z = ten.pow(y - 1);
            Bigint w = backup * z;
            quotient += z;
            remainder -= w;
        } else {
            remainder -= denominator;
            quotient += 1;
        }
    }
    return quotient;
}

Bigint module(Bigint numerator, Bigint denominator) {
    Bigint remainder = numerator;
    while (remainder >= denominator) {
        int y = remainder.digits() - denominator.digits();
        if (y > 2) {
            Bigint backup = denominator;
            Bigint ten = 10;
            Bigint z = ten.pow(y - 1);
            Bigint w = backup * z;
            remainder -= w;
        } else {
            remainder -= denominator;
        }
    }
    return remainder;
}

bool fermat_prime_test(unsigned long long x) {
    for (int i = 1; i < 5; ++i) {
        //For debug
        //cout << i << endl;
        int random = rand() % 100;
        if (power_module(random, x - 1, x) == 1) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

unsigned long long prime_generator(int security_level) {
    unsigned long long candidate = 0;
    for (int i = 0; i < security_level + 2; ++i) {
        int random = rand() % 10;
        while (i == 0 && random == 0) { //We need the first digit to be non-zero
            random = rand() % 10;
        }
        candidate = candidate * 10 + random;
    }
    while (!fermat_prime_test(candidate)) {
        candidate += 1;
        //For debug
        //cout << candidate << endl;
    }
    return candidate;
}

int fake_prime_generator(int security_level) {
    int candidate = 0;
    while (candidate < 100) {
        //srand(static_cast<unsigned int>(time(NULL)));
        candidate = rand() % 1000;
    }
    candidate += (security_level - 1) * 1000;
    ifstream infile;
    //Warning: the absolute path need to change from computer to computer
    infile.open("/Users/caoshuheng\ 1/Desktop/primelist.txt");
    string str;
    while (candidate--) {
        infile >> str;
    }
    return stoi(str);
}



