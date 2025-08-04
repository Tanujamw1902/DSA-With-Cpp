#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    map<int, string>m;
    m[101]= "Rahul";
    m[110]= "Neha";
    m[131]= "Rahul";
    cout<<m.count(101)<<endl; // 1
    cout<<m.count(120)<<endl; //0
    for(auto it:m){
        cout<<"Key = " <<it.first<<","<<"Value = "<<it.second<<endl;
        cout<<"Double = "<<it.first*2<<endl;
    }
    return 0;
}