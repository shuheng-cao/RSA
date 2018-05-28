//
//  Prime_generator.cpp
//  RSA
//
//  Created by shuster on 2018/5/27.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include "Prime_generator.h"
#include "bigint.h"
using namespace Dodecahedron;
using namespace std;

Bigint power(Bigint x, Bigint y) {
    Bigint p = 1;
    for (Bigint i = 0; i < y; i += 1) {
        p *= x;
    }
    return p;
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
            //cout << remainder << " " << denominator << endl;
            //cout << y << " " << z << " " << w << endl;
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
        for (int i = 1; i < 10; ++i) {
            srand(time(NULL));
            //cout << y << endl;
            cout << power(i, x-1) << endl;
            cout << module( power(i, x - 1) , x ) << endl;
            if (module( power(i, x - 1) , x ) == 1) {
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

Bigint prime_generator(int security_level) {
    Bigint candidate = 0;
    while (candidate < 100) {
        srand(time(NULL));
        candidate = rand() % 1000;
    }
    candidate = power(candidate, security_level);
    cout << candidate << endl;
    while (!fermat_prime_test(candidate)) {
        candidate += 1;
        cout << candidate << endl;
    }
    return candidate;
}





