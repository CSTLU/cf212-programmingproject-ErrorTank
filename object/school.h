#pragma once
#include <string>
#include <fstream>
#include "../ultils/list.h"
#include "student.h"
class School{
private:
  string name;
  float require;
  List<Student> list;
  int max;
public:
  School(){
    name="";
    require=0;
    max=0;
  };
  School(string file){
    ifstream fin(file.c_str());
    getline(fin,name,'\n');
    fin>>require;
    fin>>max;
    fin.close();
  };
  string getName(){
    return name;
  };
  float getRequire(){
    return require;
  };
  int getMax(){
    return max;
  };
  List<string> getPreference(){
    List<string> nameOnly;
    for(int i=0;i<list.length();i++){
      nameOnly.pushBack(list.valueAt(i).getName());
    }
    return nameOnly;
  };
  bool isFull(){
    return max==list.length();
  };
  bool hasStudent(string name){
    return list.find(name);
  };
  bool isJoinable(Student x){
    return x.getScore()>=require;
  };

  // Ham Loai hoc sinh
  Student reduceStudent(){
    Student t;
    list.sort(0,list.length()-1);
    if(list.length()>max){
      t=list.topBack();
      list.popBack();
    }
    return t;
  };
  // Them 1 hoc sinh vao , neu hoc sinh do' k du dieu kien thi tra ve hoc sinh do', con lai tra ve ""
  Student addStudent(Student x){
    if(isJoinable(x)){
      list.pushBack(x);
      return reduceStudent();
    }
    return x;
  };

  friend ostream& operator<<(ostream& os, School& s){
    os<<"\tName:\t"<<s.name<<"\tRequire:\t"<<s.require<<"\tMax students:\t"<<s.max<<endl;
    os<<"\tEnroll students\t: ";
    s.getPreference().show();
  };

  bool operator ==(const School& s) {
         if(name == s.name) {
            return true;
         }
         return false;
  }
  bool operator !=(const School& s) {
         if(name != s.name) {
            return true;
         }
         return false;
  }
};
