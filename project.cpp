#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

fstream fBooks ,fStudents;

struct person{
    string name, surname, index;
    int number_of_books = 0;
};
struct book{
    string name, author;
    int quantity;
};
bool comp (person a, person b){
 return a.index<b.index;
}

vector <person> list_user(0);
vector <book> list_book(0);
int mxi = -1, mxn = -1, mxs = -1;

void starting(){
    cout << endl << "        working with users:";
    cout << endl << "N - create a new user";
    cout << endl << "C - change information about an user";
    cout << endl << "S - show a list of users";
    cout << endl << "D - delete an user";
    cout << endl << "        working with books:";
    cout << endl << "B - create a new book";
    cout << endl << "V - show a list of books";
    cout << endl << "T - an user takes or gives back a book (maximum 3)";
    cout << endl << "        to quit from the simulation press Q";
    cout << endl << endl;
}

bool checking_Name_Surname(string s){
    for (int i=0; i<s.size(); i++){
        if ((i == 0 && s[0] >='A' && s[0]<='Z') || (s[i]>='a' && s[i]<='z')){

        } else {
            cout << "Sorry, you made a mistake ,try again" << endl << endl;;
            return 0;
        }
    }
    return 1;
}

void createuser(){
    person a;
    bool b =0;

    while (b == 0){
            cout << "Write user's name:" << endl;
        cin >> a.name;
        if (checking_Name_Surname(a.name) == 1) {
            b = 1;
        }
    }

    int x = a.name.size();
    b = 0;


    while (b == 0){
              cout << "Write user's surname:" << endl;
        cin >> a.surname;
        if (checking_Name_Surname(a.surname) == 1) {
            b = 1;
        }
    }

    int y= a.surname.size();

    cout << "Write user's index(it must be unique)" << endl;
    b=0;

    while (b==0){
            cin >> a.index;
            if (a.index.size() == 6){
                     b=1;
                 for (int i=0; i<list_user.size(); i++){
            if (a.index == list_user[i].index){
                cout << "You need to give an unique index, try again" << endl;
                b=0;
            }
        }
            }else{
                cout << "Sorry, you made a mistake ,try again" << endl << endl;;
            }
        }

    int z= a.index.size();
    mxi = max(mxi, z);
    mxn = max(mxn, x);
    mxs = max(mxn, y);
    list_user.push_back(a);
    sort(list_user.begin(), list_user.end(), comp);
    cout << "Person was added" << endl;;

}

void changeuser(){
    cout << "Give the index of an user, who should be changed" << endl;
    string s;
    bool b=0;
    while (b==0){
        cin >> s;
        bool test=0;
       for (int i=0;i<list_user.size(); i++){
            if (s==list_user[i].index){
                cout << "What you want to change? (n - name, s - surname, i - index)" <<  endl;;
                string ss;
                cin >> ss;
                if (ss == "n"){
                    cout << "Write a new name " << endl;
                    bool t=0;
                    while (t==0){
                        cin >> s;
                        if (checking_Name_Surname(s) == 1){
                            t=1;
                        }
                    }
                    list_user[i].name=s;
                }else if (ss == "s"){
                    cout << "Write a new surname " << endl;
                    bool t=0;
                    while (t==0){
                    cin >> s;
                    if (checking_Name_Surname(s) == 1){
                            t=1;
                        }
                    }
                    list_user[i].surname=s;
                } else if (ss== "i"){
                    cout << "Write a new index " << endl;
                        bool bb=0;
                        while (bb==0){
                            cin >> s;
                            if (s.size() == 6){
                            bb=1;
                            for (int j=0; j<list_user.size(); j++){
                            if (s == list_user[j].index){
                            cout << "You need to give an unique index" << endl;
                            bb=0;
            }
        }
                            } else {
                                cout << "Try again" << endl;;
                            }

    }
          list_user[i].index = s;
                }
                b=1;
                int x = list_user[i].index.size(), y= list_user[i].name.size(), z = list_user[i].surname.size();
           mxn = max(mxn, y);
           mxs = max(mxs, z);
           mxi = max(mxi, x);
           test = 1;
                }
  }

if (test == 0){
    cout << "Sorry, but you make a mistake" << endl;
    cout << "Do, you want to try again? (Y - yes, N - no)" << endl;;
    char ccc;
    cin >> ccc;
    if (ccc=='N'){
        return ;
    } else {
            cout << "Give the index of an user, who should be changed" << endl;
    }
} else{
    cout << "Changing was successful" << endl;
    cout << endl << "Do you want to change something else? (Y - yes, N - no)" << endl;
    char r;
    cin >> r;
    if (r == 'Y'){
        changeuser();
    }
}
        }
}

