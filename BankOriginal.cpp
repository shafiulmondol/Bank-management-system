#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//this function for pass validation.
bool Password_Validity(const string &password) {
    if(password.length()<8){
        cout <<"Password must be at least 8 characters long.\n";
        return false;
    }
   bool Upper = false, Lower = false, Digit = false, SpecialChar = false;


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
    void save_user_to_file(long account_number, const string &full_name, const string &dob,const string &nationality, const string &gender, const string &key, const string &password) {
        ofstream write("customer_data.txt", ios::app);
        if (!write) {
            cout << "Error: Unable to open file for writing.\n";
            return;
        }
        write << account_number << " " << full_name << " " << dob << " "<< nationality << " " << gender << " "<< key << " " << password << endl;
        write.close();
    }

    void save_transaction(long account_number, const double &balance, const string &type) {
    ofstream write("transactions.txt", ios::app);
    if (!write) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    write << account_number << " " << type << " " << balance << endl;
    write.close();
}


    void update_balance(long account_number, double new_balance) {
    ifstream file("balances.txt");
    ofstream temp("temp.txt");
    bool found = false;

    long acc;
    double bal;
    while (file >> acc >> bal) {
        if (acc == account_number) {
            temp << acc << " " << new_balance << endl;
            found = true;
        } else {
            temp << acc << " " << bal << endl;
        }
    }

    if (!found) {
        temp << account_number << " " << new_balance << endl;
    }

    file.close();
    temp.close();
    remove("balances.txt");
    rename("temp.txt", "balances.txt");
}


    double get_balance(long account_number) {
    ifstream file("balances.txt");
    if (!file) {
        cout << "Error";
    }

    long acc;
    double bal;
    while (file >> acc >> bal) {
        if (acc == account_number) {
            return bal;
        }
    }
    return 0.0;
}
};



class display_chart{
public:
string name;
void show_first_chart(){
    cout<<endl;
    cout<<"\n---->>Bank System<<----"<<endl;
    cout << "1: Customer Section."<<endl;
    cout << "2: Employee Section."<<endl;
    cout << "3: Help Section."<<endl;
    cout << "4: Admin."<<endl;
    cout << "Enter your choice: >>";
}
void ask_for_login() {
    cout<<endl;
    cout<<"----->>Bank Manu<<-----"<<endl;
    cout << "1: Sign Up"<<endl;
    cout << "2: Login"<<endl;
    cout << "3: Back"<<endl;//exit cilo
    cout << "Enter your choice: >>";
    }
    void show_user_chart() {
        cout<<endl;
        cout << "1: Deposit"<<endl;
        cout << "2: Withdraw"<<endl;
        cout << "3: Show Details"<<endl;
        cout << "4: Loan Request"<<endl;
        cout << "5: Help"<<endl;
        cout << "6: Logout"<<endl;
        cout << "Enter your choice: >>";
    }

void for_admin(){
    cout<<endl;
    cout<<"1: Total empolyee."<<endl;
    cout<<"2: Total customer."<<endl;
    cout<<"3: Total Lone reciver."<<endl;
    cout<<"4: Add employee"<<endl;
    cout<<"5: Back ."<<endl;
    cout<<"6: Close bank for todays"<<endl;
    cout<<"Enter your choice ->> ";
}
};


class user1 {
public:
 long account_number;
    string full_name, dob, nationality, gender, key, login_pass;

    void signup() {
    cout<<endl;
    cout << "1. Personal Information>>\n";
    cout << "\n\tFull Name: ";
    cin.ignore();
    getline(cin, full_name);
    cout << "\n\tDate of Birth (DD/MM/YYYY): ";
    getline(cin, dob);
    cout << "\n\tNationality and Residency: ";
    getline(cin, nationality);
    cout << "\n\tGender: ";
    getline(cin, gender);
    cout << "\n\tKey password(2 digits): ";
    getline(cin, key);

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
    s.save_user_to_file(account_number, full_name, dob, nationality, gender, key, login_pass);
}

long generate_unique_account_number() {
    long last_account_number = 10000000; // Default if no accounts exist
    long new_account_number;

    // Open the file and find the last account number
    ifstream inFile("customer_data.txt");
    if (inFile) {
        long account;
        while (inFile >> account) {
            string dummy;
            getline(inFile, dummy); // Skip the rest of the line
            last_account_number = account; // Update with the last number read
        }
        inFile.close();
    }

    // Generate a new account number
    new_account_number = last_account_number + 1;

    return new_account_number;
}



    void show_details() const {
        cout << "\nSignup successful! Here is your information:\n";
        cout << "\tFull Name: " << full_name << "\n";
        cout << "\tDate of Birth: " << dob << "\n";
        cout << "\tNationality and Residency: " << nationality << "\n";
        cout << "\tGender: " << gender << "\n";
        cout << "\tAccount Number: " << account_number << "\n\n";
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
        }
        else{
        double current_balance = s.get_balance(account_number);
        current_balance += deposit_amount;
        s.update_balance(account_number, current_balance);

        s.save_transaction(account_number, deposit_amount, "Deposit");
        cout << "Deposit successful. Current balance: " << current_balance << "\n\n";
    }}

    void withdraw(long account_number) {
        double withdraw_amount;
        cout << "Enter withdrawal amount: ";
        cin >> withdraw_amount;

        double current_balance = s.get_balance(account_number);
        if (withdraw_amount <= 0 || withdraw_amount > current_balance) {
            cout << "Invalid withdrawal amount. Available balance: " << current_balance << "\n";
            return;
        }
        else{
        current_balance -= withdraw_amount;
        s.update_balance(account_number, current_balance);

        s.save_transaction(account_number, withdraw_amount, "Withdrawal");
        cout << "Withdrawal successful. Remaining balance: " << current_balance << "\n\n";
    }}

    void show_transaction_history(long account_number) {
        ifstream file("transactions.txt");
        if (!file) {
            cerr << "Error: Unable to open transactions file.\n";
            return;
        }
        else{
        string record,method;
        long acc;
        bool found = false;
        cout << "\n--- Transaction History ---\n";
        while ( file>>acc>>method>>record) {
            if (acc==account_number) {
                cout << acc<<" "<<method<<" "<<record << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found.\n";
        }
        file.close();
    }}
};




