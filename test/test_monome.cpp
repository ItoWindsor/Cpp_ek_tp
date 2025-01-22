#include <gtest/gtest.h>
#include "monome.hpp"

// Test Constructor
TEST(MonomeTest, Constructor) {
    Monome_t m(5, 3);
    EXPECT_EQ(m.get_coeff(), 5);       // Check if the coefficient is correctly set
    EXPECT_EQ(m.get_degree(), 3);      // Check if the degree is correctly set
}

// Test Constructor with Default Arguments
TEST(MonomeTest, DefaultConstructor) {
    Monome_t m;
    EXPECT_EQ(m.get_coeff(), 0);       // Default coefficient should be 0
    EXPECT_EQ(m.get_degree(), 0);      // Default degree should be 0
}

// Test the '+=' Operator
TEST(MonomeTest, PlusEquals) {
    Monome_t m1(5, 3);
    Monome_t m2(3, 3);
    m1 += m2; // Add m2 to m1
    EXPECT_EQ(m1.get_coeff(), 8);       // Coefficients should be added (5 + 3 = 8)
}

// Test '+=' Operator with Different Degrees (Expecting Exception)
TEST(MonomeTest, PlusEqualsInvalidDegree) {
    Monome_t m1(5, 3);
    Monome_t m2(3, 2);
    EXPECT_THROW(m1 += m2, std::invalid_argument);  // Adding monomes with different degrees should throw an exception
}

// Test the '-=' Operator
TEST(MonomeTest, MinusEquals) {
    Monome_t m1(5, 3);
    Monome_t m2(3, 3);
    m1 -= m2; // Subtract m2 from m1
    EXPECT_EQ(m1.get_coeff(), 2);       // Coefficients should be subtracted (5 - 3 = 2)
}

// Test '-=' Operator with Different Degrees (Expecting Exception)
TEST(MonomeTest, MinusEqualsInvalidDegree) {
    Monome_t m1(5, 3);
    Monome_t m2(3, 2);
    EXPECT_THROW(m1 -= m2, std::invalid_argument);  // Subtracting monomes with different degrees should throw an exception
}

// Test the 'to_string()' method
TEST(MonomeTest, ToString) {
    Monome_t m(5, 3);
    EXPECT_EQ(m.to_string(), "5X^3");  // Ensure the to_string method outputs correctly
}

TEST(MonomeTest, MultiMonome) {
    Monome_t m1(5, 3);
    Monome_t m2(4, 2);
    Monome_t m3 = m1 * m2;
    Monome_t m4(20,5);
    EXPECT_EQ(m3 == m4, true);
}

