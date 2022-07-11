#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool is_Number_String(const string& s) {
    int length = s.length();
    for (int i = 0; i < length; i++) {
        if (s[i]<'0'||s[i]>'9'){return false;}
    }
    return true;
}

int main() {
    string credit_card_Number;
    
    cout << "This program uses the Luhn Algorigthm to validate a Credit Card number." << endl;
    cout << "You can enter 'exit' anytime to finish "<< endl;
    
    while (1) {
        cout << "Please enter a Credit Card number to validate: ";
        cin >> credit_card_Number;
        
        if(credit_card_Number=="exit"){break;}
        
        else if (!is_Number_String(credit_card_Number)) {
            cout<<"Bad input!";
            continue;
        }
            
        int len = credit_card_Number.length();
        int doubleEvenSum = 0;
        
         for (int i=len-2;i>=0;i=i-2) {
            int dbl = ((credit_card_Number[i]-48)*2);
            if (dbl>9){dbl=(dbl/10)+(dbl%10);}
            doubleEvenSum+=dbl;
        }
        
        for (int i=len-1;i>=0;i=i-2) {doubleEvenSum+=(credit_card_Number[i]-48);}
        
        cout << (doubleEvenSum%10==0?"Valid!":"Invalid!")<<endl;
        continue;        
    }

    return 0;
}