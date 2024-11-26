// Bank Management System
#include <iostream>
#include <string>
#include <math.h>

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

int main(){
    
calclute cal;
int num,amm;
string de,m,j;
float f=1000;
    
cout<<"Enter you account number"<<endl;
cin>>num;
if(num==23303106){
    cal.shafiul();
}
else {
    cout<<"Please create an account.";
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
}






    }
