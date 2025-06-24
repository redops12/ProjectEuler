#include "number_theory.h"

GeneralizedPentagonal::GeneralizedPentagonal(): prev(1) {}
GeneralizedPentagonal& GeneralizedPentagonal::operator++() {
    if (prev > 0) {
        prev *= -1;
    } else {
        prev *= -1;
        prev += 1;
    }
    return *this;
}

unsigned int GeneralizedPentagonal::operator*() const {
    return (3 * this->prev * this->prev - this->prev) / 2;
}
