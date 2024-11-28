#include <iostream>
#include <string>
using namespace std;

class display_chart{
public:
void show_first_chart(){
cout<<"Use as a customer:---(press-----C)\nUse as a Employee:---(press-----E)\nHelp\n";
}
void ask_for_login(){
    cout<<"Login/sign up";
}

};


class user{
    public:
    long account_number;
    string login_pass;
    string login(){
        cout<<"Enter account number:  ";
        cin>>account_number;
        cout<<"Enter password:  ";
        getline(cin,login_pass);
        return login_pass;
    }

};

class employee{


};

class help{


};






int main(){


}
