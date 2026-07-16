#include<iostream>
using namespace std;

class Library {

    private:
        string title, author, dueDate, type;

    public:

        static int totalBooks;

        Library() {

        }

        Library(string title, string author, string dueDate) {

            this->title = title;
            this->author = author;
            this->dueDate = dueDate;

            totalBooks++;

        }

        virtual void setDetails() {

            cin.ignore();

            cout << "Enter Title :- ";
            getline(cin, this->title);

            cout << "Enter Author Name :- ";
            getline(cin, this->author);

            cout << "Enter Due Date :- ";
            getline(cin, this->dueDate);

            totalBooks++;

        }

        void setAuthor(string author) {
            this->author = author;
        }

        void setDueDate(string date) {
            this->dueDate = date;
        }

        void setTitle(string title) {
            this->title = title;
        }

        void setType(string type) {
            this->type = type;
        }

        string getAuthor() {
            return author;
        }

        string getDueDate() {
            return dueDate;
        }

        string getTitle() {
            return title;
        }

        string getType() {
            return type;
        }
        
        virtual void displayDetails() {

            cout << "Author Name :- " << this->author << endl;
            cout << "Title :- " << this->title << endl;
            cout << "Due Date :- " << this->dueDate << endl;

        }

        virtual void checkOut(){
            
        }

        virtual void returnItem(){
            
        }

        virtual int getBookID(){
            return -1;
        }

        virtual int getDVDsID(){
            return -1;
        }

        virtual int getMagazinID(){
            return -1;
        }

        virtual ~Library() {
            totalBooks--;
        }

};

class Book: public Library {

    private:
        int bookID;
        string type = "Book";
        bool isIssued;

        static int nextBookID;

    public:

        void setDetails() override {

            nextBookID++;
            this->bookID = nextBookID;
            Library::setDetails();

            setType(type);

            isIssued = false;

        }

        void displayDetails() override {

            cout << endl << "----------------------------";

            cout << endl << "ID :- " << this->bookID << endl;

            Library::displayDetails();

            cout << "Availability :- " << (this->isIssued == false ? "Yes" : "No") << endl;

            cout << "----------------------------" << endl << endl;

        }

        int getBookID() override {
            return bookID;
        }

        void checkOut() override {

            if(isIssued == false) {

                cout << endl << "Book Issued Successfully." << endl;

                isIssued = true;
                
            } else if(isIssued == true) {

                throw string("Book Already Issued");

            }

        }

        void returnItem() override {

            if(isIssued = false) {

                throw string("Book Already Available.");

            } else if(isIssued = true) {

                cout << endl << "Book Received Successfully." << endl;

                isIssued = false;

            }

        }

};

class DVDs: public Library {

    private:
        int dvdID;
        string duration;
        string type = "DVDs";
        bool isIssued;

        static int nextDVDsID;

    public:

        void setDetails() override {

            nextDVDsID++;
            this->dvdID = nextDVDsID;

            cin.ignore();

            cout << endl << "Enter Duration(sec) :- ";
            cin >> duration;

            Library::setDetails();

            setType(type);

            isIssued = false;

        }

        void displayDetails() override {

            cout << endl << "----------------------------";

            cout << endl << "ID :- " << this->dvdID << endl;

            cout << "Duration :- " << this->duration << " sec" << endl;
            
            Library::displayDetails();

            cout << "Availability :- " << (this->isIssued == false ? "Yes" : "No") << endl;

            cout << "----------------------------" << endl << endl;

        }

        int getDVDsID() override {
            return dvdID;
        }

        void checkOut() override {

            if(isIssued == false) {

                cout << endl << "DVD Issued Successfully." << endl;

                isIssued = true;

            } else if(isIssued == true) {

                throw string("DVD Already Issued");

            }

        }

        void returnItem() override {

            if(isIssued = false) {

                throw string("DVD Already Available.");

            } else if(isIssued = true) {

                cout << endl << "DVD Received Successfully." << endl;

                isIssued = false;

            }

        }

};

class Magazine: public Library {

    private:
        int magazineID;
        string type = "Magazine";
        bool isIssued;

        static int nextMagazinID;

    public:

        void setDetails() override {

            nextMagazinID++;
            this->magazineID = nextMagazinID;

            Library::setDetails();

            setType(type);

            isIssued = false;

        }

        void displayDetails() override {

            cout << endl << "----------------------------";

            cout << endl << "ID :- " << this->magazineID << endl;

            Library::displayDetails();

            cout << "Availability :- " << (this->isIssued == false ? "Yes" : "No") << endl;

            cout << "----------------------------" << endl << endl;

        }

        int getMagazinID() override {
            return magazineID;
        }

