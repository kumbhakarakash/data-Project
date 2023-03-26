#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
struct record{
    string studentID;
    string name;
    string gender;
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
        string word;
        vector<string>con_word;
        while(getline(ss,word,',')){
            con_word.push_back(word);
        }
        record student;
        //here we are populating structure datatype--student
        student.studentID = con_word[0];
        student.name = con_word[1];
        student.gender = con_word[2];
        student.day = stoi(con_word[3]);
        student.month = con_word[4];
        student.homecity = con_word[5];
        student.math = stof(con_word[6]);
        student.phy = stof(con_word[7]);
        student.chem = stof(con_word[8]);
        student.total = stof(con_word[9]);
        //this create a vector of records taking each word from each line 
        student_record.push_back(student);

    }
    cout<<student_record[29].math;
    student_score_file.close();

    return 0;
}