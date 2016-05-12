#ifndef bitset_h
#define bitset_h

template<int N>
class bitset {
  private:
    bool bit[N];
  public:
    bitset() {
        for (int i = 0; i < N; i++)
            bit[i] = false;
    }
    void set(int pos) {
        if (pos >= 0 && pos < N) {
            bit[pos] = true;
        }
    }
    int count() {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (bit[i] == 1)
                sum++;
        }
        return sum;
    }
    bool test(int pos) {
        if (pos >= 0 && pos < N) {
            return (bit[pos] == 1);
        }
        return false;
    }
    bool any() {
        return count();
    }
    bool none() {
        return count() == 0;
    }
    bool all() {
        return count() == N;
    }
    void reset(int pos) {
        if (pos >= 0 && pos < N) {
            bit[pos] = false;
        }
    }
    friend std::ostream& operator<<(std::ostream& outP, const bitset& _bit) {
        for (int i = N - 1; i >= 0; i--) {
            outP << _bit.bit[i];
        }
        return outP;
    }
    bitset<N> operator~() {
        bitset<N> out;
        for (int i = 0; i < N; i++) {
            out.bit[i] = bit[i] == false;
        }
        return out;
    }
    bool operator==(const bitset<N> & othbit) const {
        for (int i = 0; i < N; i++) {
            if (bit[i] != othbit.bit[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const bitset<N> & othbit) const {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (bit[i] == othbit.bit[i]) {
                sum++;
            }
        }
        return !(sum == N);
    }
    bitset<N>& operator=(const bitset<N> & othbit) {
        for (int i = 0; i < N; i++) {
            bit[i] = othbit.bit[i];
        }
        return *this;
    }
    bitset<N> operator&(const bitset<N> & othbit) const {
        bitset<N> out;
        for (int i = 0; i < N; i++) {
            out.bit[i] = bit[i] & othbit.bit[i];
        }
        return out;
    }
    bitset<N>& operator&=(const bitset<N> & othbit) {
        *this = *this & othbit;
        return *this;
    }
    bitset<N> operator|(const bitset<N> & othbit) const {
        bitset<N> out;
        for (int i = 0; i < N; i++) {
            out.bit[i] = bit[i] | othbit.bit[i];
        }
        return out;
    }
    bitset<N>& operator|=(const bitset<N> & othbit) {
        *this = *this | othbit;
        return *this;
    }
    bitset<N> operator^(const bitset<N> & othbit) const {
        bitset<N> out;
        for (int i = 0; i < N; i++) {
            out.bit[i] = bit[i] ^ othbit.bit[i];
        }
        return out;
    }
    bitset<N>& operator^=(const bitset<N> & othbit) {
        *this = *this ^ othbit;
        return *this;
    }
    bitset<N> operator<<(int pos) const {
        bitset<N> out;
        for (int i = 0; i < pos; i++) {
            out.bit[i] = false;
        }
        for (int i = pos; i < N; i++) {
            out.bit[i] = bit[i - pos];
        }
        return out;
    }
    bitset<N>& operator <<= (int pos) {
        *this = *this << pos;
        return *this;
    }
    bitset<N> operator>>(int pos) const {
    bitset<N> out;
        for (int i = N - 1; i >= N - pos - 1; i--) {
            out.bit[i] = true;
        }
        for (int i = 0; i < N - pos - 1; i++) {
            out.bit[i] = bit[i + pos];
        }
        return out;
    }
    bitset<N>& operator >>= (int pos) {
        *this = *this >> pos;
        return *this;
    }
    bool operator[](int pos) {
        return (bit[pos]);
    }
};

#endif /* bitset_h */
