//
//  project2_vva_connections.cpp
//  project2_vva_connections
//
//  Created by Elizabeth Doyle on 4/9/19.
//  Copyright © 2019 Elizabeth Doyle. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <string>
using namespace std;

class temp{
public:
    int names[54] = {100};
};


temp readChapters(string fileName, map<string,int> &charKey){
    temp tempInfo;
    fill_n(tempInfo.names, 54, 100);    //SET ALL ARRAY VALUES TO 100 TO KNOW WHAT IS NULL
    fstream currentFile;
    currentFile.open(fileName);
    if(currentFile.is_open()){
        string chapter = "";
        while (!currentFile.eof()){
            string line;
            currentFile >> line;
            chapter = chapter + " " + line;
        };
        
        //cout << "\n chapter: \n\n" + chapter;

        int namesListCount = 0;
        map<string, int>::iterator itr;
        for (itr = charKey.begin(); itr != charKey.end(); ++itr) {
            size_t found = chapter.find(itr->first);
            if (found != string::npos){
                //cout << "\nFound: " + itr->first +" " + to_string(itr->second);
                tempInfo.names[namesListCount] = itr->second;        //adds the number of that person to the list
                namesListCount++;
            };
        };
        
    } else {
        cout<<"\n\nFILE NOT OPEN";
    }
    currentFile.close();
    return tempInfo;
};


void readBook(string fileName, map<string,int> &charKey, string chapterNames[]){
    //--- CREATE MATRIX
    int baseMatrix[54][54];
    
    for(int i=0; i<54; i++){ //setting all values to 0
        for(int j=0; j<54; j++){
            baseMatrix[i][j] = 0;
        }
    }
    //--- GET OTHER ITEMS READY
    temp tempInfo;
    fill_n(tempInfo.names, 54, 100);    //SET ALL ARRAY VALUES TO 100 TO KNOW WHAT IS NULL
    
    //--- READ THE FILE
    fstream currentFile;
    currentFile.open(fileName);
    if(currentFile.is_open()){
        int chaptItr = 1;
        string chapter = "";
        while (!currentFile.eof()){
            string line;
            currentFile >> line;
            if(line==chapterNames[chaptItr]){
                //-- beginning of new chapter
                //cout<< "\n"+chapterNames[chaptItr-1]+"\n";
                //cout << "\n chapter: \n\n" + chapter;
            
                //-- search for names in previous chapter
                int namesListCount = 0;
                map<string, int>::iterator itr;
                for (itr = charKey.begin(); itr != charKey.end(); ++itr) {
                    size_t found = chapter.find(itr->first);
                    if (found != string::npos){
                     //   cout << "\nFound: " + itr->first +" " + to_string(itr->second);
                        tempInfo.names[namesListCount] = itr->second;        //adds the number of that person to the list
                        namesListCount++;
                    };
                };
                
                //---- UPDATE MATRIX
                for(int i=0; i<54; i++){
                    if(tempInfo.names[i]==100){
                        break;
                    };
                    for(int j=0; j<54; j++){
                        if(tempInfo.names[j]==100){
                            break;
                        };
                        if(j!=i){
                            baseMatrix[tempInfo.names[i]][tempInfo.names[j]] += 1;
                        }
                    };
                };
                
                //-- reset for next chapter
                chapter = "";
                chaptItr++;
                fill_n(tempInfo.names, 54, 100);  //resent found names values
            } else {
                chapter = chapter + " " + line;
            };
        };

        
    } else {
        cout<<"\n\nFILE NOT OPEN";
    }
    currentFile.close();
    
    //--- print matrix
    for(int i=0; i<54; i++){
        cout<<"[";
        for(int j=0; j<54; j++){
            if(j==53){
                cout<<baseMatrix[i][j]<<"],\n";
            }else{
                cout<<baseMatrix[i][j]<<", ";
            };
        };
        
    };
    
};