class employee{
    public:
     void add_employee(){
 long account_number;
    string full_name, dob, nationality, gender, key, login_pass;
    cout << "1. Personal Information>>\n";
    cout << "\n\tFull Name: ";
    cin.ignore();
    getline(cin, full_name);
    cout << "\n\tDate of Birth (DD/MM/YYYY): ";
    getline(cin, dob);
    cout << "\n\tNationality and Residency: ";
    getline(cin, nationality);
    cout << "\n\tGender: ";
    getline(cin, gender);
    cout << "\n\tKey password(2 digits): ";
    getline(cin, key);

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

    account_number = generate_employee_account_number();

    cout << "Your Account Number: " << account_number << endl;
    ofstream file("employees.txt",ios::app);
    if(!file){
        cout<<"Error; Unable to opne file.";
    }
    file<<account_number<<" "<<full_name<<" "<<login_pass<<" "<<key<<" "<<dob<<" "<<nationality<<" "<<gender<<" "<<endl;
    file.close();
    }


long generate_employee_account_number() {
    long last_account_number = 10000000; // Default if no accounts exist
    long new_account_number;

    // Open the file and find the last account number
    ifstream File("employees.txt");
    if (File) {
        long account_number;
        while (File >> account_number) {
            string dummy;
            getline(File, dummy); // Skip the rest of the line
            last_account_number = account_number; // Update with the last number read
        }
         File.close();
    }

    // Generate a new account number
    new_account_number = last_account_number + 1;

    return new_account_number;
}
      void count_employee(){
        string full_name, dob, nationality, gender, key, login_pass;
        ifstream file("employees.txt");
        int count=0;
       long id;
        if(file .is_open()){
            while (file>>id>>full_name>>dob>>nationality>>gender>>key>>login_pass)
            {
                count++;
            }
            file.close();
        }
        else{
            cout<<"Error: Unable to open file."<<endl;
        }
        cout<<"Total Employee: "<< count<<endl;
      }
      void employee_login(){
        string id, password,name;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter password: ";
    cin >> password;
    ifstream file("employees.txt");
    string fileid, filePassword;
    bool employee_login = false;

    if (file.is_open()) {
        while (file >> fileid >>name>> filePassword) {
            if (fileid == id && filePassword == password) {
               employee_login  = true;
                break;
            }
        }
        file.close();
    }
     else {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    if (employee_login) {

        cout << "Login successful! Welcome, " << id << ".\n";
    } else {
        cout << "Invalid userid or password.\n";
    }
}

};

class bank_lone {
public:
    string name, address, profession, problem, university_name, department, office, rank_position;
    int age, income, lone_amount, id, semester;
    double balance, due_amount, payment;

    void customer_details(long account_number) {
        long a;
        bool loan_exists = false;

        // Check if account already has a loan
        ifstream file1("Loan.txt");
        if (!file1) {
            cout << "Error opening Loan.txt for reading.\n";
        }
        while (file1 >> a) {
            if (a == account_number) {
                cout << "Sorry sir! You already have a loan. Please pay your dues first.\n";
                file1.close();
                return; // Exit the function if a loan exists
            }
        }
        file1.close();

        // New loan application
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter your address: ";
        getline(cin, address);
        cout << "Enter your profession\n1. Student\n2. Working\nYour choice: ";
        int profession_choice;
        cin >> profession_choice;

        if (profession_choice == 1) { // Student
            cout << "Enter your university name: ";
            cin.ignore();
            getline(cin, university_name);
            cout << "Enter your department: ";
            getline(cin, department);
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your income: ";
            cin >> income;
            cout << "Enter your loan amount: ";
            cin >> lone_amount;
            lone_amount=lone_amount+(lone_amount*5)/100;
            cout<<"You have to pay BDT "<<lone_amount<<" Taka for 5 persent interest. Are you agree?\n1: Yes. \n2: No\nEnter choice..>> ";
            int x;
            cin>>x;
            if (x==2){
                return;
            }
            else if (x==1){
            cin.ignore();
            cout << "Why do you want to take a loan: ";
            getline(cin, problem);
            // Write to file
            ofstream loan("Loan.txt", ios::app);
            if (!loan) {
                cout << "Error opening Loan.txt for writing.\n";
            }
            loan << account_number << " " << name << " " << "Student" << " " << age << " "
                 << income << " " << lone_amount << " " << university_name << " "
                 << department << " " << id << " " << problem << '\n';
            loan.close();
            cout << "\nLoan application submitted successfully!\n"<<endl;}

    ofstream write("loan_history.txt", ios::app);
    if (!write) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    write << account_number << " | " << "Take " << ": " << lone_amount << endl;
    write.close();
        }
        else if (profession_choice == 2) { // Working
            cout << "Enter your office name: ";
            cin.ignore();
            getline(cin, office);
            cout << "Enter your position: ";
            getline(cin, rank_position);
            cout << "Enter your income: ";
            cin >> income;
            cout << "Enter your loan amount: ";
            cin >> lone_amount;
             lone_amount=lone_amount+(lone_amount*15)/100;
            cout<<"You have to pay BDT "<<lone_amount<<" Taka for 15 persent interest. Are you agree?\n1: Yes. \n2: No\nEnter choice..>> ";
            int x;
            cin>>x;
            if (x==2){
                return;
            }
            else if (x==1){
            cin.ignore();
            cout << "Why do you want to take a loan: ";
            getline(cin, problem);

            // Write to file
            ofstream loan("Loan.txt", ios::app);
            if (!loan) {
                cout << "Error opening Loan.txt for writing.\n";
            }
            loan << account_number << " " << name << " " << "Working" << " " << age << " "
                 << income << " " << lone_amount << " " << office << " "
                 << rank_position << " " << problem << '\n';
            loan.close();
            cout << "\nLoan application submitted successfully!\n"<<endl;
        } else {
            cout << "Invalid profession choice.\n"<<endl;
        }
         ofstream write("loan_history.txt", ios::app);
    if (!write) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    write << account_number << " " << "Take" << " " << lone_amount << endl;
    write.close();
    }
    }

