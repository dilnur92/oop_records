//
//  Record.cpp
//  LinkedListRecordProjectFreelancer
//
//  Created by Dilnur Yuldashev on 10/1/16.
//  Copyright © 2016 Dilnur Yuldashev. All rights reserved.
//

#include "Record.h"
//Default Constructor
Record::Record(){
    //default values
    _title = "";
    _date = "";
    _address = "";
    _price = 0;
    
}

//Constructor
Record::Record(string title, string address, string date, float price){
    _title = title;
    _date = date;
    _address = date;
    _price = price;
}

// Setters
void Record::setRecordTitle(string title){
    _title = title;
}
void Record::setRecordDate(string date){
    _date=date;
}
void Record::setRecordAddress(string address){
    _address = address;
}
void Record::setRecordPrice(float price){
    _price = price;
}

//Getters

string Record::getRecordTitle(){
    return _title;
}

string Record::getRecordDate(){
    return _date;
}

string Record::getRecordAddress(){
    return _address;
}

float Record::getRecordPrice(){
    return _price;
}

// Default Constructor
Book::Book(){
    Record::Record();
    _authorFirstName = "";
    _authorSurname = "";
    _isPaperback = true;
    _numberOfPages = 0;
    isFromFile = false;
}
// Default Constructor
Book::Book(bool t){
    Record::Record();
    _authorFirstName = "";
    _authorSurname = "";
    _isPaperback = true;
    _numberOfPages = 0;
    isFromFile = t;
}
// Constructor
Book::Book(string title, string address, string date, float price, string authorFirstName, string authorLastName, bool paperback, int numberOfPages){
    Record::Record(title, address, date, price);
    _authorFirstName = authorFirstName;
    _authorSurname = authorLastName;
    _isPaperback = paperback;
    _numberOfPages = numberOfPages;
    isFromFile = false;
}

//Book functions Getters
string Book::getBookTitle(){
    return Record::getRecordTitle();
}

string Book::getBookDate(){
    return Record::getRecordDate();
}

string Book::getBookAddress(){
    return Record::getRecordAddress();
}

float Book::getBookPrice(){
    return Record::getRecordPrice();
}

string Book::getBookAuthorFirstName(){
    return _authorFirstName;
}

string Book::getBookAuthorSurname(){
    return _authorSurname;
}

bool Book::getBookPaperback(){
    return _isPaperback;
}
int Book::getBookNumberOfPages(){
    return _numberOfPages;
}

//Book functions Setters
void Book::setBookTitle(string title){
    Record::setRecordTitle(title);
}
void Book::setBookDate(string date){
    Record::setRecordDate(date);
}
void Book::setBookAddress(string address){
    Record::setRecordAddress(address);
}
void Book::setBookPrice(float price){
    Record::setRecordPrice(price);
}

void Book::setBookAuthorFirstName(string firstName){
    _authorFirstName = firstName;
}
void Book::setBookAuthorSurname(string lastName){
    _authorSurname = lastName;
}
void Book::setBookPaperback(bool paperback){
    _isPaperback = paperback;
}
void Book::setBookNumberOfPages(int numberOfPages){
    _numberOfPages = numberOfPages;
}

bool Book::getIsFromFile(){
    return isFromFile;
}

void Book::setIsFromFileBool(bool t){
    isFromFile = t;
}
