#include <iostream>
#include <string>

using namespace std;
bool co=1;

bool isIrisNumber(int num) {
    string numStr = to_string(num);  // 将整数转换为字符串

    int diff = numStr[1] - numStr[0];  // 计算第一对相邻两位数字的差值

    for (int i = 2; i < numStr.length(); i++) {
        int currDiff = numStr[i] - numStr[i - 1];  // 计算当前对相邻两位数字的差值

        if (currDiff != diff) {
            return false;  // 差值不相等，不是鸢尾花数
        }
    }

    return true;  // 所有差值相等，是鸢尾花数
}

void findIrisNumbers(int a, int b) {
    for (int i = a; i <= b; i++) {
        if (isIrisNumber(i)) {
            cout << i << " ";  // 输出鸢尾花数
            co=0;
            
        }
        
        
    }

    //cout << endl;
}

int main() {
    int a, b;
    cin >> a >> b;

    findIrisNumbers(a, b);
    if(co){
        cout<<"-1";
    }
    cout<<endl;
    return 0;
}

