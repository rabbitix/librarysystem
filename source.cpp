//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************
#include <iostream> 
#include <string>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include <windows.h>
#include <ctime>
using namespace std;
//****************************************************************


//***************************************************************
//    	             SETCOLOR FUNCTION
//****************************************************************
void setColor(char c) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch (c) {
	case 'b':
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
		break;
	case 'g':
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
		break;
	case 'r':
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		break;
	case 'y':
		system("color e");
		break;
	default:
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
		break;
	}
}

//***************************************************************
//                   CLASS USED IN PROJECT[book class]
//****************************************************************
class book
{
private:
	string  book_number = "\0";			//book number 
	string  book_name = "\0";			//book name 
	string  author_name = "\0";			//book author 
	string  publisher = "\0";			//publisher

	int puy = 0;						//=============
	int pum = 0;						//publish date
	int pud = 0;						//=============

public:

	void create_book()
	{
		setColor('g');
		cout << "\nNEW BOOK ENTRY...\n";
		Sleep(800);
		setColor('y');
		cout << "\nEnter The Book Number: ";
		getline(cin, book_number);
		getline(cin, book_number);
		cout << "\n\nEnter The Name of The Book: ";
		getline(cin, book_name);
		cout << "\n\nEnter The Author's Name: ";
		getline(cin, author_name);
		cout << "\n\nEnter The Publisher Name: ";
		getline(cin, publisher);
		cout << "\n\nEnter The Publishing Date (format : yy mm dd ) :";
		cin >> puy >> pum >> pud;
		setColor('r');
		cout << "\n\n\nBook Created successfully ";
		setColor('g');
	}

	void show_book()
	{
		setColor('g');
		cout << "\nBook Number : " << book_number;
		cout << "\nBook Name : ";
		cout << book_name;
		cout << "\nAuthor Name : ";
		cout << author_name;
		cout << "\nPublisher Name: ";
		cout << publisher;
		cout << "\nPublishing Date : ";
		cout << puy << "/" << pum << "/" << pud;
	}

	void modify_book()
	{
		setColor('g');
		cout << "\nBook Number. : " << book_number;
		cout << "\nModify Book Name : ";
		getline(cin, book_name);
		cout << "\nModify Author's Name of Book : ";
		getline(cin, author_name);
		cout << "\nModify Publisher Name : ";
		getline(cin, publisher);
		cout << "\nModify Publishing Date (yy mm dd): ";
		cin >> puy >> pum >> pud;
		setColor('r');
		cout << "\nModifing Complete! ";
		setColor('g');
	}

	string retbno()
	{
		return book_number;
	}

	void report()
	{
		cout << "\t" << book_number << setw(20) << book_name << setw(20) << author_name << setw(22) << publisher << setw(27) << puy << "/" << pum << "/" << pud << endl;
	}


};
// end of book class


class student
{
	string admnum;//admission number OR membership number 
	string name;//student name
	string fname;//family name
	string stbno;//student book number 
	long long int cellphonenum = 0;
	int by, bm, bd;//birthday date
	int token;
public:
	void create_student()
	{
		system("cls");
		setColor('r');
		cout << "\nNEW STUDENT ENTRY...\n";
		Sleep(750);
		setColor('y');
		cout << "\nEnter The Admission Number : ";
		getline(cin, admnum);
		getline(cin, admnum);
		cout << "\n\nEnter The Name of The Student : ";
		getline(cin, name);
		cout << "\n\nEnter The Family Name of The Student : ";
		getline(cin, fname);
		cout << "\nEnter student's cell phone number : ";
		cin >> cellphonenum;
		cout << "\nEnter student birthday date (format: yy mm dd) : ";
		cin >> by >> bm >> bd;
		token = 0;
		stbno = '/0';                            
		setColor('r');
		cout << "\n\nStudent Record Created..";
	}

