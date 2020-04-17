//Created by Frank M. Carrano and Timothy M. Henry.
//Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/*
 Link-list driver program to test methods in the link-list.cpp.
 User input a list of integers as a line of string. In the for loop,
 del is position of the whitespace as a delimiter to separate each
 interger, where i indicates every character in the string to find
 del. Start is position where an integer starts, which is after a
 whitespace (del+1). Then, repeat the while loop to ask user to
 input another list and make some modifications.
 
 @Modified by: Bixia Deng
 @version: 12/ 04 / 18
 @assignment: Lab 3
 @Editor: Xcode
 @instructor: Samuel Johnson
 
 */

#include <iostream>
#include <string>
#include "LinkedList.h" // ADT list operations
using namespace std;


void displayList(ListInterface<string>* listPtr)
{
    //cout << "The list contains " << endl;
    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        try
        {
            cout << listPtr->getEntry(pos) << " ";
        }
        catch(PrecondViolatedExcep except)
        {
            cout << "Exception thrown getting entry inserted at position " << pos << endl;
            cout << except.what() << std::endl;
        }
    }
}

int main()
{
    ListInterface<string>* listPtr = new LinkedList<string>();
    string str;

    string input = "y";
    while(input == "y")
    {
        cout << "Enter a list of integers: ";
        getline(cin, str);

        int itemCount = 0;
        
        for(int i = 0, del = 0, start = 0; i <= str.length(); i++) {
            if( str.substr(i, 1) == " " || i == str.length() )
            {
                del = i;
                int num = stoi(str.substr(start, del-start)); //makes sure it's an integer
                string input = to_string(num);
                start = del + 1;
                listPtr->insert(itemCount+1, input);
                itemCount++;
            }
        }

        string target, replaceVal;
        cout << "Enter a value to be modified: ";
        cin >> target;
        cout << "Enter replacement value: ";
        cin >> replaceVal;

        int occurrence = listPtr->replaceItem(target, replaceVal);

        cout << "Modified list: ";
        displayList(listPtr);
        cout << "\nNumber of items replaced: " << occurrence << endl;

        listPtr->clear();
        displayList(listPtr);
        str = "";

        cout << "Would you like to modify another list (y/n)? ";
        cin >> input;

        cout << endl;

        cin.clear();
        cin.ignore();
    }
}




//Version of taking it as integers


//void displayList(ListInterface<int>* listPtr)
//{
//    //cout << "The list contains " << endl;
//    for (int pos = 1; pos <= listPtr->getLength(); pos++)
//    {
//        try
//        {
//            cout << listPtr->getEntry(pos) << " ";
//        }
//        catch(PrecondViolatedExcep except)
//        {
//            cout << "Exception thrown getting entry inserted at position " << pos << endl;
//            cout << except.what() << std::endl;
//        }
//    }
//}
//
//int main()
//{
//    ListInterface<int>* listPtr = new LinkedList<int>();
//    string str;
//
//    string input = "y";
//    while(input == "y")
//    {
//        cout << "Enter a list of integers: ";
//        getline(cin, str);
//
//        int itemCount = 0;
//
//        for(int i = 0, del = 0, start = 0; i <= str.length(); i++) {
//            if( str.substr(i, 1) == " " || i == str.length() )
//            {
//                del = i;
//                int num = stoi(str.substr(start, del-start)); //makes sure it's an integer
//                start = del + 1;
//                listPtr->insert(itemCount+1, num);
//                itemCount++;
//            }
//        }
//
//        int target, replaceVal;
//        cout << "Enter a value to be modified: ";
//        cin >> target;
//        cout << "Enter replacement value: ";
//        cin >> replaceVal;
//
//        int occurrence = listPtr->replaceItem(target, replaceVal);
//
//        cout << "Modified list: ";
//        displayList(listPtr);
//        cout << "\nNumber of items replaced: " << occurrence << endl;
//
//        listPtr->clear();
//        displayList(listPtr);
//        str = "";
//
//        cout << "Would you like to modify another list (y/n)? ";
//        cin >> input;
//
//        cout << endl;
//
//        cin.clear();
//        cin.ignore();
//    }
//
//}
