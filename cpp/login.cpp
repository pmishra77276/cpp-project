#include <iostream>
#include <fstream>
#include<string>
using namespace std;
class login{
    public:
    string name,password;
    login(string n){
        name=n;
        
    }
    bool checkalpha(string s){
        bool check=false;
        for(char &i: s){
            if(isalpha(i)){
                check=true;
            }
        }
        return check;
    }
    bool checkspecial(string s){
        char specialChars[]  = { '!', '@', '#', '$', '%', '^', '&', '*'};
        int count=0;
        for(char &sc:specialChars){
            if(s.find(sc)!=-1){
                count+=1;
            }
        }
        if(count!=0){
            return true;
        }
        else{
            return false;
        }
    }
    bool checkaccount(){
        ifstream file;
        file.open(name+".txt");
        if(file){
            return true;
        }
        else{
            return false;
        }
    }
    void createaccount(){
        ofstream file("loginmanager.txt",ios_base::app);
        string s;
        bool check=false;
        while(check==false){
            cout << "Enter password :: ";
            getline(cin, password);
            bool alpha=checkalpha(password);
            if(alpha==true){
                check=checkspecial(password);
                if(check==true){
                    break;
                }
                else{
                    cout<<"Password must contain a special characer !!"<<endl;
                    continue;
                }
            }
            else{
                cout<<"Password must contain atleast one alphabet !!"<<endl;
                continue;
            }
        }
        s="("+name+")"+" "+password+"\n";
        file<<s;
        file.close();
    }
    void createfile(){
        fstream file;
        file.open(name+".txt",ios::trunc|ios::in|ios::out);
        cout<<"File created";
    }
    bool checkPassword(){
        string pass;
        cout<<"Please Give Password :: ";
        getline(cin,pass);
        ifstream myfile("loginmanager.txt");
        string line;
        while(!myfile.eof()){
            getline(myfile,line);
            if(line.find("("+name+")")!=-1){
                break;
            }
        }
        int index=line.find(")");
        string subline=line.substr(index+2);
        if(pass==subline){
            cout<<"Login Successfull"<<endl;
            cout<<endl;
            return true;
        }
        else{
            printf("Password is wrong\n");
            printf("Please Enter password again\n");
            return false;
        }
    }

};
