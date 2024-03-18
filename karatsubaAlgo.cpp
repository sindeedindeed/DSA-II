#include <bits/stdc++.h>
using namespace std;
string appendZero(string str, int n){
    while(n--)
        str="0"+str; 
    return str;
}
string removeZero(string str){
    reverse(str.begin(), str.end());
    for(int i=str.length()-1;i>=0;i--){
        if(str[i]=='0')
            str.pop_back();
        else
            break;
    }
    if(str.empty())
        return "0";
    else{
        reverse(str.begin(), str.end());
        return str;
    }
}
string addTwoStrings(string x, string y){
    if(x.length()>y.length())
        y=appendZero(y,(x.length()-y.length()));
    else
        x=appendZero(x,y.length()-x.length());
    int carry=0,sum;
    string result="";
    for(int i=x.length()-1;i>=0;i--){
        sum=(x[i]-'0'+y[i]-'0'+carry);
        if(sum>9){
            result=to_string(sum%10)+result;
            carry=sum/10;
        }
        else{
            result=to_string(sum)+result;
            carry=0;
        }
    }
    return result;
}
string substractTwoStrings(string x, string y){
    if(x.length()>y.length())
        y=appendZero(y,x.length()-y.length());
    else
        x=appendZero(x,y.length()-x.length());
    string result="";
        int borrow=0,a,b;
    for(int i=x.length()-1;i>=0;i--){
        a=(int)x[i]-'0';
        b=(int)y[i]-'0';
        if(borrow==1)
            a-=1;
        if(a>=b){
            result=to_string(a-b)+result;
            borrow=0;
        }
        else{
            a+=10;
            result=to_string(a-b)+result;
            borrow=1;
        }
        }
    return removeZero(result);
}
string multiplyXY(string x, string y){
    int product;
    product=(x[0]-'0')*(y[0]-'0'); 
    return to_string(product);
}
string multiply10(string str, int n){
    while(n--)
        str+="0"; 
    return str;
}
string k_suba(string x, string y){
    if(x.length()==1 && y.length()==1)
        return multiplyXY(x,y);
    if(x.length()>y.length())
        y=appendZero(y, x.length()-y.length());
    else
        x=appendZero(x, y.length()-x.length());
    if(x.length()%2!=0){
        x="0"+x;
        y="0"+y;
    }
    string x_left,x_right,y_left,y_right,p1,p2,p3;
    int n=x.length();
    x_left=x.substr(0,x.length()/2);
    x_right=x.substr(x.length()/2);
    y_left=y.substr(0,y.length()/2);
    y_right=y.substr(y.length()/2);
    p1=k_suba(x_left,y_left);
    p2=k_suba(addTwoStrings(x_left,x_right),addTwoStrings(y_left,y_right));
    p3=k_suba(x_right,y_right);
    return removeZero(addTwoStrings(addTwoStrings(multiply10(p1,n),multiply10(substractTwoStrings(substractTwoStrings(p2,p1),p3),n/2)),p3));
}
int main(){
    string s1,s2;
    s1="12";
    s2="2";
    cout<<k_suba(s1,s2)<<endl;
}