void book2(map<string,int> &charKey, int baseMatrix[54][54]){
    
    //--- CHECK THE FILES
    
    string book1Chapters[] =
    {"/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_prologue.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_1_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_2_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_3_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_4_BRAN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_5_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_6_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_7_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_8_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_9_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_10_DAVOS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_11_THEON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_12_DAENERYS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_13_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_13_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_14_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_15_BRAN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_16_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_17_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_18_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_19_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_20_BRAN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_21_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_22_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_23_THEON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_24_TYREON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_25_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_26_DAENERYS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_27_BRAN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_28_TYREON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_29_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_30_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_31_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_32_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_33_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_34_BRAN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_35_TYREON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_36_THEON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_37_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_38_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_39_DAENERYS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_40_TYREON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_41_DAVOS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_42_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_43_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_44_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_45_BRAN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_46_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_47_DAENERYS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_48_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_49_THEON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_50_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_51_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_52_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_53_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_54_CATELYN.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_55_THEON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_56_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_57_DAVOS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_58_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_59_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_60_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_61_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_62_DAENERYS.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_63_ARYA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_64_SANSA.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_65_THEON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_67_TYRION.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_68_JON.txt",
        "/Users/Brooke/Desktop/book_chapters/book2 Class of Kings/book1_69_BRAN.txt"};
    
    for(int chapter=0; chapter<70; chapter++){
        
        temp returnedNames;
        returnedNames = readChapters(book1Chapters[chapter], charKey);
        
        //---- UPDATE MATRIX
        for(int i=0; i<54; i++){
            if(returnedNames.names[i]==100){
                break;
            };
            for(int j=0; j<54; j++){
                if(returnedNames.names[j]==100){
                    break;
                };
                if(j!=i){
                    baseMatrix[returnedNames.names[i]][returnedNames.names[j]] += 1;
                }
            };
        };
    };
    
    //----PRINT MATRIX
    
    for(int i=0; i<54; i++){
        cout<<"[";
        for(int j=0; j<54; j++){
            if(j==53){
                cout<<baseMatrix[i][j]<<"],\n";
            }else{
                cout<<baseMatrix[i][j]<<", ";
            };
        };
        
    };
    
};


