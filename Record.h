//
//  Record.h
//  LinkedListRecordProjectFreelancer
//
//  Created by Dilnur Yuldashev on 10/1/16.
//  Copyright © 2016 Dilnur Yuldashev. All rights reserved.

/*
 I looked at the attached starter code, and it does not comply with Object-Oriented Programming rules at
 all. Class Record cannot be a list. Record is an object, and there might be a list of Records.
 Making class Record a list is not the way to go.
 Hence, I created a separate class Record.
 Also, We should not mix the implementations of class Record and Linked List at all because that defeats the
 logic of later usability and expandibility. For instance, we might want to have a list of football players.
 Then, if we have a Linked List class independent of Record or FootballPlayer, we can just create  a List of
 football players using the same List class.
 */


#ifndef Record_h
#define Record_h

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

class Record{
private:
    string _title;   //Record name
    string _address; //Record Address
    string _date;    //Record date
    float _price;    //Record GPA
    
public:
    // Default Constructor
    Record();
    
    // Constructor
    Record(string title, string address, string date, float price);
    
    // Setters
    void setRecordTitle(string);
    void setRecordDate(string);
    void setRecordAddress(string);
    void setRecordPrice(float);
    
    // Getters
    string getRecordTitle();
    string getRecordDate();
    string getRecordAddress();
    float getRecordPrice();
    
    //Records are sorted by their titles
    //overloading the < operator
    //without this function, we cannot sort a list of Records
    //when we are in insert() function
    bool operator < (const Record &other_Record) const{
        if (_title < other_Record._title)
            return true;
        //if two Records have the same titles
        //we look at their prices
        else if (_title == other_Record._title){
            if(_price < other_Record._price)
                return true;
            else{
                return false;
            }
        }
        return false;
    }
    
    //overloading the == operator
    bool operator == (const Record &other_Record) const{
        if (_title == other_Record._title){
            return true;
        }
        else
            return false;
        
    }
    
    //overloading the != operator
    bool operator != (const Record &other_Record) const{
        return !(this == &other_Record);
        
    }
    
    //copying values in other to this Record
    //overloading the = operator
    Record& operator = (const Record& other)
    {
        if (this != &other) { // check if we are not assigning record to itself
            _title = other._title;
            _date = other._date;
            _address = other._address;
            _price = other._price;
        }
        return *this;
    }
};

/*
 * This class is a child of class Record
 */
class Book: Record{
private:
    string _authorFirstName;
    string _authorSurname;
    bool _isPaperback;
    int _numberOfPages;
    bool isFromFile;
public:
    // Default Constructor
    Book();
    Book(bool t);
    // Constructor
    Book(string title, string address, string date, float price, string authorFirstName, string authorLastName, bool paperback, int numberOfPages);

    
    // Setters
    void setBookTitle(string);
    void setBookDate(string);
    void setBookAddress(string);
    void setBookPrice(float);
    
    //Book-only functions Setters
    void setBookAuthorFirstName(string);
    void setBookAuthorSurname(string);
    void setBookPaperback(bool);
    void setBookNumberOfPages(int);
    void setIsFromFileBool(bool);
    // Getters
    string getBookTitle();
    string getBookDate();
    string getBookAddress();
    float getBookPrice();
    
    //Book-only functions Getters
    string getBookAuthorFirstName();
    string getBookAuthorSurname();
    bool getBookPaperback();
    int getBookNumberOfPages();
    bool getIsFromFile();
    
    Book& operator = (const Book& other){
        Record::operator=(other);
        _authorFirstName = other._authorFirstName;
        _authorSurname = other._authorSurname;
        _isPaperback = other._isPaperback;
        _numberOfPages = other._numberOfPages;
        return *this;
    }
    bool operator == (const Book &other_Record) const{
        return Record::operator==(other_Record);
    }
    
    bool operator != (const Book &other_Record) const{
        return Record::operator!=(other_Record);
    }
    
    bool operator < (const Book &other_Record) const{
        return Record::operator<(other_Record);
    }

};

#endif /* Record_h */
