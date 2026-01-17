#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main() {
    srand(time(0));
    int size;
    set<int> s;
    cout<<"Enter the size of the array: ";
    cin>>size;
    
    int arr[size];
    cout<<"Array: ";

    for(int i = 0; i < size; ++i) {
        arr[i] = rand() % 10;
        cout << arr[i] <<", ";
    }
    cout << endl;
    
    vector<int> temp;

    for(int i=0;i<size;i++){
        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
        }
        else{
            temp.push_back(i);
        }    
    }
    int sum=0;

    for(int i=0;i<size;i++){
           if(s.find(arr[i])!=s.end()){
                sum+=arr[i];
                s.erase(arr[i]);
            }    
    }
    cout<<"Sum of unique elements: "<<sum<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<"Index of duplicate element: "<<temp[i]<<endl;
    }

    return 0;
}