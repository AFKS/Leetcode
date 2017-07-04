//
//  main.cpp
//  test
//
//  Created by Rhino_mom on 2017-07-04.
//  Copyright © 2017 Rhino_mom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int str2IntOpt(string& str){
    
}

vector<int> str2IntSplit(string& str){
    vector<int> res;
    if (str.empty()) return res;
    for(int st=0;st<=str.size()-1;++st){
        string temp;
        for(int ed=st;ed<=str.size()-1;++ed){
            if (str[ed]!='+'&&str[ed]!='-'&&str[ed]!='*'){
                temp.push_back(str[ed]);
            }
            else{
                st = ed;
            }
        }
        val = str2IntOpt(temp);
        res.push_back(val);
    }
}



int main(int argc, const char * argv[]) {
    
    string str = "1+2+3+4+5";
    return 0;
}
