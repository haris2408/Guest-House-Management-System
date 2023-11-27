#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>

using namespace std;

class Customer
{
public:
	char name[50];
	char address[50];
	char phone[12];
	char from_date[9];
	char to_date[9];
	float payment_advance;
	int booking_id;
};

class Room
{
public:
	Customer customerOBJ;
	char type;
	char sizetype;
	char ac;
	int roomNumber;
	int rent;
	int status;

	Room addRoom(int);
	void searchRoom(int);
	void PrintRoom(Room);
};

class GuestHouseMgnt :public Room
{
	ofstream fout;
public:
	GuestHouseMgnt()
		:fout("SummaryReport.txt")
	{
	}
	void getSummaryReport();
	void checkIn();
	void searchCustomer(char*);
	void getAvailRoom();
	void checkOut(int);
};

class Guest_House_Management_System
{
private:
	GuestHouseMgnt obj;
	int i, j, option, R_roomNumber;
	char ch;
	char pname[100];
	void manageRooms();
	
public:
	Guest_House_Management_System(){ }
	void useSystem();
};