    void show_loan_history(long account_number) {
        ifstream file("loan_history.txt");
        if (!file) {
            cerr << "Error: Unable to open transactions file.\n"<<endl;
            return;
        }
        else{
            
        string record,method;
        long acc;
        bool found = false;
        cout << "\n--- Loan History ---\n";
        while (file>>acc>>method>> record){
            if (acc==account_number) {
                cout <<acc<<" "<<method<<" "<< record << "\n"<<endl;
                found = true;
            }
        }

        if (!found) {
            cout << "No transactions found.\n"<<endl;
        }
        file.close();
    }}
    void Transaction(long account_number) {
        string name, university_name, department, office, rank_position,profession, problem;
        int age, income, id;

        ifstream file("Loan.txt");
        ofstream temp("temp.txt");

        if (!file || !temp) {
            cout << "Error opening files.\n";
            return;
        }

        bool found = false;
        long acc;
        long double  due_amount, payment;

        while (file >> acc >> name >> profession >> age >> income >> due_amount) {
            if (profession == "Student") {
                file >> university_name >> department >> id >> problem;
            } else if (profession == "Working") {
                file >> office >> rank_position >> problem;
            }

            if (acc == account_number) {
                found = true;
                // Display current due amount
                cout << "Your current due: " << due_amount << " TK" << endl;
                // Accept payment amount
                cout << "Enter payment amount: ";
                cin >> payment;
                // Validate payment
                if (payment > due_amount) {
                    cout << "Payment exceeds due amount. Transaction cancelled.\n";
                } else {
                    due_amount -= payment;

    ofstream write("loan_history.txt", ios::app);
    if (!write) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    write << account_number << " | " << "Pay" << ": " << payment << endl;
    write.close();

                    if (due_amount == 0) {
                        cout << "Payment successful! Loan cleared.\n";
                        continue; // Skip writing this record to effectively delete it
                    } else {
                        cout << "Payment successful! Remaining balance: " << due_amount << " TK\n";
                    }
                }
            }
            // Write updated or unchanged data
            if (profession == "Student") {
                temp << acc << " " << name << " " << profession << " " << age << " "
                     << income << " " << due_amount << " " << university_name << " "
                     << department << " " << id << " " << problem << '\n';
            } else if (profession == "Working") {
                temp << acc << " " << name << " " << profession << " " << age << " "
                     << income << " " << due_amount << " " << office << " "
                     << rank_position << " " << problem << '\n';
            }
        }

        if (!found) {
            cout << "Account number not found in the loan records.\n";
        }

        file.close();
        temp.close();

        // Replace original file with updated file
        remove("Loan.txt");
        rename("temp.txt", "Loan.txt");
    }
};



class help{
public:
    
void help_menu(){
cout << "---->> Help Section <<----" << endl << endl;

  cout << "Menu:" << endl;
  cout << "\t1.  About Us " << endl;
  cout << "\t2.  How to Create an Account" << endl;
  cout << "\t3.  Password Requirements" << endl;
  cout << "\t4.  Reset Password" << endl;
  cout << "\t5.  Transaction Guidelines" << endl;
  cout << "\t6.  Report An Issue" << endl;
  cout << "\t7.  Loan Applications" << endl;
  cout << "\t8.  Security Tips" << endl;
  cout << "\t9.  Contact Support" << endl;
  cout << "\t10. Delate account" <<endl;
  cout << "\t11. Back" << endl;
  cout << "\t12. Exit" << endl;

}

void problem_1(){
    int choice;
cout << "--->> About Us<<----" << endl<< endl;
cout << "Menu: " << endl;
cout << "\t1. Introduction" << endl;
cout << "\t2. Mission Statement" << endl;
cout << "\t3. Vision" << endl;
cout << "\t4. Services" << endl;
cout << "\t5. Technical Team" << endl;
cout << "\t6. Back" << endl;
cout << "\t7. Exit" << endl;

cout << "Enter your choice: ";
cin >> choice;
cout << endl;

if(choice == 1){
    cout << "Welcome to \"SKS\" Bank..." << endl;
    cout << "The full Meaning of the bank..." << endl;
    cout << "\t-S = Md. Shafiul Islam" << endl;
    cout << "\t-K = Md. Kawsar Miah" << endl;
    cout << "\t-S = Sumaiya Haq" << endl << endl;
    
    cout << "SKS Bank, a trusted financial partner dedicated to empowering individuals, businesses, and communities with innovative and comprehensive banking solutions. With a strong foundation of integrity and excellence, SKS Bank offers a wide range of services, including personal and business accounts, loans, investments, digital banking, and wealth management." << endl;

    cout << "Choose SKS Bank today—where trust meets innovation, and your goals become our priorities." << endl;
    cout << endl;
}

else if(choice == 2){
    cout << "--->>Mission Statement<<---" << endl << endl;
    
    cout <<"Our mission is to deliver exceptional financial services that empower our customers to achieve their goals. We are committed to innovation, trust, and inclusivity, providing tailored solutions that foster economic growth, financial literacy, and long-term prosperity. Through responsible practices and a customer-first approach, we aim to create value for individuals, businesses, and communities." << endl << endl;
    
}

else if(choice == 3){
    cout << "--->>Vision<<---" << endl << endl;
    
    cout <<"To be a trusted financial partner that empowers individuals, businesses, and communities by delivering innovative, inclusive, and sustainable banking solutions. We strive to redefine banking through technological excellence, exceptional customer service, and a commitment to fostering economic growth and social well-being." << endl << endl;
    
}

else if(choice == 4){
    
    cout << "Benefits of Banking Services:" << endl;
    cout << "\t-Convenience: Access to funds and financial services 24/7." << endl;
    cout << "\t-Security: Protection of money and valuables." << endl;
    cout << "\t-Financial Planning: Expert advice on saving, investing, and managing wealth." << endl;
    cout << "\t-Accessibility: Easy access to loans for personal, educational, or business needs." << endl;
    cout << "\t-Record Keeping: Detailed account statements for better financial tracking." << endl;
    cout << "\t-Customized Services: Tailored solutions for businesses and individuals." << endl;
}

else if(choice == 5){
    cout << "--->> Team Member <<---" << endl << endl;
    cout << "\1. Member-1" << endl;
    
    cout << "\t-Name: Md. Kawsar Miah" << endl;
    cout << "\t-Age: 21" << endl;
    cout << "\t-Education: Undergraduate" << endl;
    cout << "\t-Institution: IUBAT" << endl;
    cout << "\tContact: " << endl;
    cout << "\t\t-Mobile: 016******95" << endl;
    cout << "\t\t-Email: 23303105@iubat.edu" << endl << endl;
    
    cout << "\2. Member-2" << endl;
    
    cout << "\t-Name: Md. Shafiul Islam" << endl;
    cout << "\t-Age: 22" << endl;
    cout << "\t-Education: Undergraduate" << endl;
    cout << "\t-Institution: IUBAT" << endl;
    cout << "\tContact: " << endl;
    cout << "\t\t-Mobile: 018******14" << endl;
    cout << "\t\t-Email: 23303106@iubat.edu" << endl << endl;
    
    cout << "\3. Member-3" << endl;
    cout << "\t-Name: Sumaiya Haq" << endl;
    cout << "\t-Age: 21" << endl;
    cout << "\t-Education: Undergraduate" << endl;
    cout << "\t-Institution: IUBAT" << endl;
    cout << "\tContact: " << endl;
    cout << "\t\t-Mobile: 017******98" << endl;
    cout << "\t\t-Email: 23303137@iubat.edu" << endl << endl;
    
}

else if(choice == 6){
    cout << "Successfully Back..." << endl << endl;
}

else if(choice == 7){
    cout << "Successfully Exit..." << endl;
    exit(0);
    
}

else{
    cout << "ERROR: Try Again..." << endl << endl;
    
}
}

void problem_2(){
    user1 u;
int choice;
cout << "\n--->>How to Create an Account<<---\n" << endl;
cout << "Menu: " << endl;

cout << "\t1. Details" << endl;
cout << "\t2. Sign_up" << endl;
cout << "\t3. Back" << endl;
cout << "\t4. Exit" << endl;

cout << "Enter your choice: ";
cin >> choice;

if(choice == 1){
    
    cout << "\nWelcome to the Bank System!" << endl;
    cout << "Follow these steps to create an account:" << endl << endl;
    cout << "1. Choose 'Customer Section' from the main menu" << endl;
    cout << "2. Select 'Sign Up' from the Customer Menu" << endl;
    cout << "3. Provide the following details when prompted:" << endl;
    cout << "   - Your full name." << endl;
    cout << "   - Date of Birth (format: DD/MM/YYYY)." << endl;
    cout << "   - Your nationality and residency." << endl;
    cout << "   - Gender (Male/Female/Other)." << endl;
    cout << "   -Set a 2 degit key password. Which is helping you to recover your account." << endl;
    cout << "4. Set a strong password following these rules:" << endl;
    cout << "   - At least 8 characters long." << endl;
    cout << "   - Must include uppercase and lowercase letters, at least one digit, and one special character." << endl;
    cout << "5. Once the information is submitted, your account number will be generated." << endl;
    cout << "6. Save your account number securely." << endl << endl;

 
int cho;
cout << "--->>How to Create an Account<<---" << endl;
cout << "Menu: " << endl;

cout << "\t1. Sign_up" << endl;
cout << "\t2. Back" << endl;
cout << "\t3. Exit" << endl;

cout << "Enter your choice: ";
cin >> cho;

if(cho == 1){
    cout << "Sign_up..." <<endl << endl;
    u.signup();
}

else if(cho == 2){
    cout << "Successfully Back..." << endl << endl;
}
else if(cho == 3){
    cout << "Successfully Exit..." << endl;
    exit(0);
}
else{
    cout << "ERROR: Try Again..." << endl;
}

}
else if(choice == 2){
    cout << "Sign_up..." << endl << endl;
    u.signup();
}
else if(choice == 3){
    cout << "Successfully Back..." << endl << endl;
}
else if(choice == 4){
    cout << "Successfully Exit..." << endl;
    exit(0);
}
else{
    cout << "ERROR: Try Again..." << endl;
}
}

void problem_3(){
        int choice;
    cout << "--->>Password Requirements<<---" << endl;
    cout << "Menu:" << endl;
       
       cout << "\t1.Requirements" << endl;
       cout << "\t2.Back" << endl;
       cout << "\t2.Exit" << endl;
       cout << "Enter your choice: << ";
       cin >> choice;
       cout << endl;
       
       if(choice == 1){
    cout << "1. Password must be at least 8 characters long." << endl;
    cout << "2. Password must include at least one uppercase letter (A-Z)." << endl;
    cout << "3. Password must include at least one lowercase letter (a-z)." << endl;
    cout << "4. Password must include at least one digit (0-9)." << endl;
    cout << "5. Password must include at least one special character (@, #, $, %, &, *)." << endl << endl;
    
     cout << "--->>Strong Passwords Example<<---" << endl;
      cout << "\t- Summer2024@# " << endl;
    cout << "\t- SecureP@ssw0rd123 " << endl;
    cout << "\t- P@ssw0rD!567 " << endl;
    cout << "\t- MyStrongPass!2024 " << endl;
    cout << "\t- Safe&Sound#123 " << endl << endl;
    
    cout << "--->>Normal Passwords Example<<---" << endl;
    
    cout << "\t- 12345678" << endl;
    cout << "\t- password" << endl;
    cout << "\t- abc12345" << endl;
    cout << "\t- qwerty12" << endl;
    cout << "\t- letmein@" << endl;
    cout << "\t- admin123" << endl;
    cout << "\t- welcome1" << endl;
    cout << "\t- iloveyou" << endl << endl;
           
       int cho;
       cout << "--->>Password Requirements<<---" << endl << endl;
       cout << "Menu:" << endl;
       
       cout << "\t1.Back" << endl;
       cout << "\t2.Exit" << endl;
       cout << "Enter your choice: << ";
       cin >> cho;
       
       if(cho == 1){
       cout << "Successfully Back..." << endl << endl;
       }
       else if(cho == 2){
           cout << "Successfully Exit..." << endl << endl;
           exit(0);
       }
       else{
           cout << "ERROR: Try Again..." << endl << endl;
       }
           
       }
       else if(choice == 2){
          cout << "Successfully Back..." << endl << endl;
       }
       else if(choice == 3){
           cout << "Successfully Exit..." << endl << endl;
           exit(0);
           
       }
       else{
           cout << "ERROR: Try Again..." << endl << endl;
       }
}

void problem_4(){
    user1 us;
    int res;
    string reset_pass;
     long account_number;
        string full_name,dob,nationality,gender,login_pass,key;
    cout << "1. Reset password\n2. Reset key password\n3. Back\n--Enter choice: >> ";
    cin >> res;

    if (res == 1) {
        long entered_account;
        string entered_password;

        cout << "Enter Account Number: ";
        cin >> entered_account;
        cin.ignore(); // Clear input buffer
        cout << "Enter key Password: ";
        getline(cin, entered_password);
        cout << endl;

        ifstream file("customer_data.txt");
        ofstream temp("temp.txt");

        if (!file) {
            cerr << "Error: Unable to open the customer data file for reading.\n";
            cout << "Operation aborted.\n";
           
        }
        if (!temp) {
            cerr << "Error: Unable to create a temporary file for writing.\n";
            cout << "Operation aborted.\n";
            file.close();
          
        }

        bool found = false;
        while (file >> account_number) {
            file.ignore();
            getline(file, full_name, ' ');    
            getline(file, dob, ' ');        
            getline(file, nationality, ' '); 
            getline(file, gender, ' ');   
            getline(file, key, ' ');   
            getline(file, login_pass);      
            if (account_number == entered_account && key == entered_password) {
                cout << "\nAccount belonging to " << full_name << " found and password will be reset.\n";
               //cin.ignore();
               while (true) {
        cout << "Set a strong password: ";
         getline(cin , reset_pass);
        if (Password_Validity(reset_pass)) {
            cout << "\nPassword is valid.\n";
            break;
        } else {
            cout << "Invalid password. Please try again.\n";
        }
    }

 temp << account_number << " " << full_name << " " << dob << " "
    << nationality << " " << gender << " " << key << " "<< reset_pass << endl;
            found=true;
            continue;
            }
            
            temp << account_number << " " << full_name << " " << dob << " "
        << us.nationality << " " << gender << " " << key << " "<< login_pass << endl;
        }

        file.close();
        temp.close();

        if (!found) {
            cout << "Account not found or password incorrect.\n" << endl;
            remove("temp.txt");
        } else {
            if (remove("customer_data.txt") != 0) {
                cerr << "Error: Unable to delete the original file." << endl;
                cout << "Operation aborted.\n";
            } else if (rename("temp.txt", "customer_data.txt") != 0) {
                cerr << "Error: Unable to rename the temporary file." << endl;
                cout << "Operation aborted.\n";
            } else {
                cout << "Password reset successfully!\nDo not sear your password and key password.\n" << endl;
            }
        }

    } 
    else if (res==2){
        long entered_account;
        string entered_password;

        cout << "Enter Account Number: ";
        cin >> entered_account;
        cin.ignore(); // Clear input buffer
        cout << "Enter Password: ";
        getline(cin, entered_password);
        cout << endl;

        ifstream file("customer_data.txt");
        ofstream temp("temp.txt");

        if (!file) {
            cerr << "Error: Unable to open the customer data file for reading.\n";
            cout << "Operation aborted.\n";
           
        }
        if (!temp) {
            cerr << "Error: Unable to create a temporary file for writing.\n";
            cout << "Operation aborted.\n";
            file.close();
          
        }

        bool found = false;
        while (file >>account_number) {
            file.ignore();
            getline(file, full_name, ' ');    
            getline(file, dob, ' ');        
            getline(file, nationality, ' '); 
            getline(file, gender, ' ');   
            getline(file, key, ' ');   
            getline(file, login_pass);      
            if (account_number == entered_account && login_pass == entered_password) {
                cout << "\nAccount belonging to " << full_name << " found and key password will be reset.\n";
        cout << "Set a 2 digits key password: ";
         getline(cin , reset_pass);
 temp << account_number << " " << full_name << " " << dob << " "
    << nationality << " " << gender << " " << reset_pass << " "<<login_pass  << endl;
            found=true;
            continue;
            }
            
            temp << account_number << " " << full_name << " " << dob << " "
        << nationality << " " << gender << " " << key << " "<< login_pass << endl;
        }

        file.close();
        temp.close();

        if (!found) {
            cout << "Account not found or password incorrect.\n" << endl;
            remove("temp.txt");
        } else {
            if (remove("customer_data.txt") != 0) {
                cerr << "Error: Unable to delete the original file." << endl;
                cout << "Operation aborted.\n";
            } else if (rename("temp.txt", "customer_data.txt") != 0) {
                cerr << "Error: Unable to rename the temporary file." << endl;
                cout << "Operation aborted.\n";
            } else {
                cout << "Key Password reset successfully!\nDo not sear your password and key password.\n" << endl;
            }
        }

    }
    else if (res == 3) {
        cout << "Returning to the previous menu." << endl;
    }

    else {
        cout << "Invalid choice." << endl;
        problem_4();
    }
    

}

void problem_5(){
        int choice;
    cout << "--->>Transaction Guidelines<<---" << endl << endl;
    cout << "\tMenu:" << endl;
    cout << "\t1. Guidelines" << endl;
    cout << "\t2. Back" << endl;
    cout << "\t3. Exit" << endl << endl;
    cout << "Enter your choice << ";
    cin >> choice;
    if(choice == 1){
        cout << "1. Identification:" << endl;
    cout << "   - Always carry a valid photo ID (e.g., passport, national ID, or driver's license)." << endl;
    cout << "   - Ensure the name on the ID matches the account details." << endl;
    cout << "   - Provide additional documents if required for certain transactions." << endl << endl;
    cout << "2. Accurate Details:" << endl;
    cout << "   - Verify the recipient's account number before transfers." << endl;
    cout << "   - Ensure that the account name and transaction amount are correct." << endl;
    cout << "   - Double-check all details on receipts and confirmation messages." << endl << endl;
    cout << "3. Banking Hours:" << endl;
    cout << "   - Perform cash-related transactions within the bank's operating hours." << endl;
    cout << "   - Check cut-off times for cheque clearances or fund transfers." << endl;
    cout << "   - Use ATMs or on-line banking for transactions outside banking hours." << endl << endl;
    cout << "4. Transaction Slips:" << endl;
    cout << "   - Fill out deposit and withdrawal slips legibly and accurately." << endl;
    cout << "   - Double-check the slip details before submission." << endl;
    cout << "   - Keep the counterfoil or acknowledgment slip for future reference." << endl << endl;
    cout << "5. Cash Handling:" << endl;
    cout << "   - Count cash carefully before leaving the counter." << endl;
    cout << "   - Avoid exposing large amounts of cash in public areas." << endl;
    cout << "   - Use secure methods like demand drafts or bank transfers for high-value transactions." << endl << endl;
    cout << "6. Safety:" << endl;
    cout << "   - Never disclose sensitive information like your PIN or OTP to anyone." << endl;
    cout << "   - Monitor your account regularly for unauthorized transactions." << endl;
    cout << "   - Report lost cards or suspicious activities to the bank immediately." << endl;
    cout << "   - Use strong passwords for on-line banking and change them periodically." << endl << endl;
    int cho;
    cout << "--->>Transaction Guidelines<<---" << endl << endl;
    cout << "\tMenu:" << endl;
    cout << "\t1. Back" << endl;
    cout << "\t2. Exit" << endl;
    cout << "Enter your choice << ";
    cin >> cho;
    cout << endl;
    if(cho == 1){
        cout << "successfully Back..." << endl << endl;
    }
    else if(cho == 2){
        cout << "successfully Exit..." << endl << endl;
         exit(0);
    }
    else{
        cout << "ERROR: Try Again..." << endl << endl;
    }
    }
    else if(choice == 2){
        cout << "successfully Back..." << endl << endl;
    }
    else if(choice == 3){
        cout << "successfully Exit..." << endl << endl;
        exit(0);
    }
    else{
        cout << "ERROR: Try Again..." << endl << endl;
    }
}

void problem_6(){
    int choice;


        cout << "\n--->>Issue Reporting System<<---" << endl << endl;
        cout << "Menu: " << endl;

        cout << "\t1. New Report" << endl;
        cout << "\t2. Search your report" << endl;
        cout << "\t3. View all issues(only for Admin)" << endl;
        cout << "\t4. Back" << endl;
        cout << "\t5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1){

                ofstream outFile("issues.text");
    if (!outFile) {
        cout << "Error: Unable to open file for writing." << endl;
    }

    string issue;
    double n;
    cout << "Enter your Account Number: ";
    cin >> n;
    cout << "Enter your issue: ";
    cin.ignore();
    getline(cin, issue);
    outFile << "ID: " << n << " | " << "Issue: "<<issue << endl;
    cout << "Issue reported successfully!" << endl;

    outFile.close();

            int cho;
            cout << "\n--->>Report Issue<<---\n" << endl;
            cout << "\t1. View report" << endl;
            cout << "\t2. Back" << endl;
            cout << "\t3. Exit" << endl << endl;

            cout << "Enter your choice: ";
            cin >> cho;

            if(cho == 1){
                cout << "Working..." << endl;
            }

            else if(cho == 2){
                cout << "Successfully Back..." << endl;

                cout << endl;
            }
            else if(cho == 3){
                cout << "Successfully Exit..." << endl;
                exit(0);
            }
            else{
                cout << "ERROR. Try Again...." << endl;
            }
        }

