//
//  clusterMap.hpp
//  rengineered app
//
//  Created by Anthony on 5/6/19.
//  Copyright © 2019 Anthony. All rights reserved.
//
#pragma once
#ifndef clusterMap_hpp
#define clusterMap_hpp

#include <stdio.h>
#include <map>
#endif /* clusterMap_hpp */
#include "person.hpp"
class ClusterMap
{
private:
    vector <person> vp;
    map<int, int> mapID;
    map <string , int>  mapName;
    map<string, int> mapPhone;
    map<string, int> mapPlate;

public:
    ClusterMap() {};
    void add(person P) {
       // add person to vector
        vp.push_back(P);
       
        // update maps
        int pos = vp.size()-1;
        mapID[P.getID()] = pos;
        mapName[P.getName()] = pos;
        mapPhone [P.getPhone()] = pos;
        vector<string> pvalue = P.getPlate();
        for (int i = 0; i < pvalue.size(); i++)
        {
            mapPlate[pvalue[i]] = pos;
        }
      
    }
    
    void showChronologicalOrder()
    {
        cout<< "ClusterMap in chronological order:\n ";
        for (int i =0; i < vp.size(); i++)
        {
            cout<< i << " : "<< vp[i].objstring() << endl;
            cout << "\n Map: mapID \n";
        }
            for (auto row : mapID)
            {
                cout<< row.first << "..."<< row.second<<endl;
            }
            
        
    }
    
    void showAllByID()
    {
    cout<< "ClusterMap in ID order:\n ";
        for (auto row: mapID)
            {
                int pos = row.second ;
               // person p = vp[pos];
                cout<< pos << " : "<< vp[pos].objstring()<<endl;
                cout << "\n Map: mapID \n";
            }
                for (auto row : mapID)
                {
                    cout<< row.first << "..."<< row.second<<endl;
                }
                
            
    }
    void showAllByPhone()
    {
        cout<< "ClusterMap in Phone order:\n ";
        for (auto row: mapPhone)
        {
        int pos = row.second;
        cout<< pos<< " : "<<vp[pos].objstring()<<endl;
        cout << "\n Map: mapPHone \n";
        }
            for (auto row : mapPhone)
            {
            cout<< row.first << "..."<< row.second<<endl;
            }
        
    }
    void showAllByPlate()
     {
     cout<< "ClusterMap in Plate order:\n ";
     for (auto row: mapPlate)
     {
         int pos = row.second;
         cout<<pos << " : "<< vp[pos].objstring();
         cout << "\n Map: mapPlate \n";
     }
         for (auto row : mapPlate)
            {
                cout<< row.first << "..."<< row.second<<endl;
            }
        
     }
    
    void showAllByName()
    {
    cout<< "ClusterMap in Name order:\n ";
    for (auto row: mapName)
        {
        int pos = row.second;
        cout<< pos << " : "<<  vp[pos].objstring()<<endl;
        cout << "\n Map: mapName \n";
        }
            for (auto row : mapName)
            {
                cout<< row.first << "..."<< row.second<<endl;
            }
        
    }
    int showerpersonbyID( int pId)
    {
        if (mapID.count(pId) ==1)
        {
            int pos = mapID[pId];
           
            cout << pos<< " : "<< vp[pos].objstring()<< endl;
        }
        else {
            cout << pId<< " - person not found"<< endl;
           }
   return -1;
    }
   
    int showpersonbyPhone(string phone)
    {
        if(mapPhone.count(phone) == 1)
        {
            int pos = mapPhone[phone];
           
            cout<<pos<<" : "<<vp[pos].objstring()<<endl;
        }
        else
        {
            cout<< phone << " - phone not found "<<endl;
        }
        return -1;
    }
    int showpersonbyName(string name)
    {
        if (mapName.count(name)==1)
        {
            int pos = mapName[name];
           
            cout << pos << " : "<<vp[pos].objstring()<< endl;
        }
        else
        {
            cout<< name <<" - name not found "<<endl;
        }
        return -1;
    }
    
    int showpersonbyplate(string plate)
    {
        if (mapPlate.count(plate)==1)
        {
            int pos = mapPlate[plate];
           
            cout << pos << " : "<<vp[pos].objstring()<< endl;
        }
        else
        {
            cout<< plate <<" - plate not found "<<endl;
        }
        return -1;
    }
bool deletePerson(int pId)
    {
        if (mapID.count(pId) == 0)
            return false;
        int pos = mapID[pId];
        person p = vp[pos];
        // cleanup the maps
        mapID.erase(p.getID());
        mapName.erase(p.getName());
        mapPhone.erase(p.getPhone());
      
        vector<string>pvalue = p.getPlate();
        for (int i = 0; i < pvalue.size(); i++)
        {
            mapPlate.erase(pvalue[i]);
        }
      
        // logically 'delete' vector entry
        p.setID(-1*pId);
        p.setName(" DELETED ");
        p.setPhone (" DELETED ");
        vector<string> platedelete = { "deleted" };
        p.setplate(platedelete);
        for (int i = 0; i< vp.size();i++)
        {
            if (p.getID() == pId)
            {
            vp.erase(vp.begin()+(i-1));
            }
        }
        return true;
    }

/*void showAllByPlate()
{
    cout<< "ClusterMap in Plate order:\n ";
    for (auto row: mapPlate)
    {
        int pos = row.second ;
        person p = vp[pos];
        cout<< pos << " : "<< p.objstring()<<endl;
        
    }
    cout << "\n Map: mapPlate \n";
    for (auto row : mapPlate)
    {
        cout<< &row.first << "..."<< row.second<<endl;
    }
   
}*/
    void addPlate(int pId, string plate)
    {
        if (mapID.count(pId) == 0)
        {
            cout << pId << "- Person Not Found\n" <<endl;
            return;
        }
        
        int pos = mapID[pId];
      
        person p = vp[pos];
        vector<string> pvalue = p.getPlate();
        for (int i = 0; i < pvalue.size(); i++)
        {
            if (pvalue[i] == plate)
                mapPlate.erase(pvalue[i]);
        }
        p.setPlate(plate);
       
        mapPlate[plate] = pos;
        vp[pos] = p;
        
        
    }
    
    void destroyPlate(string plate)
    {
       if (mapPlate.count(plate) == 0)
           cout<< plate << "not found";
        
        int pos = mapPlate[plate];
        person p = vp[pos];
        vector<string> pvalue = p.getPlate();
        for (int i = 0; i < pvalue.size(); i++)
        {
            if (pvalue[i] == plate)
            {
                mapPlate.erase(pvalue[i]);
                pvalue.erase(remove(pvalue.begin(), pvalue.end(),plate), pvalue.end());
            }
        }
       
        p.setplate(pvalue);
        vp[pos] = p;
       
    }

    void showDataBase()
{
    cout<< " DATABASE "<<endl;
    for (int i =0 ; i < vp.size(); i++)
        cout << i << " : " << vp[i].objstring()<<endl<<endl;
    
    
    cout << " \n Map : MapID \n";
    for (auto row : mapID)
    cout << row.first<< "..."<< row.second<<endl<<endl;
    
    cout << " \n Map : MapName \n";
    for (auto row : mapName)
        cout << row.first<< "..."<< row.second<<endl<<endl;
    
    cout << " \n Map : MapPhone \n";
    for (auto row : mapPhone)
        cout << row.first<< "..."<< row.second<<endl<<endl;
    
    cout << " \n Map : MapID \n";
    for (auto row : mapPlate)
        cout << row.first<< "..."<< row.second<<endl<<endl;
    
}
};