	void show_student()
	{
		setColor('y');
		cout << "\nAdmission number : " << admnum;
		cout << "\nStudent Name : ";
		cout << name;
		cout << "\nStudent Family name : ";
		cout << fname;
		cout << "\nStudent Cellphone Number : ";
		cout << cellphonenum;
		cout << "\nStudent Birthday Date : ";
		cout << by << "/" << bm << "/" << bd << endl;
		cout << "\nNumber of Book Issued : " << token;
		if (token == 1)
			cout << "\nBook Number " << stbno;
	}

	void modify_student()
	{
		setColor('b');
		cout << "\nAdmission Number : " << admnum;
		cout << "\nModify Student Name : ";
		getline(cin, name);
		getline(cin, name);
		cout << "\nModify Student Family Name : ";
		getline(cin, fname);
		cout << "\nEnter Student's Cell phone Number :";
		cin >> cellphonenum;
		cout << "\nEnter Student Birthday Date (format: yy mm dd): ";
		cin >> by >> bm >> bd;
		setColor('r');
		cout << "\nModify Completed";
		setColor('g');
	}

	string retadmno()
	{
		return admnum;
	}

	string retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{
		token = 1;
	}

	void resettoken()
	{
		token = 0;
	}

	void getstbno(string t)
	{
		stbno = t;
	}

	void report()
	{
		cout << "\t " << admnum << setw(16) << name << setw(19) << fname << setw(14) << "+98" << cellphonenum << setw(18) << by << "/" << bm << "/" << bd << setw(18) << token << endl;
	}


};
//End of student class 
//***************************************************************
//              	file declaration and objects 
//****************************************************************

fstream fp1, fp2;//files 
book bk;//book object 
student st;//student object 


		   //***************************************************************
		   //             	function to write in file
		   //****************************************************************

