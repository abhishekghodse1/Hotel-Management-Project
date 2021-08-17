#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
void main_menu();
void intro();
void admin();
void user();
void add_room(); 
void display_all();
void modify_room(); 
void delete_room(); 
void search_room(); 
void passw();
void bill();
void book_disp();
void usearch_room();
void bill_it();
void udisplay_all(); 
void c_entery();
class hotel
{
int room_no;
char room_type[30];
char bed_type[50];
float price;
void calc_price()
{
if(!strcmpi(bed_type,"S"))
price= 1000;
if(!strcmpi(bed_type,"D"))
price= 1800;
if(!strcmpi(room_type,"AC"))
price+= price*0.30;
}
public:
void getdata()
{
cout<<"\n\n\t\t ENTER THE ROOM NUMBER : ";cin>>room_no;
cout<<"\n\n\t\t ENTER THE ROOM TYPE (AC,NAC) : "; gets(room_type);
cout<<"\n\n\t\t ENTER THE BED TYPE (S,D) : ";gets(bed_type);
calc_price();
}
void putdata()
{
cout<<"\n"<<room_no<<"\t\t"<<room_type<<"\t\t\t"<<bed_type<<"\t\t\t"<<price;
}
void putdata1()
{
cout<<"\n\t ROOM NUMBER : "<<room_no;
cout<<"\n\t ROOM TYPE : "<<room_type;
cout<<"\n\t BED TYPE : "<<bed_type;
}
int ret_rno()
{ return room_no;}
int ret_price()
{ return price; }
}H;
void intro()
{
clrscr();
cout<<"\n\t\t*******************************************";
cout<<"\n\t\t* WELCOME TO THE GREAT HOTEL TRANSELVANIA *";
cout<<"\n\t\t*******************************************";
cout<<"\n\n\n FULLY FURNISHED ROOMS , FANTABULOUS SERVICE , AND MUCH MORE";
cout<<"\n\n\t\t FIVE STAR HOTELL *****";
cout<<"\n\n\n\n\n\t\t\t\tPress any key to continue!!";
getch();
main_menu();
}
void main_menu()
{
int choice;
A: clrscr();
cout<<"\n\t\t\t\t*************"
<<"\n\t\t\t\t* MAIN MENU *"
<<"\n\t\t\t\t*************"
<<"\n\n\n\t\t\t PRESS 1 FOR ADMIN LOGIN"
<<"\n\t\t\t PRESS 2 FOR USER LOGIN"
<<"\n\t\t\t PRESS 0 TO EXIT FROM PROGRAMME"
<<"\n\n\t\t\ Enter Your Choice: ";
cin>>choice;
switch(choice)
{
case 1: passw();break;
case 2: user(); break;
case 0: exit(0);break;
default:cout<<"\nYOU HAVE ENTERED WRONG CHOICE "
<<"\n\n PRESS ANY KEY TO GO BACK TO THE MAIN MENU.... ";
getch(); goto A;
}
}
void passw()
{
char pwd[3],def[]="777";
int i=0,mycheck;
clrscr();
cout<<"\n\n\t\t\t*******************";
cout<<"\n\t\t\t* PASSWORD ENTRY *";
cout<<"\n\t\t\t*******************";
start1 : cout<<"\n\n\n\nENTER PASSWORD FOR ADMIN MENU : ";
while(i<3)
{
pwd[i]=getch();
cout<<"*";
++i;
}
cout<<endl;
mycheck=strcmp(pwd,def);
if (mycheck!=1)
{
getch();
admin();
}
else
{
cout<<"\n\n\n\t\tACCESS DENINED!!!\n\n\t\tRETRY WITH VALID PASSWORD...";
getch();clrscr();
passw();
}
getch();
}
void admin()
{
int ch1;
A: clrscr();
cout <<"\n\t\t\t****************************"
<<"\n\t\t\t* WELCOME TO THE USER MENU *"
<<"\n\t\t\t****************************"
<<"\n\n\t\t PRESS 1 FOR ADDING ROOM DETAILS"
<<"\n\n\t\t PRESS 2 TO DISPLAY ALL ROOM DETAILS"
<<"\n\n\t\t PRESS 3 TO SEARCH FOR A PERTICULAR ROOM RECORD"
<<"\n\n\t\t PRESS 4 TO DELETE A PERTICULAR ROOM RECORD "
<<"\n\n\t\t PRESS 5 TO MODIFY DETAILS OF A PERTICULAR ROOM RECORD"
<<"\n\n\t\t PRESS 0 TO GO BACK TO MAIN MENU"
<<"\n\n\t\t ENTER CHOICE : ";
cin>>ch1;
switch(ch1)
{
case 1 : add_room();break;
case 2 : display_all();break;
case 3 : search_room();break;
case 4 : delete_room();break;
case 5 : modify_room();break;
case 0 : main_menu();break;
default : cout<<"\n\t\t\ WRONG CHOICE !!!! "
<<" \n PRESS ANY KEY TO GO BACK TO THE MAIN MENU....";
getch(); goto A;
}
}
void user()
{
int ch2;
B:
clrscr();
cout<<"\n\t\t\t\t***********************"
<<"\n\t\t\t\t* WELCOME TO USER MENU*"
<<"\n\t\t\t\t***********************"
<<"\n\n\t\t PRESS 1 TO DISPLAY ROOM DETAILS "
<<"\n\n\t\t PRESS 2 FOR BOOKING A ROOM "
<<"\n\n\t\t PRESS 0 RETURN TO MAIN MENU ";
cout<<"\n\n\t\t ENTER YOUR CHOICE : ";cin>>ch2;
switch(ch2)
{
case 1: udisplay_all(); break;
case 2: bill(); break;
case 0: main_menu();
default: cout<<"\n\t\tWRONG CHOICE !!!";
break;
}
goto B;
}
void add_room() 
{
A:
clrscr();
fstream f; char ch='y';
f.open("HOTEL.DAT",ios::out|ios::app|ios::binary);
if(!f)
{ cout<<"File does not exists"; exit(0); }
else
{ while(ch=='y' || ch=='Y')
{ H.getdata();
f.write((char*)&H,sizeof(H));
cout<<"\n\t\tDO YOU WANT TO ENTER MORE (y/n) "; cin>>ch;
if(tolower(ch)=='y')
goto A;
else if(tolower(ch)=='n')
{
cout<<"\n\n\t\t PRESS ANY KEY TO GO TO ADMIN MENU ";
admin();
}
else
{
cout<<"\n\n\t\t WRONG CHOICE !!!!!!!";
goto A ;
}
}
}
f.close();
}
void display_all()
{
clrscr();
fstream f;
f.open("HOTEL.DAT",ios::in|ios::app|ios::binary);
cout<<"\n\t\t\t\t *********"
<<"\n\t\t\t\t *RECORDS*"
<<"\n\t\t\t\t *********";
cout<<"\n\nROOM NO.\tROOM TYPE\t\tBED TYPE\t\tPRICE";
while(f.read((char*)&H,sizeof(H)))
{
H.putdata();
}
f.close();
cout<<"\n\n\t\t PRESS ANY KEY TO CONTINUE...."; getch();
admin();
f.close();
}
void udisplay_all()
{
clrscr();
ifstream f1;
f1.open("HOTEL.DAT",ios::in|ios::binary);
cout<<"\n\t\t\t****************";
cout<<"\n\t\t\t* INFORMATION *";
cout<<"\n\t\t\t****************";
cout<<"\n\nROOM_NO\t\tROOM_TYPE\t\tBED_TYPE\t\tPRICE";
while(f1.read((char*)&H,sizeof(hotel)))
{
H.putdata();
}
cout<<"\n\n\t PRESS ANY KEY TO RETUN TO USER MENU .... ";
getch(); user();
f1.close();
}
void search_room()
{
clrscr();
cout<<"\n\t\t\t************"
<<"\n\t\t\t * SEARCH * "
<<"\n\t\t\t************" ;
int a,flag=0;
cout<<"\n ENTER THE ROOM NUMBER : ";
cin>>a;
ifstream f1;
f1.open("HOTEL.DAT",ios::in|ios::binary);
if(!f1)
{
cout<<"\n\t FILE NOT EXIST";
exit(0);
}
else
{
while(f1.read((char*)&H,sizeof(H)))
{
if(H.ret_rno()==a)
{ H.putdata();flag=1;
cout<<"\n\n\t PRESS ANY KEY TO RETURN TO ADMIN ...";
getch();admin();
break;
}
}
if(!flag)
{ cout<<"\n\t\t ROOM NOT FOUND !!!!"
<<"\n\n\t\t PRESS ANY KEY TO GO BACK TO ADMIN MENU......" ;
getch(); admin();
}
}
f1.close();
}
void modify_room()
{
cout<<"\n\t\t\t************"
<<"\n\t\t\t*MODIFYING*"
<<"\n\t\t\t************";
int pos,flag=0;int r; fstream f1;
f1.open("HOTEL.DAT",ios::in|ios::out|ios::binary);
clrscr();
cout<<"\n\t ENTER THE ROOM NO. " ;
cin>>r;
while(f1.read((char*)&H,sizeof(H)))
{
pos=f1.tellg();
if(H.ret_rno()==r)
{ clrscr();
cout<<"\n Enter New Details";
cout<<"\n *****************";
H.getdata();
f1.seekg(pos);
f1.write((char*)&H,sizeof(H));
cout<<"\n Record is modified!!";
flag=1;
cout<<"\n\n\t PRESS ANY KEY TO RETURN TO ADMIN MENU ..... ";
getch(); admin();
break;
}
}
if(flag==0)
{ clrscr();
cout<<"\n Sorry Room no. not found or vacant!!";
cout<<"\n\n\t PRESS ANY KRY TO RETURN TO ADMIN ";
getch(); admin();
}
else
{
cout<<"\n\n\t PRESS ANY KEY TO RETURN TO ADMIN MENU ..... ";
getch(); admin();
}
f1.close();
}
void delete_room()
{
clrscr();
int no;
cout<<"\n\n\t\t ENTER THE ROOM NO TO BE DELETED ";
cin>>no;
fstream f,f1;
f.open("HOTEL.DAT",ios::in|ios::binary);
f1.open("temp.dat",ios::out|ios::binary);
while(f.read((char*)&H,sizeof(H)))
{
if (H.ret_rno()!=no)
f1.write((char*)&H,sizeof(H));
}
cout<<"\n\t\t ROOM DELETED.....\n\n\t\t";
remove("HOTEL.DAT");
rename("temp.dat","HOTEL.DAT");
cout<<"\n PRESS ANY KEY TO CONTINUE...."; getch();
f.close();f1.close();
admin();
}
class customer
{
int cid;
char c_name[20];
char c_address[40];
int c_pn;
int days;
public:
void c_getdata()
{ clrscr();
cout<<"\n\t ENTER CUSTOMER ID : ";cin>>cid;
cout<<"\n\t ENTER CUSTOMER NAME : ";gets(c_name);
cout<<"\n\t ENTER CUSTOMER ADDRESS : ";gets(c_address);
cout<<"\n\t ENTER CUSTOMER PHONE NO. : ";cin>>c_pn;
cout<<"\n\t ENTER THE NO. OF DAYS : ";cin>>days;
}
void c_putdata()
{
cout<<"\n"<<cid<<"\t\t"<<c_name<<"\t\t"<<c_address<<"\t\t"<<c_pn<<"\t"<<days;
}
void c_putdata1()
{
cout<<"\n\t CUSTOMER ADDRESS : "<<c_address;
cout<<"\n\t CUSTOMER PHONE NO. : "<<c_pn;
cout<<"\n\t NO. OF DAYS : "<<days;
}
int ret_days()
{
return days;
}
}C;
void cust_disp()
{
clrscr();
ifstream f;
f.open("cust.dat",ios::in|ios::binary);
cout<<"\n\t\t\t****************";
cout<<"\n\t\t\t* INFORMATION *";
cout<<"\n\t\t\t****************";
cout<<"\n\nCID\tCUSTOMER NAME\tCUSTOMER ADDRESS\tCUSTOMER NO.\tNO.OF DAYS";
while(f.read((char*)&C,sizeof(C)))
{
C.c_putdata();
}
cout<<"\n\n\t PRESS ANY KEY TO RETUN TO USER MENU .... ";
getch(); user();
f.close();
}
void bill()
{
usearch_room();
}
void usearch_room()
{
clrscr();
int a,flag=0;
cout<<"\n ENTER THE ROOM NUMBER : ";
cin>>a;
fstream f;
f.open("HOTEL.DAT",ios::in|ios::binary);
if(!f)
{
cout<<"\n\t FILE NOT EXIST";
exit(0);
}
else
{
while(f.read((char*)&H,sizeof(H)))
{
if(H.ret_rno()==a)
{ H.putdata();flag=1;
break;
}
}
if(!flag)
{ cout<<"\n\t\t ROOM NOT FOUND !!!!"
<<"\n\n\t\t PRESS ANY KEY TO GO BACK TO USER MENU......" ;
getch(); user();
}
else
{
char ch;
cout<<"\n\n\t DO YOU WANT TO BOOK THE ROOM (Y/N) ? ";
cin>>ch;
cout<<"\n\t\t ROOM IS BOOKED !!!!! "
<<"\n\n\t\t PRESS ANY KEY TO COUSTOMER ENTERY ";
getch();
if(toupper(ch)!='Y')
{
cout<<"\n\t THANKS FO VISITING "
<<"\n\t PRESS ANY KEY TO GO BACK TO USER MENU ......";
getch();user();
}
else
{
fstream fout;
fout.open("CUST.DAT",ios::out|ios::app|ios::binary);
C.c_getdata();
fout.write((char*)&C,sizeof(C));
cout<<"\n\n FOR BILL DISPLAYING PRESS ANY KEY !!!!!!"; getch();
bill_it();
fout.close();
}
}
}
f.close();
}
void bill_it()
{
clrscr();
cout<<"\n\t\t\t******"
<<"\n\t\t\t*BILL*"
<<"\n\t\t\t******";
C.c_putdata1();
H.putdata1();
float a=C.ret_days()*H.ret_price();
cout<<"\n\t TOTAL AMOUNT :"<<a;getch();
cout<<"********************** THANKS FOR VISITING**********************";
}
void main()
{ intro(); }
