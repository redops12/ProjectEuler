template<class T>
DigIterator<T>::DigIterator(T num, int base): num(num), base(base) {}

template<class T>
int DigIterator<T>::operator*() const {
    T modulo = num % base;
    return static_cast<int>(modulo);
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

template <class IterType>
uint64_t concat(const IterType &beg, const IterType &end) {
    uint64_t num = 0;
    for (auto it = beg; it < end; ++it) {
        assert(*it >= 0 && *it < 10);
        num *= 10;
        num += *it;
    }
    return num;
}

template <class IterType>
boost::multiprecision::cpp_int concat_big(const IterType &beg, const IterType &end) {
    boost::multiprecision::cpp_int num = 0;
    for (auto it = beg; it < end; ++it) {
        assert(*it >= 0 && *it < 10);
        num *= 10;
        num += *it;
    }
    return num;
}

template <class T>
int log_10(T num) {
    T base;
    int log = 0;
    for (base = 10; base < num; base *= 10) {
        log++;
    }
    return log;
}