void write_book()
{
	char ch;
	fp2.open("book.dat", ios::out | ios::app);
	do
	{
		system("cls");
		bk.create_book();
		fp2.write((char*)&bk, sizeof(book));
		cout << "\n\nDo you want to add more record?[y/n] ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	fp2.close();
}

void write_student()
{
	char ch;
	fp2.open("student.dat", ios::out | ios::app);
	do
	{
		st.create_student();
		fp2.write((char*)&st, sizeof(student));
		cout << "\n\ndo you want to add more record?[y/n] ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	fp2.close();
}


//***************************************************************
//    	function to read specific record from file
//****************************************************************


void display_spb(string n)
{
	setColor('r');
	cout << "\nBOOK DETAILS\n";
	Sleep(800);
	setColor('y');
	int flag = 0;
	fp2.open("book.dat", ios::in);
	while (fp2.read((char*)&bk, sizeof(book)))
	{
		if (bk.retbno() == n)
		{
			bk.show_book();
			flag = 1;
		}
	}

	fp2.close();
	if (flag == 0)
		cout << "\n\nBook does not exist";
	cout << endl << endl;
	system("pause");
}

void display_sps(string n)
{
	setColor('r');
	cout << "\nSTUDENT DETAILS\n";
	Sleep(600);
	int flag = 0;
	fp2.open("student.dat", ios::in);
	while (fp2.read((char*)&st, sizeof(student)))
	{
		if (st.retadmno() == n)
		{
			setColor('y');
			st.show_student();
			flag = 1;
		}
	}

	fp2.close();
	if (flag == 0)
		cout << "\n\nStudent does not exist";
	cout << endl << endl;
	system("pause");
	setColor('g');
}


//***************************************************************
//    	function to modify record of file
//****************************************************************


void modify_book()
{
	string n;
	int found = 0;
	system("cls");
	setColor('r');
	cout << "\n\n\tMODIFY BOOK REOCORD.... ";
	setColor('g');
	cout << "\n\n\tEnter The number of The book";
	cin >> n;
	fp2.open("book.dat", ios::in | ios::out);
	while (fp2.read((char*)&bk, sizeof(book)) && found == 0)
	{
		if (bk.retbno() == n)
		{
			bk.show_book();
			setColor('b');
			cout << "\nEnter The New Details of book" << endl;
			setColor('g');
			bk.modify_book();
			int pos = sizeof(bk);
			fp2.seekp(pos, ios::cur);
			fp2.write((char*)&bk, sizeof(book));
			setColor('r');
			cout << "\n\n\t Record Updated";
			found = 1;
		}
		setColor('g');
	}

	fp2.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	cout << endl << endl;
	system("pause");
}


void modify_student()
{
	string n;
	int found = 0;
	system("cls");
	setColor('y');
	cout << "\n\n\tMODIFY STUDENT RECORD... ";
	setColor('g');
	cout << "\n\n\tEnter The admission number of The student";
	cin >> n;
	fp2.open("student.dat", ios::in | ios::out);
	while (fp2.read((char*)&st, sizeof(student)) && found == 0)
	{
		if (st.retadmno() == n)
		{
			st.show_student();
			cout << "\nEnter The New Details of student" << endl;
			st.modify_student();
			int pos = sizeof(st);
			fp2.seekp(pos, ios::cur);
			fp2.write((char*)&st, sizeof(student));
			cout << "\n\n\t Record Updated";
			found = 1;
		}
	}

	fp2.close();
	if (found == 0)
		cout << "\n\n Record Not Found ";
	cout << endl << endl;
	system("pause");
}
//***************************************************************
//                  GOTOXY FUNCTION
//****************************************************************
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;

	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}
//***************************************************************
//       delete function  for delete record of file
//****************************************************************


void delete_student()
{
	string n;
	int flag = 0;
	system("cls");
	system("color 3");
	cout << "\n\n\n\tDELETE STUDENT...";
	cout << "\n\nEnter The admission number of the Student You Want To Delete : ";
	cin >> n;
	fp2.open("student.dat", ios::in | ios::out);
	fstream fp2;
	fp2.open("Temp.dat", ios::out);
	fp2.seekg(0, ios::beg);
	while (fp2.read((char*)&st, sizeof(student)))
	{
		if (st.retadmno() != n)
			fp2.write((char*)&st, sizeof(student));
		else
			flag = 1;
	}

	fp2.close();
	fp2.close();
	remove("student.dat");//delete old file
	rename("Temp.dat", "student.dat");
	setColor('r');
	if (flag == 1)
		cout << "\n\n\tRecord Deleted ..";
	else
		cout << "\n\nRecord not found";
	cout << endl << endl;
	system("pause");
}


void delete_book()
{
	string n;
	system("cls");
	setColor('r');
	cout << "\n\n\n\tDELETE BOOK ...";
	setColor('y');
	cout << "\n\nEnter The Book no. of the Book You Want To Delete : ";
	cin >> n;
	fp2.open("book.dat", ios::in | ios::out);
	fstream fp2;
	fp2.open("Temp.dat", ios::out);
	fp2.seekg(0, ios::beg);
	while (fp2.read((char*)&bk, sizeof(book)))
	{
		if (bk.retbno() != n)
		{
			fp2.write((char*)&bk, sizeof(book));
		}
	}

	fp2.close();
	fp2.close();
	remove("book.dat");
	rename("Temp.dat", "book.dat");
	cout << "\n\n\tRecord Deleted ..";
	cout << "\n\n";
	setColor('g');
	system("pause");
}
//***************************************************************
//    	function to display all students list
//****************************************************************

void display_alls()//display all students 
{
	system("cls");
	fp2.open("student.dat", ios::in);
	if (!fp2)
	{
		cout << "ERROR!!! FILE COULD NOT BE OPEN ";
		cout << "\n\n";
		system("pause");
		return;
	}

	cout << "\n\n\tSTUDENT LIST\n\n";
	cout << "========================================================================================================================\n";
	cout << "  Admission Number" << setw(9) << "Name" << "       Family name" << setw(25) << "Cellphone Number " << setw(23) << "Birthday Date" << setw(22) << "Book Issued\n";
	cout << "========================================================================================================================\n";

	while (fp2.read((char*)&st, sizeof(student)))
	{
		st.report();
	}

	fp2.close();
	cout << "\n\n";
	system("pause");
}


//***************************************************************
//    	function to display Books list
//****************************************************************

void display_allb()//display all books
{
	system("cls");
	fp2.open("book.dat", ios::in);
	if (!fp2)
	{
		setColor('r');
		cout << "ERROR!!! FILE COULD NOT BE OPEN ";
		cout << "\n\n"; system("pause");
		return;
	}

	setColor('g');
	cout << "\n\n\t\tBook LIST\n\n";
	cout << "========================================================================================================================\n";
	cout << "Book Number" << setw(20) << "Book Name" << setw(20) << "Author" << setw(25) << "Publisher Name" << setw(30) << "Publishing Date\n";
	cout << "========================================================================================================================\n";

	while (fp2.read((char*)&bk, sizeof(book)))
	{
		bk.report();
	}
	fp2.close();
	cout << "\n\n";
	system("pause");
}



//***************************************************************
//    	function to issue book
//****************************************************************

void book_issue()
{
	string sn, bn;
	int found = 0, flag = 0;

	system("cls");
	setColor('r');
	cout << "\n\nBOOK ISSUE ...";
	Sleep(400);
	setColor('y');
	cout << "\n\n\tEnter The Student's Admission Number: ";
	cin >> sn;
	fp2.open("student.dat", ios::in | ios::out);
	fp1.open("book.dat", ios::in | ios::out);
	while (fp2.read((char*)&st, sizeof(student)) && found == 0)
	{
		if (st.retadmno() == sn)
		{
			found = 1;
			if (st.rettoken() == 0)
			{
				cout << "\n\n\tEnter the book number: ";
				cin >> bn;
				while (fp1.read((char*)&bk, sizeof(book)) && flag == 0)
				{
					if (bk.retbno() == bn)
					{
						bk.show_book();
						flag = 1;
						st.addtoken();
						st.getstbno(bk.retbno());
						int pos = 1 * sizeof(st);
						fp2.seekp(pos, ios::cur);
						fp2.write((char*)&st, sizeof(student));
						setColor('g');
						cout << "\n\n\t Book issued successfully";
					}
				}
				if (flag == 0)
					cout << "Book no does not exist";
			}
			else
				cout << "You have not returned the last book ";

		}
	}
	if (found == 0)
		cout << "Student record not exist...";
	cout << "\n\n";
	system("pause");
	fp2.close();
	fp1.close();
}

//***************************************************************
//    	function to deposit book
//****************************************************************

void book_deposit()
{
	string sn, bn;
	int found = 0, flag = 0, day, fine;

	system("cls");
	setColor('b');
	cout << "\n\nBOOK DEPOSIT ...";
	setColor('g');
	cout << "\n\n\tEnter The Student's Admission Number";
	cin >> sn;
	fp2.open("student.dat", ios::in | ios::out);
	fp1.open("book.dat", ios::in | ios::out);
	while (fp2.read((char*)&st, sizeof(student)) && found == 0)
	{
		if (st.retadmno() == sn)
		{
			found = 1;
			if (st.rettoken() == 1)
			{
				while (fp1.read((char*)&bk, sizeof(book)) && flag == 0)
				{
					if (bk.retbno() == st.retstbno())
					{
						bk.show_book(); 
						flag = 1;
						cout << "\n\nEnter Book deposited in number of days";//get all the days that user have the book
						int ppp;//Payment Penalty Price
						cin >> day;
						if (day>15)
						{
							cout << "\n\nYou had the book for a long time..!!\n";
							cout << "\nEnter payment penalty price per day: ";
							cin >> ppp;
							fine = (day - 15);
							cout << "\n\nYou should pay " << ppp*fine << " $\n";
							ppp = 0;//we consider that user pay the price  
						}
						st.resettoken();
						int pos = sizeof(st);
						fp2.seekp(pos, ios::cur);
						fp2.write((char*)&st, sizeof(student));
						cout << "\n\n\t Book deposited successfully";
					}
				}
				if (flag == 0)
					cout << "Book no does not exist";
			}
			else
				cout << "No book is issued..please check!!";
		}
	}
	if (found == 0)
		cout << "Student record not exist...";
	cout << "\n\n";
	fp2.close();
	fp1.close();
	system("pause");
}




//***************************************************************
//    	INTRODUCTION FUNCTION
//****************************************************************

void intro()
{

	system("TITLE LIBRARY MANAGEMENT SYSTEM ");
	system("cls");
	gotoxy(35, 11);
	setColor('y');
	cout << "LIBRARY";
	Sleep(100);
	gotoxy(35, 13);
	cout << "MANAGEMENT";
	Sleep(100);
	gotoxy(35, 15);
	setColor('g');
	cout << "SYSTEM";
	Sleep(10);
	setColor('r');
	cout << "\n\nMADE BY :";
	setColor('g');
	cout << " ALI FAZELI";
	setColor('b');
	cout << "\n\nUNIVERSITY : KASHMAR UNIVERSITY";
	setColor('g');
	Sleep(3500);
}



//***************************************************************
//    	ADMINISTRATOR MENU FUNCTION
//****************************************************************

void admin_menu()
{
	system("cls");
	int ch2;
	setColor('y');
	cout << "\n\n\n\tADMINISTRATOR MENU";
	cout << "\n\n\t1.CREATE STUDENT RECORD";
	cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
	cout << "\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
	cout << "\n\n\t4.MODIFY STUDENT RECORD";
	cout << "\n\n\t5.DELETE STUDENT RECORD";
	cout << "\n\n\t6.CREATE BOOK ";
	cout << "\n\n\t7.DISPLAY ALL BOOKS ";
	cout << "\n\n\t8.DISPLAY SPECIFIC BOOK ";
	cout << "\n\n\t9.MODIFY BOOK ";
	cout << "\n\n\t10.DELETE BOOK ";
	cout << "\n\n\t11.BACK TO MAIN MENU";
	setColor('g');
	Sleep(200);
	cout << "\n\n\tPlease Enter Your Choice (1-11) ";
	setColor('g');
	cin >> ch2;
	string num;
	switch (ch2)
	{
	case 1: system("cls");
		write_student(); break;
	case 2: display_alls(); break;
	case 3:

		system("cls");
		cout << "\n\n\tPlease Enter The Admission Number : ";
		getline(cin, num);
		getline(cin, num);
		display_sps(num);
		break;
	case 4: modify_student(); break;
	case 5: delete_student(); break;
	case 6: system("cls");
		write_book(); break;
	case 7: display_allb(); break;
	case 8: {
		num = { NULL };
		system("cls");
		cout << "\n\n\tPlease Enter The book Number:  ";
		getline(cin, num);
		getline(cin, num);
		display_spb(num);
		break;
	}
	case 9: modify_book(); break;
	case 10: delete_book(); break;
	case 11: return;
	default:cout << "\a";
	}
	admin_menu();
}


//***************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************


void main()
{
	char ch;
	intro();
	do
	{
		system("cls");
		setColor('b');
		cout << "\n\n\n\tMAIN MENU";
		setColor('g');
		cout << "\n\n\t01. BOOK ISSUE";
		cout << "\n\n\t02. BOOK DEPOSIT";
		cout << "\n\n\t03. ADMINISTRATOR MENU";
		cout << "\n\n\t04. EXIT";
		setColor('g');
		cout << "\n\n\tPlease Select Your Option (1-4) ";
		ch = _getch();
		switch (ch)
		{
		case '1':system("cls");
			book_issue();
			break;
		case '2':book_deposit();
			break;
		case '3':admin_menu();
			break;
		case '4':
			break;
		default:
			cout << "\a";
		}
	} while (ch != '4');

	system("cls");
	system("color a");
	cout << "      @@@@@@@@@@@@        ##         ##             $$$$$$$$$$$$$$$            \n";
	cout << "      @@        @@         ##       ##              $$                         \n";
	cout << "      @@        @@          ##     ##               $$                         \n";
	cout << "      @@@@@@@@@@@@           ##   ##                $$                         \n";
	cout << "      @@          @@          ## ##                 $$==========               \n";
	cout << "      @@          @@           ###                  $$                         \n";
	cout << "      @@          @@           ###                  $$                         \n";
	cout << "      @@@@@@@@@@@@             ###                  $$$$$$$$$$$$$$$            \n";
	Sleep(2000);
	exit(0);
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
