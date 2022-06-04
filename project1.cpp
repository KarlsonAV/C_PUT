#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

fstream fBooks, fStudents;

struct student{
    string name, surname, index;
    int number_of_books = 0;
};
struct book{
    string name, author;
    int quantity;
};
bool compare_index (student a, student b){
 return a.index < b.index;
}

vector <student> list_user(0);
vector <book> list_book(0);
int mxi = -1, mxn = -1, mxs = -1;

void starting(){
    cout << endl << "        Working with users:";
    cout << endl << "N - Create a new user";
    cout << endl << "C - Change information about a User";
    cout << endl << "S - Show a list of Users";
    cout << endl << "D - Delete a User";
    cout << endl << "        Working with books:";
    cout << endl << "B - Create a new book";
    cout << endl << "V - Show a list of books";
    cout << endl << "T - User takes or gives back a book (maximum 3)";
    cout << endl << "        To quit from the simulation press Q";
    cout << endl << endl;
}

// Function checks if name or surname was entered correctly
bool checking_Name_Surname(string s){
    for (int i=0; i<s.size(); i++){
        if ((i == 0 && s[0] >='A' && s[0]<='Z') || (s[i]>='a' && s[i]<='z')){

        } else {
            cout << "Sorry, but you made a mistake, please try again" << endl << endl;
            return 0;
        }
    }
    return 1;
}

// Function that creates a User
void createuser(){

    student a;
    bool check =0;

    while (check == 0){
            cout << "Write user's name:" << endl;
        cin >> a.name;
        if (checking_Name_Surname(a.name) == 1) {
            check = 1;
        }
    }

    int x = a.name.size();
    check = 0;


    while (check == 0){

        cout << "Write user's surname:" << endl;
        cin >> a.surname;
        if (checking_Name_Surname(a.surname) == 1) {
            check = 1;
        }
    }

    int y = a.surname.size();

    cout << "Write user's index (Index must be unique)" << endl;
    check = 0;

    while (check == 0){
            cin >> a.index;
            if (a.index.size() == 6){
                     check = 1;
                 for (int i = 0; i < list_user.size(); i++){
                    if (a.index == list_user[i].index) {
                        cout << "Please, give unique index" << endl;
                        check = 0;
                        }
                    }
                }
            else {
                cout << "Sorry, but you made a mistake, please try again" << endl << endl;
            }
        }

    int z = a.index.size();
    mxi = max(mxi, z);
    mxn = max(mxn, x);
    mxs = max(mxn, y);
    list_user.push_back(a);
    sort(list_user.begin(), list_user.end(), compare_index);
    cout << "Person was added" << endl << endl;

}

