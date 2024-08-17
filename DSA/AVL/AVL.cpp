#include<iostream>
#include<string>
using namespace std;
class AVL 
{

    class node {
    public:
        int issn;
        string title;
        int refbook;
        int issuablebook;
        int NA;
        string* arr;
        node* next;
        node* prev;
        node operator=(const node& a)
        {
            issn = a.issn;
            issuablebook = a.issuablebook;
            title = a.title;
            refbook = a.refbook;
            NA = a.NA;
            if (arr != nullptr) {
                delete[]arr;
            }
            arr = new string[NA];
            for (int i = 0; i < NA; i++) {
                arr[i] = a.arr[i];

            }
            return *this;
        }
    };

    class Bnode {
    public:
        int data;
        node* p;
        Bnode* left;
        Bnode* right;
        int hight;
    };
    Bnode* root;
public:
    AVL() {
        root = nullptr;
    }
    int geth(Bnode* r) {
        if (r == nullptr) {
            return -1;
        }
        else
            return r->hight;
    }
    void rotateleft(Bnode*& x) {
        Bnode* y = x->right;
        x->right = y->left;
        y->left = x;
        x->hight = 1 + max(geth(x->left), geth(x->right));
        y->hight = 1 + max(x->hight, geth(y->right));
        x = y;
    }
    void doublerotateleft(Bnode*& x) {
        rotateright(x->right);
        rotateleft(x);
    }
    void rotateright(Bnode*& x) {
        Bnode* y = x->left;
        x->left = y->right;
        y->right = x;
        x->hight = 1 + max(geth(x->left), geth(x->right));
        y->hight = 1 + max(x->hight, geth(y->left));
        x = y;
    }
    void doublerotateright(Bnode*& x) {
        rotateleft(x->left);
        rotateright(x);
    }
    int max(int x, int y) {
        if (x > y) {
            return x;
        }
        return y;
    }

    void printdetail(node* x) {
        cout << "-----------------" << endl;
        cout << "Details Of Book"<<endl;
        cout << "-----------------" << endl;
        cout << "ISSN:" << x->issn << endl;
        cout << "Title:" << x->title << endl;

        cout << "Authors Name\n";
        for (int i = 0; i < x->NA; i++) {
            cout << "Author " << i + 1 << ": " << x->arr[i] << endl;

        }

        cout << x->refbook << "copies are available (reference book)\n";

        cout << x->issuablebook << "copies are available (issuable book)\n";
        cout << "\n\n";

    }
    void insertdetail(node*& x) {
        cin.ignore();
        cout << "Enter Title\n";
        getline(cin, x->title);

        int a;
        cout << "Number of authors of this book\n";
        cin >> a;
        x->NA = a;

        x->arr = new string[a];
        cin.ignore();
        cout << "Enter authors name\n";
        for (int i = 0; i < a; i++) {
            cout << "Author " << i + 1 << " :";
            getline(cin, x->arr[i]);

        }

        cout << "How many copies available as a reference book\n";
        cin >> a;
        x->refbook = a;

        cout << "How many copies available as a issuable book\n";
        cin >> a;
        x->issuablebook = a;

    }
    void insert(Bnode*& r, node* x, int da) {
        if (r == nullptr) 
        {
            node* temp = new node;
            temp->issn = da;
            if (x == nullptr) {
                temp->next = nullptr;
                temp->prev = nullptr;
            }
            else {
                if (da > x->issn) {
                    temp->prev = x;
                    temp->next = x->next;
                    if (x->next != nullptr) {
                        x->next->prev = temp;
                    }
                    x->next = temp;

                }
                else {
                    temp->next = x;
                    temp->prev = x->prev;
                    if (x->prev != nullptr) {
                        x->prev->next = temp;
                    }
                    x->prev = temp;
                }
            }
            insertdetail(temp);
            r = new Bnode;
            r->p = temp;
            r->left = nullptr;
            r->right = nullptr;
            r->data = da;
            r->hight = 0;
        }
        else {
            if (r->data < da) {
                insert(r->right, r->p, da);
                if (geth(r->left) - geth(r->right) == -2) {
                    if (da > r->right->data)
                        rotateleft(r);
                    else
                        doublerotateleft(r);
                }
            }
            else if (r->data > da) {
                insert(r->left, r->p, da);
                if (geth(r->left) - geth(r->right) == 2) {
                    if (da < r->left->data)
                        rotateright(r);
                    else
                        doublerotateright(r);
                }
            }
            r->hight = 1 + max(geth(r->left), geth(r->right));
        }


    }
    void insert() {
        int a;
        cout << "Enter ISSN: ";
        cin >> a;
        insert(root, nullptr, a);
    }
    int balancefactor(Bnode* r) {
        return geth(r->left) - geth(r->right);
    }
    void remove(Bnode*& root, int a) {
        if (root != nullptr) {
            if (root->data > a) {
                remove(root->left, a);
                if (geth(root->left) - geth(root->right) == -2) {
                    if (balancefactor(root->right) <= 0) {
                        rotateleft(root);
                    }
                    else if (balancefactor(root->left) == 1) {
                        doublerotateleft(root);
                    }
                }
                root->hight = 1 + max(geth(root->left), geth(root->right));
                return;
            }
            else if (root->data < a) {
                remove(root->right, a);
                if (geth(root->left) - geth(root->right) == 2) {
                    if (balancefactor(root->left) >= 0) {
                        rotateright(root);
                    }
                    else if (balancefactor(root->left) == -1) {
                        doublerotateright(root);
                    }
                }
                root->hight = 1 + max(geth(root->left), geth(root->right));
                return;
            }
            else if (root->data == a) {
                if (root->left == nullptr && root->right == nullptr) {
                    if (root->p->prev != nullptr) {
                        root->p->prev->next = root->p->next;
                    }
                    if (root->p->next != nullptr) {
                        root->p->next->prev = root->p->prev;
                    }
                    delete root->p;
                    delete root;
                    root = nullptr;
                }
                else if (root->left == nullptr) {
                    Bnode* temp = root;
                    root = root->right;
                    if (temp->p->prev != nullptr) {
                        temp->p->prev->next = temp->p->next;
                    }
                    if (temp->p->next != nullptr) {
                        temp->p->next->prev = temp->p->prev;
                    }

                    delete temp->p;
                    delete temp;
                }
                else if (root->right == nullptr) {
                    Bnode* temp = root;
                    root = root->left;
                    if (temp->p->prev != nullptr) {
                        temp->p->prev->next = temp->p->next;
                    }
                    if (temp->p->next != nullptr) {
                        temp->p->next->prev = temp->p->prev;
                    }
                    delete temp->p;
                    delete temp;
                }
                else {
                    *(root->p) = findmin(root->right);
                    root->data = root->p->issn;
                    remove(root->right, root->data);
                }
            }


        }
    }
    void remove(int a) {
        remove(root, a);
    }
    void print(Bnode* x) {
        if (x == nullptr) {
            return;
        }
        print(x->left);
        printdetail(x->p);

        print(x->right);
    }
    void print() {
        print(root);
    }

