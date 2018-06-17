//
//  Prime_generator.hpp
//  RSA
//
//  Created by shuster on 2018/5/27.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include "bigint.h"
#include <iostream>
using namespace Dodecahedron;

//Define integer division in Bigint
Bigint divide(Bigint numerator, Bigint denominator);

//Define module in Bigint
Bigint module(Bigint numerator, Bigint denominator);

//Testing whether an larger integer is prime or not using Fermat primality test
bool fermat_prime_test(unsigned long long x);

//Generating a prime number with required sercurity level
unsigned long long prime_generator(int security_level);

//Generating random prime from the prime list
int fake_prime_generator(int security_level);

