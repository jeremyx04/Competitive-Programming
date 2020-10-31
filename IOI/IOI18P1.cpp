#include<bits/stdc++.h>
using namespace std;
 
string guess_sequence(int n){
    string ans;
    char a='A',b='B',c='X';
    if(press("XY")){
        if(press("X")){
            ans="X";
            c='Y';
        }
        else{
            ans="Y";
        }
    }
    else{
        if(press("A")){
            ans="A";
            a='Y';
        }
        else{
            ans="B";
            b='Y';
        }
    }
    for(int i = 2; i < n; i++){
        int chu = press(ans+a+ans+b+a+ans+b+b+ans+b+c);
        if(chu==i)
            ans+=a;
        else if(chu==i+1)
            ans+=b;
        else 
            ans+=c;
    }  
    if(n>=2){ 
        if(press(ans+a)==n)
            ans+=a;
        else if(press(ans+b)==n)
            ans+=b;
        else
            ans+=c;
    }
    return ans;
}