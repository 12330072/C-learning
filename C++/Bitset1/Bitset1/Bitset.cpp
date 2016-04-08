#include "Bitset.h"

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
    for (int i = 0; i < N; i++)
        a[i] ^= b.a[i];
    return *this;
}
bitset& bitset::operator= (const bitset& b) {
    for (int i = 0; i < N; i++)
        a[i] = b.a[i];
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
    bitset othBit = *this;
    othBit &= b;
    return othBit;
}

bitset bitset::operator|(const bitset& b) const {
    bitset othBit = *this;
    othBit |= b;
    return othBit;
}

bitset bitset::operator^(const bitset& b) const {
    bitset othBit = *this;
    othBit ^= b;
    return othBit;
}

bitset& bitset::operator <<= (int pos) {
    while (pos--) {
        for (int i = 4; i >= 0; i--) {
            if (i == 0) {
                a[i] <<= 1;
                continue;
            }
            a[i] <<= 1;
            if (a[i - 1] & (1 << 31))
                a[i] |= 1;
            else
                a[i] &= ~1;
        }
    }
    return *this;
}

bitset& bitset::operator >>= (int pos) {
    while (pos--) {
        for (int i = 0; i < N; i++) {
            if (i == 4) {
                a[i] >>= 1;
                continue;
            }
            a[i] >>= 1;
            if (a[i + 1] & 1)
                a[i] |= 1 << 31;
            else
                a[i] &= ~(1 << 31);
        }
    }
    return *this;
}

bitset bitset::operator<<(int pos) const {
    bitset othBit = *this;
    othBit  <<= pos;
    return othBit;
}

bitset bitset::operator>>(int pos) const {
    bitset othBit = *this;
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







