//
//  decrption.cpp
//  RSA
//
//  Created by shuster on 2018/6/3.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include <iostream>
#include "decrption.hpp"
#include "encryption.hpp"
using namespace Dodecahedron;
using namespace std;

Bigint remaining_digits(Bigint x, int n) {
    if (x.digits() <= n) {
        return 0;
    }
    Bigint temp = 0;
    int length = x.digits();
    for (int i = 0; i < length - n; ++i) {
        temp = temp * 10 + x.operator[](i);
    }
    return temp;
}

unsigned long long last_n_digits(Bigint x, int n) {
    if (x.digits() <= n) {
        string str = to_string(x);
        unsigned long long temp = stoll(str);
        return temp;
    }
    unsigned long long temp = 0;
    int length = x.digits();
    for (int i = n; i > 0; --i) {
        temp = temp * 10 + x.operator[](length - i);
    }
    return temp;
}

void decrpte(long long d, long long n) {
    Bigint code;
    string ans = "";
    cout << "Please type in the text you want to decrpty: " << endl;
    cin >> code;
    while (code.digits() > 0) {
        unsigned long long temp = last_n_digits(code, 10);
        code = remaining_digits(code, 10);
        unsigned long long original = power_module(temp, d, n);
        while (original != 0) {
            ans = static_cast<char>(original % 100 + 27) + ans;
            original /= 100;
        }
    }
    cout << "Decrption completed! Original text is: " << endl;
    cout << ans << endl;
}

void decrpte(void) {
    Bigint code;
    long long d, n;
    string ans = "";
    cout << "Please type in the text you want to decrpty: " << endl;
    cin >> code;
    cout << "Please type in the public keys" << endl;
    cin >> d >> n;
    while (code.digits() > 0) {
        unsigned long long temp = last_n_digits(code, 10);
        code = remaining_digits(code, 10);
        unsigned long long original = power_module(temp, d, n);
        while (original != 0) {
            ans = static_cast<char>(original % 100 + 27) + ans;
            original /= 100;
        }
    }
    cout << "Decrption completed! Original text is: " << endl;
    cout << ans << endl;
}

