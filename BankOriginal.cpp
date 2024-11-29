#include <iostream>
#include <string>
#include <regex>
using namespace std;

// Helper function to validate password
bool isPasswordValid(const string& password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long.\n";
        return false;
    }
    if (!regex_search(password, regex("[A-Z]"))) {
        cout << "Password must include at least one uppercase letter.\n";
        return false;
    }
    if (!regex_search(password, regex("[a-z]"))) {
        cout << "Password must include at least one lowercase letter.\n";
        return false;
    }
    if (!regex_search(password, regex("[0-9]"))) {
        cout << "Password must include at least one digit.\n";
        return false;
    }
    if (!regex_search(password, regex("[^a-zA-Z0-9]"))) {
        cout << "Password must include at least one special character.\n";
        return false;
    }
    return true;
}


class display_chart{
public:
string name;
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
void show_user_chart(){
    cout<<"Hellow "<<name<<" sir! Your chart below now>>\n";
    cout<<"\t1.Deposit--(D).\n\t2.Withdrow--(W).\n\t3.Show details--(S)\n\t4.Check balance--(C)"<<endl;
}

};


class user1{
      
    public:
    string set_pass;
     int count;
    long account_number;
    string login_pass,full_name, dob, nationality, gender;;
    
   long login() {
        for (int i = 0; i < 3; i++) {
            cout << "Enter account number:  ";
            cin >> account_number;
            cin.ignore(); // Clear input buffer
            cout << "Enter password:  ";
            getline(cin, login_pass);
            if (account_number == 23303106 && login_pass == "user#@01") {
                cout << ">> Login Successful\n";
                return account_number;
            } else {
                cout << ">> Wrong ID / Pin\n>> Please try again\n";
            }
        }
        cout << ">> Too many failed attempts. Go to help center.\n";
    }

    

    void signup() {
    cout << "1. Personal Information>>\n";
    cout << "\n\tFull Name: ";
    getline(cin, full_name);
    cout << "\n\tDate of Birth (DD/MM/YYYY): ";
    getline(cin, dob);
    cout << "\n\tNationality and Residency: ";
    getline(cin, nationality);
    cout << "\n\tGender: ";
    getline(cin, gender);
   while (true) {
        cout << "Set a strong password (at least 8 characters, include uppercase, lowercase, digits, and special symbols): "<<endl;
        getline(cin, set_pass);
        if (isPasswordValid(set_pass)) {
            cout << "\nPassword is valid.\n";
            break;  // Exit the loop if the password is valid
        } else {
            cout << "Invalid password. Please try again.\n";
        }
    }

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
    long id;
    cin>>option;
    if (option=="c"||option=="C"){
    chart.ask_for_login();
    cin.ignore();
    getline(cin,log_option);}

    user1 user; //create object
if(log_option=="login"||log_option=="Login"){
    id=user.login();}
if (log_option=="signup"||log_option=="sign up"||log_option=="Sighup"||log_option=="Sign up"){
    user.signup();
}

employee employee_log;//create object
if (option=="E"||option=="e") {
    chart.employee_login();
    employee_log.login_id();
    }

if (id==23303106){
    chart.name="Md. Shafiul Islam";
    chart.show_user_chart();
}
}
