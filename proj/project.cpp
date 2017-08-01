#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct log{
	int cord;
	double amnt;
};
class acc{
	char name[50];
	log l[5];
	int lno;
	long acno;
	char address[150];
	char pan[20];
	char pno[50];
	char mstatus[60];
	char fname[150];
	char type[70];
	double balance;
	public:
		acc(){
			lno=0;}
		void input(){
			cout<<"\n\n\t\tEnter A/C no : ";
			cin>>acno;fflush(stdin);
			cout<<"\n\t\tEnter your name : ";
			gets(name);fflush(stdin);
			cout<<"\n\t\tEnter your fathers name : ";
			gets(fname);fflush(stdin);
			cout<<"\n\t\tEnter the type : ";
			cin>>type;fflush(stdin);
			cout<<"\n\t\tEnter the balance : ";
			cin>>balance; fflush(stdin);
			cout<<"\n\t\tEnter your address : ";
			gets(address);fflush(stdin);
			cout<<"\n\t\tEnter PAN no : ";
			cin>>pan;fflush(stdin);
			cout<<"\n\t\tEnter maritual status(Single/Married) : ";
			cin>>mstatus;fflush(stdin);
			cout<<"\n\t\tEnter your Phone no : ";
			cin>>pno;fflush(stdin);
		}
		long retacno(){
			return acno;}
		char* retname(){
			return name;
		}
		double retbal(){
			return balance;
		}
		void takepno(){fflush(stdin);
			cout<<"\nEnter updated Phone no : ";cin>>pno;}
		void takemstatus(){fflush(stdin);
			cout<<"\nEnter updated maritual status : ";cin>>mstatus;}
		void takeadd(){fflush(stdin);
			cout<<"\nEnter updated address : ";
			cin>>address;
		}
		
		void credit(){double amnt;
			cout<<"\nEnter amount to withdraw : ";
			cin>>amnt;
			if(amnt>balance)
			{cout<<"Not Sufficient Funds";
			return;}
			else {
			
			if(lno<4)
			{l[lno].cord=1;
			l[lno].amnt=amnt;
		lno++;
		}
		else if(lno==4){
			for(int i=0;i<4;i++){
				l[i].cord=l[i+1].cord;
				l[i].amnt=l[i+1].amnt;}
				l[lno].cord=1;
				l[lno].amnt=amnt;}
				
		}}
		void debit(){
		double amnt;
		cout<<"\n\n\t\tEnter amount to debit : ";
		cin>>amnt;
		balance+=amnt;
		if(lno<4)
		{l[lno].cord=0;
			l[lno].amnt=amnt;
		lno++;
		}
		else if(lno==4){
			for(int i=0;i<4;i++){
				l[i].cord=l[i+1].cord;
				l[i].amnt=l[i+1].amnt;}
				l[lno].cord=0;
				l[lno].amnt=amnt;}
				
		}
			
			
			
		
		void disp(){cout<<"\n\n\t\tA/C no :  "<<acno;
			cout<<"\n\n\t\tName :  "<<name;
			cout<<"\n\n\t\tFathers name :  "<<fname;
			cout<<"\n\n\t\tType of Account :  "<<type;
			cout<<"\n\n\t\tBalance :  "<<balance; 
			cout<<"\n\n\t\tAddress :  "<<address;
			cout<<"\n\n\t\tPAN no :  "<<pan;
			cout<<"\n\n\t\tMaritual status :  "<<mstatus;
			cout<<"\n\n\t\tPhone no :  "<<pno;
			cout<<"\n\n\n\tlast few transactions were : \n\n ";
			for(int i=0;i<lno;i++){
				if(l[i].cord==1)
				cout<<"\n\t\tCredit of amount : "<<l[i].amnt;
				else
				cout<<"\n\t\tDebit of amount : "<<l[i].amnt;
			}

cout<<endl;	}
};
		
void write()
{acc a;
ofstream fout("FinalDB.bat",ios::binary|ios::out|ios::app);
char ch;
do{system("cls");
a.input();
fout.write((char*)&a,sizeof(acc));
cout<<"\nWant to enter more records(y/n) : ";
cin>>ch;
}while(ch=='y'||ch=='Y');


fout.close();
}
	
