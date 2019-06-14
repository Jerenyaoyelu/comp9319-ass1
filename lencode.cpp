#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<vector>

using namespace std;
// The reason for the ./ prefix is because the current path (as referred to by the shortcut ".") is not in your $PATH environment variable.
// The short answer is, put "." in your $PATH environment: 'export PATH=$PATH:.'
// but it may cause security risk
int main(int argc, char* argv[]){
    string data;
    char cr;
    string output;
    string w;
    int index = 256; // upper boundary is 16384
    bool having_l = false;
    map<string,string> lzwDict;
    vector<string> cmd;

    while(cin.peek()!='\n'){
        cr = cin.get();
        data += cr;
    }
    
    for(int i = 0;i<argc;i++){//c-style
        cmd.push_back(argv[i]);
    }
    if(find(cmd.begin(),cmd.end(),"-l")!= cmd.end()){
        having_l = true;
    }
    for (string::iterator it = data.begin();it != data.end(); ++it){
        if(it == data.begin()){
            w = *it;
            if(having_l){cout<<"NIL"<<' '<<*it<<"\n";}
        }else{
            if(having_l){
                //print w and k
                cout<<w<<' '<<*it;
            }
            string temp = static_cast<string>(w + *it);
            if(lzwDict.find(temp)!=lzwDict.end()){
                w = temp;
                if(having_l){
                    cout<<"\n";
                }
            }else{
                if(having_l){cout<<' ';}
                //print output
                // if w in the dictionary, then output the index
                if(lzwDict.find(w)!=lzwDict.end()){
                    cout<<lzwDict[w];
                }else{
                    cout<<w;
                }
                // if out of capacity of dictionary, then cannot print anything except newline character
                if(having_l){
                    if(lzwDict.size() <= 16384 - 256){cout<<' ';}
                }else{
                    cout<<' ';
                }
                // the dictionary reaches its maximal capacity
                if(lzwDict.size() <= 16384 - 256){
                    lzwDict.insert(pair<string,string>((w + *it),to_string(index++)));
                    if(having_l){
                        //print index and symbols within the capacity
                        cout<<index-1<<' '<<w + *it<<'\n';
                    }
                }else{
                    if(having_l){
                        //print newline without the capacity
                        cout<<'\n';
                    }
                }
                w = *it;
            }
        }
    }
    if(having_l){
        // print last row
        cout<<w<<' '<<"EOF"<<' ';
    }
    //output in last row
    if(lzwDict.find(w)!=lzwDict.end()){
        cout<<lzwDict[w];
    }else{
        cout<<w;
    }
    cout<<'\n';
    return 0;
}