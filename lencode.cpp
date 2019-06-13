#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
#include<vector>
// #include<cstring>

using namespace std;
// The reason for the ./ prefix is because the current path (as referred to by the shortcut ".") is not in your $PATH environment variable.
// The short answer is, put "." in your $PATH environment: 'export PATH=$PATH:.'
// but it may cause security risk


//next step: need to consider space, tabs in the input text!!

int main(int argc, char* argv[]){
    string data;
    char cr;
    string output;
    string w;
    int index = 256; // upper boundary is 16384
    map<string,int> lzwDict;

    // if(find(argv[0],argv[argc-1],"-l") != argv[argc-1]){
    // cout<<*(argv+argc-1)<<endl;
    // cout<<argc<<endl;
    while(cin.peek()!='\n'){
        cr = cin.get();
        data += cr;
    }
    // cout << data << endl;
    if(argc == 1){
        // string iterator
        string::iterator it;
        for (it = data.begin();it != data.end(); ++it){
            if(it == data.begin()){
                w = *it;
            }else{
                string temp = static_cast<string>(w + *it);
                if(lzwDict.find(temp)!=lzwDict.end()){
                    w = temp;
                    if(it+1 ==data.end()){
                        cout<<lzwDict[w];
                    }
                }else{
                    // if w in the dictionary, then output the index
                    if(lzwDict.find(w)!=lzwDict.end()){
                        cout<<lzwDict[w];
                    }else{
                        cout<<w;
                    }
                    if(it+1!=data.end()){
                        cout<<' ';
                    }else{
                        // when it visited last char, the loop will terminate,
                        // So the last w will bot be printed out.
                        // Thus, we need to print it out here
                        cout<<' '<<*it; 
                    }
                    // the dictionary reaches its maximal capacity
                    if(lzwDict.size() <= 16384 - 256){
                        lzwDict.insert(pair<string,int>((w + *it),index++));
                    }
                    w = *it;
                }
            }
        }
        cout <<"\n";
    }else{
        vector<string> cmd;
        for(int i = 0;i<argc;i++){//c-style
            cmd.push_back(argv[i]);
        }
        if(find(cmd.begin(),cmd.end(),"-l")!= cmd.end()){
            string::iterator it;
            for (it = data.begin();it != data.end(); ++it){
                if(it == data.begin()){
                    w = *it;
                    cout<<"NIL"<<' '<<*it<<"\n";
                }else{
                    //print w and k
                    cout<<w<<' '<<*it;
                    string temp = static_cast<string>(w + *it);
                    if(lzwDict.find(temp)!=lzwDict.end()){
                        w = temp;
                        cout<<"\n";
                    }else{
                        cout<<' ';
                        //print output
                        // if w in the dictionary, then output the index
                        if(lzwDict.find(w)!=lzwDict.end()){
                            cout<<lzwDict[w];
                        }else{
                            cout<<w;
                        }
                        // the dictionary reaches its maximal capacity
                        if(lzwDict.size() <= 16384 - 256){
                            lzwDict.insert(pair<string,int>((w + *it),index++));
                            //print index and symbols within the capacity
                            cout<<' '<<index-1<<' '<<w + *it<<"\n";
                        }
                        w = *it;
                    }
                }
            }
            //print last row
            cout<<w<<' '<<"EOF"<<' ';
            if(lzwDict.find(w)!=lzwDict.end()){
                cout<<lzwDict[w];
            }else{
                cout<<w;
            }
            cout<<"\n";
        }
    }
    return 0;
}