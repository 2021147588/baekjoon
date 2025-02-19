# include <iostream>
# include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    string input;
    string x = "";
    cin>> input;
    
    for(int i=0;i<input.length();i++){
        x+=input[i];
        if(x.size()>3){
            if(x.substr(x.size()-4)=="PPAP"){
                x.erase(x.size()-4);
                x+="P";
            }
        }
    }
    if (x=="P") 
        cout << "PPAP"; 
    else 
        cout << "NP";

    return 0;
}