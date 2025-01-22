#include <iostream>

#include "monome.hpp"
#include "polynome.hpp"


Polynome_t::Polynome_t(int coeff, unsigned int degree) {
    data.push_back(Monome_t(coeff, degree));
}

Polynome_t::Polynome_t(int coeff[], unsigned int degre[], int n) {
    for (int i = 0; i < n; ++i) {
        if (coeff[i] != 0) {
            data.push_back(Monome_t(coeff[i], degre[i]));
        }
    }
    std::sort(this->data.begin(),this->data.end());
}

Polynome_t::Polynome_t(const MonoVec &data0)
: data(data0) {
}

const MonoVec& Polynome_t::get_data() const {
    return data;
}

std::ostream& operator<<(std::ostream& stream_output, Polynome_t const& P) {
    bool is_first = true;
    MonoVec data = P.get_data();
    for (MonoVec_cIt it = data.begin(); it != data.end(); ++it) {
        if (!is_first) {
            stream_output << " + ";
        }
        else {
            is_first = false;
        }
        stream_output << it->to_string();
    }

    if (is_first) {
        stream_output << "0";
    }
    return stream_output;
}

bool operator==(Polynome_t const& P1, Polynome_t const& P2) {
    MonoVec data1 = P1.get_data();
    MonoVec data2 = P2.get_data();
    if ( data1.size() != data2.size() ){
        return false;
    }
    if (std::equal(data1.begin(),data1.end(),data2.begin())) {
        return true;
    }
    return false;
}