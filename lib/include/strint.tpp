template<class T>
DigIterator<T>::DigIterator(T num): num(num) {}

template<class T>
int DigIterator<T>::operator*() const {
    T modulo = num % 10;
    return modulo;
}

template<class T>
DigIterator<T>& DigIterator<T>::operator++() {
    num /= 10;
    return *this;
}

template<class T>
bool DigIterator<T>::operator!=(const DigIterator<T>& other) const {
    return this->num != other.num;
}

template<class T>
bool DigIterator<T>::operator==(const DigIterator<T>& other) const {
    return this->num == other.num;
}

template<class T>
DigIterator<T> DigIterator<T>::end() {
    return DigIterator(0);
}

template <class T>
std::vector<int> get_digits(T x) {
    std::vector<int> digits;
    for (DigIterator<T> it(x); it != it.end(); ++it) {
        digits.push_back(*it);
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}