        else if(choice == 2){

        }

        else if(choice == 3){

        cout << "Only for Admin..." << endl;
        const string password = "1234";
        string p;
        cout << "Enter your password: ";
        cin >> p;

        if(password != p){
            cout << "ERROR: Tray Again..." << endl;
        }
        else{
                ifstream inFile("issues.text");

    if (!inFile) {
        cout << "Error: Unable to open file for reading." << endl;
    }

    string issue;
    cout << "\nReported Issues:\n";
    while (getline(inFile, issue)) {
        cout << "- " << issue << endl;
    }

    inFile.close();

            int cho;
            cout << "\n---> Report<<---" << endl;
            cout << "Menu: " << endl;

            cout << "\t1. Back" << endl;
            cout << "\t2. Exit" << endl;

            cout << "Enter your choice: ";
            cin >> cho;

            if(cho==1){
                 cout << "Successfully Back..." << endl;

            }
            else if(cho == 2){
                 cout << "Successfully Exit..." << endl;
                 exit(0);
            }
            else{
                cout << "ERROR: Try Again..." << endl;
            }
        }
        }

        else if(choice == 4){
            cout << "Successfully Back..." << endl;
        }

        else if(choice == 5){
            cout << "Successfully Exit..." << endl;
            exit(0);
        }