int main() {
    
    //----- define characters and their number in the list
    map<string,int> charKey;
    
    charKey.insert(pair<string,int>("Tyrion",0));
    charKey.insert(pair<string,int>("Eddard",1));
    charKey.insert(pair<string,int>("Robert",2));
    charKey.insert(pair<string,int>("Jaime",3));
    charKey.insert(pair<string,int>("Catelyn",4));
    charKey.insert(pair<string,int>("Cersei",5));
    charKey.insert(pair<string,int>("Daenerys",6));
    charKey.insert(pair<string,int>("Jorah",7));
    charKey.insert(pair<string,int>("Viserys",8));
    charKey.insert(pair<string,int>("Jon",9));
    charKey.insert(pair<string,int>("Sansa",10));
    charKey.insert(pair<string,int>("Arya",11));
    charKey.insert(pair<string,int>("Robb",12));
    charKey.insert(pair<string,int>("Theon",13));
    charKey.insert(pair<string,int>("Brandon",14));
    charKey.insert(pair<string,int>("Joffrey",15));
    charKey.insert(pair<string,int>("Sandor",16));
    charKey.insert(pair<string,int>("Khal",17));
    charKey.insert(pair<string,int>("Petyr",18));
    charKey.insert(pair<string,int>("Davos",19));
    charKey.insert(pair<string,int>("Samwell",20));
    charKey.insert(pair<string,int>("Stannis",21));
    charKey.insert(pair<string,int>("Melisandre",22));
    charKey.insert(pair<string,int>("Jeor",23));
    charKey.insert(pair<string,int>("Bronn",24));
    charKey.insert(pair<string,int>("Varys",25));
    charKey.insert(pair<string,int>("Shae",26));
    charKey.insert(pair<string,int>("Margaery",27));
    charKey.insert(pair<string,int>("Tywin",28));
    charKey.insert(pair<string,int>("Ygritte",29));
    charKey.insert(pair<string,int>("Gendry",30));
    charKey.insert(pair<string,int>("Tormund",31));
    charKey.insert(pair<string,int>("Brienne",32));
    charKey.insert(pair<string,int>("Ramsay",33));
    charKey.insert(pair<string,int>("Gilly",34));
    charKey.insert(pair<string,int>("Daario",35));
    charKey.insert(pair<string,int>("Missandei",36));
    charKey.insert(pair<string,int>("Ellaria",37));
    charKey.insert(pair<string,int>("Tommen",38));
    charKey.insert(pair<string,int>("Jaqen",39));
    charKey.insert(pair<string,int>("Roose",40));
    charKey.insert(pair<string,int>("High Sparrow",41));
    charKey.insert(pair<string,int>("Hodor",42));
    charKey.insert(pair<string,int>("Gregor",43));
    charKey.insert(pair<string,int>("Lancel",44));
    charKey.insert(pair<string,int>("Myrcella",45));
    charKey.insert(pair<string,int>("Maester",46));
    charKey.insert(pair<string,int>("Loras",47));
    charKey.insert(pair<string,int>("Podrick",48));
    charKey.insert(pair<string,int>("Grey",49));
    charKey.insert(pair<string,int>("Olenna",50));
    charKey.insert(pair<string,int>("Olly",51));
    charKey.insert(pair<string,int>("Mace",52));
    charKey.insert(pair<string,int>("Waif",53));
    
    //---PRINT THE KEYS

    /*
     map<string, int>::iterator itr;
     for (itr = charKey.begin(); itr != charKey.end(); ++itr) {
     cout << '\t' << itr->first
     << '\t' << itr->second << '\n';
     }
     cout << endl;
     */
    
    //--- CREATE MATRIX
     int baseMatrix[54][54];

     for(int i=0; i<54; i++){ //setting all values to 0
         for(int j=0; j<54; j++){
             baseMatrix[i][j] = 0;
         }
     }
    
    string book1Chapters[73] = {"PROLOGUE",    "BRAN",    "CATELYN",    "DAENERYS",    "EDDARD",    "JON",    "CATELYN",    "ARYA",    "BRAN",    "TYRION",    "JON",    "DAENERYS",    "EDDARD",    "TYRION",    "CATELYN",    "SANSA",    "EDDARD",    "BRAN",    "CATELYN",    "JON",    "EDDARD",    "TYRION",    "ARYA",    "DAENERYS",    "BRAN",    "EDDARD",    "JON",    "EDDARD",    "CATELYN",    "SANSA",    "EDDARD",    "TYRION",    "ARYA",    "EDDARD",    "CATELYN",    "EDDARD",    "DAENERYS",    "BRAN",    "TYRION",    "EDDARD",    "CATELYN",    "JON",    "TYRION",    "EDDARD",    "SANSA",    "EDDARD",    "DAENERYS",    "EDDARD",    "JON",    "EDDARD",    "ARYA",    "SANSA",    "JON",    "BRAN",    "DAENERYS",    "CATELYN",    "TYRION",    "SANSA",    "EDDARD",    "CATELYN",    "JON",    "DAENERYS",    "TYRION",    "CATELYN",    "DAENERYS",    "ARYA",    "BRAN",    "SANSA",    "DAENERYS",    "TYRION",    "JON",    "CATELYN",    "DAENERYS"};
    
    string book3Chapters[82] = {"PROLOGUE",    "JAIME",    "CATELYN",    "ARYA",    "TYRION",    "DAVOS",    "SANSA",    "JON",    "DAENERYS",    "BRAN",    "DAVOS",    "JAIME",    "TYRION",    "ARYA",    "CATELYN",    "JON",    "SANSA",    "ARYA",    "SAMWELL",    "TYRION",    "CATELYN",    "JAIME",    "ARYA",    "DAENERYS",    "BRAN",    "DAVOS",    "JON",    "DAENERYS",    "SANSA",    "ARYA",    "JON",    "JAIME",    "TYRION",    "SAMWELL",    "ARYA",    "CATELYN",    "DAVOS",    "JAIME",    "TYRION",    "ARYA",    "BRAN",    "JON",    "DAENERYS",    "ARYA",    "JAIME",    "CATELYN",    "SAMWELL",    "ARYA",    "JON",    "CATELYN",    "ARYA",    "CATELYN",    "ARYA",    "TYRION",    "DAVOS",    "JON",    "BRAN",    "DAENERYS",    "TYRION",    "SANSA",    "TYRION",    "SANSA",    "JAIME",    "DAVOS",    "JON",    "ARYA",    "TYRION",    "JAIME",    "SANSA",    "JON",    "TYRION",    "DAENERYS",    "JAIME",    "JON",    "ARYA",    "SAMWELL",    "JON",    "TYRION",    "SAMWELL",    "JON",    "SANSA",    "EPILOGUE"};
    
    string book4Chapters[46] = {"PROLOGUE",    "PROPHET",    "CAPTAIN",    "CERSEI",    "BRIENNE",    "SAMWELL",    "ARYA",    "CERSEI",    "JAIME",    "BRIENNE",    "SANSA",    "KRAKEN’S",    "CERSEI",    "SOILED",    "BRIENNE",    "SAMWELL",    "JAIME",    "CERSEI",    "IRON",    "DROWNED",    "BRIENNE",    "QUEENMAKER",    "ARYA",    "ALAYNE",    "CERSEI",    "BRIENNE",    "SAMWELL",    "JAIME",    "CERSEI",    "REAVER",    "JAIME",    "BRIENNE",    "CERSEI",    "JAIME",    "CANALS",    "SAMWELL",    "CERSEI",    "BRIENNE",    "JAIME",    "CERSEI",    "PRINCESS",    "ALAYNE",    "BRIENNE",    "CERSEI",    "JAIME",    "SAMWELL"};
    
    
    string book5Chapters[73] = {"PROLOGUE",    "TYRION",    "DAENERYS",    "JON",    "BRAN",    "TYRION",    "MERCHANT’S",    "JON",    "TYRION",    "DAVOS",    "JON",    "DAENERYS",    "REEK",    "BRAN",    "TYRION",    "DAVOS",    "DAENERYS",    "JON",    "TYRION",    "DAVOS",    "REEK",    "JON",    "TYRION",    "DAENERYS",    "LOST",    "WINDBLOWN",    "WAYWARD",    "TYRION",    "JON",    "DAVOS",    "DAENERYS",    "MELISANDRE",    "REEK",    "TYRION",    "BRAN",    "JON",    "DAENERYS",    "WINTERFELL",    "WATCHER",    "JON",    "TYRION",    "TURNCLOAK",    "KING’S",    "DAENERYS",    "JON",    "BLIND",    "WINTERFELL",    "TYRION",    "JAIME",    "JON",    "DAENERYS",    "THEON",    "DAENERYS",    "JON",    "CERSEI",    "THE QUEENSGUARD",    "THE IRON SUITOR",    "TYRION",    "JON",    "THE DISCARDED KNIGHT",    "THE SPURNED SUITOR",    "REBORN",    "SACRIFICE",    "VICTARION",    "UGLY",    "CERSEI",    "TYRION",    "KINGBREAKER",    "DRAGONTAMER",    "JON",    "QUEEN’S",    "DAENERYS",    "EPILOGUE"};
    
    //--- GET MATRIX OF BOOKS
   /* cout<<"\n\n\n\nBOOK 1: \n\n";
    readBook("/Users/Brooke/Desktop/book_chapters/A Game Of Thrones - George RR Martin.txt", charKey, book1Chapters);
    
    cout<<"\n\n\n\nBOOK 2: \n\n";
    book2(charKey, baseMatrix);
    
    cout<<"\n\n\n\nBOOK 3: \n\n";
    readBook("/Users/Brooke/Desktop/book_chapters/A Storm of Swords - George RR Martin.txt", charKey, book3Chapters);

    cout<<"\n\n\n\nBOOK 4: \n\n";
    readBook("/Users/Brooke/Desktop/book_chapters/A Feast For Crows - George RR Martin.txt", charKey, book4Chapters);
        */
    cout<<"\n\n\n\nBOOK 5: \n\n";
    readBook("/Users/Brooke/Desktop/book_chapters/A Dance With Dragons - George RR Martin.txt", charKey, book5Chapters);
    
    
    //----PRINT CHARACTER NAMES IN ORDER OF NUMBER
     /*
    for(int x=0; x<54;x++){
        for (itr = charKey.begin(); itr != charKey.end(); ++itr) {
            if(itr->second == x){
                cout <<"\""<< itr->first <<"\""<< ", ";
            };
        };
    };
      */
    
    
    return 0;
    
}




