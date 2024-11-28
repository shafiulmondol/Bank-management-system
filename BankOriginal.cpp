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
<<<<<<< HEAD
=======
    char first;
    long num;
    string user_openion,op;
    first=first_chart();
    if (first=='C' ||first=='c'){
calclute cal;
int amm,count=0;
string de,m,j;
float f=1000;
    cout<<"login/sign up--\n";
    cin>>user_openion;
    if(user_openion=="login"){
        num=enter();
if(num==23303106){
    cal.shafiul();
}
else {
    cout<<"Not found.Try again\n";
    count++;
    if(count==2){
        cout<<"Please sign up first";

        cout<<"Are you interested to create an account?\n yes/no\n";
        cin>>op;
        if(op=="yes"||"Yes"){
            sing_up();
        }
        else {
            cout<<"Thank you sir!";
        }
    }
}
    
cin>>de;
if(de=="w"||de=="W"){
do{
cout<<"enter your withdeow ammount: ";
cin>>amm;
if(amm>f){
    cout<<"unsufficient balance. Do you want to continue? press w or no\n";
    cin>>j;
    if(j=="W"||j=="w"){
        continue;
    }
>>>>>>> bf859948d43eab3a04cd4a2aaa69dbba5b14e1af


}
