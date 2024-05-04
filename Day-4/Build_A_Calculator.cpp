#include<iostream>
using namespace std;

int main(){
    int a, b;
    char op;

    cout <<"Enter a: ";
    cin >> a;
    cout <<"Enter b: ";
    cin >> b;
    cout <<"Enter operator: ";
    cin >> op;

    // Calculator (Using if else)...
    if(op == '+'){
        cout << "a + b = " << (a + b) << endl;
    }else if(op == '-'){
        cout << "a - b = " << (a - b) << endl;
    }else if(op == '*'){
        cout << "a * b = " << (a * b) << endl;
    }else if(op == '/'){
        cout << "a / b = " << (a / b) << endl;
    }else{
        cout << "Invalid Operator";
    }

    //Calculator(Using Switch Case)...
    switch(op){
        case '+' : cout << "a + b = " << (a + b) << endl;
                    break;
        case '-' : cout << "a - b = " << (a - b) << endl;
                    break;
        case '*' : cout << "a * b = " << (a * b) << endl;
                    break;
        case '/' : cout << "a / b = " << (a / b) << endl;
                    break;
        default : cout << "Invalid Operator" << endl;             
    }

    return 0;
}