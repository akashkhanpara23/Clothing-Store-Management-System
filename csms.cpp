#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class product {
    int pno;
    char name[50];
    float price, qty, tax, dis;

public:
    product() {
        pno = 000;
        strcpy(name, "...");
        price = 000;
        qty = 000;
        tax = 000;
        dis = 000;
    }

    void create_product() {
        cout << "Please Enter the Product Number of The Product: ";
        cin >> pno;
        cin.ignore(); // To ignore the newline character left by cin
        cout << "Please Enter The Name Of The Product: ";
        cin.getline(name, 50);
        cout << "Please Enter The Price of The Product: ";
        cin >> price;
        cout << "Please Enter The Discount (%): ";
        cin >> dis;
    }

    void show_product() {
        cout << "\nProduct Number: " << pno;
        cout << "\nName: " << name;
        cout << "\nPrice: " << price;
        cout << "\nDiscount (%): " << dis << endl;
    }

    int retpno() { return pno; }
    float retprice() { return price; }
    char* retname() { return name; }
    int retdis() { return dis; }
};

fstream fp;
product pr;

void write_product() {
    fp.open("Shop.dat", ios::out | ios::app);
    pr.create_product();
    fp.write((char*)&pr, sizeof(product));
    fp.close();
    cout << "\n\nThe Product Has Been Created!\n";
}

void display_all() {
    cout << "\n\n\t\t DISPLAY ALL RECORDS!!!\n\n";
    fp.open("Shop.dat", ios::in);
    while (fp.read((char*)&pr, sizeof(product))) {
        pr.show_product();
        cout << "\n=====================\n";
    }
    fp.close();
}

void display_sp(int n) {
    int flag = 0;
    fp.open("Shop.dat", ios::in);
    while (fp.read((char*)&pr, sizeof(product))) {
        if (pr.retpno() == n) {
            pr.show_product();
            flag = 1;
        }
    }
    fp.close();
    if (flag == 0)
        cout << "\n\nRecord does not exist.\n";
}

void modify_product() {
    int no, found = 0;
    cout << "\n\n\t To Modify ";
    cout << "\n\n Please Enter The Product No. of The Product: ";
    cin >> no;
    fp.open("Shop.dat", ios::in | ios::out);
    while (fp.read((char*)&pr, sizeof(product)) && found == 0) {
        if (pr.retpno() == no) {
            pr.show_product();
            cout << "\nPlease Enter The New Details of The Product:\n";
            pr.create_product();
            int pos = -1 * sizeof(pr);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&pr, sizeof(product));
            cout << "\n\n\t Record Updated";
            found = 1;
        }
    }
    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";
}

void delete_product() {
    int no;
    cout << "\n\n\n\t Delete Record";
    cout << "\n\n Please Enter The Product No. of The Product You Want To Delete: ";
    cin >> no;
    fp.open("Shop.dat", ios::in);
    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    while (fp.read((char*)&pr, sizeof(product))) {
        if (pr.retpno() != no) {
            fp2.write((char*)&pr, sizeof(product));
        }
    }
    fp2.close();
    fp.close();
    remove("Shop.dat");
    rename("Temp.dat", "Shop.dat");
    cout << "\n\n\t Record Deleted ..\n";
}

void menu() {
    fp.open("Shop.dat", ios::in);
    if (!fp) {
        cout << "ERROR!!! FILE COULD NOT BE OPENED\n";
        cout << "Go To Admin Menu to create File\n";
        cout << "Program is closing....\n";
        exit(0);
    }
    cout << "\n\n\t\t Product MENU \n\n";
    cout << "=================================\n";
    cout << "P.NO.\t\tNAME\t\tPRICE\n";
    cout << "=================================\n";
    while (fp.read((char*)&pr, sizeof(product))) {
        cout << pr.retpno() << "\t\t" << pr.retname() << "\t\t" << pr.retprice() << "\n";
    }
    fp.close();
}

void place_order() {
    int order_arr[50], quan[50], c = 0;
    float amt, total = 0;
    char ch = 'Y';
    menu();
    cout << "\n================\n";
    cout << " PLACE YOUR ORDER\n";
    cout << "================\n";
    do {
        cout << "\n\n Enter The Product No. Of The Product: ";
        cin >> order_arr[c];
        cout << "Quantity in number: ";
        cin >> quan[c];
        c++;
        cout << "Do You Want To Order Another Product? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n Thank You For Placing The Order\n";
    cout << "\nPr No. \tPr Name \tQuantity \tPrice \tAmount\n";
    for (int x = 0; x < c; x++) {
        fp.open("Shop.dat", ios::in);
        while (fp.read((char*)&pr, sizeof(product))) {
            if (pr.retpno() == order_arr[x]) {
                amt = pr.retprice() * quan[x];
                cout << order_arr[x] << "\t" << pr.retname() << "\t\t" << quan[x] << "\t\t" << pr.retprice() << "\t" << amt << "\n";
                total += amt;
            }
        }
        fp.close();
    }
    cout << "=================================\n";
    cout << "TOTAL = " << total << "\n";
}

void admin_menu() {
    char ch2;
    cout << "\n\n\t ADMIN MENU \n";
    cout << "1. CREATE PRODUCT\n";
    cout << "2. DISPLAY ALL PRODUCTS\n";
    cout << "3. QUERY\n";
    cout << "4. MODIFY PRODUCT\n";
    cout << "5. DELETE PRODUCT\n";
    cout << "6. VIEW PRODUCT MENU\n";
    cout << "7. BACK TO MAIN MENU\n";
    cout << "8. EXIT\n";
    cout << "Please Enter Your Choice (1-8): ";
    cin >> ch2;
    switch (ch2) {
        case '1': write_product(); break;
        case '2': display_all(); break;
        case '3': {
            int num;
            cout << "\n\n Please Enter The Product No.: ";
            cin >> num;
            display_sp(num);
            break;
        }
        case '4': modify_product(); break;
        case '5': delete_product(); break;
        case '6': menu(); break;
        case '7': return;
        case '8': exit(0);
        default: cout << "\a"; admin_menu();
    }
}

int main() {
    char ch;
    do {
        cout << "\n\n\t MAIN MENU \n";
        cout << "1. CUSTOMER\n";
        cout << "2. ADMINISTRATOR\n";
        cout << "3. EXIT\n";
        cout << "Please Select Your Option (1-3): ";
        cin >> ch;
        switch (ch) {
            case '1': place_order(); break;
            case '2': admin_menu(); break;
            case '3': exit(0);
            default: cout << "Alert: Wrong Choice\n";
        }
    } while (ch != '3');
    return 0;
}
