#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <vector> // Added for transaction history
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
    cout<<"\t1.Deposit--(D).\n\t2.Withdrow--(W).\n\t3.Show details--(S)\n\t4.Check balance--(C)\n\t5.customer lone --(L)\n\t6.Exit"<<endl;
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
         cout << "\tAccount Number: " << account_number << "\n";

    }
    void show_details(){
         cout << "\nSignup successful! Here is your information:\n";
        cout << "\tFull Name: " << full_name << "\n";
        cout << "\tDate of Birth: " << dob << "\n";
        cout << "\tNationality and Residency: " << nationality << "\n";
        cout << "\tGender: " << gender << "\n";
        cout << "\tAccount Number: " << account_number << "\n";
    }
};
long user1::next_account_number = 10000000;

class after_login {
public:
    static map<long, long double> balances; // Each user has a unique balance
    map<long, vector<string>> transaction_history; // Transaction logs for each user

    long double deposit_balance, withdraw_amount;
    string op, sh;

    void deposit(long account_number) {
        cout << "\tEnter deposit amount: ";
        cin >> deposit_balance;

        if (deposit_balance <= 0) {
            cout << "Invalid deposit amount. Please try again.\n";
            return;
        }

        balances[account_number] += deposit_balance;
        transaction_history[account_number].push_back("Deposited: " + to_string(deposit_balance));
        cout << "Deposit successful. Current balance: " << balances[account_number] << "\n";
    }

    void withdraw(long account_number) {
        cout << "\tEnter withdrawal amount (max 50000 at a time): ";
        cin >> withdraw_amount;

        if (balances[account_number] == 0) {
            cout << "Sorry! You have no funds.\n";
            return;
        }

        if (withdraw_amount > 50000) {
            cout << "Maximum withdrawal limit is 50000. Please try again.\n";
            return;
        }

        if (withdraw_amount > balances[account_number]) {
            cout << "Insufficient funds. Available balance: " << balances[account_number] << "\n";
            return;
        }

        balances[account_number] -= withdraw_amount;
        transaction_history[account_number].push_back("Withdrawn: " + to_string(withdraw_amount));
        cout << "Withdrawal successful. Remaining balance: " << balances[account_number] << "\n";
    }

   void show_detail(long account_number, map<long, user1>& users) {
    cout << "Do you want to show your biodata (b) or transaction details (a)? ";
    cin >> sh;
    if (sh == "b" || sh == "B") {
        auto it = users.find(account_number);
        if (it != users.end()) {
            cout << "\n--- Biodata ---\n";
            it->second.show_details(); // Call the show_details method of the user
        } else {
            cout << "User details not found.\n";
        }
    } else if (sh == "a" || sh == "A") {
        cout << "\n--- Transaction Details ---\n";
        if (transaction_history[account_number].empty()) {
            cout << "No transactions found.\n";
        } else {
            for (const auto& entry : transaction_history[account_number]) {
                cout << "- " << entry << "\n";
            }
        }
    } else {
        cout << "Invalid option. Try again.\n";
    }
}

};

map<long, long double> after_login::balances; // Define static member



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
        cout<<"problem= "<<problem<<endl;
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
    string option,openion,second_chart;
    after_login log;

    while (true) {
        chart.show_first_chart();
        cin >> option;
        cin.ignore();
        if (option == "exit" || option == "Exit") {
            cout << "Exiting program. Thank you!\n"; // Change Made
            break; // Exit the loop // Change Made
        }
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
                    cin>>second_chart;
                    if(second_chart=="l"||second_chart=="L"){
                         cout<<"Are you withdrow a LOAN..Yes/No= ";
                             cin>>openion;
                             cin.ignore();
                             if (openion=="yes"||openion=="Yes")
                             {
                             loan.customer_details();
                           loan.occupation();
                             }
                    }
                    else if(second_chart=="exit"||second_chart=="Exit"){
                        continue;
                    }

                   if (second_chart == "d" || second_chart == "D") {
                     log.deposit(it->first); // Pass the account number
                    } else if (second_chart == "w" || second_chart == "W") {
                   log.withdraw(it->first); // Pass the account number
                } 
                else if (second_chart == "s" || second_chart == "S") {
    log.show_detail(it->first, users); // Pass account number and users map
}




                } else {
                    cout << ">> Wrong ID / Pin. Please try again.\n";
                }
            } else if (log_option == "signup" || log_option == "Signup") {
                user1 new_user;
                new_user.signup();
                users[new_user.account_number] = new_user;
                //new_user.show_details();
            }
        } else if (option == "E" || option == "e") {
            chart.employee_login();
            emp.login_id();
        } else if (option == "H" || option == "h") {
            cout << "Help Section: Please contact customer service for support.\n";
        } else {
            cout << "Invalid option. Try again.\n";
        }
       /* cout<<"Are you withdrow a LOAN..Yes/No= ";
        cin>>openion;
        cin.ignore();
        if (openion=="yes"||openion=="Yes")
        {
            loan.customer_details();
            loan.occupation();
        }*/
        
    }   
}



int main(){
   continue_code();
    
   
}
