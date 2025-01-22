#ifndef POLYNOME_HPP
#define POLYNOME_HPP

#include <vector>
#include "monome.hpp"

typedef std::vector<Monome_t> MonoVec;
typedef std::vector<Monome_t>::iterator MonoVec_It;
typedef std::vector<Monome_t>::const_iterator MonoVec_cIt;

class Polynome_t{
  public:
    Polynome_t(int coeff = 0,unsigned int degre = 0);
    Polynome_t(int coeff[], unsigned int degre[], int n);
    Polynome_t(const MonoVec &data0);
    const MonoVec& get_data() const;
  private:
    MonoVec data;
};

std::ostream& operator<<(std::ostream& output_stream, Polynome_t const& P);
bool operator==(Polynome_t const& P1, Polynome_t const& P2);

#endif
