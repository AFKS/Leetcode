# 241 Different Ways to Add Parentheses

## Description
> Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
>
>
> **Example 1**
> <pre>
> Input: "2-1-1".
> ((2-1)-1) = 0
> (2-(1-1)) = 2
> Output: [0, 2]
> </pre>
>
> **Example 2**
> <pre>
> Input: "2*3-4*5"
> (2*(3-(4*5))) = -34
> ((2*3)-(4*5)) = -14
> ((2*(3-4))*5) = -10
> (2*((3-4)*5)) = -10
> (((2*3)-4)*5) = 10
> Output: [-34, -14, -10, -10, 10]
> </pre>
>

## Solution
- Divide and Conquer

### Divide and Conquer

```c
class Solution {
public:
    int intCompute(int a, int b, char opt){
        if (opt=='+') return a+b;
        if (opt=='-') return a-b;
        if (opt=='*') return a*b;
    }
    
    vector<int> twoVectorComputer(vector<int>& vect1, vector<int>& vect2, char opt){
        vector<int> res = {};
        if (vect1.empty()&&vect2.empty()) return res;
        else if (vect1.empty()) return vect2;
        else if (vect2.empty()) return vect1;
        else{
            for(int i=0;i<vect1.size();++i){
                for(int j=0;j<vect2.size();++j){
                    int temp = intCompute(vect1[i],vect2[j],opt);
                    res.push_back(temp);
                }
            }
        }
        return res; 
    }
    
    vector<int> diffWay2Computer(string& input, int st, int ed){
        /*
        p1. input string has operator mixed. -> need to be splited 
        p2. input string has no operator mixed -> need to be translate to be INT
        */
        vector<int> res = {};
        if (st>ed) return res;
        
        vector<int> lfCompute{};
        vector<int> rtCompute{};
        
        bool pureNum = true;    //flag for p2
        int tempInt=0; 
        
        for (int i=st;i<=ed;++i){
            //p1
            if (input[i]=='+'||input[i]=='-'||input[i]=='*'){
                pureNum = false;
                //keep split
                lfCompute = diffWay2Computer(input,st,i-1);
                rtCompute = diffWay2Computer(input,i+1,ed);
                vector<int> lfComputeOptRtCompute = twoVectorComputer(lfCompute, rtCompute, input[i]);
                for (int i=0;i<=lfComputeOptRtCompute.size()-1;++i)
                    res.push_back(lfComputeOptRtCompute[i]);
            }
            if (pureNum==true)  tempInt = tempInt*10+(input[i]-'0');
        }
        
        if (pureNum==true)  res.push_back(tempInt);
        
        return res;
    }
    
    
    vector<int> diffWaysToCompute(string input) {
        return diffWay2Computer(input,0,input.size()-1);
    }
};
```

