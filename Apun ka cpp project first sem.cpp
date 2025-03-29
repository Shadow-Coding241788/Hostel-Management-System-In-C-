#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct person {
	string name;
	string cnic;
	int roomnum;
	string fee;
	string messfee;
	string checkin_date;
	string checkout_date;
};
int  displaymenu() {
	int choice;
	

		
		cout << "Enter the number of what you want.\n\n";

		cout << "1. Add a new Person.\n\n";
		cout << "2. Delete a person.\n\n";
		cout << "3. Search a person.\n\n";
		cout << "4. Show all the persons.\n\n";
		cout << "5. Which room is free.\n\n";
		cout << "6. Total number of person.\n\n";
		cout << "7. Exit.\n\n";
		cin >> choice;
	

	return choice;
}

void addperson(person p[], int rooms[])
{
	
	
	int roomnum;
	int i = 0;
	cout << "The rooms which are free are: \n";
	for (int i = 0;i < 20;i++) 
	{
		if (rooms[i] == 0) 
		{
			cout << "Room " << i + 1 << "  ";
		}
		cout << endl;
	}
	cout << "Enter the room number for the person from above given rooms.\n\n";
	cin >> roomnum;
	i=roomnum-1;

	if (rooms[roomnum - 1] == 0)
	{
		rooms[roomnum - 1] = 1;
		cout << "Enter the name of the person.\n" << endl;
		cin >> p[i].name;
		cout << "Enter the CNIC of the person.\n" << endl;
		cin >> p[i].cnic;
		cout << "Enter the room number of the person.\n" << endl;
		cin >> p[i].roomnum;
		cout << "Enter the fee status of the person.\n" << endl;
		cin >> p[i].fee;
		cout << "Enter the check in date of the person.\n" << endl;
		cin >> p[i].checkin_date;
		cout << "Enter the check out date of the person.\n" << endl;
		cin >> p[i].checkout_date;
		cout << "Enter the mess fee of the person.\n" << endl;
		cin >> p[i].messfee;

		ofstream file;
		file.open("data.txt", ios::app);
		
			file << p[i].name << endl;
			file << p[i].cnic << endl;
			file << p[i].roomnum << endl;
			file << p[i].fee << endl;
			file << p[i].checkin_date << endl;
			file << p[i].checkout_date << endl;
			file << p[i].messfee << endl;
		
		cout << "The person has been added successfully.\n\n";
	}
	else
	{
		cout << "The room is already occupied.\n\n";
	}

}

void deleteperson(person p[], int rooms[])
{
	string name, cnic;
	cout << "Enter the name of the person you want to delete.\n\n";
	cin >> name;

	cout << "Enter the CNIC of the person.\n\n";
	cin >> cnic;
	
	for (int i = 0;i < 20;i++)
	{
		if (name ==p[i].name && cnic == p[i].cnic)
		{
			p[i].name = "";
			p[i].cnic = "";
			p[i].roomnum = 0;
			rooms[p[i].roomnum - 1] = 0;

			cout << "The person has been deleted successfully.\n\n";

			ofstream file;
			file.open("data.txt",ios::app);
			for (int i = 0;i < 20;i++)
			{
				file << p[i].name << endl;
				file << p[i].cnic << endl;
				file << p[i].roomnum << endl;
				file << p[i].fee << endl;
				file << p[i].checkin_date << endl;
				file << p[i].messfee << endl;
			}
			file.close();
		}
		else
		{
			cout << "The person is not found.\n\n";
		}
	}
}

void searchperson(person p[])
{
	string name, cnic;
	cout << "Enter the name of the person you want to search.\n\n";
	cin >> name;

	cout << "Enter the CNIC of the person.\n\n";
	cin >> cnic;

	for (int i = 0;i < 20;i++)
	{
		if (name == p[i].name && cnic == p[i].cnic)
		{
			cout << "The person is found.\n\n";
			cout << "Name: " << p[i].name << endl;
			cout << "CNIC: " << p[i].cnic << endl;
			cout << "Room Number: " << p[i].roomnum << endl;
			cout << "Fee Status: " << p[i].fee << endl;
			cout << "Check in date: " << p[i].checkin_date << endl;
			cout << "Mess fee: " << p[i].messfee << endl;

		}
		else
		{
			cout << "The person is not found.\n\n";
		}
	}
}

void showall(person p[])
{
	for (int i = 0;i < 20;i++)
	{
		if (p[i].name != "")
		{
			cout << "Name: " << p[i].name << endl;
			cout << "CNIC: " << p[i].cnic << endl;
			cout << "Room Number: " << p[i].roomnum << endl;
			cout << "Fee Status: " << p[i].fee << endl;
			cout << "Check in date: " << p[i].checkin_date << endl;
			cout << "Mess fee: " << p[i].messfee << endl;
		}
	}
}



void freeroom(int rooms[])
{
	cout << "The rooms which are free are: \n";
	for (int i = 0;i < 20;i++)
	{
		if (rooms[i] == 0)
		{
			cout << "Room " << i + 1 << "  ";
		}
		cout << endl;
	}
}

void totalperson(person p[])
{
	int count = 0;
	for (int i = 0;i < 20;i++)
	{
		if (p[i].name != "")
		{
			count++;
		}
	}
	cout << "The total number of persons are: " << count << endl;
}
void exit()
{
	cout << "Thank you for using the Hostel Management System.\n\n";
}

void dispalydata(person p[])
{
	ifstream file;
	file.open("data.txt");
	for (int i = 0;i < 20;i++)
	{
		file >> p[i].name;
		file >> p[i].cnic;
		file >> p[i].roomnum;
		file >> p[i].fee;
		file >> p[i].checkin_date;
		file >> p[i].messfee;
	}
	file.close();
}






void display(person p[], int rooms[])
{
	int choice;
	do
	{
		choice = displaymenu();
		switch (choice)
		{
		case 1:
			addperson(p, rooms);
			break;
		case 2:
			deleteperson(p, rooms);
			break;
		case 3:
			searchperson(p);
			break;
		case 4:
			showall(p);
			break;
		case 5:
			freeroom(rooms);
			break;
		case 6:
			totalperson(p);
			break;
		case 7:
			exit();
			break;
		default:
			cout << "Invalid choice.\n\n";
		}
	} while (choice != 7);
}


int main()
{
	int rooms[20] = { 0 };
	person p[20];

	string pass = "safee.1234", password;
	cout << "Enter the password. " << endl;
	cin >> password;
	if (password == pass)
	{
		cout << "Welcome to the Hostel Management System ." << endl;

		display(p, rooms);

	}

}