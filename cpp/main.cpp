#include<iostream>
#include<fstream>
#include <ctime>
#include <iomanip> // To format date output
#include "login.cpp"
#include "todo.cpp"
//#include "savetofile.cpp"
using namespace std;

bool isFileEmpty(const std::string& filename) {
    ifstream file(filename);
    return file.peek() == file.eof();
}
int main(){
    string name,pass;
    cout<<"Your Name :: "; // INput as name
    getline(cin,name);
    login l(name); //Input name sent to login class
    bool val=l.checkaccount();
    if(val==false){
        l.createaccount();
        l.createfile();
    }
    else{
        int count=3;
        while(true){
            bool val=l.checkPassword();
            if(val==false){
                count-=1;
                if(count==0){
                    return 0;
                    break;
                }
                cout<<"Number of chances left are "<<count<<endl;
                
            }
            else{
                break;
            }
        }
    }
    Task* root;
    if (isFileEmpty(name+".txt")==true) {
        root=NULL;
    }
    else{
    root = NULL;
    // int count=0;
    root=readfromfile(root,name);
    }
    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. View tasks " << endl;
        cout << "3. To save file" << endl;
        cout << "4. To Delete something" << endl;
        cout << "5. To update something"<<endl;
        cout << "6. To see upcoming tasks"<<endl;
        cout << "7. To search task on a given date"<<endl;
        cout << "8. To exit"<<endl;
        int choice;
        cout << "Enter your choice: "<<endl;
        cin >> choice;
        switch (choice) {
            case 1:{
                root=addTask(root,0);
                break;}
            case 2:{
                if(root==NULL){
                    cout<<"Your list is empty!"<<endl;
                    break;
                }
                else{
                    cout<<"Select the option in which you want to see you list :: "<<endl;
                    int choice;
                    cout<<"1. in Priority order"<<endl;
                    cout<<"2. in order of Due Date"<<endl;
                    cin>>choice;
                    if(choice==1){
                        inorder(root);
                    }
                    else if(choice==2){
                        sortbydate(root);
                    }
                break;}}
            case 3:{
                ofstream file(name+".txt",ios_base::trunc);
                savefile(root,file);
                cout<<"\nFile Saved"<<endl;
                file.close();
                break;}
                // }
            case 4:{
                if(root==NULL){
                    cout<<"Your list is empty!"<<endl;
                    break;
                }
                else{
                cout<<"Below is the list of Task :- "<<endl;
                cout<<endl;
                inorder(root);
                cout<<endl;
                int pri;
                string des;
                cin.ignore();
                cout<<"Enter the description which you want to delete :: "<< endl;
                getline(cin,des);
                cout<<"Enter the priority of desciption :: "<<endl;
                cin>>pri;
                int f=0;
                root=Delete(root,pri,des,f);
                // if(f==0){
                //     cout<<"Task Deleted !"<<endl;
                // }
                
                break;}}
            case 5:{
                while (true)
                {
                cout << "Select which task you want to update :: " << endl;
                inorder(root);
                cout << endl;
                int pri;
                string des;
                cout << "Enter priority :: ";
                cin >> pri;
                cout << "Enter task description :: ";
                // root=Delete(root,pri,des);
                cin.ignore();
                getline(cin, des);
                int flag = 0 ;
                root = Delete(root, pri, des, flag);
                // root=update(root,pri,des);
                if (flag == 0)
                {
                        root = addTask(root, 1);
                        break;
                }
                else
                {
                    continue;
                }
                
                // cout << "Enter due date (YYYY MM DD format): ";
                // cin >> year >> month >> day;
                // struct tm dueDate = {};
                // dueDate.tm_year = year - 1900;
                // dueDate.tm_mon = month - 1;
                // dueDate.tm_mday = day;
                // time_t duedate = mktime(&dueDate);
                }
                break;
            }
            case 6:{
                viewUpcomingTasks(root);
                break;
            }
            case 7:{
                time_t dueTime;
                int year,month,day;
                cout << "Enter due date for which you want to search task(YYYY MM DD format): ";
                cin >> year >> month >> day;
                struct tm dueDate = {};
                dueDate.tm_year = year - 1900;
                dueDate.tm_mon = month - 1;
                dueDate.tm_mday = day;
                dueTime = mktime(&dueDate);
                bool found=searchByDate(root,dueTime);
                if(found==false){
                    cout<<"Task not found!"<<endl;
                }
                break;
            }
            case 8:{
                // Cleanup and exit
                return 0;}
            
            default:{
                cout << "Invalid choice. Try again." << endl;
                cin.clear(); // Clear error flags
                while (cin.get() != '\n') ; // Clear the input buffer
                break;}
            }
        }
    }
