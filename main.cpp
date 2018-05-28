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
#include "bigint.h"
#include "Prime_generator.h"
using namespace std;
using namespace Dodecahedron;

int main(int argc, const char * argv[]) {
    //std::cout << module(1234, 2) << std::endl;
    //std::cout << fermat_prime_test(1234) << std::endl;
    //Dodecahedron::Bigint x = module(10, 2);
    //std::cout << x;
    //Bigint z = 0;
    //bool y = (x[0] == 0);
    //std::cout << y << std::endl;
    //Bigint y = module(977, 2);
    //bool z = (y[0] == 1);
    //cout << y << z << endl;
    //Bigint y =power(55, 977 - 1);
    //cout << y << endl;
    //Bigint z = module(123451235, 977);
    //cout << z << endl;
    //std::cout << fermat_prime_test(102679) << endl;
    //cout << prime_generator(2) << endl;
    //Bigint x = 5;
    //Bigint y = x.pow(10);
    cout << power(5, 100000) << endl;
    //std::cout << "Hello, World!\n";
    return 0;
}