// Function that changes information about User
void changeuser(){

    cout << "Give the index of a user, whose information must be changed" << endl;
    string s;
    bool check = 0;
    while (check == 0){
        cin >> s;
        bool test = 0;
       for (int i = 0; i < list_user.size(); i++){
            if (s == list_user[i].index){
                cout << "What you want to change? (n - name, s - surname, i - index)" <<  endl;
                string ss;
                cin >> ss;
                if (ss == "n"){
                    cout << "Write a new name " << endl;
                    bool t = 0;
                    while (t == 0){
                        cin >> s;
                        if (checking_Name_Surname(s) == 1){
                            t=1;
                        }
                    }
                    list_user[i].name=s;
                }
                else if (ss == "s"){
                    cout << "Write a new surname " << endl;
                    bool t = 0;
                    while (t == 0){
                    cin >> s;
                    if (checking_Name_Surname(s) == 1){
                            t = 1;
                        }
                    }
                    list_user[i].surname=s;
                }
                else if (ss == "i"){
                    cout << "Write a new index " << endl;
                        bool bb = 0;
                        while (bb == 0){
                            cin >> s;
                            if (s.size() == 6){
                            bb = 1;
                            for (int j = 0; j<list_user.size(); j++){
                                if (s == list_user[j].index) {
                                cout << "You need to give an unique index" << endl;
                                bb = 0;
                                    }
                            }
                        }
                        else {
                                cout << "Try again" << endl;;
                            }

                    }
            list_user[i].index = s;
                }
            check = 1;
            int x = list_user[i].index.size(), y= list_user[i].name.size(), z = list_user[i].surname.size();
            mxn = max(mxn, y);
            mxs = max(mxs, z);
            mxi = max(mxi, x);
            test = 1;
        }
  }

if (test == 0){
    cout << "Sorry, but you made a mistake" << endl;
    cout << "Do, you want to try again? (Y - yes, N - no)" << endl;;
    char ccc;
    cin >> ccc;
    if (ccc=='N'){
        return ;
    } else {
            cout << "Give the index of a User, whose information must be changed" << endl;
    }
} else {
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

// Function that shows all the users
void showuser(){

    if (list_user.size()!=0){
     /*
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

    for (int i=0; i<mxi+mxs+mxn+14; i++){
        cout << "-";
    }


    cout << endl;
string N, S, I;

    for (int i=0; i<list_user.size(); i++){
            N = list_user[i].name;
            S = list_user[i].surname;
            I = list_user[i].index;
        cout << "| " << list_user[i].name;

        for (int q=0; q<mxn-N.size()+2; q++){
            cout << " ";
        }
        cout << " | " << list_user[i].surname;
        for (int q=0; q<mxs-S.size()+2; q++){
            cout << " ";
        }
        cout << " | " << list_user[i].index << " | "<<endl;

    for (int qqq=0; qqq<mxi+mxs+mxn+14; qqq++){
        cout << "-";
    }
    cout << endl;
    }

    cout << endl;


 */
 for (int i = 0; i < list_user.size(); i++){
       cout << list_user[i].name << " " <<  list_user[i].surname << " " << list_user[i].index << endl;;;
   }
} else {
    cout << "We have no users" << endl;
}
}

// Function that deletes User
void deleteuser(){
    cout << "Write the index of a user, who must be deleted" << endl;
    string s;
    cin >> s;
    bool check = 0;
    for (int i = 0; i < list_user.size(); i++){
        if (s == list_user[i].index){
            check = 1;
            list_user.erase(list_user.begin() + i);
            cout << "The user was deleted successfully" << endl;
            break;
        }
    }
    if (check == 0){
        cout << "We haven't this user" << endl << "Do you want to try again (Y-yes, N-no)" << endl;
        char ccc;
        cin >> ccc;
        if (ccc == 'Y'){
            deleteuser();
        } else{
            cout << "No one was deleted" << endl;
        }
    }
}

// Function that checks if author's name was entered correctly
bool check_author(string s){
    for (int i = 0; i < s.size(); i++){
        if ((s[i] >='a' && s[i]<='z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] == ' ' || s[i] == '-'){

        } else {
            return 0;
        }
    }
    return 1;
}

// Function that creates a book
void createbook(){
    book a;
    bool check = 0;
    string str;
    int x = 0;
    cout << "Write a name of the book" << endl;
    getline(cin, a.name);
    getline(cin, a.name);
    bool q = 1;
    while (q == 1){
        cout << "Write a name of the author" << endl;
     getline(cin, a.author);
     if (check_author(a.author) == 1){
        q = 0;
     } else {
        cout << "You wrote a wrong name of the author" << endl << endl;
     }
    }

    while (check == 0){
            x = 0;
            check = 1;
        cout << "Write a quantity of this books (how many of these books do we have)" << endl;
        cin >> str;
        for (int i = 0 ; i < str.size(); i++){
            if (str[i] >= '0' && str[i] <= '9'){
                x *= 10;
                x += (str[i]-'0');
            } else {
                cout << "You made a mistake, try again" << endl << endl;
                check = 0;
                break;
            }
        }
    }
    a.quantity = x;
    check = 0;
    for (int i=0; i<list_book.size(); i++){
        if (list_book[i].author == a.author && list_book[i].name == a.name){
            cout << "This book already exists, please try again" << endl;
            check=1;
        }
    }
    if (check == 0){
         list_book.push_back(a);
    cout << "Books were added" << endl;
    }

}

// Function that shows all the available books
void showbook(){
    if (list_book.size()!=0){
        cout << "This is the list of books:" << endl;

    for (int i = 0; i < list_book.size(); i++){
        cout << '"' << list_book[i].name << '"' << " (" << list_book[i].author << ")"  << " - we have " << list_book[i].quantity << " examples" << endl;
    }
    } else{
        cout << "There are no books" << endl<< endl;
    }

}

void takebook(){
    cout << "Write the index of a User" << endl;
    string s;
    cin >> s;
    int ind;
    bool test = 0, check = 0;
    for (int i = 0; i < list_user.size(); i++){
            if (s == list_user[i].index){
                test = 1;
                ind = i;
                break;
            }
    }

    if (test == 0){
        cout << "Sorry, but you make a mistake, try everything again" << endl;
        takebook();
    } else {
        cout << "What you want to do? (t - take a book, r - return a book)" << endl;
        char  c;
        cin >> c;
        bool bo = 0;
        while (bo == 0){
            if (c == 't'){
                if (list_user[ind].number_of_books == 3){
        cout << "Sorry, but you already have 3 books, so return an old one, in order to get a new" << endl;
        takebook();
    }
            cout << "Write a name of the book, that you want to take"<< endl;
            string ss;

            getline(cin, ss);
            getline(cin, ss);
            for (int j = 0; j < list_book.size(); j++){
                if (ss == list_book[j].name){
                    if (list_book[j].quantity > 0){
                        cout << "Okey, you take it" << endl;
                        list_book[j].quantity--;
                        list_user[ind].number_of_books++;
                        check = 1;
                    } else {
                        cout << "Sorry, we don't have this book anymore" << endl;;
                    }
                }
            }
            if (check == 0){
                cout << "Sorry, we don't have this book anymore" << endl;

            }
            check = 0;
            bo = 1;
        } else if (c=='r'){
            cout << "Write a name of the book, that you return back"<< endl;;
            string ss;
            getline(cin, ss);
            getline(cin, ss);
            for (int j = 0; j < list_book.size(); j++){
                if (ss == list_book[j].name){

                        cout << "Okey, you return it" <<endl;;
                        list_book[j].quantity++;
                        list_user[ind].number_of_books--;
                    check = 1;
                }
    }
            bo = 1;
            if (check == 0){
                cout << "Sorry, we didn't have this book, you can't return it"  << endl;

            }
            check = 0;
        } else {
            cout << "There is no such an action, try again" << endl << endl;
            bo=1;
        }
    }
        }

    cout << "Do you want to take or return a book again? (Y - yes, N - no)" << endl;
    char c;
    cin >> c;

    if (toupper(c) == 'Y'){
        takebook();
    }
}


void quit(){
    cout << endl << "Thank you for playing with the simulation!" << endl << "Have a good day!"  <<endl << endl;;
}

int main()
{
    // Read information from the files"
    fBooks.open("book.txt", fstream::in | fstream::out);
    fStudents.open("student.txt", fstream::in | fstream::out);
    if (fBooks.is_open() && fStudents.is_open()){

    string NAME, SURNAME, IND, AUTHOR;
    int Q_BOOKS, N_BOOKS;
    student temporary_student;
    book temporary_book;

    if (fStudents.peek() != EOF) {

    while (!fStudents.eof()){
        fStudents >> NAME >> SURNAME >> IND >> Q_BOOKS;

        temporary_student.name = NAME;
        temporary_student.surname = SURNAME;
        temporary_student.index = IND;
        temporary_student.number_of_books = Q_BOOKS;
        int x = temporary_student.index.size(), y= temporary_student.name.size(), z = temporary_student.surname.size();
           mxn = max(mxn, y);
           mxs = max(mxs, z);
           mxi = max(mxi, x);
        list_user.push_back(temporary_student);
        sort(list_user.begin(), list_user.end(), compare_index);
    }
    }

   if (fBooks.peek() != EOF) {

    while (!fBooks.eof()){
        fBooks >> NAME >> AUTHOR >> N_BOOKS;
        temporary_book.name = NAME;
        temporary_book.author = AUTHOR;
        temporary_book.quantity = N_BOOKS;
        bool check = 0;
    for (int i = 0; i < list_book.size(); i++){
        if (list_book[i].author == temporary_book.author && list_book[i].name == temporary_book.name && list_book[i].quantity == temporary_book.quantity){
            check=1;
        }
    }
    if (check == 0){
         list_book.push_back(temporary_book);
    }
    }
    }
    cout << "This is a library simulation." << endl << endl << "The following operations are available to you:";

    string c="_";
    while (c!="Q"){

        starting();
        cin >> c;
        if (c.size()!=1){
                cout << "Incorrect input, please try again" << endl << endl;
            continue;
        }
        if (c[0]<='z' && c[0]>='a'){
            c[0]+='A'-'a';
        }
        cout << endl << endl;
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

    // Write new information into the files
    fBooks.open("book.txt", fstream::trunc | fstream::out);
    fStudents.open("student.txt", fstream::trunc | fstream::out);

    for (int i=0 ; i<list_user.size(); i++){
        fStudents << list_user[i].name << " " << list_user[i].surname << " " << list_user[i].index << " " << list_user[i].number_of_books ;
        if (i != list_user.size()-1){
            fStudents << endl;
        }
    }
    for (int i=0 ; i<list_book.size(); i++){
        fBooks << list_book[i].name << " " << list_book[i].author  << " " << list_book[i].quantity ;
        if (i != list_book.size()-1){
            fBooks << endl;
        }
    }
     } else {
        cout << "Sorry, but something is wrong with the file" << endl;
     }

    fBooks.close();
    fStudents.close();
    return 0;
}
