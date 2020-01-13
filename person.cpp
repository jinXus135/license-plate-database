//
//  person.cpp
//  rengineered app
//
//  Created by Anthony on 5/6/19.
//  Copyright © 2019 Anthony. All rights reserved.
//

#include "person.hpp"
#include "clusterMap.hpp"
int main()
{
    int input=-1;
   /* cout<< " enter option \n ";
    cout<<"--------------------------------------------------"<< endl;
    cout<<" 0 end \n 1 show chronological order \n 2 show all by ID \n 3 add person \n 4 delete person \n 5 find person by ID \n";
    cout<<"--------------------------------------------------"<<endl;
    cin>> input;*/
    //making the person database
    ClusterMap c;
    c.add (person (333, "name333", "3106998325",{"555GGG", "777yyy"}));
    c.add (person (222, "name222", "3106998326",{"FGT457"}));
    c.add (person (555, "name555", "3106998327", {"DFH678"}));
    c.add (person (111, "name111", "3106998328",{"568thy"}));
    c.add (person (444, "name444", "3106998329", {"HTF575"}));
    

   while (input !=0)
   {
       cout<< " enter option \n ";
       cout<<"--------------------------------------------------"<< endl;
       cout<<" 0 end \n1 show chronological order  \n2 add person \n3 delete person  \n4 show all by phone \n5 show all by plate order \n6 show all by ID\n7 Show all by name \n8 find by Name \n9 find by ID \n10 find by Phone \n11 find person by plate \n12 Add license plate\n13 delete license plate\n14 delete person \n15 show database\n";
       cout<<"--------------------------------------------------"<<endl;
       cin>> input;
       
       switch (input)
    {
        case 1:
        {
            c.showChronologicalOrder();
            break;
        }
  
       
        case 2:
        {
            vector<string> platevector;
            int pId,count;
            string pName, pPhone,pPlate;
            cout<< "Enter ID : ";
            cin>> pId;
            cout<< " Enter Name: ";
            cin.ignore();
            getline(cin, pName);
           
            cout << "enter Phone: ";
            getline(cin, pPhone);
            cout<< "how many plates are being added: ";
            cin>> count;
            for (int i = 0; i < count; i++)
            {
               
                cout<<" enter a plate"<<(i+1)<< ": ";
                cin>> pPlate;
                platevector.push_back(pPlate);
            }
            person p(pId , pName, pPhone, platevector);
            c.add(p);
            break;
        }
        case 0:
        {
            return 0;
        }
        case 9:
        {
            int cid;
            cout<< " ID: search: ";
            cin>> cid;
            c.showerpersonbyID(cid);
            break;
        }
        case 4:
        {
            c.showAllByPhone();
            break;
        }
        case 5:
        {
            c.showAllByPlate();
            break;
        }
        case 8:
        {
            
            cout<< " Name: search: ";
            string name;
            cin>> name;
            c.showpersonbyName(name);
            break;
        }
        case 10:
        {
            string phone;
            cout<< " Phone: search: ";
            cin>>phone;
            c.showpersonbyPhone(phone);
            break;
        }
            
        case 3:
        {
            int pid;
            cout<< "What is the ID of the person you want to delete?\n";
            cin>> pid;
            c.deletePerson(pid);
            break;
        }
        case 12:
        {
            string plate;
            int pid;
            cout<< "enter the ID of the person who is adding a plate\n";
            cin>> pid;
            cout<< "enter a license plate\n";
            cin>> plate;
            c.addPlate(pid, plate);
            break;
        }
        case 13:
        {
            string plate;
            cout<< "enter the license plate to be deleted\n";
            cin>> plate;
            c.destroyPlate(plate);
            break;
        }
        case 6:
        {
            c.showAllByID();
            break;
        }
        case 7:
        {
            c.showAllByName();
            break;
        }
        case 14:
        {
            double id;
            cout<< "enter the persons ID \n";
            cin>> id;
            c.deletePerson(id);
            break;
            
        }
        case 15:
        {
            c.showDataBase();
            break;
        }
        case 11:
        {
            string plate;
            cout<< " Plate: search: ";
            cin>>plate;
            c.showpersonbyplate(plate);
            break;
        }
    }
   
   }

        
// retrieve person by ID

//cout<< "enter an ID: "<<endl;
//cin>> pId;
//c.showerpersonbyID(pId);
    
    //insert a new person object
    /*cout<< "Enter ID : ";
    cin>> pId;
    cout<< " Enter Name: ";
    getline( cin, pName);
    cout << "enter Phone: ";
    getline (cin, pPhone);
    c.add(person(pId, pName, pPhone));*/
   // c.showAllByID();
    
    
    // remove person object from database
   
   
    
    
    
    
  
    
    };
