#include "String.h"
#include <cstring>
#include <string>
#include <cstdio>

String::String() {
    _length = 0;
    _size = 0;
    _buff = NULL;
}

char String::_error_sign = '!';

String::String(const char *src) {
    _length = strlen(src);
    _size = _length + 1;
    _buff = new char[_size];
    memset(_buff, 0, _size);
    snprintf(_buff, _size, "%s", src);
}

String::String(const String &src) {
    _length = src._length;
    _size = src._size;
    _buff = new char[_size];
    memset(_buff, 0, _size);
    snprintf(_buff, _size, "%s", src._buff);
}

String::~String() {
    if (_buff) {
        clear();
    }
}

void String::clear() {
    if (_buff) {
        _size = 0;
        _length = 0;
        delete []_buff;
        _buff = 0;
    }
}

const char* String::c_str() const {
    if (empty())
        return "";
    else
        return _buff;
}

bool String::empty() const {
    return (_length == 0);
}

int String::find(const String &other, int pos) const {
    int i, j, check;
    for (i = pos; i <= _size - other._size; i++) {
        if (_buff[i] == other._buff[0]) {
            check = 0;
            j = 0;
            while (_buff[i + j] == other._buff[j] &&
                   j < other._size && i + j < _size) {
                j++;
                check++;
            }
            if (check == other._length) {
                return i;
            }
        }
    }
    return this->_length;
}

int String::length() const {
    return _length;
}

String String::substr(const int &pos, const int &count) const {
    //  cCount: change count
    int cCount = count;
    if (pos + cCount > _length)
        cCount = _length - pos;
    char* cOut = new char[cCount + 1];
    for (int i = 0; i < cCount; i++) {
        cOut[i] = _buff[i + pos];
    }
    cOut[cCount] = '\0';
    String out(cOut);
    delete []cOut;
    return out;
}

char& String::operator[](const int &index) {
    if (index >= 0 && index <_length) {
        return _buff[index];
    } else {
        return _error_sign;
    }
}

void String::assign(const char *src) {
    if (_buff != NULL) {
        clear();
    }
    _length = strlen(src);
    _size = _length + 1;
    _buff = new char[_size];
    memset(_buff, 0, _size);
    snprintf(_buff, _size, "%s", src);
}

void String::append(const char &other) {
    if (this->empty()) {
        _buff = new char[2];
        _buff[0] = other;
        _buff[1] = '\0';
        _size = 2;
        _length = 1;
    } else {
        char* temp = new char[_size + 1];
        memset(temp, 0, _size + 1);
        for (int i = 0; i < _length; i++) {
            temp[i] = _buff[i];
        }
        temp[_length] = other;
        temp[_size] = '\0';
        delete []_buff;
        _buff = temp;
        _length++;
        _size++;
    }
}

void String::operator=(const String &other) {
    assign(other.c_str());
}

void String::operator=(const char *src) {
    assign(src);
}

String String::operator+(const String &other) const {
    String newString;
    int i;
    newString._size = _size + other._length;
    newString._length = _length + other._length;
    newString._buff = new char[newString._size];
    memset(newString._buff, 0, newString._size);
    for (i = 0; i < _length; i++) {
        newString._buff[i] = _buff[i];
    }
    for (i = 0; i < other._size; i++) {
        newString._buff[i + _length] = other._buff[i];
    }
    return newString;
}

bool String::operator<(const String &other) const {
    return(compare(other) == -1);
}

bool String::operator<=(const String &other) const {
    int check = compare(other);
    return(check == -1 || check == 0);
}

bool String::operator>(const String &other) const {
    return (compare(other) == 1);
}

bool String::operator>=(const String &other) const {
    int check = compare(other);
    return(check == 1 || check == 0);
}

bool String::operator==(const String &other) const {
    return (!compare(other));
}

bool String::operator!=(const String &other) const {
    return (compare(other));
}

std::ostream& operator<<(std::ostream& out, const String& str) {
    for (int i = 0; i < str._length; i++) {
        if (str._buff[i] != '\0') {
            out << str._buff[i];
        }
    }
    return out;
}

int String::compare(const String &other) const {
    int min = (_length > other._length) ? other._length : _length;
    for (int i = 0; i <= min; i++) {
        if (_buff[i] > other._buff[i]) {
            return 1;
        }
        else if (_buff[i] < other._buff[i]) {
            return -1;
        }
    }
    return 0;
}