        void checkOut() override {

            if(isIssued == false) {

                cout << endl << "Magazine Issued Successfully." << endl;

                isIssued = true;

            } else if(isIssued == true) {

                throw string("Magazine Already Issued");

            }

        }

        void returnItem() override {

            if(isIssued == false) {

                throw string("Magazine Already Available.");

            } else if(isIssued == true) {

                cout << endl << "Magazine Received Successfully." << endl;

                isIssued = false;

            }

        }

};

int Library::totalBooks = 0;
int Book::nextBookID = 100;
int DVDs::nextDVDsID = 200;
int Magazine::nextMagazinID = 300;



int main() {

    cout << "<======== LIBRARY MANAGEMENT SYSTEM========>" << endl << endl;

    Library *library[50];

    int choice;
    int index = 0;

    do {

        cout << endl << "Press 1 to Add." << endl;
        cout << "Press 2 to Display" << endl;
        cout << "Press 3 to Issue" << endl;
        cout << "Press 4 to Return" << endl;
        cout << "Press 5 to Exit" << endl;

        try_Again:
        cout << endl << "Enter Your Choice :- ";
        cin >> choice;

        try {

            if(choice < 1 || choice > 5) {
                throw choice;
            }

        } catch (int) {
            cout << endl << "Invalid Choice....." << endl;
            goto try_Again;
        }

        switch(choice) {

            case 1:

                int option_one;

                do{

                    cout << endl << endl << "<====== SELECT OPTION ======>" << endl;

                    cout << endl << "Press 1 to Add Book." << endl;
                    cout << "Press 2 to Add DVDs." << endl;
                    cout << "Press 3 to Add Magazine." << endl;
                    cout << "Press 4 to Exit." << endl;

                    try_Again1:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_one;

                    try {

                        if(option_one < 1 || option_one > 4) {
                            throw option_one;
                        }

                    } catch(int) {
                        cout << endl << "Invalid Choice....." << endl;
                        goto try_Again1;
                    }

                    switch(option_one) {

                        case 1:

                            library[index] = new Book();
                            library[index]->setDetails();
                            index++;

                            break;

                        case 2:

                            library[index] = new DVDs();
                            library[index]->setDetails();
                            index++;

                            break;

                        case 3:

                            library[index] = new Magazine();
                            library[index]->setDetails();
                            index++;

                            break;

                        case 4:

                            break;

                    }

                } while(option_one != 4);

                break;

            case 2:

                try {

                    if(index == 0) {
                        throw string("No Information Found.");
                    }

                } catch(string msg) {
                    cout << endl << msg << endl << endl;

                    break;
                }

                int option_two;

                do{

                    cout << endl << endl << "<====== SELECT OPTION ======>" << endl;

                    cout << endl << "Press 1 to Display Books." << endl;
                    cout << "Press 2 to Display DVDs." << endl;
                    cout << "Press 3 to Display Magazine." << endl;
                    cout << "Press 4 to Go Back." << endl;

                    try_Again2:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_two;

                    try{

                        if(option_two < 1 || option_two > 4) {
                            throw option_two;
                        }

                    } catch(int) {
                        cout << endl << "Invalid Choice..." << endl;
                        goto try_Again2;
                    }
                    
                    int found = 0;

                    switch(option_two) {

                        case 1:

                            for(int i = 0; i < index; i++) {

                                if(library[i]->getType() == "Book") {
                                    library[i]->displayDetails();
                                    found = 1;
                                }

                            }

                            if(found == 0) {
                                cout << endl << "Book Not Found." << endl;
                            }

                            break;

                        case 2:

                            for(int i = 0; i < index; i++) {
                                
                                if(library[i]->getType() == "DVDs") {
                                    library[i]->displayDetails();
                                    found = 1;
                                }

                            }

                            if(found == 0) {
                                cout << endl << "DVDs Not Found." << endl;
                            }

                            break;

                        case 3:

                            for(int i = 0; i < index; i++) {

                                if(library[i]->getType() == "Magazine") {
                                    library[i]->displayDetails();
                                    found = 1;
                                }

                            }

                            if(found == 0) {
                                cout << endl << "Magazine Not Found." << endl;
                            }

                            break;

                        case 4:

                            break;

                    }

                } while(option_two != 4);
 
                break;

            case 3:

                try {

                    if(index == 0) {
                        throw string("No Information Found.");
                    }

                } catch(string msg) {
                    cout << endl << msg << endl << endl;
                    break;
                }

                int option_three;

                do {

                    cout << endl << endl << "<====== SELECT OPTION ======>" << endl;

                    cout << endl << "Press 1 to Issue Book." << endl;
                    cout << "Press 2 to Issue DVD." << endl;
                    cout << "Press 3 to Issue Magazine." << endl;
                    cout << "Press 4 to Go BAck." << endl;

                    try_Again3:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_three;

                    try {

                        if(option_three < 1 || option_three > 4) {
                            throw string("Invalid Choice..");
                        }

                    } catch(string msg) {
                        cout << endl << msg << endl;
                        goto try_Again3;
                    }

                    int id;
                    int found = 0;

                    switch(option_three) {

                        case 1:

                            cout << endl << "Enter Book ID :- ";
                            cin >> id;

                            try {

                                for(int i = 0; i < index; i++) {

                                    if(library[i]->getBookID() == id && library[i]->getType() == "Book") {
                                        found = 1;
                                        library[i]->checkOut();
                                        break;
                                    }

                                }

                                if(found == 0) {
                                    throw string("Book Not Found.");
                                }

                            } catch(string msg) {
                                cout << endl << msg << endl;
                            }

                            break;

                        case 2:

                            cout << endl << "Enter DVD ID :- ";
                            cin >> id;

                            try {

                                for(int i = 0; i < index; i++) {

                                    if(library[i]->getDVDsID() == id && library[i]->getType() == "DVDs") {
                                        found = 1;
                                        library[i]->checkOut();
                                        break;
                                    }

                                }

                                if(found == 0) {
                                    throw string("DVD Not Found.");
                                }

                            } catch(string msg) {
                                cout << endl << msg << endl;
                            }

                            break;

                        case 3:

                            cout << endl << "Enter Magazine ID :- ";
                            cin >> id;

                            try {

                                for(int i = 0; i < index; i++) {

                                    if(library[i]->getMagazinID() == id && library[i]->getType() == "Magazine") {
                                        found = 1;
                                        library[i]->checkOut();
                                        break;
                                    }
                                    
                                }

                                if(found == 0) {
                                    throw string("Magazine Not Found.");
                                }

                            } catch(string msg) {
                                cout << endl << msg << endl;
                            }

                            break;

                        case 4:

                            break;

                    }

                } while(option_three != 4);

                break;

            case 4:

                try {

                    if(index == 0) {
                        throw string("No Information Found.");
                    }

                } catch(string msg) {
                    cout << endl << msg << endl << endl;
                    break;
                }

                int option_four;

                do {

                    cout << endl << endl << "<====== SELECT OPTION ======>" << endl;

                    cout << endl << "Press 1 to Return Book." << endl;
                    cout << "Press 2 to Return DVD." << endl;
                    cout << "Press 3 to Return Magazine." << endl;
                    cout << "Press 4 to Go BAck." << endl;

                    try_Again4:
                    cout << endl << "Enter Your Choice :- ";
                    cin >> option_four;

                    try {
                        
                        if(option_four < 1 || option_four > 4) {
                            throw string("Invalid Choice..");
                        }

                    } catch(string msg) {
                        cout << endl << msg << endl;
                        goto try_Again4;
                    }

                    int found = 0;

                    switch(option_four) {

                        case 1:

                            int bookID;

                            cout << endl << "Enter Book ID :- ";
                            cin >> bookID;

                            try {

                                for(int i = 0; i < index; i++) {

                                    if(library[i]->getBookID() == bookID && library[i]->getType() == "Book") {
                                        found = 1;
                                        library[i]->returnItem();
                                        break;
                                    }

                                }

                                if(found == 0) {
                                    throw string("Book Not Found");
                                }

                            } catch(string msg) {
                                cout << endl << msg << endl;
                            }

                            break;

                        case 2:

                            int dvdID;

                            cout << endl << "Enter DVD ID :- ";
                            cin >> dvdID;

                            try {

                                for(int i = 0; i < index; i++) {

                                    if(library[i]->getDVDsID() == dvdID && library[i]->getType() == "DVDs") {
                                        found = 1;
                                        library[i]->returnItem();
                                        break;
                                    }

                                }

                                if(found == 0) {
                                    throw string("DVD Not Found.");
                                }

                            } catch(string msg) {
                                cout << endl << msg << endl;
                            }

                            break;

                        case 3:

                            int magazineID;

                            cout << endl << "Enter Magazine ID :- ";
                            cin >> magazineID;

                            try {

                                for(int i = 0; i < index; i++) {

                                    if(library[i]->getMagazinID() == magazineID && library[i]->getType() == "Magazine") {
                                        found = 1;
                                        library[i]->returnItem();
                                        break;
                                    }

                                }

                                if(found == 0) {
                                    throw string("Magazine Not Found.");
                                }

                            } catch(string msg) {
                                cout << endl << msg << endl;
                            }

                            break;

                        case 4:

                            break;

                    }

                } while(option_four != 4);

                break;

            case 5:

                cout << endl << "<===== THANK YOU =====>" << endl;

                break;

        }

    } while(choice != 5);

    for(int i = 0; i < index; i++) {
        delete library[i];
    }


    return 0;
}