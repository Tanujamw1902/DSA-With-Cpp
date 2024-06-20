#include <iostream>
using namespace std;

class User{
private:
    int id;
    string password;

public:
    string username;

    User(int id){
        this->id = id;
    }

    //Getter
    string getPassword(){
        return password;
    }

    //Setter
    void setPassword(string password){
        this->password = password;
    }
};

int main(){
    User user1(101);
    user1.username = "Tanuja Waware";
    user1.setPassword("HareKrishn");

    cout << "Username:" << user1.username << endl;
    cout << "Password:" << user1.getPassword() << endl;

    return 0;
}