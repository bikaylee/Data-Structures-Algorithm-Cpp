/*
This lab will apply pointers to create a linked list of objects, 
where each object is a node in the linked list. The struct has 
in it data members that are used to represent a moment in time. 
A moment in time has a value for an hour, a value for a minute, 
a value for a second, and an array of characters that contians 
a value for the name of the moment. 

(1) nodes that each have a "link", or pointer to anther node
(2) a separate headPtr pointer that always is meant to point to 
the start of the linked list, and is used to help in managing a 
linked list 


@author: Bixia Deng
@version: 10 / 9 / 18
@assignment: Lab 2
@Editor: Visual Studio 2017
@instructor: Samuel Johnson

*/




#include <iostream>
#include <cstring>
using namespace std;



struct tod {
	int h; // hour, 0 – 23
	int m; // minute, 0-59
	int s; // second 0 – 59
	char d[32]; // moment in time description
	tod* next; // link

	void coutTod()
	{
		// Function to print times and description in the object.
		cout << h << ':';
		if (m < 10)
		{
			std::cout << '0'; cout << m << ':';
		}
		else { 
			std::cout << m << ':';
		}
		if (s < 10)
		{
			cout << '0'; 
			cout << s << endl;
		}
		else { 
			cout << s << endl; 
		}

		cout << d << endl;
	}

	void todSet(int hr, int min, int sec, string day)
	{
		h = hr;
		m = min;
		s = sec;

		//char array conversion from string to c-string
		strcpy(d,day.c_str());
	}
};


int main()
{
	tod noon;
	noon.todSet(12, 0, 0, "noon");
	tod midnight;
	midnight.todSet(0, 0, 0, "midnight");
	tod lunchtime;

	//Three additional objects 
	lunchtime.todSet(1, 0, 0, "lunchtime");
	tod suppertime;
	suppertime.todSet(6, 0, 0, "suppertime");
	tod bedtime;
	bedtime.todSet(11, 0, 0, "bedtime");

	//The start of the list is the midnight object
	tod *headPtr = 0; //empty linked list, 0 to initialize nullptr
	headPtr = &midnight;
	

	//Setting the next member of each struct object to its proper value
	midnight.next = &noon;
	noon.next = &lunchtime;
	lunchtime.next = &suppertime;
	suppertime.next = &bedtime;
	bedtime.next = 0; //set next pointer to null

	for (tod *p = headPtr; p; p = p->next)
	{
		cout << p;
	}

}