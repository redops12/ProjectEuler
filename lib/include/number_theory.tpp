
template <class T>
Frac<T>::Frac(T num, T denom): num(num), denom(denom) {}

template <class T>
bool Frac<T>::operator==(const Frac& other) const {
    return this->num * other.denom == this->denom * other.num;
}

template <class T>
Frac<T> Frac<T>::operator*(const Frac& rhs) const {
    auto f = Frac<T>(this->num * rhs.num, this->denom * rhs.denom);
    f.reduce();
    return f;
}

template <class T>
Frac<T>::operator std::string() const {
    return std::to_string(num) + " / " + std::to_string(denom);
}

template <class T>
void Frac<T>::reduce() {
    T gcd_res = gcd<T>(this->num, this->denom);
    this->num   /= gcd_res;
    this->denom /= gcd_res;
}


