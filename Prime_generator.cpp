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
using namespace Dodecahedron;
using namespace std;

//This is a dangerous function, must make should overload won't appear
int convert(Bigint x) {
    string str = to_string(x);
    int temp = stoi(str);
    return temp;
}

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

bool fermat_prime_test(Bigint x) {
    if (module(x, 2)[0] == 0) {
        return false;
    } else {
        for (int i = 1; i < 5; ++i) {
            cout << i << endl;
            srand(static_cast<unsigned int>(time(NULL)));
            Bigint random = rand() % 100;
            if (module( random.pow(convert(x-1)) , x) == 1) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int prime_generator(int security_level) {
    Bigint candidate = 0;
    while (candidate < 100) {
        srand(static_cast<unsigned int>(time(NULL)));
        candidate = rand() % 1000;
    }
    candidate = candidate.pow(security_level);
    cout << candidate << endl;
    while (!fermat_prime_test(candidate)) {
        candidate += 1;
        cout << candidate << endl;
    }
    return convert(candidate);
}

int fake_prime_generator(int security_level) {
    int candidate = 0;
    while (candidate < 100) {
        srand(static_cast<unsigned int>(time(NULL)));
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



