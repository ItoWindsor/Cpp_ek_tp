#ifndef _MONOME_HPP_
#define _MONOME_HPP_

#include <iostream>
#include "polynome.hpp"

class Monome_t{
  friend class Polynome_t;
  public:
    Monome_t(int coeff = 0, unsigned int degree = 0);

    unsigned int get_degree() const;
    int get_coeff() const;
    std::string to_string() const;

    Monome_t& operator+=(const Monome_t& other);
    Monome_t& operator-=(const Monome_t& other);
  private:
    int coeff;
    unsigned int degree;
};

std::ostream& operator<<(std::ostream& output_stream, Monome_t const& X);
bool operator==(Monome_t const& X1, Monome_t const& X2);
bool operator>(Monome_t const& X1, Monome_t const& X2);
bool operator>=(Monome_t const& X1, Monome_t const& X2);
bool operator<(Monome_t const& X1, Monome_t const& X2);

Monome_t operator+(Monome_t const& X1, Monome_t const& X2);
Monome_t operator-(Monome_t const& X1, Monome_t const& X2);
Monome_t operator*(Monome_t const& X1, double const& X2);


#endif
