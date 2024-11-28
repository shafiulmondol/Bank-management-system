#include <iostream>
#include <string>
using namespace std;

class display_chart{
public:
void show_first_chart(){
cout<<"1. Use as a customer:---(press-----C)\n2. Use as a Employee:---(press-----E)\n3.Help\n";
}
void ask_for_login(){
    cout<<">>Login/sign up\n";
}

};

class useer_account{
    public:
    long account_id;



};

class user1{
    public:
    long account_number;
    string login_pass;
    long login(){
        cout<<"Enter account number:  ";
        cin>>account_number;
        cout<<"Enter password:  ";
        getline(cin,login_pass);
        return account_number;
    }

};



class employee{


};

class help{


};






int main(){
    display_chart chart;//create object
    chart.show_first_chart();

    string option,log_option;
    cin>>option;
    if (option=="c"||option=="C"){
    chart.ask_for_login();}

    cin>>log_option;
if(log_option=="login"||log_option=="Login"){
    user1 user; //create object
    user.login();}


}
