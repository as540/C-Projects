#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool is_Number_String(const string& s){
    int length = s.length();
    for (int i = 0; i < length; i++){if (s[i]<'0'||s[i]>'9'){return false;}}
    return true;
}

int main(){
    string credit_card_Number;

    cout<<"This program uses the Luhn Algorigthm to validate a Credit Card number."<<endl;
    cout<<"You can enter 'exit' anytime to finish"<<endl;

    while (1){
        cout<<"Please enter a Credit Card number to validate:";
        cin>>credit_card_Number;

        if(credit_card_Number=="exit"){break;}

        else if (is_Number_String(credit_card_Number)==0){
            cout<<"Bad input!";
            continue;
        }

        int len=credit_card_Number.length();
        int double_Even_Sum=0;

         for (int i=len-2;i>=0;i=i-2){
            int doubl=((credit_card_Number[i]-48)*2);
            if(doubl>9){doubl=(doubl/10)+(doubl%10);}
            double_Even_Sum+=doubl;
        }

        for (int i=len-1;i>=0;i=i-2) {double_Even_Sum+=(credit_card_Number[i]-48);}

        cout << (double_Even_Sum%10==0?"Valid!":"Invalid!")<<endl;
        continue;
    }

    return 0;
}
