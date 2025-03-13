#include <string>
#include <vector>

using namespace std;

int convert_str_to_int(string time){
    int int_time = 0;
    size_t semi = time.find(':');
    int first = stoi(time.substr(0, semi)); 
    int second = stoi(time.substr(semi + 1));
    
    int_time = first*60 + second;
    return int_time;
}

string convert_int_to_str(int time){
    string str_time = "";
    int min = time/60;
    int sec = time%60;
    string s_min = to_string(min);
    string s_sec = to_string(sec);
    if(s_min.size()==1){
        s_min = "0"+s_min;
    }
    if(s_sec.size()==1){
        s_sec = "0"+s_sec;
    }
    str_time = s_min + ":"+s_sec;
    return str_time;    
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int l = convert_str_to_int(video_len);
    int c = convert_str_to_int(pos);
    int op_s = convert_str_to_int(op_start);
    int op_e = convert_str_to_int(op_end);
    
    for(int i=0;i<commands.size();i++){
        if(c<=op_e && c >= op_s ){
            c = op_e;
        } 
        
        if(commands[i]=="next"){
            if(c+10<l) c +=10;
            else c = l;
        }
        else if(commands[i]=="prev"){
            if(c-10>0) c -=10;
            else c = 0;
        }
        if(c<=op_e && c >= op_s ){
            c = op_e;
        } 
        
    }
    answer = convert_int_to_str(c);
    
    return answer;
}