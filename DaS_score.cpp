#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>

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
bool extractData(string source_file,vector<record> &student_record){//funtion that will extract data from source file to a vector...
    ifstream student_score_file(source_file);
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
        //these are updating structure from the data from con_word
        student.studentID = con_word[0];
        student.name = con_word[1];
        student.gender = con_word[2].c_str()[0];
        student.day = stoi(con_word[3]);
        student.month = con_word[4];
        student.homecity = con_word[5];
        student.math = stof(con_word[6]);
        student.phy = stof(con_word[7]);
        student.chem = stof(con_word[8]);
        student.total = stof(con_word[9]);
        //this will store individual record into vector student_record
        student_record.push_back(student);

    }
    return 0;
}

int main(){
    vector<record>student_record;                      
    extractData("score.csv", student_record);
    //at this level we have our data inside vector named student_record....
    //now we can utilize those data to extract different information....
    int Mcount = 0,Fcount = 0,Tcount = 0;
    for(int i = 0; i < student_record.size(); i++){
        if(student_record[i].gender == 'M'){
            Mcount = Mcount + 1;
            Tcount = Tcount + 1;
        }
        else{
            Fcount = Fcount + 1;
            Tcount = Tcount + 1;
        }
    }
    cout<<"MaleStudent="<<Mcount<<"\n"<<"FemaleStudent="<<Fcount<<"\n"<<"TotalStudent="<<Tcount<<"\n";
    return 0;
}