void update(long ac,int a)
{acc s;
ofstream fout("temp.bat",ios::binary|ios::out);
ifstream fin("FinalDB.bat",ios::binary|ios::in);
while(fin.read((char*)&s,sizeof(acc)))
{if(ac==s.retacno())
{
switch(a)
{
case 1:{s.takepno();
fout.write((char*)&s,sizeof(acc));
break;}
case 2:{s.takeadd();
fout.write((char*)&s,sizeof(acc));
break;}
case 3:{s.takemstatus();
fout.write((char*)&s,sizeof(acc));
break;}
case 4:{s.credit();
fout.write((char*)&s,sizeof(acc));
break;}
case 5: {s.debit();
fout.write((char*)&s,sizeof(acc));
break;}
} 
}
else
fout.write((char*)&s,sizeof(acc));

}
fout.close();
fin.close();
remove("FinalDB.bat");
rename("temp.bat","FinalDB.bat");
}




void del(long ac)
{acc s;
ofstream fout("temp.bat",ios::binary|ios::out);
ifstream fin("FinalDB.bat",ios::binary|ios::in);
while(fin.read((char*)&s,sizeof(acc)))
{if(ac!=s.retacno())
{fout.write((char*)&s,sizeof(acc));
}
}
fout.close();
fin.close();
remove("FinalDB.bat");
rename("temp.bat","FinalDB.bat");
}

void read(long ac=0)
{system("cls");
acc s;
ifstream fin("FinalDB.bat",ios::binary|ios::in);

if(ac==0){
		cout<<"\n\nA/C no\t\tName\t\tBalance(in Rs)\n----------------------------------------------------\n\n";
while(fin.read((char*)&s,sizeof(acc)))
{

	cout<<endl<<s.retacno()<<"\t\t"<<s.retname()<<"\t\t"<<s.retbal()<<endl;
}
}
else
{while(fin.read((char*)&s,sizeof(acc)))
{if(s.retacno()==ac)
s.disp();
}
 
}
fin.close();
}


int checkacno(long ac)
{acc s;
ifstream fin("FinalDB.bat",ios::binary|ios::in);
while(fin.read((char*)&s,sizeof(acc))){
	if(s.retacno()==ac)
	return 1;
	
}
return 0;
fin.close();
}

int main()
{//wlic(1);
int ch;
long acn;
int sch;
//if(readlic()==0){system("cls");
//	cout<<"\n\n\n\n\n\nTHIS SYSTEM IS BLOCKED FOR SECURITY REASONS CONTACT THE SUPPORT TEAM FOR HELP";
//_sleep(5000);
//exit(0);}
//login();



ab:
	system("cls");
	cout<<"\n\t\t1.Create new account\n\t\t2.Modify Existing Record\n\t\t3.Perform Credit\n\t\t4.Perform Debit\n\t\t5.Display basic details of all A/C holders\n\t\t6.Complete Details of a Customer\n\t\t7.Delete Existing A/C\n\t\t8.EXIT\n\n\t\tENTER YOUR CHOICE : ";
	cin>>ch;system("cls");
	switch(ch){
		case 1:
			{write();getch();
			break;}
		case 2:{cout<<"\n\n\t\tEnter the A/C no : ";
		cin>>acn;
		if(checkacno(acn)){
		
		cout<<"\n\t\t1.Change Phone NO\n\t\t2.Change Address\n\t\t3.Change Maritual Status\n\nEnter your choice : ";
		cin>>sch; 
		update(acn,sch);
		getch();break;}
		else {cout<<"\n\n\t\tInvalid A/C no ";getch();break;}}
		case 3:
			{cout<<"\n\n\t\tEnter the A/C no : ";
		cin>>acn;
		if(checkacno(acn)){
		 
		update(acn,4);getch();
		break;}
		else {cout<<"\n\n\t\tInvalid A/C no ";getch();break;}}
		case 4:{cout<<"\n\n\t\tEnter the A/C no : ";
		cin>>acn;
		if(checkacno(acn)){
		update(acn,5);getch();
		break;}
		else {cout<<"\n\n\t\tInvalid A/C no ";getch();break;}}
		case 5:{
		read();getch();	break;}
		case 6:{cout<<"\n\n\t\tEnter the A/C no : ";
		cin>>acn;
		if(checkacno(acn)){
		read(acn);getch();
		break;}
		else {cout<<"\n\n\t\tInvalid A/C no ";getch();break;}}
		case 7:{cout<<"\n\n\t\tEnter the A/C no : ";
		cin>>acn;
		if(checkacno(acn)){
		del(acn);getch();
		break;}
		else {cout<<"\n\n\t\tInvalid A/C no ";getch();break;}}	
		case 8:{
			exit(0);
		}
	}
	goto ab;
	return 0;
}
