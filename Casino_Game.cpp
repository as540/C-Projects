/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib> //for random numbers
using namespace std;
void rules();
int main()
{
    string playerName;
    int balance;// storing Current Balance
    int bettingAmount;
    int guess;
    int random_number;// storing numbers from cstlib
    char choice;

    cout<<"\t\t________WELCOME TO CASINO GAME_________"<<endl<<endl;
    cout<<endl<<"What's your Name:";
    getline(cin,playerName);
    cout<<endl<<endl<<"Enter the starting balance to play game(in dollars):$";
    cin>>balance;
    do
    {   rules();
        cout<<endl<<endl<<"Your current balance is $"<<balance<<endl;
        do
        {   cout<<"Hi,"<<playerName<<",enter amount to bet:$";
            cin>>bettingAmount;
            if(bettingAmount>balance)
                cout <<"Betting balance can't be more than current balance!"<<endl<<"Re-enter balance"<<endl;
        }while(bettingAmount>balance);
// Get number from player
        do
        {cout<<"Guess any betting number between 1 & 10:";
        cin>>guess;
        if(guess<=0||guess>10){cout<<endl<<"Number should be between 1 and 10"<<endl<<"Re-enter number:"<<endl;}
        }while(guess <= 0||guess > 10);

         random_number=rand()%10+1;

        if(random_number==guess)
        {
            cout<<endl<<"You are in luck!!You have won $"<<bettingAmount*10;
            balance=balance+bettingAmount*10;
        }
        else
        {
            cout <<"Oops,better luck next time!!You lost $"<<bettingAmount<<endl;
            balance=balance-bettingAmount;
        }
        cout<<endl<<"The winning number was:"<<random_number <<endl;
        cout <<endl<<playerName<<",You have balance of $"<<balance <<endl;
        if(balance==0)
        {
            cout <<"You have no money to play";
            break;
        }
        cout<<endl<<endl<<"->Do you want to play again (y/n)?";
        cin>>choice;
        if(choice!='y'||choice!='Y'||choice!='n'||choice!='N'){
        cout<<"enter proper choice.."<<"one more incorrect choice will terminate you from the game"<<endl;
        cin>>choice;
    }
    }while(choice=='Y'||choice=='y');

    //if the game is ended

    cout<<endl<<endl;
    cout<<endl<<endl<<"Thanks for playing the game.Your balance is $"<<balance<<endl;
    return 0;
}
void rules()
{

    cout<<"\t\t________NUMBER GUESSING RULES_________"<<endl;
    cout<<"1.Choose a number between 1 and 10"<<endl;
    cout<<"2.For Correct Guess,10 times of the amount bet is added to total"<<endl;
    cout<<"3.For Wrong Guess,The amount of money bet is deducted from the total"<<endl<<endl;
}
