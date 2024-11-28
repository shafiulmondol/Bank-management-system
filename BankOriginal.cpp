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
void employee_login()
{
    cout<<"...Login..."<<endl;
}

};


class user1{
    public:
     int count;
    long account_number;
    string login_pass;
    
   void login() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter account number:  ";
            cin >> account_number;
            cin.ignore(); // Clear input buffer
            cout << "Enter password:  ";
            getline(cin, login_pass);
            if (account_number == 23303106 && login_pass == "user#@01") {
                cout << ">> Login Successful\n";
                return;
            } else {
                cout << ">> Wrong ID / Pin\n>> Please try again\n";
            }
        }
        cout << ">> Too many failed attempts. Go to help center.\n";
    }

    

    void signup() {
    string full_name, dob, nationality, gender;
    cout << "1. Personal Information>>\n";
    cout << "\n\tFull Name: ";
    getline(cin, full_name);
    cout << "\n\tDate of Birth (DD/MM/YYYY): ";
    getline(cin, dob);
    cout << "\n\tNationality and Residency: ";
    getline(cin, nationality);
    cout << "\n\tGender: ";
    getline(cin, gender);

//this part for this time
    cout << "\nSignup successful! Here is your information:\n";
    cout << "\tFull Name: " << full_name << "\n";
    cout << "\tDate of Birth: " << dob << "\n";
    cout << "\tNationality and Residency: " << nationality << "\n";
    cout << "\tGender: " << gender << "\n";
}


};




class employee{
    public:
    long id;
    string password;
     int count_enter;

     void login_id() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter your ID number: ";
            cin >> id;
            cin.ignore(); // Clear input buffer
            cout << "Enter your password: ";
            getline(cin, password);
            if (id == 23303137 && password == "sum01*#") {
                cout << ">> Login Successful\n";
                return;
            } else {
                cout << ">> Wrong ID / Pin\n>> Please try again\n";
            }
        }
        cout << ">> Too many failed attempts. Go to help center.\n";
    }
};

class bank_lone{
    public:

};




class help{


};






int main(){
    display_chart chart;//create object
    chart.show_first_chart();

    string option,log_option;
    cin>>option;
    if (option=="c"||option=="C"){
    chart.ask_for_login();
    cin.ignore();
    getline(cin,log_option);}

    user1 user; //create object
if(log_option=="login"||log_option=="Login"){
    user.login();}
if (log_option=="signup"||log_option=="sign up"||log_option=="Sighup"||log_option=="Sign up"){
    user.signup();
}

employee employee_log;//create object
if (option=="E"||option=="e") {
    chart.employee_login();
    employee_log.login_id();
    }
}
