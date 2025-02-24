#include "functions.h"

using std::distance;

template <class T>
typename std::vector<T>::iterator binary_search(const vector<T> &array, T item) {
    if (array.size() == 0) return array.end();
    if (array.back() < item) return array.end();
    size_t left = 0;
    size_t right = array.size() - 1;
    while (left + 1 < right) {
        size_t mid = left + right / 2;
        T val = array[mid];
        if (item < val) {
            right = mid;
        } else if (item > val) {
            left = mid;
        } else {
            left = right = mid;
        }
    }

    return array.begin() + left;
}
