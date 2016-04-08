#include "BigInteger.h"

BigInteger operator+(const BigInteger& left, const BigInteger& right) {
    BigInteger newBigInt;
    int i, min, max;
    //  获取最小长度
    min = left.size_ > right.size_ ? right.size_ : left.size_;
    //  获取最大长度
    max = left.size_ < right.size_ ? right.size_ : left.size_;
    newBigInt.size_ = max;
    //  多创建一位，用于最后一位进位
    newBigInt.data_ = new int[max + 1];
    //  全部初始化为0
    for (i = 0; i < max + 1; i++) {
        newBigInt.data_[i] = 0;
    }
    //  从头加起
    for (i = 0; i < min; i++) {
        newBigInt.data_[i] = newBigInt.data_[i] + left.data_[i] +
        right.data_[i];
        if (newBigInt.data_[i] > 9) {
            newBigInt.data_[i] -= 10;
            newBigInt.data_[i + 1]++;
        }
        else if (newBigInt.data_[i] < 0) {
            newBigInt.data_[i] += 10;
            newBigInt.data_[i + 1]--;
        }
    }
    //  接驳位可能出现无法进位现象所以也要弥补
    //  更好的做法是最后一次性解决进位的问题
    if (max == left.size_) {
        for (i = min; i < max; i++) {
            newBigInt.data_[i] += left.data_[i];
            if (newBigInt.data_[i] > 9) {
                newBigInt.data_[i] -= 10;
                newBigInt.data_[i + 1]++;
            }
            else if (newBigInt.data_[i] < 0) {
                newBigInt.data_[i] += 10;
                newBigInt.data_[i + 1]--;
            }
        }
    }
    else if (max == right.size_) {
        for (i = min; i < max; i++) {
            newBigInt.data_[i] += right.data_[i];
            if (newBigInt.data_[i] > 9) {
                newBigInt.data_[i] -= 10;
                newBigInt.data_[i + 1]++;
            }
            else if (newBigInt.data_[i] < 0) {
                newBigInt.data_[i] += 10;
                newBigInt.data_[i + 1]--;
            }
        }
    }
    if (newBigInt.data_[max] > 0) {
        newBigInt.size_++;
    }
    return newBigInt;
}

BigInteger operator-(const BigInteger& left, const BigInteger& right) {
    int i;
    for (i = right.size_ - 1; i >= 0; i--) {
        right.data_[i] = -right.data_[i];
    }
    return (left + right);
}

ostream& operator<<(ostream& out, const BigInteger& Bint) {
    int i = Bint.size_ - 1;
    //  只检查到i＝1位，不然越界
    while (Bint.data_[i] == 0 && i > 0) {
        i--;
    }
    while (i > 0) {
        out << Bint.data_[i];
        i--;
    }
    out << Bint.data_[0];
    return out;
}

BigInteger::BigInteger() {
    data_ = NULL;
    size_ = 0;
}

BigInteger::BigInteger(const string& number) {
    size_ = number.length();
    data_ = new int[size_];
    for (int i = 0; i < size_; i++) {
        data_[i] = number[size_ - 1 - i] - '0';
    }
}

BigInteger::BigInteger(const BigInteger& other) {
    size_ = other.size_;
    data_ = new int[size_];
    for (int i = size_ - 1; i >= 0; i--) {
        data_[i] = other.data_[i];
    }
}

BigInteger::~BigInteger() {
    delete []data_;
    size_ = 0;
    data_ = NULL;
}