void showuser(){
    cout << "This is the list of users:" << endl;

    cout <<" Name";
    for (int q = 0; q<mxn; q++ ){
        cout << " ";
    }

    cout << " Surname";
    for (int q = 0; q<mxs-2; q++ ){
        cout << " ";
    }

    cout << " Index";
    for (int q = 0; q<mxi-6; q++ ){
        cout << " ";
    }

    cout << endl;
    for (int i=0; i<mxi+mxs+mxn+12; i++){
        cout << "-";
    }

    cout << endl;
string N, S, I;

    for (int i=0; i<list_user.size(); i++){
            N = list_user[i].name;
            S = list_user[i].surname;
            I = list_user[i].index;
        cout << "| " << list_user[i].name;

        for (int q=0; q<mxn-N.size()+1; q++){
            cout << " ";
        }
        cout << " | " << list_user[i].surname;
        for (int q=0; q<mxs-S.size()+1; q++){
            cout << " ";
        }
        cout << " | " << list_user[i].index << " | "<<endl;

    for (int qqq=0; qqq<mxi+mxs+mxn+12; qqq++){
        cout << "-";
    }
    cout << endl;
    }

    cout << endl;

 //   for (int i=0; i<list_user.size(); i++){
 //       cout << list_user[i].name << " " <<  list_user[i].surname << " " << list_user[i].index << endl;;;
 //   }
}

void deleteuser(){
    cout << "Write the index of an user, who should be deleted" << endl;
    string s;
    cin >> s;
    bool b = 0;
    for (int i=0; i<list_user.size(); i++){
        if (s == list_user[i].index){
            b = 1;
            list_user.erase(list_user.begin()+i);
            cout << "The user was deleted successfully" << endl;;
            break;
        }
    }
    if (b==0){
        cout << "We haven't this user" << endl << "Do you want to try again (Y-yes, N-no)" << endl;;
        char ccc;
        cin >> ccc;
        if (ccc == 'Y'){
            deleteuser();
        }else{
            cout << "Noone was deleted" << endl;
        }
    }
}


