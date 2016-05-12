//
//  vector.h
//  MyVector2
//
//  Created by 邱兆丰 on 16/5/9.
//  Copyright © 2016年 菇生. All rights reserved.
//

#ifndef vector_h
#define vector_h
#include "base.h"

template <typename T, class C>
class myVector: public Base {
public:
    int size() {
        return _size;
    }
    
    
private:
    int _size;
    
    
};


#endif /* vector_h */
