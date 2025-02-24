#include <vector>

using std::vector;

class PrimeIterator {
private:
    vector<int>::iterator current_prime;
public:
    PrimeIterator();
    PrimeIterator(int start);
    int operator*() const;
    PrimeIterator& operator++();
    bool operator!=(const PrimeIterator& other) const;
};
