#include "Bitset.hpp"

bitset::bitset () {
    for (int i = 0; i < N; i++)
        a[i] = 0;
}

void bitset::set (int pos) {
    int Apos = pos / 32;
    int Bpos = pos % 32;
    a[Apos] |=  1 << Bpos;
}

void bitset::reset (int pos) {
    int Apos = pos / 32;
    int Bpos = pos % 32;
    a[Apos] &= ~(1 << Bpos);
}

int bitset::count () const {
    int Tcount = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++) {
            if (a[i] & (1 << j))
                Tcount++;
        }
    }
    return Tcount;
}

bool bitset::test (int pos) const {
    int Apos = pos / 32;
    int Bpos = pos % 32;
    if (a[Apos] & (1 << Bpos))
        return 1;
    else
        return 0;
}

bool bitset::any () const {
    if (count ())
        return 1;
    else
        return 0;
}

bool bitset::none () const {
    if (count ())
        return 0;
    else
        return 1;
}

bool bitset::all () const {
    if (count () == max_length)
        return 1;
    else
        return 0;
}

bitset& bitset::operator&= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] &= b.a[i];
    }
    return *this;
}

bitset& bitset::operator|= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] |= b.a[i];
    }
    return *this;
}

bitset& bitset::operator^= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] ^= b.a[i];
    }
    return *this;
}
bitset& bitset::operator= (const bitset& b) {
    for (int i = 0; i < N; i++) {
        a[i] = b.a[i];
    }
    return *this;
}

bitset bitset::operator~() const {
    bitset othBit;
    for (int i = 0; i < 5; i++) {
        othBit.a[i] = ~a[i];
    }
    return othBit;
}

bitset bitset::operator&(const bitset& b) const {
    bitset othBit;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 32; j++) {
            if ((a[i] & (1 << j)) & (b[j] & (1 << j))) {
                othBit.set (32 * i + j);
            }
            else {
                othBit.reset (32 * i + j);
            }
        }
    }
    return othBit;
}

bitset bitset::operator|(const bitset& b) const {
    bitset othBit;
    othBit |= *this;
    return othBit;
}

bitset bitset::operator^(const bitset& b) const {
    bitset othBit;
    othBit ^= *this;
    return othBit;
}

bitset& bitset::operator <<= (int pos) {
    int i, j, k;
    if (pos >= N * 32)
        pos = N * 32;
    int last[4];
    while (pos--) {
        last[3] = a[3] & (1 << 31);
        last[2] = a[2] & (1 << 31);
        last[1] = a[1] & (1 << 31);
        last[0] = a[0] & (1 << 31);
        for (j = 4; j > 0; j--) {
            for (k = 30; k >= 0; k--) {
                if (a[j] & (1 << k))
                    set(j * 32 + k + 1);
                else
                    reset(j * 32 + k + 1);
            }
            if (last[j - 1])
                set(j * 32);
            else
                reset(j * 32);
        }
        for (k = 30; k >= 0; k--) {
            if (a[0] & (1 << k))
                set(k + 1);
            else
                reset(k + 1);
        }
        reset(0);
    }
    return *this;
}

bitset& bitset::operator >>= (int pos) {
    int i, j, k;
    if (pos >= N * 32)
        pos = N * 32;
    int frist[4];
    while (pos--) {
        frist[3] = a[4] & 1;
        frist[2] = a[3] & 1;
        frist[1] = a[2] & 1;
        frist[0] = a[1] & 1;
        for (j = 0; j < 4; j++) {
            for (k = 1; k < 30; k++) {
                if (a[j] & (1 << k))
                    set(j * 32 + k - 1);
                else
                    reset(j * 32 + k - 1);
            }
            if (frist[j + 1])
                set(j * 32 + 31);
            else
                reset(j * 32 + 31);
        }
        for (k = 1; k <= 31; k++) {
            if (a[4] & (1 << k))
                set(32 * 4 + k  - 1);
            else
                reset(32 * 4 + k - 1);
        }
        set(4 * 32 + 31);
    }
    return *this;
}

bitset bitset::operator<<(int pos) const {
    bitset othBit;
    othBit <<= pos;
    return othBit;
}

bitset bitset::operator>>(int pos) const {
    bitset othBit;
    othBit >>= pos;
    return othBit;
}

bool bitset::operator== (const bitset& b) const {
    if ((*this & b).count () == N * 32)
        return 1;
    else
        return 0;
}

bool bitset::operator!= (const bitset& b) const {
    if ((*this & b).count () == N * 32)
        return 0;
    else
        return 1;
}

bool bitset::operator[] (int pos) const {
    int Apos = pos / 32;
    int Bpos = pos % 32;
    if (a[Apos] & (1 << Bpos))
        return 1;
    else
        return 0;
}

