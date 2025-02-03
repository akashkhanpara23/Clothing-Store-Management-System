CODE OF SUPERMARKET BILLING SYSTEM .
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
class product
{
    int pno;
    char name[50];
    float price,qty,tax,dis;
    public:
    product()
    {
      pno=000;
      strcpy(name,"...");
      price=000;
      qty=000;
      tax=000;
      dis=000;
    }
    void create_product()
    {
      cout<<"Please Enter the Product Number of The Product: "<<endl;
      cin>>pno;
      cout<<"\n\n Please Enter The Name Of The Product: "<<endl;
      gets(name);
      cout<<"\n Please Enter The Price of The Product: "<<endl;
      cin>>price;
      cout<<\n Please Enter The Discount (%): "<<endl;
      cin>>dis;
    }
    void show_product()
    {
      cout<<"\nThe Product Number of The Product: "<<pno;
      cout<<"\n The Name Of The Product: "
      puts(name);
      cout<<"\n The Price of The Product: "<<price;
      cout<<\n Discount (%): "<<dis;
    }
    int retpno()
    {
        return pno;
    }
    float retprice();
    {
        return price;
    }
    char* retname()
    {
        return name;
    }
    int retdis()
    {
        return dis;
    }
};
    fstream fp;
    product pr;
    void write_product()
    {
      fp.open("Shop.dat",ios::out| ios::app);
      pr.create_product();
      fp.write((char*)&pr,sizeof(product));
      fp.close();
      cout<<\n\nThe Product Has Been Created ";
      getch();
    }
    void display_all()
    {
        clrscr();
        cout<<"\n\n\n\t\t DISPLAY ALL RECORD!!!\n\n";
        fp.open("Shop.dat",ios::in);
        while(fp.read((char*)&pr,sizeof(product)))
        {
          pr.show_product();
          cout<<"\n\n =====================\n" ;
          getch();
        }
        fp.close();
        getch();
    }
    void display_sp(int n)
    {
      int flag=0;
      fp.open("Shop.dat",ios::in);
      while(fp.read((char*)&pr,sizeof(product)))
      {
        if (pr.retpno()==n)
        {
          clrscr();
          pr.show_product();
          flag=1;
        }
      }
      fp.close();
      if (flag==0)
      cout<<"\n\n record not exist"<<endl;
      getch();
    }
    void modify_product()
    {
      int no.,found=0;
      clrscr();
      cout<<"\n\n\t To Modify ";
      cout<<"\n\n Please Enter The Product No. of The Product: "; <<endl;
      cin>>no.;
      fp.open("Shop.dat",ios::in||ios::out);
      while(fp.read((char*)&pr,sizeof(product)) &&found=0)
      {
        if (pr.retpno()==no.)
        {
            pr.show_product();
            cout<<"\nPlease Enter The New Details of The Product:\n";
            pr.create_product();
            int pos=-1*size of (pr);
            fp.seekp (pos, ios::cur);
            fp.write((char*) &pr, size of (product));
            cout<<"\n\n\t Record Updated";
            found=1;
        }
      }
      fp.close();
      if(found==0)
      cout<<"\n\n Record Not Found ";
      getch();
    }
    void delete_product()
    {
      int no.;
      clrscr();
      cout<<"\n\n\n\t Delete Record";
      cout<<"\n\n Please Enter The Product No. of The Product You Want To Delete: ";
      cin>>no;
      fp.open("Shop.dat",ios::in||ios::out);
      fstream fp2;
      fp2.open("Temp.dat",ios::out);
      fp2.seekg(0,ios::out);
      fp.seekg(0,ios::beg);
      while(fp.read((char*)&pr,sizeof(product)))
      {
        if (pr.retpno()!==no.)
        {
          fp2.write((char*)&pr,sizeof(product));
        }
      }
      fp2.close();
      fp.colse();
      remove("Shop.dat");
      rename("Temp.dat","Shop.dat");
      cout<<"\n\n\t Record Deleted ..";
      getch ();
    }
    void menu()
    {
      clrscr();
      fp.open("Shop.dat",ios::in);
      if(!fp)
      {
        cout<<"ERROR!!! FIKE COULD NOT BE OPEN";
        cout<<"\n Go To Admin Menu to create File";
        cout<<"\n\n Program is closing....";
        getch();
        exit(0);
      }
      cout<<"\n\n\t\t Product MENU \n\n";
      cout<<"=================================\n";
      cout<<"P.NO.\t\t NAME \t\t PRICE \n";
      cout<<"=================================\n";
      while(fp.read((char*)&pr,sizeof(product)))
      {
          cout<<pr.retpno()<<"\t"<<pr.retname()<<"\t\t"<<pr.retprice()<<\n;
      }
      fp.close();
    }
    void place_order()
    {
      int order_arr[50],quat[50],c=0;
      float amt, damt, total=0;
      char ch='Y' ;
      menu();
      cout<<"\n================";
      cout<<"\n PLACE YOUR ORDER";
      cout<<"\n================\n";
      do{
        cout<<"\n\n Enter The Product No. Of The Product :";
        cin>>order_arr[c];
        cout<<"\n Quantity in number:";
        c++;
        cout<<"\n Do You Want To Order Another Product? (y/n);
        cin>>ch;
      }
      while (ch=='y' || ch=='Y');
      cout<<"\n\n Thank You For Placing The Order";
      getch();
      clrscr();
      gotoxy(36,2);
      cout<<"-INVOICE-\n";
      cout<<"\nPr No. \t Pr Name \t Quantity \tPrice \tAmount \t\ Amount after discount\n";
      for( int x=0; x<=c; x++)
      {
        fp.open("Shop.dat",ios::in);
        fp.read((char*)&pr,size of(product));
        while (!fp.eof())
        {
            if (pr.retpno()==order_arr[x])
            {
            amt=pr.retprice()*quan[x];
            damt=amt-(amt*pr.retdis()/100);
            cout<<"\n"<<order_arr[x]<<"\t"<<pr.retname()<<"\t\t"<<quan[x]<<"\t\t"<<pr.retprice()<
            <"\t"<<amt<<"\t\t"<<damt;
            total+=damt;
            }
          fp.read((char*)&pr,size of(product));
        }
        fp.close();
      }
      gotoxy(36,10);
      cout<<"TOTAL="<<total;
      getch ();
    }
    void box(void)
    {
      int i;
      for( i=18; i<60; i++)
      {
        gotoxy(i,1);
        cout<<"*";
      }
      for( i=18; i<60; i++)
      {
          gotoxy(i,3);
          cout<<"*";
      }
      for( i=1; i<22; i++)
      {
          gotoxy(16,i);
          cout<<"*";
      }
      for( i=18; i<60; i++)
      {
          gotoxy(i,21);
          cout<<"*";
      }
      for( i=1; i<22; i++)
      {
        gotoxy(61,i);
        cout<<"*";
      }
    }
    void admin_menu()
    {
      clrscr();
      box();
      char ch2;
      gotoxy(35,2);
      cout<<" ADMIN MENU ";
      gotoxy(32,4);
      cout<<" 1. CREATE PRODUCT ";
      gotoxy(28,6);
      cout<<" 2. DISPLAY ALL PRODUCTS ";
      gotoxy(36,8);
      cout<<" 3. QUERY ";
      gotoxy(32,10);
      cout<<" 4. MODIFY PRODUCT ";
      gotoxy(32,12);
      cout<<" 5. DELETE PRODUCT ";
      gotoxy(30,14);
      cout<<" 6. VIEW PRODUCT MENU ";
      gotoxy(30,16);
      cout<<" 7. BACK TO MAIN MENU ";
      gotoxy(36,18);
      cout<<" 8. EXIT ";
      gotoxy(25,20);
      cout<<" Please Enter Your Choice (1-7) ";
      ch2=getche();
      switch(ch2)
      {
        case '1' :
        clrscr();
                    write_product();
                    break;
        case '2' :
                    display_all();
                    break;
        case '3' :
                    int num;
                    clrscr();
                    cout<<"\n\n Please Enter The Product No.";
                    cin>>num;
                    display_sp(num);
                    break;
        case '4' :
                    modify_product();
                    break;
        case '5' :
                    delete_product();
                    break;
        case '6' :
                    menu();
                    getch();
        case '7' :
                    break;
        case '8' :
                    exit(0);
                    break;
        default:
                    cout<<"\a";
                    admin_menu();
      }
    }
void main()
{
    char ch;
    intro();
    do{
      clrscr();
      box();
      gotoxy(34,2);
      cout<<" MAIN MENU ";
      gotoxy(32,4);
      cout<<" 01. CUSTOMER";
      gotoxy(30,6);
      cout<<" 02. ADMINISTRATOR";
      gotoxy(34,8);
      cout<<" 03. EXIT";
      gotoxy(25,20);
      cout<<" Please Select Your Option (1-3) ";
      ch=getche();
      switch(ch)
      {
        case '1' :
                  clrscr();
                  place_order();
                  break;
        case '2' :
                  admin_menu();
                  break;
        case '3' :
                  exit(1);
                  break;
        default:
                  cout<<"alert:wrong choice";
                  break;
      }
    }
    while(ch!='3');
}
