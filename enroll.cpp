#include <iostream>
#include "ultils/list.h"
#include "ultils/stack.h"
#include "object/school.h"
#include <string>
#include <fstream>

using namespace std;

//Doc du lieu tu files

void setupList(List<Student> &student,List<School> &school){
  List<string> studentFiles,schoolFiles;
  ifstream fin1("data/stlocate.txt"),fin2("data/sclocate.txt");
  string temp;
  while(getline(fin1,temp,'\n')){
    studentFiles.pushBack(temp);
  }
  while(getline(fin2,temp,'\n')){
    schoolFiles.pushBack(temp);
  }

  for(int i=0;i<studentFiles.length();i++){
    Student a(studentFiles.valueAt(i));
    student.pushBack(a);
  }
  for(int i=0;i<schoolFiles.length();i++){
    School a(schoolFiles.valueAt(i));
    school.pushBack(a);
  }
};

//Kiem tra xem tat ca hoc sinh con duoc dang ky ko

bool enrollComplete(List<Student> student){
  for(int i=0;i<student.length();i++){
    if(student.valueAt(i).enrollable()){
        return false;
    }
  }
  return true;
};

// Loai bo truong dau tien khoi danh sach uu tien

void removePrefer(List<Student> &list,Student t){
  for(int i=0;i<list.length();i++){
    if(list.valueAt(i).getName()==t.getName()){
      t.setEnrollState(false);
      t.removeTopPrefer();
      list.change(i,t);
      break;
    }
  }

};

//Mot vong dang ky cua hoc sinh

void startRegisted(List<Student> &studentList,List<School> &schoolList){

  for(int i=0;i<studentList.length();i++){
    Student tempStudent=studentList.valueAt(i);

    //Neu hoc sinh van duoc dang ky thi tiep tuc dang ky
     if(tempStudent.enrollable()){

       for(int j=0;j<schoolList.length();j++){
         School tempSchool=schoolList.valueAt(j);
         if((tempSchool.getName() == tempStudent.topPrefer())){
           Student t=tempSchool.addStudent(tempStudent);

            tempStudent.setEnrollState(true);
           if(t.getName()!=""){
            //Neu hoc sinh ko duoc nhan vao
             studentList.change(i,tempStudent);
             removePrefer(studentList,t);
           }else{
            //Neu duoc nhan vao
             studentList.change(i,tempStudent);
           }

           schoolList.change(j,tempSchool);
           break;

         }
       }
     }

  }
};
int main(){
  List<Student> studentList;
  List<School> schoolList;
  setupList(studentList,schoolList);
  while(!enrollComplete(studentList)){
    startRegisted(studentList,schoolList);
    cout<<endl;
  }
  studentList.show();
  schoolList.show();
  return 0;
};
