# Hostel-Management-System-In-C-
This is a hostel management system using the language of C++.
The code you've shared is a Hostel Management System project written in C++. The project is designed to manage the information of people residing in a hostel. It allows the user to perform various operations such as adding a new person, deleting an existing person, searching for a person, displaying all persons, finding free rooms, and displaying the total number of persons currently in the hostel.

Here's a detailed breakdown of the different components and functionality in the code:

1. Struct Definition: person
The person structure is used to hold information about each person residing in the hostel. It includes the following fields:

name: The name of the person.

cnic: The CNIC (National Identity Card Number) of the person.

roomnum: The room number assigned to the person.

fee: The fee status (can be used to store if the person has paid or not).

messfee: The mess fee status.

checkin_date: The date the person checked in.

checkout_date: The date the person plans to check out.

2. Main Menu Function: displaymenu()
This function displays a menu of options for the user and prompts them to choose an option. It returns an integer corresponding to the choice made by the user. Options:

Add a new person.

Delete an existing person.

Search for a person by their name and CNIC.

Show all the persons.

Show which rooms are free.

Display the total number of persons in the hostel.

Exit the program.

3. Functionality for Each Operation
Add a New Person: addperson(person p[], int rooms[])
This function is responsible for adding a new person to the system.

It first displays a list of free rooms (rooms with value 0).

The user selects a free room for the new person.

The details for the new person (name, CNIC, fee status, check-in date, check-out date, and mess fee) are collected.

The person’s information is stored in the p array (which holds all persons) and a file called data.txt for persistent storage.

The corresponding room is marked as occupied (by changing the value in the rooms[] array to 1).

Delete a Person: deleteperson(person p[], int rooms[])
This function allows the user to delete a person from the system.

It prompts the user for the name and CNIC of the person to be deleted.

The system searches for the person, and if found, it clears their information from the p array.

The room they occupied is marked as free (setting the corresponding room in rooms[] to 0).

The system then updates the data.txt file to reflect the change.

Search for a Person: searchperson(person p[])
This function allows the user to search for a person by their name and CNIC.

If the person is found, their details (name, CNIC, room number, fee status, check-in date, mess fee) are displayed.

Show All Persons: showall(person p[])
This function iterates through all the persons stored in the p[] array and displays the details of each person whose name is not empty.

Free Rooms: freeroom(int rooms[])
This function displays the room numbers that are free (i.e., the rooms in the rooms[] array that are set to 0).

Total Number of Persons: totalperson(person p[])
This function counts how many rooms are currently occupied (i.e., it counts how many non-empty names exist in the p[] array) and displays the total number of persons in the hostel.

Exit: exit()
This function displays a thank you message and ends the program.

4. Data File Handling:
The program uses a text file (data.txt) to persist data between program runs. When a new person is added, their information is appended to this file. Similarly, when a person is deleted, the data in the file is updated.

However, in the delete person function, it seems there's a flaw: the program overwrites the file after deleting a person, but doesn't properly delete the specific person's data from the file. The correct approach would be to read the file, skip the deleted person's data, and write the rest back to the file.

5. Password Protection:
Before allowing access to the system, the program prompts the user to enter a password.

If the password entered matches the pre-set password (safee.1234), the user is allowed access to the hostel management menu.

6. Program Flow and Logic:
The program starts by prompting the user for a password to ensure that only authorized users can access the system.

After the password is validated, the display(p, rooms) function is called, which repeatedly displays the main menu until the user chooses to exit.

The system allows only a limited number of persons (20, as defined by the size of the p[] array) and rooms (20 rooms as represented by the rooms[] array).

Issues and Improvements:
File Handling: The way data is written to and read from the data.txt file could be improved. For example, deleting a person should involve reading the file, removing the specific person's data, and writing the remaining data back to the file.

Room Number Validation: The program allows a person to choose any room, but there is no validation to ensure that the room number selected is within the valid range (1 to 20). This could be improved by adding input validation.

Missing Details in Delete Function: When deleting a person, the code doesn't update the file properly to reflect the changes. It would be better to re-write the file after deletion, omitting the removed person's data.

Search Function: The search function does not break after finding a person, which means it could print "not found" even after a person is located. It should exit the loop once the person is found.

Conclusion:
The Hostel Management System is a simple yet effective program to manage the records of hostel residents. It allows the user to add, delete, search, and display the information of people living in the hostel. The system uses arrays to store the data and a text file for persistent storage. While the core features are functional, there are some areas for improvement, particularly in the file handling and input validation.
