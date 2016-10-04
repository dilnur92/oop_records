//
//  main.cpp
//  LinkedListRecordProjectFreelancer
//
//  Created by Dilnur Yuldashev on 10/1/16.
//  Copyright © 2016 Dilnur Yuldashev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Record.h"

#define MAX_STRING_SIZE 20
ostream* std_out= &cout;
string convertFloatToString(float f){
    std::ostringstream ss;
    ss << f;
    std::string s(ss.str());
    return s;
}

string restrictOrPadStringToCertainSize(string s){
    string t;
    if(s.length()>=MAX_STRING_SIZE){
        t= s.substr(0, MAX_STRING_SIZE-3);
        for(long i=0;i<3;i++){
            t = t + ".";
        }
    }
    else{
        //we need to pad the string so its certain size
        long size =s.length();
        for(long i=size;i<MAX_STRING_SIZE;i++){
            s = s + " ";
        }
        t= s;
    }
    
    for(long i=0;i<5;i++){
        t = t + " ";
    }
    return t;
}

//this function is used for writing Book records to file or STDIN
ostream & operator<<(ostream & str, Book * book) {
    string paper = "yes";
    if(book->getBookPaperback() == false)
        paper = "no";
    if (str.rdbuf() == std::cout.rdbuf()){
        str<<restrictOrPadStringToCertainSize(book->getBookTitle())
        <<restrictOrPadStringToCertainSize(book->getBookAddress())
        <<restrictOrPadStringToCertainSize(book->getBookDate())
        <<restrictOrPadStringToCertainSize(convertFloatToString (book->getBookPrice())+"$")
        <<restrictOrPadStringToCertainSize(book->getBookAuthorFirstName()+" "+book->getBookAuthorSurname())
        <<restrictOrPadStringToCertainSize(paper)
        <<restrictOrPadStringToCertainSize(convertFloatToString(book->getBookNumberOfPages()))<<endl;
    }else{
        str<<book->getBookTitle()<<endl<<book->getBookAddress()<<endl<<book->getBookDate()<<endl<<book->getBookPrice()<<endl<<book->getBookAuthorFirstName()<<endl<<book->getBookAuthorSurname()<<endl<<paper<<endl<<book->getBookNumberOfPages()<<endl;
    }
    return str;
}

void printHeaders(){
    cout<<restrictOrPadStringToCertainSize("Title");
    cout<<restrictOrPadStringToCertainSize("Address");
    cout<<restrictOrPadStringToCertainSize("Date");
    cout<<restrictOrPadStringToCertainSize("Price");
    cout<<restrictOrPadStringToCertainSize("Author Name");
    cout<<restrictOrPadStringToCertainSize("Paperback");
    cout<<restrictOrPadStringToCertainSize("NumPages");
    cout<<endl;
    cout<<"------------------------";
    cout<<"------------------------";
    cout<<"------------------------";
    cout<<"------------------------";
    cout<<"------------------------";
    cout<<"------------------------";
    cout<<"------------------------";
    cout<<endl;
}

//this function is used for reading in Book records from file or STDIN
istream& operator>>(std::istream& is, Book * book){
    if(book->getIsFromFile())
        cout<<"Reading In a Book From File"<<endl;
    else
        cout<<"Reading In a Book"<<endl;
    string title = "", address = "", date = "", first_name = "", last_name = "";
    float price = 0;
    bool is_paperback = true;
    int number_of_pages = 0;
    string temp = "";
    getline(is, temp);

    //read Professor from input is
    if(!book->getIsFromFile()) cout<<"Title: "<<endl;
    getline(is, title);
    if(!book->getIsFromFile()) cout<<"Address: "<<endl;
    getline(is, address);
    if(!book->getIsFromFile()) cout<<"Date: "<<endl;
    getline(is, date);
    if(!book->getIsFromFile()) cout<<"Price: "<<endl;
    getline(is, temp);
    price = stof(temp);
    if(!book->getIsFromFile()) cout<<"First Name: "<<endl;
    getline(is, first_name);
    if(!book->getIsFromFile()) cout<<"Last Name: "<<endl;
    getline(is, last_name);
    if(!book->getIsFromFile()) cout<<"Is Paperback('yes'or 'no'): "<<endl;
    getline(is, temp);
    if(temp=="yes")
        is_paperback = true;
    else
        is_paperback = false;
    if(!book->getIsFromFile()) cout<<"Number Of Pages: "<<endl;
    getline(is, temp);
    
    number_of_pages = (int)stof(temp);

    book->setBookTitle(title);
    book->setBookAddress(address);
    book->setBookDate(date);
    book->setBookPrice(price);
    book->setBookAuthorFirstName(first_name);
    book->setBookAuthorSurname(last_name);
    book->setBookPaperback(is_paperback);
    book->setBookNumberOfPages(number_of_pages);
    return is;
}