        else{
            cout << "Invalid choice. Please try again." << endl;
        }

}

void problem_7(){
     int choice;
    do{
        cout << "--->>Types of Bank Loans<<---" << endl;
        cout << "-----------------------------" << endl << endl;
        
        cout << "1. Home Loan" << endl;
        cout << "2. Car Loan" << endl;
        cout << "3. Student Loan" << endl;
        cout << "4. Personal Loan" << endl;
        cout << "5. Agriculture Loan" << endl;
        cout << "6. Business Loan" << endl;
        cout << "7. More details" << endl;
        cout << "8. Exit" << endl;
        
        cout << "Enter your choice: ";
        cin>> choice;
        cout << endl << endl;
        
        switch(choice){
            
        case 1:
        cout << "--->>Home Loan<<---" << endl;
        cout << "- Interest Rate: 7%" << endl;
        cout << "- Maximum Tenure: 20 years" << endl;
        cout << "- Minimum Amount: 5,00,000"<< endl;
        break;
            
        case 2:
        cout << "--->>Car loan<<---" << endl;
        cout << "- Interest Rate: 9%" << endl;
        cout << "- Maximum Tenure: 7 years" << endl;
        cout << "- Minimum Amount: 1,00,000" << endl;
        break;
            
        case 3:
        cout << "--->>Student Loan<<---" << endl;
        cout << "- Interest Rate: 4%\n";
        cout << "- Maximum Tenure: 15 years\n";
        cout << "- Minimum Amount: 50,000\n";
        break;
            
        case 4:
        cout << "--->>Personal Loan<<---" << endl;
        cout << "- Interest Rate: 12%\n";
        cout << "- Maximum Tenure: 5 years\n";
        cout << "- Minimum Amount: 50,000\n";
            break;
            
        case 5:
        cout << "--->>Agriculture Loan<<---" << endl;
        cout << "- Interest Rate: 5%" << endl;
        cout << "- Maximum Tenure: 10 years" << endl;
        cout << "- Minimum Amount: 1,00,000" << endl;
        break;
        
        case 6:
        cout <<"--->>Business Loan<<---" << endl;
        cout << "- Interest Rate: 10%";
        cout << "- Maximum Tenure: 15 years";
        cout << "- Minimum Amount: 2,00,000";
        
        case 7:
        cout << "--->>More details<<---" << endl;
        cout << "-->>Contruct us.." << endl << endl;
        cout << "Email: -bankmanagement@gmil.com" <<endl;
        cout << "Phone: \n-01727**** \n-01610******" << endl;
        cout << "\nThank you" << endl;
        break;
        
        case 8:{
        cout << "Thank you for visiting us." << endl << endl;
        return;
        }
        break;
        
        default:
        cout << "Error.Try Again" << endl;
        cout << "xxxxxxxxxxxxxxx" << endl << endl;
        problem_7();
        break;
        }
        
        cout << "\n--->>Types of Bank Loans<<---" << endl;
        cout << "1. Again" << endl;
        cout << "2. Back" << endl;
        cout << "Enter your choice (1-2): ";
        cin >> choice;
        cout << endl;
        
        if (choice == 2);
        } while (choice == 1);
    
}

void problem_8(){
    int choice;
    cout << "--->>Security Tips<<---" << endl << endl;
    
    cout << "Menu:"<< endl;
    cout << "\t1. Tips" << endl;
    cout << "\t2. Back" << endl;
    cout << "\t3. Exit" << endl;
    
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    
    if(choice == 1){
        cout << "--->>Security Tips<<---" << endl << endl;
        
        
    cout << "1. Protect your PIN and passwords." << endl;
    cout << "   - Keep your PIN and passwords confidential; never share them with anyone." << endl;
    cout << "   - Avoid writing down your PIN or saving it in an easily accessible place." << endl;
    cout << "   - Use a strong combination of uppercase, lowercase, numbers, and symbols for passwords." << endl << endl;
    cout << "   - Change your passwords regularly to enhance security." << endl;

    cout << "2. Monitor account activity regularly." << endl;
    cout << "   - Frequently review your bank statements and transaction history online or via mobile banking apps." << endl;
    cout << "   - Check for any unauthorized or suspicious transactions, even small amounts." << endl;
    cout << "   - Set reminders to review your account weekly." << endl << endl;

    cout << "3. Beware of phishing scams." << endl;
    cout << "   - Avoid clicking on links in unsolicited emails, messages, or pop-ups that claim to be from your bank." << endl;
    cout << "   - Verify the sender's email address or phone number before responding to any requests for personal information." << endl;
    cout << "   - Your bank will never ask for your PIN or full password through email or phone." << endl << endl;

    cout << "4. Secure your devices." << endl;
    cout << "   - Install and update antivirus software to protect against malware and viruses." << endl;
    cout << "   - Keep your operating system and apps updated to fix security vulnerabilities." << endl;
    cout << "   - Avoid using public or unsecured Wi-Fi for online banking. If necessary, use a trusted VPN service." << endl;
    cout << "   - Enable screen lock features on your devices to prevent unauthorized access." << endl << endl;

    cout << "5. Report issues immediately." << endl;
    cout << "   - Notify your bank as soon as you suspect unauthorized access to your account or card." << endl;
    cout << "   - Use the bank's official helpline or visit the branch to report lost or stolen cards." << endl;
    cout << "   - Keep your bank's customer support number saved for quick access." << endl << endl;

    cout << "6. Set up transaction alerts." << endl;
    cout << "   - Enable SMS or email notifications for every transaction on your account." << endl;
    cout << "   - Use these alerts to quickly detect unauthorized or suspicious activity." << endl;
    cout << "   - Customize alerts for large withdrawals or transactions over a specific amount." << endl << endl;

        
        
        
    int cho;
    cout << "--->>Security Tips<<---" << endl << endl;
    
    cout << "Menu:"<< endl;
    cout << "\t1. Back" << endl;
    cout << "\t2. Exit" << endl;
    
    cout << "Enter your choice: ";
    cin >> cho;
    cout << endl;
    
    if(cho == 1){
        cout << "Successfully Back..." << endl;
    }
    else if(cho == 2){
        cout << "Successfully Exit..." << endl;
        exit(0);
    }
    else{
        cout << "ERROR: Try Again..." << endl;
    }
    }
    else if(choice == 2){
        cout << "Successfully Back..." << endl;
    }
    
    else if(choice == 3){
        cout << "Successfully Exit..." << endl;
        exit(0);
    }
    else{
        cout << "ERROR: Try Again..." << endl;
    }
    
}

void problem_9(){
    
}

void problem_10(){
   user1 use;
     cout << "Do you want to delete your account?\n1. Yes\n2. No\n3. Back\nEnter your choice >> ";
    int dlt;
    cin >> dlt;

    if (dlt == 1) {
        long entered_account;
        string entered_password;

        cout << "Enter Account Number: ";
        cin >> entered_account;
        cin.ignore(); // Clear input buffer
        cout << "Enter Password: ";
        getline(cin, entered_password);
        cout << endl;

        ifstream file("customer_data.txt");
        ofstream temp("temp.txt");

        if (!file) {
            cerr << "Error: Unable to open the customer data file for reading.\n";
            cout << "Operation aborted.\n";
           
        }
        if (!temp) {
            cerr << "Error: Unable to create a temporary file for writing.\n";
            cout << "Operation aborted.\n";
            file.close();
          
        }

        bool found = false;
        while (file >> use.account_number) {
            file.ignore();
            getline(file, use.full_name, ' ');    
            getline(file, use.dob, ' ');        
            getline(file, use.nationality, ' '); 
            getline(file, use.gender, ' ');   
            getline(file, use.key, ' ');   
            getline(file, use.login_pass);      
            if (use.account_number == entered_account && use.login_pass == entered_password) {
                cout << "\nAccount belonging to " << use.full_name << " found and will be deleted.\n";
                found = true;
                continue;
            }
            temp << use.account_number << " " << use.full_name << " " << use.dob << " "
                 << use.nationality << " " << use.gender << " " << use.key << " "<< use.login_pass << endl;
        }

        file.close();
        temp.close();

        if (!found) {
            cout << "Account not found or password incorrect.\n" << endl;
            remove("temp.txt");
        } else {
            if (remove("customer_data.txt") != 0) {
                cerr << "Error: Unable to delete the original file." << endl;
                cout << "Operation aborted.\n";
            } else if (rename("temp.txt", "customer_data.txt") != 0) {
                cerr << "Error: Unable to rename the temporary file." << endl;
                cout << "Operation aborted.\n";
            } else {
                cout << "Account deleted successfully!" << endl;
            }
        }

    } else if (dlt == 2) {
        cout << "No action taken." << endl;
    } else if (dlt == 3) {
        cout << "Returning to the previous menu." << endl;
    }

    else {
        cout << "Invalid choice." << endl;
        problem_10();
    }
    }


void problem_11(){
cout << "Thank you for visiting us." << endl;
cout << "Successfully Back..." << endl << endl;
}

void problem_12(){
    cout << "Successfully Exit..." << endl;
    exit(0);
}


};

