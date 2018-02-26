#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;

bool stringToBool(string c){
    if(c.compare("1")==0){
        return true;
    }else{
        return false;
    }
}


int countEval(string s, bool result, map<string, int> &memo){
    if(s.length()== 0){
        return 0;
    }
    if(s.length() == 1){
        return stringToBool(s) == result ? 1:0;
    }
    map<string, int>::iterator iter;
    if(result){
        iter = memo.find("true"+s);
    }else{
        iter = memo.find("false"+s);
    }

    if(iter != memo.end()){
        if(result){
            return memo["true"+s];
        }else{
            return memo["false"+s];
        }

    }

    int ways=0;
    for(int i=1; i<s.length();i+=2){
        char c = s.at(i);
        string left = s.substr(0,i);
        string right = s.substr(i+1);

        int leftTrue = countEval(left, true, memo);
        int leftFalse = countEval(left, false, memo);
        int rightTrue = countEval(right, true, memo);
        int rightFalse = countEval(right, false, memo);
        int total = (leftTrue + leftFalse)*(rightTrue+rightFalse);

        int totalTrue = 0;
        if(c=='^'){
            totalTrue = leftTrue*rightFalse + leftFalse*rightTrue;
        }else if(c=='&'){
            totalTrue = leftTrue*rightTrue;
        }else if(c=='|'){
            totalTrue = leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
        }

        int subWays = result ? totalTrue: (total-totalTrue);
        ways += subWays;

    }

    if(result){
        memo.insert(pair<string, int>("true"+s, ways));
    }else{
        memo.insert(pair<string, int>("false"+s, ways));
    }

    return ways;

}



int main(){
    string expression = "0&0&0&1^1|0";
    bool target_result = true;
    map<string, int> memo;
    int result_ways = countEval(expression, target_result, memo);
    cout<<"the number of ways is "<<result_ways<<endl;
    return 0;
}

