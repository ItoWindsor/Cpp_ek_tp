#include <iostream>
#include "monome.hpp"

Monome_t::Monome_t(int coeff, unsigned int degree)
  :coeff(coeff),degree(degree)
  {}

int Monome_t::get_coeff() const{
  return(coeff);
}

unsigned int Monome_t::get_degree() const{
  return(degree); 
}

Monome_t& Monome_t::operator+=(const Monome_t &other) {
    if (this->degree != other.get_degree() ) {
        throw std::invalid_argument("Degrees must match to add monomials.");
    }
    this->coeff += other.get_coeff();

    return *this;
}

Monome_t& Monome_t::operator*=(const Monome_t &other) {
    this->coeff *= other.get_coeff();
    this->degree += other.get_degree();
    return *this;
}

Monome_t& Monome_t::operator-=(const Monome_t &other) {
    if (this->degree != other.get_degree() ) {
        throw std::invalid_argument("Degrees must match to add monomials.");
    }
    this->coeff -= other.get_coeff();

    return *this;
}

std::string Monome_t::to_string() const{
    std::string str = std::to_string(get_coeff());
    if(get_degree() > 0) {
        str += "X^";
        str += std::to_string(get_degree());
    }
    return(str);
}


std::ostream& operator<<(std::ostream& stream_output, Monome_t const& X){
    stream_output << X.to_string() ;
    return(stream_output);
}

bool operator==(Monome_t const& X1, Monome_t const& X2){
    if( (X1.get_coeff() == X2.get_coeff() ) && ( X1.get_degree() == X2.get_degree() ) ){
        return true;
    }
    return false;
}

bool operator> (Monome_t const& X1, Monome_t const& X2) {
   // add error handling -> what happens if we compare two monome with different degrees ?
    if( (X1.get_coeff() > X2.get_coeff() ) && ( X1.get_degree() == X2.get_degree() ) ){
    return true;
    }
    return false;
}

bool operator< (Monome_t const& X1, Monome_t const& X2) {
    return (X2 > X1) ;
}

bool operator >= (Monome_t const& X1, Monome_t const& X2) {
    return (X1 > X2) || (X1 == X2);
}

Monome_t operator*(Monome_t const& X1, Monome_t const& X2) {
    int new_coeff = X1.get_coeff() * X2.get_coeff();
    unsigned int new_degree = X1.get_degree() + X2.get_degree();

    Monome_t temp(new_coeff,new_degree);

    return temp;
}


