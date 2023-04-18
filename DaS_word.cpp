#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;
struct record_word{
    int serialNumber;
    string word;
    string partOfSpeech;
    short int LetterCount;
};

int main(){
    vector<record_word>paragraph;
    ifstream paragraph_word_file("word.csv");
    //Note that if you initialize an ifstream object with a filename, 
    //you do not need to call the open() function to open the file.
    // The ifstream constructor will attempt to open the file for you, 
    //and if the file cannot be opened, an error flag will be set.
    if(!paragraph_word_file.is_open()){
        cout<<"Error!! openning file!!"<<endl;
        return(1);
    }
    string line;
    while(getline(paragraph_word_file,line)){
        static bool skip = true;
        if(skip){
            skip = false;
            continue;
        }
        stringstream ss(line);
        //So, the return type of a std::stringstream object depends on how you use it. 
        //If you write data to the stringstream, the result is a std::string. 
        //If you read data from the stringstream, the type of the data that you extract 
        //depends on the type of the variable that you are extracting into
        string word;
        vector<string>con_word;
        //getting data from each line and storing it in con_word vector of string..
        while(getline(ss,word,',')){
            con_word.push_back(word);
        }
        record_word para_word;
        //populating the structure variable para_word..
        para_word.serialNumber = stoi(con_word[0]);
        para_word.word = con_word[1];
        para_word.partOfSpeech = con_word[2];
        para_word.LetterCount = stoi(con_word[3]);
        //pushing the populated structure to vector of structure type..
        paragraph.push_back(para_word);

    }

    cout<<paragraph[10].serialNumber<<"\n";
    cout<<paragraph[10].word<<"\n";
    cout<<paragraph[10].partOfSpeech<<"\n";
    cout<<paragraph[10].LetterCount<<"\n";
    paragraph_word_file.close();
}