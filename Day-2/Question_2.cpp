#include<iostream>
using namespace std;

int main(){
    float penCost, pencilCost, eraserCost;
    cin>>penCost;
    cin>>pencilCost;
    cin>>eraserCost;

    float totalCost = penCost + pencilCost + eraserCost;
    cout<<"Total Cost is = "<<totalCost<<endl;
    cout<<"Total cost with GST = "<<(totalCost + (0.18 * totalCost))<<endl;

    return 0;
}