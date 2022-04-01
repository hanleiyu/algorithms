#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(n, 0);
    for(int i = 0; i < n; i ++){
        int value;
        cin >> value;
        num[i] = value;
    }
    int k;
    cin >> k;
    k = k % n;
    if(n == 0){
        return 0;
    }else if (n == 1){
        cout << num[0];
    }else if (k == 0){
        for(int i = 0; i < n; i ++){        
            cout << num[i];
            if(i != n - 1){
                cout << " ";
            }
        }
    }else{
        for(int i = k; i < n; i ++){
            cout << num[i] << " ";
        }
        for(int i = 0; i < k; i ++){
            cout << num[i];
            if(i != k - 1){
                cout << " ";
            }
        }
    }
    return 0;
}

// class Node{
// public:
//     int value;
//     Node* next;

//     Node(){}
//     Node(int value):value(value), next(nullptr){}
    
// };

// int main(){
//     int n;
//     cin >> n;
//     Node* head = new Node();
//     Node* temp = head;
//     for(int i = 0; i < n; i ++){
//         int value;
//         cin >> value;
//         if(temp == head){
//             head->value = value;
//         }else{
//             temp = new Node(value);
//         }
//         temp = temp->next;
//     }
//     int k;
//     cin >> k;
//     k = k % n;
//     if(n == 0){
//         return 0; 
//     }else if (n == 1){
//         cout << head->value;
//     }else if (k == 0){
//         while(head != nullptr){
//             cout << head->value;
//             head = head->next;
//             if(head != nullptr){
//                 cout << " ";
//             }
//         }
//     }else{
//         queue<int> q;
//         Node* newHead = head;
//         for(int i = 0; i < k; i ++){
//             q.push(newHead->value);
//             newHead = newHead->next;
//         }
//         while(newHead != nullptr){
//             cout << newHead->value << " ";
//             newHead = newHead->next;
//         }
//         while(!q.empty()){
//             cout << q.front();
//             q.pop();
//             if(!q.empty()){
//                 cout << " ";
//             }
//         }
//     }
//     return 0;
// }