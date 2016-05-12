//
//  String.h
//  String(FINAL EXAM A)
//
//  Created by 邱兆丰 on 16/4/22.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef String_h
#define String_h
#include <cstring>

class String {
  public:
    String() {
        _size = 0;
        _buff = NULL;
    }
    explicit String(const char *src) {
        _size = strlen(src);
        _buff = new char[_size +  1];
        for (int i = 0; i < _size; i++) {
            _buff[i] = src[i];
            _buff[_size] = '\0';
        }
    }
    String(const String &src) {
        _size = src._size;
        _buff = new char[_size + 1];
        for (int i = 0; i < _size; i++) {
            _buff[i] = src._buff[i];
            _buff[_size] = '\0';
        }
    }
    ~String() {
        delete []_buff;
        _buff = NULL;
    }
    String& operator =(const String& src) {
        if (_buff != NULL) {
            delete []_buff;
        }
        _size = src._size;
        _buff = new char[_size + 1];
        for (int i = 0; i < _size; i++) {
            _buff[i] = src._buff[i];
            _buff[_size] = '\0';
        }
        return *this;
    }
    const char* c_str() const {
        return _buff;
    }
    inline char& operator[](int i) {
        return _buff[i];
    }
    friend std::ostream& operator <<(std::ostream& os, const String& src) {
        os << src._buff;
        return os;
    }
  private:
    char *_buff;
    int _size;
};


#endif /* String_h */
