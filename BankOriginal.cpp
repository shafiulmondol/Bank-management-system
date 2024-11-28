// Bank Management System.
#include <iostream>
#include <string>
#include <math.h>
#include<conio.h>
using namespace std;

class calclute{
    public:
    string name;
    int withdrow;
    int initial=1000;

    float ammount (int withdrow){
        initial=initial-withdrow;
       // cout<<"your current balance is: "<<initial<<endl;
        return initial;
    }

    void shafiul(){
    cout<<"hi Shafiul! Your bank menu here-----"<<endl<<"1. For know details press D\n2. For withdrow ammount press W\n";
    }

    void details(){
        cout<<"NAME : MD SHAFIUL iSLAM\nID : 23303106\n Your current balance is 100000 TK.";
    }


    };
    char first_chart(){
        char first;
        cout<<"1.Use as a customer-(press---C).\n2.Use as a employee-(press---E)\n3.help-(press---H)\n";
        cin>>first;
        return first;
    }
    long enter(){
        long num;
        cout<<"Enter you account number"<<endl;
        cin>>num;
        return num;
    }
    void sing_up(){
        string name,date,address,phone,mail;
        cout<<"Full Name: ";
        getline(cin,name);
        cout<<"Date of Birth: ";
        getline(cin,date);
        cout<<"Address: ";
        getline(cin,address);
        cout<<"Contact Details:\n\tPhone number: ";
        getline(cin,phone);
        cout<<"\tEmail address: ";
        getline(cin,mail);
        
    }


int main(){
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

    else{
        cout<<"thank you\n";
        break;
    }
}
else{
    f=cal.ammount(amm);
cout<<"your current balance is "<<f<<endl<<"Do you want to withdrow again! press w or no\n";
cin>>m;
if(f==0){
    cout<<"you have no balance. please deposite on your account first\n";
break;
}
if(m=="no"){
cout<<"Thank you\n";
break;
}
if(m=="w"||m=="W"){
continue;
}
}

}
while (f>0);

}
else{
    cout<<"Enter correct command: ";
}}
    }
    }
