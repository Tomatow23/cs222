// css222Project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


void trim(string& a) {
    while (a.length() > 1 && a[0] == '0') a = a.substr(1);
}
string add(string a, string b){
    trim(a);
    trim(b);
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    a = "0" + a;
    b = "0" + b;
    string ans = "";
    int carry = 0;
    for (int i = a.length()-1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        ans = (char)(sum % 10 + '0') + ans;
        carry = sum / 10;
    }
    trim(ans);
    return ans;
}
string sub(string a, string b) {
    trim(a);
    trim(b);
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    for (int i = 0; i < b.length(); i++) {
        b[i] = (char)('9' - b[i] + '0');
    }
    string diff = add(add(a, b), "1").substr(1);
    trim(diff);
    return diff;
}
string multiply(string a, string b) {
    trim(a);
    trim(b);
    string sum = "0";
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < b.length(); j++) {
            int prod = (a[i] - '0') * (b[j] - '0');
            string addend = to_string(prod);
            for (int k = 0; k < a.length() - 1 - i + b.length() - 1 - j; k++)
                addend += "0";
            sum = add(sum, addend);
        }
    return sum;
}
//Does not currently work.
int compareTo(string a, string b) {
    for(int i = 0; i < a.length(); i++)
    if ((a[i] - '0') > (b[i] - '0')) {
        return 1;
    }
    else if ((a[i] - '0') > (b[i] - '0')) {
        return -1;
    }
    else return 0;
}
string sqroot(string a) {
    trim(a);
    int ans = 0;
    int len = a.length() * 2;
    

    int x = 0;
    int z = 1;
    bool flag = true;
    while(flag) {
        int j = 4 * z;
        cout << compareTo(to_string(j), a) << endl;
        // I am currently fixing this infinite loop as my compare to does not work currently.
        //if (compareTo(to_string(j), a) == 1) {
       //     flag = false;
       // }
        x++;
        z = j;
        //placeholder so your code doesn't run forever.
        flag = false;
    }
    string* fourArr = new string[x];
    fourArr[0] = 1 + '0';
    int y = 1;
    for (int i = 1; i < len; i++) {
        int j = 4 * y;
        y = j;
        string prod = to_string(j);
        fourArr[i] = prod;
    }
    //for (int i = 0; i < 4; i++) {
      // cout << fourArr[i] << endl;
    //}
    //string* four = new string[x];
    //for (int i = 1; i < x; i++) {
       // int j = 4 * z;
       // z = j;
       // string prod = to_string(j);
       // cout << four[i] << endl;
       // four[i] = prod;
    //}
    for (int i = sizeof(fourArr); i >= 0; i--) {
            int subTrue = (4 * ans + 1);
            string str = to_string(subTrue);
            string temp = multiply(fourArr[i], str);
           // cout << a << " a" << endl;
           // cout << temp << " b" << endl;
            if (compareTo(a, temp) >= 0) {
                ans = 2 * ans + 1;
                a = sub(a, temp);
            }
            else ans = 2 * ans;
            
            
    }
    
    return to_string(ans);
}

int main()
{
    cout << sqroot("729") << endl;
}
