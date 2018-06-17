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

struct keys {
    int e;
    long long d;
    long long n;
};

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

void key_generator(struct keys &x) {
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
    x.e = e;
    x.d = d;
    x.n = n;
}

void print_key(struct keys mykey) {
    cout << "Public key: (" << mykey.e << ", " << mykey.n << "). Private key: (" << mykey.d << ", " << mykey.n << ")."  << endl;
}

int main(int argc, const char * argv[]) {
    vector<keys> key_bank;
    cout << "Welcome to RSA. You can do the following: " << endl;
    cout << "1. Generate random prime numbers for fun. (g)" << endl;
    cout << "2. Generate keys. (k)" << endl;
    cout << "3. Encrpyion. (e)" << endl;
    cout << "4. Decrption. (d)" << endl;
    cout << "5. Check my key bank. (c)" << endl;
    cout << "6. Quit. (q)" << endl;
    bool state = true;
    while (state) {
        char c;
        char which;
        cerr << "Command?" << endl;
        cin >> c;
        switch(c) {
            case 'g': {
                cout << "What security level number do you want? " << endl;
                cout << "Level 1: 3 digits" << endl
                    << "Level 2: 4 digits" << endl
                    << "Level 3: 5 digits" << endl
                    << "Level 4: 6 digits" << endl
                    << "Level 5: 7 digits" << endl;
                int temp;
                cin >> temp;
                cout << "Here is your prime: " << prime_generator(temp) << endl;
                break;
            }
            case 'k': {
                struct keys temp;
                key_generator(temp);
                key_bank.push_back(temp);
                cout << "Your key have been stored in the " << key_bank.size() << "th position" << endl;
                break;
            }
            case 'e': {
                cout << "Whether or not use the key from key bank? (y/n)" << endl;
                cin >> which;
                if (which == 'y') {
                    cout << "Which key do you want to use? Type in the key number: " << endl;
                    int x; cin >> x;
                    if (x >= key_bank.size()) {
                        cout << "Error: key does not exists" << endl;
                    }
                    string str;
                    getline(cin, str);
                    encrpte(key_bank[x - 1].e, key_bank[x - 1].n);
                } else {
                    string str;
                    getline(cin, str);
                    encrpte();
                }
                break;
            }
            case 'd': {
                cout << "Whether or not use the key from key bank? (y/n)" << endl;
                cin >> which;
                if (which == 'y') {
                    cout << "Which key do you want to use? Type in the key number: " << endl;
                    int x; cin >> x;
                    if (x >= key_bank.size()) {
                        cout << "Error: key does not exists" << endl;
                    }
                    string str;
                    getline(cin, str);
                    decrpte(key_bank[x - 1].d, key_bank[x - 1].n);
                } else {
                    decrpte();
                }
                break;
            }
            case 'c': {
                cout << "Print all keys? (y/n)" << endl;cin >> which;
                if (which == 'y') {
                    for (int i = 0; i < key_bank.size(); ++i) {
                        cout << i + 1 << "th key: ";
                        print_key(key_bank[i]);
                    }
                } else {
                    cout << "Which key do you want? Type in the key number: " << endl;
                    int x; cin >> x;
                    print_key(key_bank[x - 1]);
                }
                break;
            }
            case 'q':
                state = false;
                break;
            default:
                cout << "Invalid Command!" << endl;
        }
    }
    return 0;
}





