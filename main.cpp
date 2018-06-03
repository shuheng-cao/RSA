//
//  main.cpp
//  RSA
//
//  Created by shuster on 2018/5/27.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <fstream>
#include <bitset>
#include "bigint.h"
#include "Prime_generator.h"
#include "encryption.hpp"
#include "decrption.hpp"
using namespace std;
using namespace Dodecahedron;

void Extended_Euclid(long long big, long long small, long long &count_big, long long &count_small) {
    if (small == 0) {
        count_big = 1;
        count_small = 0;
    } else {
        long long temp_big = 0;
        long long temp_small = 0;
        Extended_Euclid(small, big % small, temp_big, temp_small);
        count_big = temp_small;
        count_small = temp_big - (big / small) * temp_small;
    }
}


int main(int argc, const char * argv[]) {
    //Generate Public and Private Key
    int security = 1;
    cout << "Please enter the sercurity level you want: (1~5)" << endl;
    cin >> security;
    long long n = 0, phi = 0;
    int e = 1;
    while (n <= 0) {
        int p = fake_prime_generator(security), q = fake_prime_generator(security);
        n = p * q;
        phi = (p - 1) * (q - 1);
        long long mod = phi % e;
        while (mod == 0) {
            e = fake_prime_generator(security);
            mod = phi % e;
        }
    }
    
    long long cnt1 = 0;
    long long cnt2 = 0;
    Extended_Euclid(phi, e, cnt1, cnt2);
    long long d = cnt2;
    while (d <= 0 || d >= phi) {
        (d <= 0) ? d += phi : d -= phi;
    }
    
    if ((d*e)%phi != 1) {
        cout << "Sorry, unexpected error occurs. Please reopen the program" << endl;
    }
    
    cout << "What's to do next? You can do the following: " << endl;
    cout << "1. See public key. (p)" << endl;
    cout << "2. See secret key. (s)" << endl;
    cout << "3. Encrpyion. (e)" << endl;
    cout << "4. Decrption. (d)" << endl;
    cout << "5. Quit. (q)" << endl;
    bool state = true;
    while (state) {
        char c;
        char which;
        cerr << "Command?" << endl;
        cin >> c;
        switch(c) {
            case 'p':
                cout << "Your public key is: " << "(" << e << "," << n << ")" << endl;
                break;
            case 's':
                cout << "Your secret key is: " << "(" << d << "," << n << ")" << endl;
                break;
            case 'e': {
                cout << "Whether or not use the key just generate? (y/n)" << endl;
                cin >> which;
                if (which == 'y') {
                    string str;
                    getline(cin, str);
                    encrpte(e, n);
                } else {
                    string str;
                    getline(cin, str);
                    encrpte();
                }
                break;
            }
            case 'd':
                //decrpte(d, n);
                break;
            case 'q':
                state = false;
                break;
            default:
                cout << "Invalid Command!" << endl;
        }
    }
    return 0;
}
