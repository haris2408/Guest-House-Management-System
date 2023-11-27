#include "Guest_House_Management_System.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>


using namespace std;

Room AllroomsArr[200];
int cnt = 0;


Room Room::addRoom(int R_roomNumber)
{
	Room obj;
	obj.roomNumber = R_roomNumber;
	cout << "\nAC/Non-AC (A/N) : ";
	cin >> obj.ac;
	cout << "\nComfort Type(S/N) : ";
	cin >> obj.type;
	cout << "\nSize (B/S) : ";
	cin >> obj.sizetype;
	cout << "\nRent(charged per day) : ";
	cin >> obj.rent;
	obj.status = 0;

	cout << "\n Room Added to the Hotel Successfully!";
	cnt++;
	_getch();
	return obj;
}

void Room::searchRoom(int R_roomNumber)
{
	int i, isFound = 0;
	for (i = 0; i < cnt; i++)
	{
		if (AllroomsArr[i].roomNumber == R_roomNumber)
		{
			isFound = 1;
			break;
		}
	}
	if (isFound == 1)
	{
		cout << "Room Details\n";
		if (AllroomsArr[i].status == 1)
		{
			cout << "\nRoom is Not Available\n";
		}
		else
		{
			cout << "\nRoom is available\n";
		}
		PrintRoom(AllroomsArr[i]);
		_getch();
	}
	else
	{
		cout << "\n(ERROR 404): Room not Found";
		_getch();
	}
}

void Room::PrintRoom(Room obj)
{
	cout << "\nRoom #: \t" << obj.roomNumber 
		<< "\nAC/Non-AC (A/N) " << obj.ac 
		<< "\nComfort Type (S/N) " << obj.type 
		<< "\nSize (B/S) " << obj.sizetype 
		<< "\nRent(Charged per day): " << obj.rent;
}

void GuestHouseMgnt::getSummaryReport() {

	if (cnt == 0) 
	{
		cout << "\n No Guest here yet !!\n";
	}
	for (int i = 0; i < cnt; i++)
	{
		if (AllroomsArr[i].status == 0)
		{
			continue;
		}
		else
		{
			cout << "\n Customer's First Name : " << AllroomsArr[i].customerOBJ.name
				 << "\n Room # : " << AllroomsArr[i].roomNumber
				 << "\n Address (city) : " << AllroomsArr[i].customerOBJ.address
				 << "\n Phone# : " << AllroomsArr[i].customerOBJ.phone
				 << "\n-------------------------------------------------\n";
		}

	}
	_getch();
}

void GuestHouseMgnt::checkIn()
{
	int i, isFound = 0, R_roomNumber;

	cout << "\nPlease Enter Room # : ";
	cin >> R_roomNumber;

	for (i = 0; i < cnt; i++)
	{
		if (AllroomsArr[i].roomNumber != R_roomNumber)
		{
			continue;
		}
		else
		{
			isFound = 1;
			break;
		}
	}
	if (isFound == 1)
	{
		if (AllroomsArr[i].status == 1)
		{
			cout << "\nRoom is already Booked for Another Customer";
			_getch();
			return;
		}
		fout << "\n\n------------------------------------------";
		fout << "\nRoom #: " << AllroomsArr[i].roomNumber;

		cout << "\nEnter Booking ID: ";
		cin >> AllroomsArr[i].customerOBJ.booking_id;
		fout << "\nBooking ID: " << AllroomsArr[i].customerOBJ.booking_id;

		cout << "\nEnter Customer's First Name: ";
		cin >> AllroomsArr[i].customerOBJ.name;
		fout << "\nCustomer's First Name: " << AllroomsArr[i].customerOBJ.name;

		cout << "\nEnter Address (city): ";
		cin >> AllroomsArr[i].customerOBJ.address;
		fout << "\nAddress (city): " << AllroomsArr[i].customerOBJ.address;

		cout << "\nEnter Phone# : ";
		cin >> AllroomsArr[i].customerOBJ.phone;
		fout << "\nPhone# : " << AllroomsArr[i].customerOBJ.phone;

		cout << "\nEnter Check-in Date: ";
		cin >> AllroomsArr[i].customerOBJ.from_date;
		fout<<"\nCheck-in Date: "<< AllroomsArr[i].customerOBJ.from_date;

		cout << "\nEnter Expected Check-Out Date: ";
		cin >> AllroomsArr[i].customerOBJ.to_date;
		fout << "\nCheck-Out  Date: " << AllroomsArr[i].customerOBJ.to_date;;

		cout << "\nEnter Advance Payment that the Customer wishes to pay: ";
		cin >> AllroomsArr[i].customerOBJ.payment_advance;
		fout << "\nAdvance Payment Received: " << AllroomsArr[i].customerOBJ.payment_advance;

		AllroomsArr[i].status = 1;

		cout << "\n Customer Checked-in Successfully!!!!!";

		_getch();
	}
	else
	{
		cout << "Room not found!!!!!";
		_getch();
	}
}

void GuestHouseMgnt::getAvailRoom()
{
	int i;
	bool isFound = false;
	for (i = 0; i < cnt; i++)
	{
		if (AllroomsArr[i].status == 0)
		{
			PrintRoom(AllroomsArr[i]);
			cout << "\n\nPress any key for next room";
			isFound = true;
			_getch();
		}
	}
	if (isFound == false)
	{
		cout << "\nAll rooms are in use";
		_getch();
	}
}

