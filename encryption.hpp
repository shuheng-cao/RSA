//
//  encryption.hpp
//  RSA
//
//  Created by shuster on 2018/6/3.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#ifndef encryption_hpp
#define encryption_hpp

#include "bigint.h"
#include <stdio.h>
using namespace std;

//Convert a string into long long integer, this is not normal convert as I minus every char by 27 in order to fit in a two digits int
void string_to_ints(string str, unsigned long long &temp, size_t len);

//Shift the bigint x by certain digits
void shift(Dodecahedron::Bigint &x, int digits);

//power_module will do the (x^power) % mode in the quick way
unsigned long long power_module(unsigned long long x, unsigned long long power, unsigned long long mode);

//encrpte consumes two numbers and need user to type in a text
void encrpte(unsigned int e, unsigned long long n);

//This encrpt need user to tyope in two numbers together with a text
void encrpte(void);

#endif /* encryption_hpp */
