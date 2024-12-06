#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
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

class save_file {
public:
    void save_user_to_file(long account_number, const string &full_name, const string &dob,
                           const string &nationality, const string &gender, const string &password) {
        ofstream write("customer_data.txt", ios::app);
        if (!write) {
            cerr << "Error: Unable to open file for writing.\n";
            return;
        }
        write << account_number << " " << full_name << " " << dob << " "
              << nationality << " " << gender << " " << password << endl;
        write.close();
    }

    void save_transaction(long account_number, const double &balance, const string &type) {
        ofstream write("transactions.txt", ios::app);
        if (!write) {
            cerr << "Error: Unable to open file for writing.\n";
            return;
        }
        write << account_number << " | " << type << ": " << balance << endl;
        write.close();
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
    string full_name, dob, nationality, gender, login_pass;

    // Login method
    bool login(long entered_account, const string &entered_password) {
        ifstream inFile("customer_data.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file for reading.\n";
            return false;
        }

        while (inFile >> account_number >> full_name >> dob >> nationality >> gender >> login_pass) {
            if (entered_account == account_number && entered_password == login_pass) {
                
                inFile.close();
                return true;
            }
        }
        inFile.close();
        return false;
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

    account_number = generate_unique_account_number();

    cout << "Your Account Number: " << account_number << endl;

    save_file s;
    s.save_user_to_file(account_number, full_name, dob, nationality, gender, login_pass);
}

long generate_unique_account_number() {
    long new_account_number;
    bool is_unique;

    do {
        new_account_number = 10000000 + rand() % 90000000; // Generate an 8-digit number
        is_unique = true;

        ifstream inFile("customer_data.txt");
        if (!inFile) {
            cerr << "Error: Unable to open file for reading. Assuming account number is unique.\n";
            break;
        }

        long stored_account_number;
        string dummy;
        while (inFile >> stored_account_number) {
            getline(inFile, dummy); // Skip the rest of the line
            if (stored_account_number == new_account_number) {
                is_unique = false;
                break;
            }
        }
        inFile.close();
    } while (!is_unique);

    return new_account_number;
}


    void show_details() const {
        cout << "\nSignup successful! Here is your information:\n";
        cout << "\tFull Name: " << full_name << "\n";
        cout << "\tDate of Birth: " << dob << "\n";
        cout << "\tNationality and Residency: " << nationality << "\n";
        cout << "\tGender: " << gender << "\n";
        cout << "\tAccount Number: " << account_number << "\n";
    }
};


class after_login {
public:
    save_file s;

    void deposit(long account_number) {
        double deposit_amount;
        cout << "Enter deposit amount: ";
        cin >> deposit_amount;

        if (deposit_amount <= 0) {
            cout << "Invalid deposit amount. Please try again.\n";
            return;
        }

        s.save_transaction(account_number, deposit_amount, "Deposit");
        cout << "Deposit successful. Amount: " << deposit_amount << "\n";
    }

    void withdraw(long account_number, double &balance) {
        double withdraw_amount;
        cout << "Enter withdrawal amount: ";
        cin >> withdraw_amount;

        if (withdraw_amount <= 0 || withdraw_amount > balance) {
            cout << "Invalid withdrawal amount. Available balance: " << balance << "\n";
            return;
        }

        balance -= withdraw_amount;
        s.save_transaction(account_number, withdraw_amount, "Withdrawal");
        cout << "Withdrawal successful. Remaining balance: " << balance << "\n";
    }

    void show_transaction_history(long account_number) {
        ifstream file("transactions.txt");
        if (!file) {
            cerr << "Error: Unable to open transactions file.\n";
            return;
        }

        string record;
        bool found = false;
        cout << "\n--- Transaction History ---\n";
        while (getline(file, record)) {
            if (record.find(to_string(account_number)) == 0) {
                cout << record << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found.\n";
        }
        file.close();
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


void start(){
   
}

};

void continue_code() {
    display_chart chart;
    function_handel fun;
    employee emp;
    user1 user;
    bank_lone loan;
    string openion;
    after_login log;
    int option,second_chart,log_option,a;

    while (true) {
        chart.show_first_chart();
        cin >> option;
        cin.ignore();
        cout<<endl;
        if (option == 4) {
          cout << "Thank you for using our service. Goodbye!\n";
            break; // Exit the loop // Change Made
        }
        if (option == 1) {
             chart.ask_for_login(); 
            cin>>log_option;
            cout<<endl;

            if(log_option==1){
                user.signup();
                user.show_details();
                //user.show_details();
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


                if (user.login(entered_account, entered_password)) {
                    double balance = 0.0;
                    while (true)
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
                        cout << "Logging out...\n";
                        break;
                    }

                   if (second_chart == 1) {
                     log.deposit(entered_account);
                    } 
                    else if (second_chart == 2) {
                   log.withdraw(entered_account, balance);
                } 
                else if (second_chart == 3) {
                   log.show_transaction_history(entered_account);
}
                } 
                else {
                   cout << "Invalid option. Try again.\n";
                }

            }
        else if (log_option==3){
             cout << "Help Section: Please contact customer support.\n";
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
        } 
        else if (option == 3) {
            cout << "Help Section: Please contact customer service for support.\n";
        } 
        else {
            cout << "Invalid option. Try again.\n";
        }
        cout<<endl;
    }   
}



int main(){
    srand(time(0)); 
   continue_code();
    
   
}