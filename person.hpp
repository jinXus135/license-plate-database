//
//  person.hpp
//  rengineered app
//
//  Created by Anthony on 5/6/19.
//  Copyright © 2019 Anthony. All rights reserved.
//
#pragma once
#ifndef person_hpp
#define person_hpp

#include <stdio.h>

#endif /* person_hpp */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class person
{
private:
    int ID;
    string name;
    string phone;
    vector<string> plate;
    
public:
    //getters
    int getID (){return ID;}
    string getName(){return name;}
    string getPhone(){return phone;}
    vector<string> getPlate(){ return plate;}
   
    //setters
    void setID( int idvalue){ID = idvalue;}
    void setName(string value){ name = value;}
    void setPhone(string value){ phone = value;}
    void setPlate(string pvalue) {plate.push_back(pvalue); }
    void setplate(vector<string> pvalue) { plate = pvalue ;}
   /* void printVector(vector<string> plate)
    {
     
        for (int i = 0 ; i < plate.size(); i++)
        {
            cout<< plate[i]<<endl;
        }
    }*/
        
       
        
    
                  person (int idvalue = 0 , string namevalue = "no name" , string phonevalue = "000000000", vector<string> pvalue = {"none"})
    {
        setID(idvalue);
        setName(namevalue);
        setPhone(phonevalue);
        setplate(pvalue);
    }
    ~person(){};
        
      /*  ostringstream plist;
        for(int i = 0 ; i<plate.size(); i++)
        {
            plist<< plate.at(i)<< " ";
        }*/
            
      
    string objstring(string msg = " ")
    {
       ostringstream sout;
        sout << msg << " person [ ID: "<< getID()<< ", name: "<< getName() << ", phone number: "<< getPhone()<<", plate values: "<< printvector()<< ", this: " << this<< " ]";
        return sout.str();
    }
                  string printvector()
                  {
                      ostringstream sout;
                      if (plate.size() == 0)
                          return " ";
                      for (int i = 0; i <plate.size(); i++)
                      {
                          sout << plate[i]<<", ";
                      }
                      return sout.str();
                  }
                      
                  
};
    
   

