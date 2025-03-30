#include <iostream>
#include <cmath>
#include "complex.hpp"

 /* I USED THE FOLLOWING COMMAND TO COMPILE:
 *
 *     g++ -std=c++20 -o complex main.cpp
 */
 
int main(void)
{
	using com = complex<double>;
	
	double r1 = 1.2;
	com c1(1.1,-2.3);
	com c2(2.5,3.0);
	
	double pi1 =  c1.immag();
	double pr2 = c2.reale();
	
	std::cout << pi1 << std::endl;
	std::cout << pr2 << std::endl;
	
	std::cout << c1+c2 << std::endl;
	std::cout << r1+c1 << std::endl;
	
	com c4(1.2,2.3);
	std::cout << abs(c4) << std::endl;
	
	com c5 = coniug(c1);
	std::cout << c5 << std::endl;
	
	com c6 = c2 - c1;
	std::cout << c6 << std::endl; 
	com c7 = r1 - c2;                     
	std::cout << c7 << std::endl; 
	
	com c8 = r1 * c1;
	std::cout << c8 << std::endl;
	com c9 = c1 * c2;
	std::cout << c9 << std::endl;

	return 0;
}