//
//  Prime_generator.hpp
//  RSA
//
//  Created by shuster on 2018/5/27.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include "bigint.h"
#include "bigint.h"
#include <iostream>
using namespace Dodecahedron;

//Define power in Bigint
Bigint power(Bigint x, Bigint y);

//Define module in Bigint
Bigint module(Bigint numerator, Bigint denominator);

//Testing whether an larger integer is prime or not using Fermat primality test
bool fermat_prime_test(Bigint x);

//Generating a prime number with required sercurity level
Bigint prime_generator(int security_level);
