#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct person{
    string name, surname, index;
    int number_of_books = 0;
};
struct book{
    string name;
    int quantity;
};
bool comp (person a, person b){
 return a.index<b.index;
}

vector <person> list_user(0);
vector <book> list_book(0);
int mxi = -1, mxn = -1, mxs = -1;

void starting(){
    cout << "This is a library simulation." << endl << endl << "The following operations are available to you:";
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

void createuser(){
    person a;
    cout << "Write user's name:" << endl;
    cin >> a.name;
    int x = a.name.size();
    cout << "Write user's surname:" << endl;;
    cin >> a.surname;
    int y= a.surname.size();
    cout << "Write user's index(it must be unique)" << endl;
    bool b=0;
    while (b==0){
            cin >> a.index;
            b=1;
        for (int i=0; i<list_user.size(); i++){
            if (a.index == list_user[i].index){
                cout << "You need to give an unique index, try again" << endl;
                b=0;
            }
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
                    cin >> s;
                    list_user[i].name=s;
                }else if (ss == "s"){
                    cout << "Write a new surname " << endl;
                    cin >> s;
                    list_user[i].surname=s;
                } else if (ss== "i"){
                    cout << "Write a new index " << endl;
                        bool bb=0;
                        while (bb==0){
                            cin >> s;
                            bb=1;
                        for (int j=0; j<list_user.size(); j++){
                            if (s == list_user[j].index){
                            cout << "You need to give an unique index" << endl;
                            bb=0;
            }
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
} else{
    cout << "Changing was successful" << endl;
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
    for (int i=0; i<mxi+mxs+mxn+10; i++){
        cout << "-";
    }
    cout << endl;
    for (int i=0; i<list_user.size(); i++){
        cout << "| " << list_user[i].name;
        for (int q=0; q<mxn-list_user[i].name.size(); q++){
            cout << " ";
        }
        cout << " | " << list_user[i].surname;
        for (int q=0; q<mxs-list_user[i].surname.size(); q++){
            cout << " ";
        }
        cout << " | " << list_user[i].index;
        for (int q=0; q<mxi-list_user[i].index.size(); q++){
            cout << " ";
        }
        cout <<" | "<<endl;

    for (int qqq=0; qqq<mxi+mxs+mxn+10; qqq++){
        cout << "-";
    }
    cout << endl;
    }
    cout << endl;
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

void createbook(){
    book a;
    cout << "Write a name of the book" << endl;
    getline(cin, a.name);
    getline(cin, a.name);
    cout << "Write a quantity of this books (how much we have this books)" << endl;
    cin >> a.quantity;
    list_book.push_back(a);
    cout << "Books were added" << endl;
}

void showbook(){
   cout << "This is the list of books:" << endl;

    for (int i=0; i<list_book.size(); i++){
        cout << '"' << list_book[i].name << '"' << " - we have " << list_book[i].quantity << " examples" << endl;
    }
}

void takebook(){
    cout << "Write the index of an user" << endl;
    string s; cin >> s;
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
        }
    }
}

void quit(){
    cout << endl << "Thank you for playing with the simulation!" << endl << "Have a good day!"  <<endl << endl;;
}

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    
    char c='q';
    while (c!='Q'){

        starting();
        cin >> c;
        if (c<='z' && c>='a'){
            c+='A'-'a';
        }

        switch (c) {
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
                cout << "There is no such an option\nPlease, try again" << endl;
                break;
        }
    }


    return 0;
}
