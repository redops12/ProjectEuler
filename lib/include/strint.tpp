template<class T>
DigIterator<T>::DigIterator(T num, int base): num(num), base(base) {}

template<class T>
int DigIterator<T>::operator*() const {
    T modulo = num % base;
    return modulo;
}

template<class T>
DigIterator<T>& DigIterator<T>::operator++() {
    num /= base;
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
std::vector<int> get_digits(T x, int base) {
    std::vector<int> digits;
    for (DigIterator<T> it(x, base); it != it.end(); ++it) {
        digits.push_back(*it);
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}