bool check_author(string s){
    for (int i=0; i<s.size(); i++){
        if ((s[i] >='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || s[i] == ' ' || s[i] == '-'){

        } else {
            return 0;
        }
    }
    return 1;
}


void createbook(){
    book a;
    bool b = 0;
    string str;
    int x = 0;
    cout << "Write a name of the book" << endl;
    getline(cin, a.name);
    getline(cin, a.name);
    bool q = 1;
    while (q==1){
        cout << "Write a name of the author" << endl;
     getline(cin, a.author);
     if (check_author(a.author) == 1){
        q = 0;
     } else {
        cout << "You write a wrong name of the author" << endl << endl;;
     }
    }

    while (b == 0){
            x=0;
            b=1;
        cout << "Write a quantity of this books (how much we have this books)" << endl;
        cin >> str;
        for (int i=0 ; i<str.size(); i++){
            if (str[i]>='0' && str[i]<='9'){
                x*=10;
                x+=(str[i]-'0');
            }else {
                cout << "You made a mistake, try again" << endl << endl;
                b = 0;
                break;
            }
        }
    }
    a.quantity = x;

    list_book.push_back(a);
    cout << "Books were added" << endl;
}

void showbook(){
   cout << "This is the list of books:" << endl;

    for (int i=0; i<list_book.size(); i++){
        cout << '"' << list_book[i].name << '"' << " (" << list_book[i].author << ")"  << " - we have " << list_book[i].quantity << " examples" << endl;
    }
}

void takebook(){
    cout << "Write the index of an user" << endl;
    string s;
    cin >> s;
    int ind;
    bool test = 0;
    for (int i=0; i<list_user.size(); i++){
            if (s == list_user[i].index){
                test = 1;
                ind = i;
                break;
            }
    }

    if (test == 0){
        cout << "Sorry, but you make a mistake, try everyting again" << endl;
        takebook();
    } else {
        cout << "What you want to do? (t - take a book, r - return a book)" << endl;
        char  c;
        cin >> c;
        bool bo = 0;
        while (bo == 0){
            if (c=='t'){
                if (list_user[ind].number_of_books==3){
        cout << "Sorry, but you already have 3 books, so return an old one, to take a new" << endl;
        takebook();
    }
            cout << "Write a name of book, that you want to take"<< endl;;
            string ss;
            getline(cin, ss);
            getline(cin, ss);
            for (int j=0; j<list_book.size(); j++){
                if (ss==list_book[j].name){
                    if (list_book[j].quantity>0){
                        cout << "Okey, you take it" <<endl;;
                        list_book[j].quantity--;
                        list_user[ind].number_of_books++;
                    } else {
                        cout << "Sorry, we haven't this book anymore" << endl;;
                    }
                }
            }
            bo = 1;
        } else if (c=='r'){
            cout << "Write a name of book, that you return to take"<< endl;;
            string ss;
            getline(cin, ss);
            getline(cin, ss);
            for (int j=0; j<list_book.size(); j++){
                if (ss==list_book[j].name){
                    if (list_book[j].quantity > 0){
                        cout << "Okey, you return it" <<endl;;
                        list_book[j].quantity++;
                        list_user[ind].number_of_books--;
                    }
                }
    }
            bo = 1;
        } else {
            cout << "There is no such an action, try again" << endl << endl;
            bo=0;
        }
    }
        }

    cout << "Do you want to take or return a book again? (Y - yes, N - no)" << endl;
    char c;
    if (c=='Y'){
        takebook();
    }
}

void quit(){
    cout << endl << "Thank you for playing with the simulation!" << endl << "Have a good day!"  <<endl << endl;;
}

int main()
{
    fBooks.open("book.txt", fstream::in | fstream::out);
    fStudents.open("student.txt", fstream::in | fstream::out);
    if (fBooks.is_open() && fStudents.is_open()){


    string NAME, SURNAME, IND, AUTHOR;
    int Q_BOOKS, N_BOOKS;
    person aaa;
    book bbb;
    while (!fStudents.eof()){
        fStudents >> NAME >> SURNAME >> IND >> Q_BOOKS;

        aaa.name = NAME;
        aaa.surname = SURNAME;
        aaa.index = IND;
        aaa.number_of_books = Q_BOOKS;
        int x = aaa.index.size(), y= aaa.name.size(), z = aaa.surname.size();
           mxn = max(mxn, y);
           mxs = max(mxs, z);
           mxi = max(mxi, x);
        list_user.push_back(aaa);
        sort(list_user.begin(), list_user.end(), comp);


    }

    while (!fBooks.eof()){
        fBooks >> NAME >> AUTHOR >> N_BOOKS;
        bbb.name = NAME;
        bbb.author = AUTHOR;
        bbb.quantity = N_BOOKS;
        list_book.push_back(bbb);
    }

    cout << "This is a library simulation." << endl << endl << "The following operations are available to you:";

    string c="_";
    while (c!="Q"){

        starting();
        cin >> c;
        if (c.size()!=1){
                cout << "Incorrect input, please try again" << endl << endl;;
            continue;
        }
        if (c[0]<='z' && c[0]>='a'){
            c[0]+='A'-'a';
        }

        switch (c[0]) {
            case 'N':
                createuser();
                break;
            case 'C':
                changeuser();
                break;
            case 'S':
                showuser();
                break;
            case 'D':
                deleteuser();
                break;
            case 'B':
                createbook();
                break;
            case 'V':
                showbook();
                break;
            case 'T':
                takebook();
                break;
            case 'Q':
                quit();
                break;
            default:
                cout << "There is no such an option\nPlease, try again" << endl << endl;;
                break;
        }
    }

    fBooks.close();
    fStudents.close();

  //  fStudents.clear();
   // fBooks.clear();

    fBooks.open("book.txt", fstream::in | fstream::out);
    fStudents.open("student.txt", fstream::in | fstream::out);

    for (int i=0 ; i<list_user.size(); i++){
        fStudents << list_user[i].name << " " << list_user[i].surname << " " << list_user[i].index << " " << list_user[i].number_of_books ;
        if (i != list_user.size()-1){
            fStudents << endl;
        }
    }
    for (int i=0 ; i<list_book.size(); i++){
        fBooks << list_book[i].name << " " << list_book[i].author  << " " << list_book[i].quantity << endl;
        if (i != list_book.size()-1){
            fBooks << endl;
        }
    }
     }else {
        cout << "Sorry, you can't work with files, try again" << endl;;
     }

    fBooks.close();
    fStudents.close();
    return 0;
}

