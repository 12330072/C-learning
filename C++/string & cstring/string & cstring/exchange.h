//
//  exchange.h
//  string & cstring
//
//  Created by 邱兆丰 on 16/2/29.
//  Copyright © 2016年 邱兆丰. All rights reserved.
//

#ifndef exchange_h
#define exchange_h
std::string change1(char st2[]){    //把char*类的字符串转成string类的字符串
    std::string temp;
    temp = st2;
    return temp;
}

void change2(std::string str1, char st2[]) {
    st2 = str1.c_str();
}


#endif /* exchange_h */
