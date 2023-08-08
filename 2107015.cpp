#include <bits/stdc++.h>
#include<conio.h>
using namespace std;

class Items {
private:
    string name;
    double price;

public:
    Items(){}
    Items(string nam, double p)
        {
            name = nam;
            price = p;
        }

    string getName()const
    {
        return name;
    }

    void setPrice(double p)
    {
        price = p;
    }

    double getPrice()const
    {
        return price;
    }
};

class Menu {
private:
    vector<Items> itemsList;

public:
    void addItem(const Items& item)
    {
        itemsList.push_back(item);
    }

    void displayMenu(){
        cout << "Menu:\n";
        for (size_t i = 0; i < itemsList.size(); i++) {
            cout << i + 1 << ". " << itemsList[i].getName() << " - " << itemsList[i].getPrice() << " TK\n";
        }
    }


    void changeItemPrice( const string& itemName, double newPrice) {
        for (auto& item : itemsList) {
            if (item.getName() == itemName) {
                item.setPrice(newPrice);
                return;
            }
        }
        cout << "Item not found in the menu.\n";
    }



    void addNewItem(const Items& newItem) {
        itemsList.push_back(newItem);
    }

    friend class Waiter;
    friend class Manager;
};

class Waiter {
private:
    vector<Items> orders;
    const Menu& menu;

public:


    Waiter(const Menu& m): menu(m) {

    }

    void takeOrder() {
        int choice;
        cout << "Enter item number to add to order (0 to finish): ";
        cin >> choice;

        while (choice != 0) {
            if (choice > 0 && choice <= menu.itemsList.size()) {
                orders.push_back(menu.itemsList[choice - 1]);
            } else {
                cout << "Invalid item number. Try again.\n";
            }

            cout << "Enter item number to add to order (0 to finish): ";
            cin >> choice;
        }
    }

   friend void displayOrder(Waiter &ob);
};

//friend function
void displayOrder(Waiter &ob) {
	if(ob.orders.size()==0)
	{
		cout <<"No Orders given yet!!"<<endl;
	}
	else{
        double total = 0.0;
        cout << "Order:\n";
        for (const auto& item : ob.orders) {
            cout << item.getName() << " - TK " << item.getPrice() << "\n";
            total += item.getPrice();
        }
        cout << "Total: TK " << total << "\n";
	}
    }

class Manager {
private:
    Menu& menu;

public:
    Manager(Menu& menu) : menu(menu) {}


    void changeItemPrice(const string& itemName, double newPrice) {
        menu.changeItemPrice(itemName, newPrice);
    }


    void addNewItem(const Items& newItem) {
        menu.addNewItem(newItem);
    }
};

int main() {
    Menu obj1;
    obj1.addItem(Items("Pizza", 250));
    obj1.addItem(Items("Burger", 220));
    obj1.addItem(Items("Pasta", 150));

    Waiter waiter(obj1);
    Manager manager(obj1);
    cout << endl<<"\t******* WELCOME TO HOTEL DE GUSTAVO ******* "<<endl;
    cout <<endl<<endl<<endl;
    cout << "Please Enter Your Name: ";
    string cust;
    getline(cin,cust);

    int n;
    system("cls");
    back_to_main:
    cout << "\t---Welcome "<<cust<<" ---"<<endl;
    cout << "How can we help you today? "<<endl;
    do
    {
        cout << "1. I'd like to see the menu."<<endl;
        cout << "2. I'd like to order."<<endl;
		cout << "3. Get the pay receipt."<<endl;
        cout << "4. I am the manager."<<endl;
        cout << "5. Exit "<<endl;

        cin >> n;
        if(n==1)
        {
            obj1.displayMenu();
            cout << "Would you like to place the order?(Y/N): ";
            char or_ch;
            cin >> or_ch;
            if(or_ch =='Y' || or_ch=='y')
            goto order_take;
        }
        else if( n== 2)
        {
            order_take:
            waiter.takeOrder();
            cout <<"Would You like to get the reciept?(Y/N): ";
            char recip;
            cin >> recip;
            if(recip == 'y'||recip == 'Y')
            goto show_order;


        }
		else if(n==3)
		{
            show_order:
            system("cls");
			displayOrder(waiter);
		}
        else if(n == 4)
        {
         char ch;
        do{
            try_again:
            string pass (6,'a');
            cout <<"Enter the password: ";
            for(int i=0 ; i<6; i++)
            {
            pass.at(i) = getch();

            cout<<"*";
            }
            if(pass=="danger"){
            system("cls");
			boss_section:
          cout << " Welcome Mr. "<<cust<<endl;
		  cout <<"\t---*---"<<endl;
          cout << "What do you want to do? "<<endl;
          cout << "a. Add a new item to the menu."<<endl;
          cout << "b. Change the price of an existing item."<<endl;
          cout << "c. Back to main menu."<<endl;

          cin >> ch;

          if(ch == 'a')
          {
            string na;
            double pric;
            cout << "Name: ";
            cin >> na;
            cout <<"price: ";
            cin >> pric;

            manager.addNewItem(Items(na,pric));
            cout << "Successfully added a new Item to the menu!"<<endl;

          }
          else if(ch =='b')
          {
            cout << "Enter the items name: ";
            string na;
            double p;
            cin >> na;
            cout << "The updated price: ";
            cin>> p;
            manager.changeItemPrice(na,p);
            cout <<"Updated price Successfully!"<<endl;

          }
          else if(ch =='c')
          {
            cout<< "Bye Boss!"<<endl;
            system("cls");
            goto back_to_main;
          }
          else{
            cout << "Invaild Option!!!"<<endl;
          }
          cout <<"Do you want to continue?(Y/N): ";
          char res;
          cin >> res;
          if(res == 'n'||res== 'N')
          {
            system("cls");
            goto sesh;
          }
		  else
		  {
				system("cls");
				goto boss_section;
		  }


        }
        else
        {
            cout << "\n\nInvaild Password!!"<<endl;
            cout << "\nDo you want to try again?(Y/N): ";
            char again;
            cin>> again ;
            system("cls");
            if(again == 'y'||again =='Y')
             goto try_again;
            else
            {
                n=5;
            goto sesh;
            }
        }

        }
        while (ch != 'c');


        }
        else if(n==5)
        {

            goto sesh;
        }

        cout << "Do you want to continue?(Y/N): ";
        char take;
        cin >> take;

        if( take == 'n'|| take =='N')
        {

            n = 5;
        }
        else{
            system("cls");
            goto back_to_main;
        }
      sesh:
      system("cls");
      cout <<"Thank You for visiting Hotel De Gustavo!!"<<endl;

    } while (n != 5);


    return 0;
}