void access_help(){
     int choice;
             help  h;

    while (true) {

        h.help_menu();

        cout << "\nEnter your choice: >> ";
        cin >> choice;
        cout << endl;

        switch(choice){

            case 1:
            h.problem_1();
            break;

            case 2:
            h.problem_2();
            break;

            case 3:
            h.problem_3();
            break;

            case 4:
            h.problem_4();
            break;

            case 5:
            h.problem_5();
            break;

            case 6:
            h.problem_6();
            break;

            case 7:
            h.problem_7();
            break;

            case 8:
            h.problem_8();
            break;

            case 9:
            h.problem_9();
            break;

            case 10:
            h.problem_10();

            case 11:
           cout << "Successfully Back to help section..." << endl;
            return;
            break;

            case 12:
            h.problem_12();
            break;

            default:
            cout << "Error. Try Again" << endl << endl;

            }
          }
}

class login_conditions{
    public:
     bank_lone loan;
      user1 user;
       display_chart chart;
       after_login log;
    save_file file_manager;
bool is_valid;
 long account_number;
        string full_name,dob,nationality,gender,login_pass,key;

    login_conditions(){
        is_valid=false;
    }
void login_conditionn(){

     long entered_account;
    string entered_password;

    cout << "Enter Account Number: ";
    cin >> entered_account;
    cin.ignore();
    cout << "Enter Password: ";
    getline(cin, entered_password);
    cout << endl;
    ifstream file("customer_data.txt");
    if (!file) {
        cout << "Error: Unable to open customer data file.\n";
    }


    while (file >> account_number) {
        file.ignore(); 
        getline(file, full_name, ' ');
        getline(file, dob, ' ');
        getline(file, nationality, ' ');
        getline(file, gender, ' ');
        getline(file, key, ' ');
        getline(file, login_pass);

        if (account_number == entered_account && login_pass == entered_password) {
            cout << "\nLogin successful! Welcome, " << full_name << ".\n";
            is_valid = true;

            int second_chart;
            while (true) {
                chart.show_user_chart();
                cin >> second_chart;
                cout << endl;

                if (second_chart == 1) {
                    log.deposit(account_number);
                    cout<<endl;
                } else if (second_chart == 2) {
                    log.withdraw(account_number);
                    cout<<endl;
                } else if (second_chart == 3) {
                    cout<<"1: Show biodata.\n2: Show transection history.\n--Enter your choice-->>"<<endl;
                    int b;
                    cin>>b;
                    if(b==1){
                    double balance = file_manager.get_balance(account_number);
                    cout << "---Account Details---\n";
                    cout<<"Full name : "<<full_name<<endl;
                    cout<<"Date of birth: " << dob<<endl;
                     cout<<"Nationality: "<<  nationality<<endl;
                    cout<<"Gender: "<<gender<<endl;

                    cout << "Current Balance: " << balance << endl<<endl;}
                    else if (b==2){
                       log. show_transaction_history(entered_account);
                    }
                }
                else if (second_chart == 4) {
                    int  openion;
                    cout << "1: Take a loan .\n2: Pamment due loan.\n3: Check loan details.\n4: Back.\n Inter your choice: >>  ";
                    cin >> openion;
                    cin.ignore();
                    cout << endl;
                    if (openion == 1 ) {
                        loan.customer_details(entered_account);
                    }
                    else if(openion==2){
                        
                        loan.Transaction(entered_account);

                    }
                    else if (openion==3){
                        loan.show_loan_history(entered_account);
                    }
                    else if(openion==4)
                    {
                        continue;
                    }

                } 
                else if (second_chart==5){
                    access_help();
                }
                else if (second_chart == 6) {
                    cout << "Logging out successfull.....\n";
                    break;
                } else {
                    cout << "Invalid choice. Please try again.\n";
                }
            }
            break;
        }
    }

    if (!is_valid) {
        cout << "Invalid account number or password. Please try again.\n";
    }

    file.close();
}
};
void count_total_customer(){
    ifstream inFile("customer_data.txt");
                    int count_customer=0;
                    long account_number;
                    string full_name, dob, nationality, gender, key, login_pass;

                     if (inFile.is_open()) {
                        while (inFile >>full_name>>dob>>nationality>>gender>>key>>login_pass) {
                            count_customer++;
                        }
                        inFile.close();
                    } 
                    else {
                        cout << "Error: Unable to open customer data file.\n";
                    }

                    cout << "Total Customers: " << count_customer << endl;
}
void count_total_loan_receivers(){
    ifstream file1("Loan.txt");
    int count_loan=0;
    long account_number;
    string name, university_name, department, office, rank_position,profession, problem;
    int age, income, id;
    double loan_amount;
    if(file1.is_open()){
        while (file1>>account_number>>name>>profession>>age>>income>>loan_amount){
            if (profession == "Student") {
                                file1 >> university_name >> department >> id >> problem;
                            } 
                            else if (profession == "Working") {
                                file1 >> office >> rank_position >> problem;
                            }
                            count_loan++; 
        }
        file1.close();
    }
    else {
        cout<<"Error: Unable to open loan data file."<<endl;
    }
    cout<<"Total lone receiver: "<<count_loan<<endl;
}

