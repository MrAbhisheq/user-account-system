#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

string name[30];
string username[30];
string password[30];
int users = 0;

int loggedin = 0;
int ch;

void home();
void signup();
void signin();
void profile();
void changepass();
void logout();
void account();

int main()
{
    do{
        home();

        if(ch==1)
        {
            signup();
        }

        else if(ch==2)
        {
            signin();
        }
    }while(ch != 3);

    return 0;
}

void home()
{
    cout << "\n======================================";
    cout << "\n\n>> ACCOUNT SYSTEM <<" << endl;
    cout << " 1. Registration\n 2. Login\n 3. Exit" << endl;
    cout << "Enter Choice: ";
    cin >> ch;
    cout << "\n======================================";
}

void signup()
{
    string n, u, p;
    cout << "\nREGISTRATION"<<endl;

    cout << "\nName: ";
    cin >> n;                   

    cout << "\nUsername: ";
    cin >> u;                     
    
    cout << "\nPassword: ";
    cin >> p;                   

    for(int i=1; i<=30; i++)
    {
        if(u == username[i])
        {
            cout << "\nUsername is already exists!";
            signup();
        }
    }

    n = name[users+1];
    u = username[users+1];
    p = password[users+1];

    cout << "\nRegistration Successful..."; 
}

void signin()
{
    string uname, pass;
    cout << "\nLOGIN";

    do
    {
        cout << "\nUsername: ";
        cin >> uname;

        cout << "\nPassword: ";
        cin >> pass;

        for(int i=1; i<=30; i++)
        {
            if(uname==username[i] && pass==password[i])
            {
                loggedin = i;
                cout << "\nLogin Successfull";
                account();
            }
            continue;
        }
        if(loggedin == 0)
        {
            cout<<"\nInvalid Username or Password";
        }
    }while(loggedin != 0);
}

void profile()
{
    cout<<"\n=====================================";
    cout<<"\n   NAME    : " << name[loggedin] << "   ";
    cout<<"\n   USERNAME: " << username[loggedin] << "  ";
    cout<<"\n   PASSWORD: " << "********";
    cout<<"\n=====================================";
    account();
}

void changepass()
{
    string currpass, newpass;
    cout << "\nEnter current password: ";
    cin >> currpass;
    if(currpass == password[loggedin])
    {
        cout<<"Enter New Password: ";
        cin>> newpass;
        // cout<<"Confirm Password: ";
        // cin>> confirmpass;

        // if(newpass != confirmpass)
        // {
        //     cout << "  **Password not match!";
        //     cout<<"Confirm Password: ";
        //     cin>> confirmpass;  
        // }
        password[loggedin] = newpass;
    }
    else
    {
        cout << "Invalid Password!";
        changepass();
    }
    account();
}

void logout()
{
    loggedin = 0;
    cout << "\n==================================";
    cout << "\nSuccessfully logged out!"<<endl;
    cout << "\nRedirecting you to Home..."<<endl;
    cout << "\n==================================";
    home();
}

void account()
{
    int ch1;
    cout << "\n======================================";
    cout << "\n\nWelcome " << name[loggedin] << " to our portal!" << endl;
    do{
        cout << "\n 1. Profile details\n 2. Change password\n 3. Logout\n\nEnter choice: ";
        cin >> ch1;

        if(ch1==1)
        {
            profile();
        }
        else if(ch1==2)
        {
            changepass();
        }
        else if(ch1==3)
        {
            logout();
        }
        else
        {
            cout << "\n**Invalid Choice!";
        }
    }while(ch1 > 4);
    cout << "\n======================================";
}