void GuestHouseMgnt::searchCustomer(char* pname)
{
	int i;
	bool isFound = false;
	for (i = 0; i < cnt; i++)
	{
		if (AllroomsArr[i].status == 1 )
		{
			if (_stricmp(AllroomsArr[i].customerOBJ.name, pname) == 0)
			{
				cout << "\nCustomer's First Name: " << AllroomsArr[i].customerOBJ.name;
				cout << "\nRoom #: " << AllroomsArr[i].roomNumber;

				cout << "\n\nPress any key for next record";
				isFound = true;
				_getch();
			}
		}
	}
	if (isFound == false)
	{
		cout << "\nPerson not Found.";
		_getch();
	}
}

void GuestHouseMgnt::checkOut(int roomNum)
{
	int  days, i, R_roomNumber;
	float TotalBill = 0;
	bool isFound = false;
	for (i = 0; i < cnt; i++)
	{
		if (AllroomsArr[i].status == 1 && AllroomsArr[i].roomNumber == roomNum)
		{
			isFound = true;
			break;
		}
	}
	if (isFound == true)
	{
		cout << "\nEnter Number of Stay Days :\t";
		cin >> days;
		TotalBill = days * AllroomsArr[i].rent;

		cout << "\n\t-------- CheckOut Details --------\n";
		cout << "\nCustomer's First Name : " << AllroomsArr[i].customerOBJ.name;
		cout << "\nRoom # : " << AllroomsArr[i].roomNumber;
		cout << "\nPhone # : " << AllroomsArr[i].customerOBJ.phone;
		cout << "\nAddress(City) : " << AllroomsArr[i].customerOBJ.address;
		cout << "\nTotal Bill : " << TotalBill << " /";
		cout << "\nAdvance Paid: " << AllroomsArr[i].customerOBJ.payment_advance << " /";
		cout << "\n_____________Total Payable: " << TotalBill - AllroomsArr[i].customerOBJ.payment_advance << "/ only";

		AllroomsArr[i].status = 0;
	}
	_getch();
}

void Guest_House_Management_System::manageRooms()
{
	Room obj;
	int opt, R_roomNumber, i, checc = 0;
	do
	{
		system("cls");
		cout << "\n___ Manage Rooms ___";
		cout << "\n1. Add Room";
		cout << "\n2. Search Room";
		cout << "\n3. Back to Main Menu";
		cout << "\n\n Option: ";
		cin >> opt;


		switch (opt)
		{
		case 1:
			cout << "\nEnter Room #: ";
			cin >> R_roomNumber;
			for (i = 0; i < cnt; i++)
			{
				if (AllroomsArr[i].roomNumber == R_roomNumber)
				{
					checc = 1;
					break;
				}
			}
			if (checc == 1)
			{
				cout << "\nRoom Number is already Present.\nPlease enter a unique Number";
				checc = 0;
				_getch();
			}
			else
			{
				AllroomsArr[cnt] = obj.addRoom(R_roomNumber);
				cnt++;
			}
			break;
		case 2:
			cout << "\nEnter room #: ";
			cin >> R_roomNumber;
			obj.searchRoom(R_roomNumber);
			break;
		case 3:
			return;
			break;
		default:
			cout << "\nPlease Enter Valid/Available option";
			_getch();
			break;
		}
	} while (true);
}

void Guest_House_Management_System::useSystem()
{
	do
	{
		system("cls");
		cout << "________ Guest House Management ________\n";
		cout << "\n1. Manage Rooms(ADD,SEARCH)";
		cout << "\n2. Check-In ";
		cout << "\n3. Get Available Rooms";
		cout << "\n4. Search Customer";
		cout << "\n5. Check-Out";
		cout << "\n6. Get Guest Summary Report";
		cout << "\n7. Exit";
		cout << "\n\n Option: ";
		cin >> option;
		switch (option)
		{
		case 1:
			this->manageRooms();
			break;
		case 2:
			if (cnt == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				_getch();
			}
			else
				obj.checkIn();
			break;
		case 3:
			if (cnt == 0)
			{
				cout << "\nRooms data is not available.\nPlease add the rooms first.";
				_getch();
			}
			else
				obj.getAvailRoom();
			break;
		case 4:
			if (cnt == 0)
			{
				cout << "\nNO ROOM AVAIABLE.\nPlease add the rooms first.";
				_getch();
			}
			else
			{
				cout << "Enter Customer Name: ";
				cin >> pname;
				obj.searchCustomer(pname);
			}
			break;
		case 5:
			if (cnt == 0)
			{
				cout << "\nRooms are not available.\nPlease add the rooms first.";
				_getch();
			}
			else
			{
				cout << "Enter Room Number : ";
				cin >> R_roomNumber;
				obj.checkOut(R_roomNumber);
			}
			break;
		case 6:
			obj.getSummaryReport();
			break;
		case 7:
			cout << "\nGOOD BYE_!_";
			return;
			break;
		default:
			cout << "\nEnter valid/available option";
			break;
		}
	} while (true);
}
