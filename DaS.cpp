//though I have created here struct but I am not using it now
//this code is taking data from "score.csv" file and without storing it in any container it directly output streaming to console


#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
struct record{
    string studentID;
    string name;
    char gender;
    short int day;
    string month;
    string homecity;
    float math;
    float phy;
    float chem;
    float total;
};

int main(){
    vector<record>student_record;
    ifstream student_score_file("score.CSV");
    if(!student_score_file.is_open()){
        cerr<<"Error!! Openning file!!"<<endl;
        return 1;
    }
    string line;
    while(getline(student_score_file, line)){
        static bool skip = true;
        if(skip){
            skip = false;
            continue;
        }
        stringstream ss(line);
        record student;
        string word;
        while(getline(ss,word,',')){
            cout<<word<<" ";
        }
        cout<<endl;

    }
    student_score_file.close();

    return 0;
}
