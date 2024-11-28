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


class user1{
    public:
    static int count;
    long account_number;
    string login_pass;
    
    long login(){
        cout<<"Enter account number:  ";
        cin>>account_number;
        cin.ignore();
        cout<<"Enter password:  ";
        getline(cin,login_pass);
        if(account_number==23303106 && login_pass=="user#@01"){
        return account_number;
        count++;}
        else{
            if(count<=3){
            cout<<">> Wrong ID / Pin\n>>Please try again\n";
            login();}
            else{
               cout << ">> Too many failed attempts. Go to help center.\n";
            }
        }
    }

};
int user1::count=0;



class employee{
    public:
    long id;
    string password;
    static int count_enter;

    long login_id()
    {
        cout<<"Enter your id number: ";
        cin>>id;
        cout<<"Enter your password: ";
        getline(cin,password);
        if(id==23303137 && password=="sum01*#")
        {
        return id;
        count_enter++;
        }
        else{
            if(count_enter<=3){
            cout<<">> Wrong ID"<<endl<<"Please try again"<<endl;
            login_id();}
            else{
               cout << ">> Too many failed attempts. Go to help center."<<endl;
                }
             }

    }
};
int employee::count_enter=0;




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


if (option=="E"||option=="e")
    {
    chart.ask_for_login();
    }


    cin>>log_option;
if(log_option=="login"||log_option=="Login")
    {
    employee user; //create object
    user.login_id();
    }
    


}
