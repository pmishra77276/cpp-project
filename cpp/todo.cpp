#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <sstream>
#include <chrono>
#include <map>
using namespace std;
class Task {
    public:
    string description;
    int priority;
    time_t dueDate; // Use time_t for storing due date as a timestamp
    Task* left;
    Task* right;
    Task(string desc, int prio, time_t due) {
        description= desc;
        priority = prio;
        dueDate=due;
        left = nullptr;
        right = nullptr;
    }
};



Task *insertp(Task *root, string description, int priority, time_t dueDate)
{

    if (root == NULL)
    {
        Task *newtask = new Task(description, priority, dueDate);
        root = newtask;
    }
    else if (priority <= root->priority)
    {
        root->left = insertp(root->left, description, priority, dueDate);
    }
    else if (priority > root->priority)
    {
        root->right = insertp(root->right, description, priority, dueDate);
    }
    return root;
}

// void inorderp(Task *root)
// {
//     if (root)
//     {
//         inorderp(root->left);
//         cout << "Priority: " << root->priority << " - Due Date: " << put_time(localtime(&root->dueDate), "%Y-%m-%d") << " - Task: " << root->description << endl;
//         inorderp(root->right);
//     }
// }



// Task *insert(Task *root, string description, int priority, time_t dueDate)
// {
//     if (root == nullptr)
//     {
//         root = new Task(description, priority, dueDate);
//         return root;
//     }

//     if (dueDate < root->dueDate || (dueDate == root->dueDate && priority < root->priority))
//     {
//         root->left = insert(root->left, description, priority, dueDate);
//     }
//     else
//     {
//         root->right = insert(root->right, description, priority, dueDate);
//     }

//     return root;
// }

void inorder(Task *root)
{
    if (root)
    {
        inorder(root->left);
        cout << "Priority: " << root->priority << " - Due Date: " << put_time(localtime(&root->dueDate), "%Y-%m-%d") << " - Task: " << root->description << endl;
        inorder(root->right);
    }
}




bool isValidDate(int year, int month, int day) {
    int daysInMonth;
    if (year < 1900 || month < 1 || month > 12){
        return false;
        daysInMonth = 31;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        daysInMonth = 30;
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth = 29;
        } else {
            daysInMonth = 28;
        }
    }
return (day >= 1 && day <= daysInMonth);
}
bool isDateValid(int year, int month, int day){
    time_t currentTime;
    time(&currentTime);
    tm* currentDate = localtime(&currentTime);

    // Compare the entered date with the current date
    if (year < currentDate->tm_year + 1900) {
        return false;  // Year is in the past
    }
    else if (year == currentDate->tm_year + 1900) {
        if (month < currentDate->tm_mon + 1) {
            return false;  // Month is in the past
        }
        else if (month == currentDate->tm_mon + 1) {
            if (day < currentDate->tm_mday) {
                return false;  // Day is in the past
            }
        }
    }
return true;  // Date is valid
}
Task* addTask(Task* root,int flag) {
    if(flag==0){
        string description;
        int priority;
        int year, month, day;
        cout << "Enter task description: ";
        cin.ignore();
        getline(cin, description);
        cout << "Enter task priority: ";
        cin >> priority;
        // cout << "Enter due date (YYYY MM DD format): ";
        // cin >> year >> month >> day;
        // struct tm dueDate = {};
        // dueDate.tm_year = year - 1900;
        // dueDate.tm_mon = month - 1;
        // dueDate.tm_mday = day;
        // time_t dueTime = mktime(&dueDate);
        time_t dueTime;
        bool valid= false;
        bool dvalid=false;
        while((valid==false) || (dvalid==false)){
        // cout << "Invalid due date. Please check the entered date should not be older than today or an invalid date." << endl;
            cout << "Enter due date (YYYY MM DD format): ";
            cin >> year >> month >> day;
            valid = isDateValid(year, month, day);
            dvalid = isValidDate(year, month, day);
            if (valid == false)
            {
                cout << "Invalid due date. Please enter a date not older than today." << endl;
            }
            else if (dvalid == false)
            {
                cout << "Invalid due date. Please enter a valid date." << endl;
            }
        }
    // ol valid=isDateValid(year,month,day);
    
    struct tm dueDate = {};
    dueDate.tm_year = year - 1900;
    dueDate.tm_mon = month - 1;
    dueDate.tm_mday = day;
    dueTime = mktime(&dueDate);
    root = insertp(root, description, priority, dueTime);
    cout << "Task added successfully!" << endl;
    return root;
    }
        //root = insertp(root, description, priority, dueTime);

        // cout << "Task added successfully!" << endl;
        // return root;
    
    else if (flag == 1){
        int val, year, month, day;
        string desc;
        cout << "Enter new task description :: ";
        // cin.ignore();
        getline(cin, desc);
        // cout<<desc<<endl;
        cout << "Enter new priority of task :: ";
        cin >> val;
        // cout << "Enter due date (YYYY MM DD format): ";
        // cin >> year >> month >> day;
        // struct tm dueDate = {};
        // dueDate.tm_year = year - 1900;
        // dueDate.tm_mon = month - 1;
        // dueDate.tm_mday = day;
        // time_t dueTime = mktime(&dueDate);
        time_t dueTime;
        bool valid= false;
        bool dvalid=false;
        while((valid==false) || (dvalid==false)){
        // cout << "Invalid due date. Please check the entered date should not be older than today or an invalid date." << endl;
            cout << "Enter due date (YYYY MM DD format): ";
            cin >> year >> month >> day;
            valid = isDateValid(year, month, day);
            dvalid = isValidDate(year, month, day);
            if (valid == false)
            {
                cout << "Invalid due date. Please enter a date not older than today." << endl;
            }
            else if (dvalid == false)
            {
                cout << "Invalid due date. Please enter a valid date." << endl;
            }
        }
    // ol valid=isDateValid(year,month,day);
    
        struct tm dueDate = {};
        dueDate.tm_year = year - 1900;
        dueDate.tm_mon = month - 1;
        dueDate.tm_mday = day;
        dueTime = mktime(&dueDate);
        root = insertp(root, desc, val, dueTime);
        cout << "Task updated successfully!" << endl;
        return root;
        //root =insertp(root, desc, val, dueTime);
        //return root;
    }
}




