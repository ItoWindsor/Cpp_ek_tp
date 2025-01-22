#include <gtest/gtest.h>

#include "monome.hpp"
#include "polynome.hpp"

TEST(PolynomeTest, IsEqual) {
    Polynome_t P1(5, 3);
    Polynome_t P2(5, 3);
    EXPECT_EQ( P1 == P2, true);
}