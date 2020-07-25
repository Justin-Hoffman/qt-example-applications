#include "factorizer.h"
#include "math.h"
#include <stdio.h>
#include <thread>
#include <chrono>


void Factorizer::factors(unsigned int n) 
{   
    std::vector<unsigned int> factors;
    std::this_thread::sleep_for (std::chrono::seconds(5)); // Artificially adding 5s of overhead 
    factors.push_back(1);
    while (n % 2 == 0)
    {  
        factors.push_back(2);
        n = n/2;  
    }  
  
    for (unsigned int i = 3; i <= sqrt(n); i = i + (unsigned int) 2)  
    {  
        
        while (n % i == 0) 
        {  
            factors.push_back(i); 
            n = n / i;
        }  
    } 
  
    if (n > 2)  
      factors.push_back(n);
    emit factorsReady( factors );
}

