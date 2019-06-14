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
    bool having_l = false;
    char data;
    string elemt;
    int index = 256;
    vector<string> codewords;
    map<string,string> lzwDict;
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
        }
    }
    //after the last character, there will no more delimiter before "\n"
    //so need to add the last code word.
    codewords.push_back(elemt);
    ofstream codes;
    codes.open("codes.txt");
    for(vector<string>::iterator it = codewords.begin();it!=codewords.end();it++){
        codes<< *it <<'|';
    }
    codes.close();

    vector<string> cmd;
    for(int i = 0;i<argc;i++){//c-style
        cmd.push_back(argv[i]);
    }
    if(find(cmd.begin(),cmd.end(),"-l") != cmd.end()){//command line with "-l"
        having_l = true;
    }
    for(vector<string>::iterator it = codewords.begin();it!=codewords.end();++it){
        if(it == codewords.begin()){
            if(having_l){
                cout<<"NIL"<<' '<<*it<<' '<<*it<<'\n';
            }else{
                cout<<*it;
            }
            //next w 
            w = *it;
        }else{
            string k = *it;
            if(having_l){
                //print w,k
                cout<<w<<' '<<k<<' ';
            }
            string output;
            string symbol;
            bool is_catch = false;
            //print output
            //consider index larger than the biggest one in the dictionary
            if(k.size()>1){// k is a dictionary reference
                if(lzwDict.find(k) != lzwDict.end()){
                // k is in the dictionary
                    output = lzwDict[k];
                }else{// k is not in the dictionary
                    is_catch = true;
                    if(lzwDict.find(w) != lzwDict.end()){
                        // w is a dictionary reference
                        output = lzwDict[w]+lzwDict[w][0];
                    }else{
                        // w is a character
                        output = w+w;
                    }
                }
            }else{//k is a character
                output = k;
            }
            cout<<output;
            // if out of capacity of dictionary, then cannot print anything except newline character
            if(having_l && (lzwDict.size() <= 16384 - 256)){
                cout<<' ';
            }
            if(lzwDict.size() <= 16384 - 256){
                if(is_catch){
                    symbol = output;
                }else{
                    if(w.size()>1){//w is a dictionary reference
                        if(k.size()>1){ //k is a dictionary reference
                            symbol = (lzwDict[w]+ lzwDict[k][0]);
                        }else{//k is a character
                            symbol = (lzwDict[w]+ k);
                        }
                    }else{//w is a character
                        if(k.size()>1){ //k is a dictionary reference
                            symbol = (w+ lzwDict[k][0]);
                        }else{//k is a character
                            symbol = (w+ k);
                        }
                    }
                }
                lzwDict.insert(pair<string,string>(to_string(index++),symbol));
                if(having_l){
                    //print index and symbols within the capacity
                    cout<<index-1<<' '<<symbol<<"\n";
                }
            }else{
                if(having_l){
                    //print newline without the capacity
                    cout<<'\n';
                }
            }
            w = k;
        }
    }
    if(!having_l){
        cout<<'\n';
    }
    return 0;
}