#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <array>
#include <algorithm>
#include <string>

using namespace std;

bool read_file(char * file_name,vector<string> & w);

int main()
{
    vector<string> words;
    size_t index;
    const char* temp_word;
    const char* temp_word2;
    string temp;
    string english[] = {"hello", "goodbye", "thank you", "i'm hungry",
    "i swear", "fire", "i hate you", "toy", "what", "apple", "ice cream", "butt",
    "one", "two", "three", "for you", "chair", "cheers", "can we start", "look at you",
    "kiss", "i'm sorry", "bottom", "stop"}; //words to be translated into minion

    //char * filename;
    string minion[] = {"Bello", "Poopaye", "Bank yu", "Me want banana",
    "Underwear", "Bee Do! Bee Do! Bee Do! Bee Do!", "Tatata bala tu", "Baboi", "Po ka", "Bable", "Gelato", "Butt",
    "Nah", "Dul", "Sae", "Para tu", "Chasy", "Kan pai", "Pwede na", "Luk at tu",
    "Muak Muak", "Ditto", "Buttom", "Stopa"}; //minion translation
    //cout<<"Enter a file to translate: "<<endl;
    //cin>>filename;
    string file_words = "";
    if (read_file("text.txt", words)) //take entire file to translate and put it into the vector words
    {
        for (int k = 0; k< words.size(); k++)
        {
            file_words = file_words + " "+ words[k]; //take the vectors and make it one string with a space in between each element
        }
    }
    else
    {
        cout<<"Issue opening the file\n"; //if we cannot read in the file let the user know there was an issue
    }
    temp_word2=file_words.c_str();//to make const char*
    const char * temp_word3;
    size_t j = 0; //starting point for each search
    int num = strlen(temp_word2); //last index of strlen that we will search up till
    int i = 0;
         while(i<24) //search for every english word
        {
            temp_word3 = english[i].c_str();
            //cout << i << endl; cout.flush();
            while (j<num) //search until end of string
            {
                index = file_words.find(english[i], j); //starting from the last find point, search for current english word
                if (index != -1 && (temp_word2[index-1]==' ' || temp_word2[index-1]=='"' || temp_word2[index-1]== '“') && (temp_word2[index + strlen(temp_word3)] == ' ' || temp_word2[index + strlen(temp_word3)] == '"' || temp_word2[index + strlen(temp_word3)] == '“' || temp_word2[index + strlen(temp_word3)] =='\'' || temp_word2[index + strlen(temp_word3)] =='’'))// && temp_word2[index-1]=='  ')      //strcmp(temp_word2[index - 1], " ") !=0)
                {
                    temp_word = english[i].c_str(); //make english word a const char *
                    file_words.replace(index, strlen(temp_word), minion[i]); // replace english word with minion word
                    j = index; //change search start point to last found point
                    temp_word2=file_words.c_str();
                }
                else
                {
                    j++;
                    //j = num; //make search start point the end of the string
                }
            }
            j = 0; //reset search start point to beginning of string
            i++; //move to next english word
        }
    ofstream out;
    out.open("output.txt");
    out<<file_words; //write new string to file
    out.clear(); out.close();

    return 0;
}
bool read_file(char * file_name,vector<string> & w) //take each word from a file and push them into a vector
{
    int i;
    ifstream in;
    in.open(file_name);
    if(!in.is_open()) return false;
    char * word=new char [100];
    string s_word;
    while(in.peek()!=EOF)
    {
        in.getline(word,100,' ');
        for(i=0; i<strlen(word); i++) word[i]=tolower(word[i]);     //make lowercase
        s_word=(string)word;
        w.push_back(s_word);
    }
    in.clear();
    in.close();
    return true;
}

