# RSA

RSA consists several parts:

1. Prime Number Generator
  Use random to generate a random number and take advangtage of Fermat's little theorem and Fermat test to check if it's a prime.

2. RSA Setup
    1) Default generator is to use the primelist for efficiency. However, you can change the generator by change the function key_generator() in the main.cc
    2) After we have the primes p and q, we will generate e, d and n using Extended Euclid Algorithm.
    3) We can generate as many keys as we want and all of them will be stored in the vector key_bank
  
3. Encryption and Decryption
    1) For encryption, we break a whole text into several piece (the way to break it is unknown to user) in order to reduce the runtime of the whole program. That's why only this program can decrypt only it's own ciphertext.
    2) For decryption, we do the ordinary RSA and bring back the original text the way we break them.
  
3.5. Bigint class
    This is a special class in order to deal with extremely large integer. It store integer in the form of strings and do the basic calculation as we did to integers.
  
4. Note:
    1) If you want the faked_prime_generator to work, don't forget to type in the absolute path to primelist.txt at line 96 in Prime_generator.cpp.
    2) Don't try to decrypt any ciphertext from other source as I made some improvement for RSA of my own, which will probably cause the program to crash for outside ciphertext.
