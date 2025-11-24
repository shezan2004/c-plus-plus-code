#include<iostream>
using namespace std;
struct Student {
    string uniqueId;
    int creditsCompleted;
    float cgpa;
    void setInformation(string uniqueId, int creditsCompleted, float cgpa){
           this->uniqueId = uniqueId;
           this->creditsCompleted = creditsCompleted;
           this->cgpa = cgpa;
}
};

int main(){
 Student students[10];
 for (int i = 0; i<3; i++){
    string uniqueId;
     int creditsCompleted;
      float cgpa;
    cout<< "Enter you id : ";
    cin>>uniqueId;
    cout<<"Enter of credits completed : ";
    cin>>creditsCompleted;
    cout<<"Enter cgpa : ";
    cin>>cgpa;
    students[i];
    students[i].setInformation(uniqueId ,creditsCompleted,cgpa);
    
 }
 cout<< " Id of the students with  cgpa>3.75 :"<<endl;
 for(int i =0; i<10; i++){
if(students[i].cgpa >3.75){
    cout<<students[i].uniqueId<<endl;
}
 }
  cout<< " Id of the students with more than 50 credit  : " ;
 for(int i = 0; i<10; i++){
    if(students[i].creditsCompleted>50){  
        cout<<students[i].uniqueId << endl;
    }
 }
 return 0;
}