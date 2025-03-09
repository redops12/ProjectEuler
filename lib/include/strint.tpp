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
bool DigIterator<T>::done() const {
    return this->num == 0;
}
