#include<bits/stdc++.h>
using namespace std;
class inventory {
public:
  vector<tuple<string,int,int>> items;
  void addItem(string item,int quantity,int unitprice) {
    bool found = false;
    for(int i=0;i<items.size();i++) {
      if(get<0>(items[i])==item) {
        found = true;
        break;
      }
    }
    if(!found) {
      items.push_back(make_tuple(item,quantity,unitprice));
      cout<<"Item \""<<item<<"\" added."<<endl;
    }else {
      cout<<"This item already exists."<<endl;
    }
  }
  void removeItem(string item) {
    bool found = false;
    int foundindex = 0;
    for(int i=0;i<items.size();i++) {
      if(get<0>(items[i])==item) {
        found = true;
        foundindex=i;
        break;
      }
    }
    if(found) {
      items.erase(items.begin()+foundindex);
      cout<<"Item \""<<item<<"\" removed."<<endl;
    }else {
      cout<<"This item does not exist."<<endl;
    }
  }
  void updateItem(string item,int quantity) {
    bool found = false;
    int foundindex = 0;
    for(int i=0;i<items.size();i++) {
      if(get<0>(items[i])==item) {
        found = true;
        foundindex=i;
        break;
      }
    }
    if(found) {
      get<1>(items[foundindex])+=quantity;
      cout<<"quantity updated: "<<get<1>(items[foundindex])<<endl;
    }else {
      cout<<"This item does not exist."<<endl;
    }
  }
  void searchItem(string item) {
    bool found = false;
    int foundindex = 0;
    for(int i=0;i<items.size();i++) {
      if(get<0>(items[i])==item) {
        found = true;
        foundindex=i;
        break;
      }
    }
    if(found) {
      cout<<"Item: "<<get<0>(items[foundindex])<<" | Qty: "<<get<1>(items[foundindex])<<" | Price: "<<get<2>(items[foundindex])<<" EGP"<<" | Total: "<<get<1>(items[foundindex])*get<2>(items[foundindex])<<" EGP"<<endl;
    }else {
      cout<<"This item does not found."<<endl;
    }
  }
  void display() {
    for(int i=0;i<items.size();i++) {
      cout<<i+1<<"- Item: "<<get<0>(items[i])<<" | Qty: "<<get<1>(items[i])<<" | Price: "<<get<2>(items[i])<<" EGP"<<" | Total: "<<get<1>(items[i])*get<2>(items[i])<<" EGP"<<endl;
    }
  }
};
  int main() {
    inventory inv;
    string item;
    int quantity,unitprice,option;
    bool v=true;
    while(v) {
      cout<<"=== Inventory Management System ==="<<endl;
      cout<<"1. Add Item\n2. Remove Item\n3. Update Quantity\n4. Search Item\n5. Display Inventory\n6. Exit"<<endl;
      cout<<"choose your option: ";
      cin>>option;
      switch(option) {
        case 1:
          cout<<"Enter item name: ";
          cin>>item;
          cout<<endl;
          cout<<"Enter quantity: ";
          cin>>quantity;
          cout<<endl;
          cout<<"Enter unitprice: ";
          cin>>unitprice;
          inv.addItem(item,quantity,unitprice);
          break;
        case 2:
          cout<<"Enter item name: ";
          cin>>item;
          cout<<endl;
          inv.removeItem(item);
          break;
        case 3:
          cout<<"Enter item name: ";
          cin>>item;
          cout<<endl;
          cout<<"Enter quantity: ";
          cin>>quantity;
          cout<<endl;
          inv.updateItem(item,quantity);
          break;
        case 4:
          cout<<"Enter item name: ";
          cin>>item;
          cout<<endl;
          inv.searchItem(item);
          break;
        case 5:
          inv.display();
          break;
        case 6:
          cout<<"Goodbye!"<<endl;
          v=false;
          break;
        default:
          cout<<"Invalid option!"<<endl;
          break;
      };
    };
    return 0;
  }