    void updates(node* p) {
        cout << "\nYou can Update\n";
        int x;
        while (1) 
        {
            cout << "-----------------" << endl;
            cout << "\n1) Title \n2)No of copies available for a refernce book\n"
                "3)No of copies available for a issuable books\n4)Authors List\n-1)Quit\n\n";
            cout << "-----------------" << endl;
            cout << "Select from above\n";
            cin >> x;
            if (x == 1) {
                cin.ignore();
                cout << "Enter new Title\n";
                getline(cin, p->title);
                cout << "\nUpdated\n\n";
            }
            else if (x == 2) {
                cout << "Enter new value of refernce book\n";
                cin >> p->refbook;
                cout << "\nUpdated\n\n";
            }
            else if (x == 3) {
                cout << "Enter new value of issuable book\n";
                cin >> p->issuablebook;
                cout << "\nUpdated\n\n";
            }
            else if (x == 4) {

                cout << "How many authors of this book\n";
                cin >> p->NA;
                p->arr = new string[p->NA];
                cin.ignore();
                cout << "Enter authors name\n";
                for (int i = 0; i < p->NA; i++) {
                    cout << "Author " << i + 1 << " :";
                    getline(cin, p->arr[i]);
                    cout << endl;
                }
                cout << "\nUpdated\n\n";
            }
            else if (x == -1) {
                break;
            }
            else {
                cout << "Please Enter correct value from above\n";
            }
        }
    }

    bool update(Bnode* r, int a) {
        if (r == nullptr) {
            return 0;
        }
        else if (r->data > a) {
            return update(r->left, a);
        }
        else if (r->data > a) {
            return update(r->right, a);
        }
        else {
            updates(r->p);
            return 1;
        }
    }
    void update(int y) {
        int x = update(root, y);
        if (!x) {
            cout << "Book not exist\n";
        }
    }

    bool review(Bnode* r, int a) {

        if (r == nullptr) {
            return 0;
        }
        else if (r->data > a) {
            return review(r->left, a);
        }
        else if (r->data > a) {
            return review(r->right, a);
        }
        else {
            printdetail(r->p);
            return 1;
        }

    }

    void review(int y) {

        int x = review(root, y);
        if (!x) {
            cout << "Book not exist\n";
        }

    }
    node findmin(Bnode* r) {
        if (r->left == nullptr) {
            return *(r->p);
        }
        return findmin(r->left);
    }


};

int main() {
    AVL a;
    int x;
    cout << "------------WELCOME TO FAST LIBRARY SYSTEM--------\n";

    while (1) {
        cout << "_______________________________________________" << endl;
        cout << "Enter 1 to create new record of book" << endl;
        cout << "Press 2 to review a book record" << endl;
        cout << "Enter 3 to Update a book record" << endl;
        cout << "Enter 4 Delete a book record" << endl;
        cout << "Press -1 For Quit" << endl;
        cout << "_______________________________________________" << endl;
        cout << "\nEnter: ";
        cin >> x;
        if (x == 1) {
            a.insert();
        }
        else if (x == 2)
        {
            int y;
            cout << "Enter ISSN: ";
            cin >> y;
            cout << endl;
            a.review(y);
        }
        else if (x == 3) {
            int y;
            cout << "Enter ISSN: ";
            cin >> y;

            a.update(y);
        }
        else if (x == 4) {
            int y;
            cout << "Enter ISSN: ";
            cin >> y;
            a.remove(y);
        }
        else if (x == -1) {
            break;
        }
        cout << "END";
    }
}