#pragma once
#include <string>
#include <fstream>
#include "../ultils/list.h"
#include "school.h"
class Student{
private:
  string name;
  float score;
  List<string> list;
  bool enroll;
public:
  Student(){
    name="";
    score=0;
    enroll=false;
  };
  Student(string file){
    enroll=false;
    ifstream fin(file.c_str());
    getline(fin,name,'\n');
    fin>>score;
    string space;
    getline(fin,space);
    string temp;
    while(getline(fin,temp,'\n')){
      list.pushBack(temp);
    }
    fin.close();
  };
  void setEnrollState(bool x){
    enroll=x;
  };
  bool enrollable(){
    return !enroll && !list.isEmpty();
  };
  string topPrefer(){
    return list.valueAt(0);
  };
  string getName(){
    return name;
  };
  float getScore(){
    return score;
  };
  List<string> getPreference(){
    return list;
  };
  void removeTopPrefer(){
    list.popFront();
  };
  friend ostream& operator<<(ostream& os, Student& s){
    os<<"\tName:\t"<<s.name<<"\tScore:\t"<<s.score<<endl;
    os<<"\tPreferences\t: ";
    s.list.show();
  };
  bool operator <(const Student& s) {
         if(score < s.score) {
            return true;
         }
         return false;
  }
  bool operator >(const Student& s) {
         if(score > s.score) {
            return true;
         }
         return false;
  }
  bool operator ==(const Student& s) {
         if(score == s.score) {
            return true;
         }
         return false;
  }
  bool operator <=(const Student& s) {
         if(score <= s.score) {
            return true;
         }
         return false;
  }
  bool operator >=(const Student& s) {
         if(score >= s.score) {
            return true;
         }
         return false;
  }
};
