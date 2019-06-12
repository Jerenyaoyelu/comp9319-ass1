#include<iostream>
#include<fstream>
#include<algorithm>
#include<map>
// #include<cstring>

using namespace std;
// The reason for the ./ prefix is because the current path (as referred to by the shortcut ".") is not in your $PATH environment variable.
// The short answer is, put "." in your $PATH environment: 'export PATH=$PATH:.'
// but it may cause security risk

int main(int argc, char* argv[]){
    string data;
    string output;
    string w,k,s;
    int index = 256; // upper boundary is 16384
    map<string,int> lzwDict;

    // if(find(argv[0],argv[argc-1],"-l") != argv[argc-1]){
    // cout<<*(argv+argc-1)<<endl;
    // cout<<argc<<endl;
    cin >> data;
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
                    lzwDict.insert(pair<string,int>((w + *it),index++));
                    w = *it;
                }
            }
        }
        cout <<"\n";
    }
    // if(strchr(argv,"-l") != NULL)
    // cout<<find(argv,argv+argc,"-l")<<endl;
    // cout<<argv+argc<<endl;
    if(
       
        (find(argv,argv+argc,"-l")!= argv+argc)
        ||
        (find(argv,argv+argc,"-l") == argv+argc && strcmp(argv[argc-1],"-l")==0)
    )
    {
        // ifstream infile;
        // infile.open("test.txt",ios::in);
        // infile >> data;
        cout<<"test"<<endl;
        cout << data << endl;
    }
    return 0;
}