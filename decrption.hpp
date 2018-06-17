//
//  decrption.hpp
//  RSA
//
//  Created by shuster on 2018/6/3.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#ifndef decrption_hpp
#define decrption_hpp

#include <stdio.h>
#include "bigint.h"
using namespace Dodecahedron;

//return a bigint with last n digits cut
Bigint remaining_digits(Bigint x, int n);

//return the last n digits of the bigint
unsigned long long last_n_digits(Bigint x, int n);

//consumes two numbers and a code, which is ecrypted by my excryption, then decrypt the code
void decrpte(long long d, long long n);

//do the same thing as above, but require the user to type in private keys
void decrpte(void);

#endif /* decrption_hpp */