void admin() {
    cout << "Username: ";
    employee emp;
    display_chart chart;
    string username, password;
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    if (username == "Shafiul" && password == "sumai137") {
        while (true) { // Loop to stay in the admin section
            chart.for_admin();
            int choice;
            cin >> choice;
            cin.ignore(); // Clear input buffer
            cout << endl;

            switch (choice) {
                case 1:
                    emp.count_employee();
                    break;
                case 2:// Implement total customer functionality
                    count_total_customer();
                    break;
                
                case 3:
                    // Implement total loan receiver functionality
                    count_total_loan_receivers();
                    break;
                case 4:
                    emp.add_employee();
                    break;
                case 5:
                    return; // Exit admin section
                case 6:
                cout<<"Have a nice day! Thank you";
                exit(0);
                default:
                    cout << "Invalid choice. Try again." << endl;
            }

            cout << endl;
        }
    } else {
        cout << "Invalid credentials. Try again.\n";
    }

}


class continue_code {
    public:
    display_chart chart;
    employee emp;
    user1 user;
    help h;
   login_conditions loginC;
    string openion;
    after_login log;
    save_file file_manager;
    int option,second_chart,log_option,a;
void second(){
    while (true) {
        chart.show_first_chart();
        cin >> option;
        cin.ignore();
        cout<<endl;
        if (option == 1) {
            second21();
        }
          
        
        else if (option == 2) {
            cout<<"\n1: Employee"<<endl;
            cout<<"2: Back\n>>>Choice an option: ";
            int b;
            cin>>b;
            if (b==1){
             cout<<endl;
            cout<<"...Login..."<<endl;
            emp.employee_login();}
            else if(b==2){
                continue;
            }
            else{
              cout<<"Invalid choice."<<endl;
              continue;
            }
        } 
        else if (option == 3) {
            access_help();
        } 
        else if (option == 4) {
            admin();
        }}}

        void second21(){
        chart.ask_for_login(); 
            cin>>log_option;
            cout<<endl;
            if(log_option==1){
                cout <<"1: Process of creating an account.\n2: Create an account.\n3: Back.\n4: Exit.\nEnter your choice: >>";
                int s;
                cin >> s;
                if(s==1)
                h.problem_2();
                else if (s==2){
                user.signup();
                user.show_details();}
               else if(s==3) second21();
               else if (s==4) second();
               else {cout<<"Wrong choice\n\n";}
        }
        else if (log_option == 2) {
                loginC.is_valid=false;
               for(int i=0;i<=3;i++){
               if(loginC.is_valid==false){
                if(i==3){
                     cout<<"Please go to help section.";
                     continue;
                }
               loginC. login_conditionn();
               }}
              
}
        else if (log_option==3){
            return;
        }  
        }
};

int main(){
   continue_code con;
    con.second();
   return 0;
}