void initializeArray(LinkedList<Book*> &books, int choice, bool& repeat){
    int read_switch = choice;
    switch(read_switch)
    {
        case 0:{
            printHeaders();
            books.displayList(*std_out);
            break;
        }
        case 1:{
            std::cout << "Inserting to the Book List(sorted by title):\n";
            Book * t = new Book();
            cin>>t;
            books.insertNode(t);
            break;
        }
        case 2:{
            std::cout << "Deleting from the Books List \n";
            string title;
            cout<<"Enter Book Title You wish to delete: "<<endl;
            getline(cin, title);
            getline(cin, title);
            
            Book* t = new Book();
            t->setBookTitle(title);
            cout<<"Book Title being deleted: "<<title<<endl;
            Book *tk = books.SearchNode(t);
            if(tk->getBookAddress() == ""){
                cout<<"No such book in the list"<<endl;
            }else{
                cout<<"Details about the Book that is deleted: "<<endl;
                printHeaders();
                cout<<tk<<endl;
                books.deleteNode(t);
            }
            break;
        }
        case 3:{
            std::cout << "Searching for book from the list \n";
            string title;

            cout<<"Enter Book Title You wish to search: "<<endl;
            getline(cin, title);
            getline(cin, title);
            
            Book* t = new Book();
            t->setBookTitle(title);
            cout<<"Book Title being searched: "<<title<<endl;
            Book *tk = books.SearchNode(t);
            if(tk->getBookAddress() == ""){
                cout<<"No such book in the list"<<endl;
            }else{
                cout<<"Details about the Book that is found: "<<endl;
                printHeaders();
                cout<<tk<<endl;
            }
            break;
        }
        case 4:{
            std::cout << "Exiting the Main Menu\n";
            repeat = false;
            break;
        }
        default:
            std::cout << "default \n";
    }
}


void mainMenu(LinkedList<Book*> &books, bool& repeat)
{// Start startOutput
    int choice = -1; // Declare choice as int
    //books.displayList();
    while (choice < 0 || choice > 7)
    {
        std::cout << "Please select an option from below:\n"; // Initial prompt
        std::cout << "0. Display Books\n";
        std::cout << "1. Add\n";
        std::cout << "2. Delete\n";
        std::cout << "3. Search\n";
        std::cout << "4. Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice; // Read in user choice
        std::cout << std::endl;	
        if (choice > 7)
        {
            std::cout << "Invalid input, please enter #'s 0-7!\n";
        }
    }
    initializeArray(books, choice, repeat);
}// End startOutput

int main(){// Start main
    bool repeat = true; // Declare repeat as boolean
    LinkedList<Book*> books;
    //read in the records from file first
    ifstream in;
    in.open("database.txt");
    Book * temp;
    string t;
    int books_number;
    int i = 0;
    if(in.is_open()){
        getline(in, t);
        
        books_number = (int)stof(t);

        while(i<books_number){
            temp = new Book(true);
            in>> temp;
            books.insertNode(temp);
            //getline(in, t);
            i++;
        }
        in.close();
    }
    do
    {// Start do
        mainMenu(books, repeat);
        //another(repeat);
    }while(repeat); // End do
    ofstream out;
    out.open("database.txt");
    if(out.is_open()){
        cout<<"Saving the books to the database"<<endl;
        out<<books.getSize()<<endl<<endl;
        books.displayList(out);
    }
    out.close();
    //here we need to save everything to the database
    return 0;
}// End main