Task* findmin(Task* root){
    if(root==NULL){
        return NULL;
    }
    else if(root->left==NULL){
        return root;
    }
    return findmin(root->left);
}
Task* Delete(Task* root,int val,string des,int &flag){
    if(root==NULL){
        
        return NULL;
    }
    else if(val<root->priority){
        root->left=Delete(root->left,val,des,flag);
    }
    else if(val>root->priority){
        root->right=Delete(root->right,val,des,flag);
    }
    else if(val==root->priority && des==root->description){
        if(root->left==NULL && root->right==NULL ){
            //cout<<"I'm here"<<endl;
            delete root;
            root=NULL;
            
        }
        else if(root->left==NULL ){
            Task* temp=root;
            root=root->right;
            //cout<<"I'm here"<<endl;
            delete temp;
        }
        else if(root->right==NULL ){
            Task* temp=root;
            root=root->left;
            //cout<<"I'm here"<<endl;
            delete temp;
            
        }
        else if(root->right!=NULL && root->left!=NULL ){
            cout<<"I'm here "<<endl;
            Task* temp=findmin(root->right);
            root->description=temp->description;
            root->dueDate=temp->dueDate;
            root->priority=temp->priority;
            root->right=Delete(root->right,temp->priority,temp->description,flag);
            // flag=1;
            // cout<<"I'm here"<<endl;
        }
    }
    else{
        cout<<"\nData not found"<<endl;
        flag=1;
    }
    return root;
}




void savefile(Task* root,ofstream &file) {

    ostringstream oss;
    //ofstream file(name+".txt");
    string formatdate;
    // if(file.is_open()){
    //     file.close();
    //     file.open(name+".txt",ios::app);
    
    //file.open(name+".txt",ios_base::trunc);
    string s;
        if (root){
            savefile(root->left, file);
            oss << put_time(localtime(&root->dueDate), "%Y-%m-%d");
            formatdate = oss.str();
            s = to_string(root->priority) + " " + formatdate + " " + root->description + "\n";
            file << s;
            savefile(root->right, file);
        }
        // else{
        //     flag=0
        // }
    //  }
}




void returnpriority(Task* root,vector<int>& pri){
    if(root==NULL){
        return;
    }
    else{
    returnpriority(root->left,pri);
    pri.push_back(root->priority);
    returnpriority(root->right,pri);}
}
void returnduedate(Task* root,vector<time_t>& duedate){
    if(root==NULL){
        return;
    }
    else{
    returnduedate(root->left,duedate);
    duedate.push_back(root->dueDate);
    returnduedate(root->right,duedate);}
}
void returndes(Task* root,vector<string>& des){
    if(root==NULL){
        return;
    }
    else{
    returndes(root->left,des);
    des.push_back(root->description);
    returndes(root->right,des);}
}
void sortbydate(Task* root){
    vector<int> pri;
    vector<time_t> duedate;
    vector<string> des;
    returnpriority(root,pri);
    returnduedate(root,duedate);
    returndes(root,des);
    int length=des.size();
    for(int i =0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(duedate[i]>duedate[j]){
                swap(duedate[i],duedate[j]);
                swap(pri[i],pri[j]);
                swap(des[i],des[j]);
            }
        }
    }
    for(int i=0;i<length;i++){
        cout << "Priority: " << pri[i] << " - Due Date: " << put_time(localtime(&duedate[i]), "%Y-%m-%d") << " - Task: " << des[i] << endl;
    }
    
}
void split(string s,vector<string> &parts){
    istringstream iss(s);
    string part;
    while(iss>>part){
        parts.push_back(part);
    }
    return;
}


