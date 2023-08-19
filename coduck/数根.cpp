#include <iostream>

using namespace std;

int main(){
    string num;
    cin>>num;
    while(num.size()>1){
        int sum=0;
        for(char c:num)sum+=c-'0';
        num=to_string(sum);
    }
    cout<<num<<endl;
    return 0;
    
}