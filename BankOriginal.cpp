#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <vector> // Added for transaction history
#include<math.h> // For storing multiple users
using namespace std;

//this function for function validation.
bool Password_Validity(const string &password) {
    if(password.length()<8){
        cout <<"Password must be at least 8 characters long.\n";
        return false;
    }
    bool Upper,Lower,Digit,SpecialChar;

    for (int i=0;i<password.length();i++){
        char ch=password[i];
        if(ch>='A'&& ch<='Z') {
            Upper =true;
        }
        else if(ch>='a'&&ch<='z'){
            Lower =true;
        }
        else if(ch>='0'&&ch<='9') {
            Digit =true;
        }
        else {
            SpecialChar =true; 
        }
    }

    if(!Upper){
        cout <<"Password must include at least one uppercase letter.\n";
        return false;
    }
    if (!Lower) {
        cout << "Password must include at least one lowercase letter.\n";
        return false;
    }
    if (!Digit) {
        cout << "Password must include at least one digit.\n";
        return false;
    }
    if (!SpecialChar) {
        cout << "Password must include at least one special character.\n";
        return false;
    }
    return true;
}

class save_file{
    void save_user_to_file(long account_number, const string& full_name, const string& dob,
                       const string& nationality, const string& gender, const string& password) {
    FILE* file = fopen("users.txt", "a");
    if (file) {
        fprintf(file, "%ld|%s|%s|%s|%s|%s\n", account_number, full_name.c_str(), dob.c_str(),
                nationality.c_str(), gender.c_str(), password.c_str());
        fclose(file);
    } else {
        cout << "Error: Unable to open file for saving user data.\n";
    }
}

// Function to read user data from file
bool find_user_in_file(long account_number, string& full_name, string& dob,
                       string& nationality, string& gender, string& password) {
    FILE* file = fopen("users.txt", "r");
    if (!file) return false;

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file)) {
        long acc_no;
        char name[100], birth[20], nation[50], gen[10], pass[50];
        sscanf(buffer, "%ld|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]", &acc_no, name, birth, nation, gen, pass);
        if (acc_no == account_number) {
            full_name = name;
            dob = birth;
            nationality = nation;
            gender = gen;
            password = pass;
            fclose(file);
            return true;
        }
    }

    fclose(file);
    return false;
}

// Function to save transaction details
void save_transaction(long account_number, const string& detail) {
    FILE* file = fopen("transactions.txt", "a");
    if (file) {
        fprintf(file, "%ld|%s\n", account_number, detail.c_str());
        fclose(file);
    } else {
        cout << "Error: Unable to save transaction.\n";
    }
}

// Function to show transaction history
void show_transactions(long account_number) {
    FILE* file = fopen("transactions.txt", "r");
    if (!file) {
        cout << "Error: Unable to open file for transactions.\n";
        return;
    }

    char buffer[256];
    bool found = false;

    cout << "\n--- Transaction History ---\n";
    while (fgets(buffer, sizeof(buffer), file)) {
        long acc_no;
        char detail[200];
        sscanf(buffer, "%ld|%[^\n]", &acc_no, detail);
        if (acc_no == account_number) {
            cout << "- " << detail << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No transactions found.\n";
    }

    fclose(file);
}

};


class display_chart{
public:
string name;
void show_first_chart(){
    cout<<"\n---->>Bank System<<----"<<endl;
    cout << "1: Customer Section"<<endl;
    cout << "2: Employee Section"<<endl;
    cout << "3: Help Section"<<endl;
    cout << "4: Exit"<<endl;
    cout << "Enter your choice: >>";
}
void ask_for_login() {
    cout<<"----->>Bank Manu<<-----"<<endl;
    cout << "1: Sign Up"<<endl;
    cout << "2: Login"<<endl;
    cout << "3: View All Users (Admin only)"<<endl;
    cout << "4: Back"<<endl;//exit cilo
    cout << "Enter your choice: >>";
    }
    void show_user_chart() {
        cout << "1: Deposit"<<endl;
        cout << "2: Withdraw"<<endl;
        cout << "3: Show Details"<<endl;
        cout << "4: Loan Request"<<endl;
        cout << "5: Exit"<<endl;
        cout << "Enter your choice: >>";
    }
void employee_login()
{
    cout<<"...Login..."<<endl;
}

void show_exit(){
    cout << "Thank you for using our service. Goodbye!"<<endl;
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
            if (Password_Validity(login_pass)) {
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

class function_handel{
public:
display_chart chart2;
 int log_option,a;

void start(){
    chart2.ask_for_login(); 
            cin>>log_option;
            cout<<endl;
}

};

void continue_code() {
    display_chart chart;
    function_handel fun;
    map<long, user1> users; // Store users with account_number as key
    employee emp;
    bank_lone loan;
    string openion;
    after_login log;
    int option,second_chart,log_option;

    while (true) {
        chart.show_first_chart();
        cin >> option;
        cin.ignore();
        cout<<endl;
        if (option == 4) {
            cout << "Exiting program. Thank you!\n"; // Change Made
            break; // Exit the loop // Change Made
        }
        if (option == 1) {
            fun.start();

            if(log_option==1){
                user1 new_user;
                new_user.signup();
                users[new_user.account_number] = new_user;
                //new_user.show_details();
            }
            else if (log_option ==2) {
                long entered_account;
                string entered_password;
                cout << "Enter Account Number: ";
                cin >> entered_account;
                cin.ignore();
                cout << "Enter password: ";
                getline(cin, entered_password);
                cout<<endl;

                auto it = users.find(entered_account);
                if (it != users.end() && it->second.login(entered_account, entered_password)) {
                    chart.name = it->second.full_name;
                    chart.show_user_chart();
                    cin>>second_chart;
                    cout<<endl;
                    if(second_chart==4){
                         cout<<"Are you withdrow a LOAN..Yes/No= ";
                             cin>>openion;
                             cin.ignore();
                             cout<<endl;
                             if (openion=="yes"||openion=="Yes")
                             {
                             loan.customer_details();
                           loan.occupation();
                             }
                    }
                    else if(second_chart==5){
                        break;
                    }

                   if (second_chart == 1) {
                     log.deposit(it->first); // Pass the account number
                    } 
                    else if (second_chart == 2) {
                   log.withdraw(it->first); // Pass the account number
                } 
                else if (second_chart == 3) {
    log.show_detail(it->first, users); // Pass account number and users map
}
                } 
                else {
                    cout << ">> Wrong ID / Pin. Please try again.\n";
                }

            }
        else if (log_option==3){
            //leter
        }
        else if(log_option==4){
            continue;
           

        }
        }
        else if (option == 2) {
            cout<<"\n1: Employee"<<endl;
            cout<<"2: Back";
            int b;
            cin>>b;
            if (b==1){
            chart.employee_login();
            emp.login_id();}
            else if(b==1){
                continue;
            }
            else{
                //letter
            }
        } else if (option == 3) {
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
        cout<<endl;
    }   
}



int main(){
   continue_code();
    
   
}