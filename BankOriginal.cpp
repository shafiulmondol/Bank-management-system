#include <iostream>
#include <string>
#include <regex>
#include <map>
#include<math.h> // For storing multiple users
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
    cout<<"\t1.Deposit--(D).\n\t2.Withdrow--(W).\n\t3.Show details--(S)\n\t4.Check balance--\n\t5.customer lone details--(L)(C)"<<endl;
}

void show_exit(){
    cout<<"Thank you Sir! logout your account:"<<endl;
}


};


class user1 {
public:
    long account_number;
    string login_pass, full_name, dob, nationality, gender;
    static long next_account_number;

    user1() : account_number(next_account_number++) {}

    // Login method for a specific user
    bool login(long entered_account, const string& entered_password) {
        return (entered_account == account_number && entered_password == login_pass);
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
            cout << "Set a strong password: ";
            getline(cin, login_pass);
            if (isPasswordValid(login_pass)) {
                cout << "\nPassword is valid.\n";
                break;
            } else {
                cout << "Invalid password. Please try again.\n";
            }
        }

        cout << "\nSignup successful! Here is your information:\n";
        cout << "\tFull Name: " << full_name << "\n";
        cout << "\tDate of Birth: " << dob << "\n";
        cout << "\tNationality and Residency: " << nationality << "\n";
        cout << "\tGender: " << gender << "\n";
        cout << "\tAccount Number: " << account_number << "\n";
    }
};
long user1::next_account_number = 10000000;



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
    string name,address,profession,problem;
    string university_name,department;
    string office,rank_position;
    int age,income,lone_amount,id,semester;

    void customer_details()
    {
        cout<<"Enter your name= ";
        getline(cin,name);
        cout<<"Enter your age= ";
        cin>>age;
        cin.ignore();
        cout<<"Enter your address= ";
        getline(cin,address);
        cout<<"Enter your profession student/working person= ";
        getline(cin,profession);
    }
    void occupation()
    {
        if(profession=="student"||profession=="Student"){
        cout<<"Enter your university name= ";
        getline(cin,university_name);
        cout<<"Enter your department= ";
        getline(cin,department);
        cout<<"Enter your id= ";
        cin>>id;
        cout<<"Enter your income= ";
        cin>>income;
        cout<<"Enter your lone amount= ";
        cin>>lone_amount;
        cin.ignore();
        cout<<"Why do you want to take a loan= ";
        getline(cin,problem);

        cout<<endl;
        cout<<"name= "<<name<<endl;
        cout<<"University name= "<<university_name<<endl;
        cout<<"Department = "<<department<<endl;
        cout<<"your id = "<<id<<endl;
        cout<<"Your income= "<<income<<endl;
        cout<<"your want "<<lone_amount<<"tk lone."<<endl;
        cout<<"problem= "<<problem;
        }
        else{
            cout<<"Enter your office name= ";
            getline(cin,office);
            cout<<"Enter your position= ";
            getline(cin,rank_position);cout<<"Enter your income= ";
            cin>>income;
            cout<<"Enter your lone amount= ";
            cin>>lone_amount;
            cin.ignore();
            cout<<"Why do you want to take a loan= ";
            getline(cin,problem);

            cout<<endl;
            cout<<"name= "<<name<<endl;
            cout<<"Office name is = "<<office<<endl;
            cout<<"Your position= "<<rank_position<<endl;
            cout<<"Your income= "<<income<<endl;
            cout<<"your want "<<lone_amount<<"tk lone."<<endl;
            cout<<"problem= "<<problem;

            
        }
    }
};




class help{


};

void continue_code() {
    display_chart chart;
    map<long, user1> users; // Store users with account_number as key
    employee emp;
    bank_lone loan;
    string option,openion;

    while (true) {
        chart.show_first_chart();
        cin >> option;
        cin.ignore();

        if (option == "C" || option == "c") {
            chart.ask_for_login();
            string log_option;
            getline(cin, log_option);

            if (log_option == "login" || log_option == "Login") {
                long entered_account;
                string entered_password;
                cout << "Enter account number: ";
                cin >> entered_account;
                cin.ignore();
                cout << "Enter password: ";
                getline(cin, entered_password);

                auto it = users.find(entered_account);
                if (it != users.end() && it->second.login(entered_account, entered_password)) {
                    chart.name = it->second.full_name;
                    chart.show_user_chart();
                } else {
                    cout << ">> Wrong ID / Pin. Please try again.\n";
                }
            } else if (log_option == "signup" || log_option == "Signup") {
                user1 new_user;
                new_user.signup();
                users[new_user.account_number] = new_user;
            }
        } else if (option == "E" || option == "e") {
            chart.employee_login();
            emp.login_id();
        } else if (option == "H" || option == "h") {
            cout << "Help Section: Please contact customer service for support.\n";
        } else {
            cout << "Invalid option. Try again.\n";
        }
        cout<<"Are you withdrow a LOAN..Yes/No= ";
        cin>>openion;
        cin.ignore();
        if (openion=="yes"||openion=="Yes")
        {
            loan.customer_details();
            loan.occupation();
        }
        
    }   
}



int main(){
   continue_code();
    
   
}