bool checkdate(time_t date){
    time_t currentTime;
    time(&currentTime);
    time_t yesterdayTime = currentTime - 86400;
    if(date>yesterdayTime){
        return true;
    }
    else{
        return false;
    }
}





Task* readfromfile(Task* root,string name){
    ifstream myfile(name+".txt");
    string line;
    while(getline(myfile,line)){
        //getline(myfile,line);
        vector<string> splitt;
        split(line,splitt);
        int prior=stoi(splitt[0]);
        string date=splitt[1];
        istringstream iss(date);
        tm dateInfo = {};
        iss>>get_time(&dateInfo, "%Y-%m-%d");
        time_t dateAsTimeT = mktime(&dateInfo);
        // if(checkdate(dateAsTimeT)==true){
        //     string des=splitt[2];
        //     root=insertp(root,des,prior,dateAsTimeT);
        // }
        // else{
        //     continue;
        // }
        string des=splitt[2];
        cout<<des<<endl;
        root=insertp(root,des,prior,dateAsTimeT);
    }
    myfile.close();
    //cout<<"Content is readed"<<endl;
    return root;
}





string formatTime(time_t time) {
    struct tm* timeinfo = localtime(&time);
    char buffer[12];  // "YYYY MM DD\0"
    strftime(buffer, sizeof(buffer), "%Y %m %d", timeinfo);
    return string(buffer);
}
void collectTasks(Task* node, map<string, vector<string>>& tasksByDate, time_t dueDateThreshold) {
    //cout<<"I'm here"<<endl;
    //cout<<"\nmy value is "<<node->description<<endl;
    if (node!=NULL) {
        // cout<<"I'm here";
        collectTasks(node->left, tasksByDate, dueDateThreshold);
        // cout<<node->dueDate<<endl;
        if (node->dueDate <= dueDateThreshold) {

            //cout<<"\nTEst"<<node->description<<endl;
            string formattedDate = formatTime(node->dueDate);
            string taskInfo = "Priority: " + to_string(node->priority) + " - Task: " + node->description;
            tasksByDate[formattedDate].push_back(taskInfo);
        }

        collectTasks(node->right, tasksByDate, dueDateThreshold);
    }
    else{
        return;
    }
}
void viewUpcomingTasks(Task* root) {
    time_t currentTime;
    time(&currentTime);

    time_t dueDateThreshold = currentTime + 7 * 24 * 60 * 60;
    //cout<<dueDateThreshold<<endl;
    cout << "Tasks for the upcoming 7 days:" << endl;
    map<string, vector<string>> tasksByDate;
    auto formatTime = [](time_t time) {
        struct tm* timeinfo = localtime(&time);
        char buffer[12];
        strftime(buffer, sizeof(buffer), "%Y %m %d", timeinfo);
        return string(buffer);
    };
    collectTasks(root, tasksByDate, dueDateThreshold);
    for (const auto& entry : tasksByDate) {
        cout << entry.first << ":" << endl;
        for (const string& taskInfo : entry.second) {
            cout << "  " << taskInfo << endl;
        }
    }
}





bool searchByDate(Task* root, time_t searchDate) {
    bool found = false;
    if (root) {
        if (searchByDate(root->left, searchDate)) {
            found = true;
        }
        if (root->dueDate == searchDate) {
            cout << "Priority: " << root->priority << " - Due Date: " << put_time(localtime(&root->dueDate), "%Y-%m-%d") << " - Task: " << root->description << endl;
            found = true;
        }
        if (searchByDate(root->right, searchDate)) {
            found = true;
        }
    }

    return found;
}





// Task* inupdate(Task* root,string desc,int val,time_t dueDate){
//     if(root==NULL){
//         Task* newtask=new Task(desc,val,dueDate);
//         // cout<<desc<<endl;
//         // cout<<newtask->description<<endl;
//         root=newtask;
//     }
//     else if(val<root->priority){
//         root->left=inupdate(root->left,desc,val,dueDate);
//     }
//     else if(val>root->priority){
//         root->right=inupdate(root->right,desc,val,dueDate);
//     }
//     return root;
// }
// Task* update(Task* root){
//     int val,year,month,day;
//     string desc;
//     cout<<"Enter new task description :: ";
//     // cin.ignore();
//     getline(cin,desc);
//     //cout<<desc<<endl;
//     cout<<"Enter new priority of task :: ";
//     cin>>val;
//     cout << "Enter due date (YYYY MM DD format): ";
//     cin >> year >> month >> day;
//     struct tm dueDate = {};
//     dueDate.tm_year = year - 1900;
//     dueDate.tm_mon = month - 1;
//     dueDate.tm_mday = day;
//     time_t dueTime = mktime(&dueDate);

//     root=inupdate(root,desc,val,dueTime);
//     return root;
// }