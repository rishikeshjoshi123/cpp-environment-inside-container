
#include <bits/stdc++.h>

using namespace std; 

struct paymentInfo{
    string paidTo;
    float amount;
    
    paymentInfo(string _paidTo, float _amount){
        paidTo= _paidTo; amount= _amount;
    }
};
struct Flow{
        string user; 
        float amount;
        
        Flow(string _user, float _amount){
            user= _user; amount = _amount;
        }
    };
static bool __comp(const Flow &a, const Flow &b){
    return a.amount < b.amount;
}
int main() {
    
    //create users
    vector<string> users;
    int N; 
    cout<<"\n--------------------------------------------------------------------------------";
    cout<<"\nEnter the number of users : ";
    cin>>N;
    cout<<"\n--------------------------------------------------------------------------------";
    cout<<"\nEnter name of all the users : ";
    for(int i=0; i<N; ++i){
        string s; cin>>s; 
        users.push_back(s);
    }
    unordered_map<string, vector<paymentInfo>> adjList;
    for(int i=0; i<N; ++i){
        adjList.insert({users[i], vector<paymentInfo>()});
    }
    
       // Enter transactions
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\nEnter the UserName and Amount (Example: Peter 5000): \n";
    while (true) {
        cout << "-> ";
        string user;
        float amount;

        // Check if the input format is correct
        if (!(cin >> user >> amount)) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter in the format: UserName Amount\n";
            continue; // prompt for input again
        }

        float dividedAmount = amount / N;
        for (auto &I : adjList) {
            if (I.first != user) {
                I.second.push_back(paymentInfo(user, dividedAmount));
            }
        }

        cout << "\n[ Add more? (Y/N) ]: ";
        string ans;
        cin >> ans;
        if (ans == "N" || ans == "n" || ans == "No" || ans == "no") break;
    }
    cout<<"\n--------------------------------------------------------------------------------";


    
    //algorithm
    unordered_map<string, float> totalFlow;
    for(auto I: adjList){
        string paidBy= I.first;
        for(paymentInfo paymentObj: I.second){
            string paidTo = paymentObj.paidTo;
            float amount= paymentObj.amount;
            
            totalFlow[paidBy]-= amount;
            totalFlow[paidTo]+= amount;
        }
        
    }
    
    
    vector<Flow> flowArray;
    for(auto I: totalFlow) flowArray.push_back(Flow(I.first, I.second));
    
    sort(flowArray.begin(), flowArray.end(), __comp);
    
    int L=0, R= flowArray.size()-1;
    while( L < R){
        string leftUser= flowArray[L].user, rightUser= flowArray[R].user;
        float leftAmount= flowArray[L].amount;
        float rightAmount= flowArray[R].amount; 
        
        float amountTransfered= min(abs(leftAmount), abs(rightAmount));
        float remainingAmount= leftAmount+ rightAmount;
        
        cout<<"\n"<<leftUser<<" --> "<<rightUser<<" [ "<<amountTransfered<<" ]";
        if(remainingAmount == 0){//move L to right and R to left
            L++, R--;
        }
        else if(remainingAmount > 0){// move L to right
            L++;
        }
        else { //move R to left
            R--; 
        }
        
    }
    
    cout<<"\n";
    return 0;
}