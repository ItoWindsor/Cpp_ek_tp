#include <iostream>
#include "polynome.hpp"
#include "monome.hpp"

int main() {

  int coeff[] = { 2, -1, 4, 0, 2};
  unsigned degre[] = { 0, 3, 2, 5, 6 };
  Monome_t Q(2,3);
  std::cout<< "Hello World Ex1" <<std::endl;
  std::cout<< Q <<std::endl;

  Monome_t P1(1,3);
  Monome_t P2(3,3);
  Monome_t P3(2,3);
  Monome_t P4(0,3);

  std::cout<< "P1  = " << P1 << std::endl;
  std::cout<< "P2  = " << P2 << std::endl;
  std::cout<< "P3  = " << P3 << std::endl;
  std::cout<< "P4  = " << P4 << std::endl;
  std::cout << "P1 == P2 ? " << (P1 == P2) << std::endl;
  std::cout << "P3 > P2 ? " << (P3 > P2) << std::endl;
  std::cout << "P4 < P1 ? " << (P4 < P1) << std::endl;
  std::cout << "P2 >= P1 ? " << (P2 >= P1) << std::endl;

  P4 += P1;
  P2 -= P1;
  Monome_t P5 = P1*P2;

  std::cout << "P4 = " << P4 << std::endl;
  std::cout << "P2 = " << P2 << std::endl;
  std::cout << "P5 = " << P5 << std::endl;
}
