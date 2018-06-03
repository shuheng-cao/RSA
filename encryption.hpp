//
//  encryption.hpp
//  RSA
//
//  Created by shuster on 2018/6/3.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#ifndef encryption_hpp
#define encryption_hpp

#include <stdio.h>

long long power_module(long long x, int power, long long mode);

void encrpte(unsigned int e, unsigned long long n);

void encrpte(void);

#endif /* encryption_hpp */
