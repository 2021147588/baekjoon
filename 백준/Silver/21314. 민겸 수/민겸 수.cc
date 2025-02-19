# include <iostream>
# include <string>
# include <stack>
# include <cassert>
# include <cmath>
using namespace std;

string convert_mingyeom_to_num(string mingyeom){
    int m=0;
    int k=0;
    string result;
    for(int i=0;i<mingyeom.size();i++){
        if(mingyeom[i]=='M') m++;
        else k++;
    }

    assert(k<=1);

    if(k==1) {
        result = '5';
        for(int i=0;i<m;i++){
            result +='0';
        }
    }
    else if(k==0 && m==0) return "";
    else {
        result = '1';
        for(int i=0;i<m-1;i++){
            result +='0';
        }
    };
    return result;

}

int main(){
    string input;
    stack<char> s;
    string top="";
    string max="";
    string min="";
    cin>>input;
    
    for(int i=0;i<input.size();i++){
        if(input[i]=='K'){
            while(!s.empty()){
                top += s.top();
                s.pop();
            }
            //make max 
            max += convert_mingyeom_to_num(top + 'K');
            //make min
            min += convert_mingyeom_to_num(top);
            min += "5";
            top = "";
        }
        else{
            s.push(input[i]);
        }
         
    }
    while(!s.empty()){
        top += s.top();
        s.pop();
        max += '1';
    }
    
    min += convert_mingyeom_to_num(top);
    
    
    cout<<max<<endl;
    cout<<min<<endl;
}