/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *author,*title,*publisher;
	float *price;
	int *stock;
public:	
	book()	{
	          author= new char[100];
	          title=new char[20];
	          publisher=new char[50];
	          price= new float;
	          stock=new int;
	         }
	void feed_data();
	void edit_data();
	void show_data();
	int search(char[],char[]);
	void buy_book();
	
};

void book::feed_data()	{
	cin.ignore();
	cout<<endl<<"Enter Author Name: ";      
	cin.getline(author,20);
	cout<<"Enter Title Name: ";       
	cin.getline(title,20);
	cout<<"Enter Publisher Name: ";   
	cin.getline(publisher,20);
	cout<<"Enter Price: ";            
	cin>>*price;
	cout<<"Enter Stock Position: ";   
	cin>>*stock;   
	
}

void book::edit_data()	{
	
	cout<<endl<<"Enter Author Name:";      
	cin.getline(author,20);
	cout<<"Enter Title Name:";       
	cin.getline(title,20);
	cout<<"Enter Publisher Name:";   
	cin.getline(publisher,20);
	cout<<"Enter Price: ";           
	cin>>*price;
	cout<<"Enter Stock Position:";   
	cin>>*stock;   
	
}

void book::show_data(){
	cout<<endl<<"Author Name:"<<author;
	cout<<endl<<"Title Name:"<<title;
	cout<<endl<<"Publisher Name:"<<publisher;
	cout<<endl<<"Price:"<<*price;
	cout<<endl<<"Stock Position:"<<*stock;   
	
}

int book::search(char tbuy[20],char abuy[20]){
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0){return 1;}
	else return 0;
		
}

void book::buy_book(){
	int count;
	cout<<endl<<"Enter Number Of Books to buy:";
	cin>>count;
	if(count<=*stock){
		*stock=*stock-count;
		cout<<endl<<"Books Bought Sucessfully";
		cout<<endl<<"Amount: Rs."<<count*(*price);
	}
	else
		cout<<endl<<"Required Copies not in Stock";
}

int main()	{
	book *Book[20];
	int i=0,r,t,choice_number;
	char title_buy[20],author_buy[20];
	while(1){
		cout<<endl<<endl<<"\t\t MENU"<<endl<<"1.Entry of New Book"<<endl<<"2.Buy Book"<<endl<<"3.Search For Book"<<endl<<"4.Edit Details Of Book"<<endl<<"5.Exit"<<endl<<endl<<"Enter your Choice:";
		
		cin>>choice_number;
		
		switch(choice_number){
			case 1:	Book[i]=new book;
				Book[i]->feed_data();
				i++;	
				break;
				
			case 2:cin.ignore();
				cout<<endl<<"Enter Title Of Book:";cin.getline(title_buy,20);
				cout<<endl<<"Enter Author Of Book:"; cin.getline(author_buy,20);
				for(t=0;t<i;t++){
					if(Book[t]->search(title_buy,author_buy)){
						                                 Book[t]->buy_book();
						                                 break;
				                                        }
				                }
				if(t==1)
				cout<<endl<<"This Book is Not in Stock";
				break;
			case 3:cin.ignore();
				cout<<endl<<"Enter Title Of Book:";cin.getline(title_buy,20);
				cout<<"Enter Author Of Book:";cin.getline(author_buy,20);
				
				for(t=0;t<i;t++)	{
					if(Book[t]->search(title_buy,author_buy))	{
						cout<<endl<<"Book Found Successfully";
						Book[t]->show_data();
						break;
					}
				}
				if(t==i)
				cout<<endl<<"This Book is Not in Stock";
				break;
			
			case 4:cin.ignore();
				cout<<endl<<"Enter Title Of Book:";cin.getline(title_buy,20);
				cout<<endl<<"Enter Author Of Book:";cin.getline(author_buy,20);
				
				for(t=0;t<i;t++)	{
					if(Book[t]->search(title_buy,author_buy))	{
						cout<<endl<<"Book Found Successfully";
						Book[t]->edit_data();
						break;
					}
				}
				if(t==i)
				cout<<endl<<"This Book is Not in Stock";
				break;
			
			case 5: exit(0);
			default: cout<<endl<<"Invalid Choice Entered";
			
		}
	}
	
	return 0;
}