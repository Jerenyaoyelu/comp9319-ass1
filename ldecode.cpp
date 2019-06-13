#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
#include<cctype>

using namespace std;

int main(int argc, char* argv[]){
    string w;
    int continuous_ws_counter = 0;
    char data;
    string elemt;
    vector<string> codewords;
    //INSIGHTS OF INPUT:
    //the each code word in the input will not appear the case, such as "XXX(whitespace)(whitespace)XXX"
    //because in the code word either it is a single char or a dictionary reference number
    while(cin.peek() != '\n'){
        data = cin.get();
        if(elemt.size() == 0){
            elemt += data;
            if(isspace(data)){
                codewords.push_back(elemt);
                elemt.clear();
            }
        }else{
            if(isspace(data)){
                if(elemt.size() == 0){
                    elemt += data;
                }
                codewords.push_back(elemt);
                elemt.clear();
            }else{
                elemt += data;
            }
            // int n = elemt.size();
            // if(!isspace(data)){
            //     if(isspace(elemt[n-1])){
            //         elemt.erase(n-1,n-1);
            //         codewords.push_back(elemt);
            //         elemt.clear();
            //     }
            //     elemt += data;
            // }else{
            //     // last two chars in elemt are both ws
            //     // then the last ws has to be earsed to get the complete single code word
            //     // and do not forget add the current ws to the next elemt
            //     if(isspace(elemt[n-1])&&isspace(elemt[n-2])){
            //         elemt.erase(n-1,n-1);
            //         codewords.push_back(elemt);
            //         elemt = data;
            //     }else if(isspace(elemt[n-1])){
            //         //only the last char of elemt is ws
            //         //
            //         elemt += data;
            //     }else{
            //         codewords.push_back(elemt);
            //         elemt.clear();
            //     }
            // }
        }
    }
    //after the last character, there will no more delimiter before "\n"
    //so need to add the last code word.
    codewords.push_back(elemt);
    for(vector<string>::iterator it = codewords.begin();it != codewords.end();++it){
        cout<<*it<<' ';
    }
    // vector<string> cmd;
    // for(int i = 0;i<argc;i++){//c-style
    //     cmd.push_back(argv[i]);
    // }
    // if(find(cmd.begin(),cmd.end(),"-l")== cmd.end()){
    //     for(string::iterator k = data.begin();k!=data.end();++k){
    //         // if(k == data.begin()){
    //         //     cout<<*k<<' ';
    //         //     //next w 
    //         //     w = *k;
    //         // }else{
                
    //         // }
    //         cout << *k<<endl;
    //     }
    // }
    return 0;
}