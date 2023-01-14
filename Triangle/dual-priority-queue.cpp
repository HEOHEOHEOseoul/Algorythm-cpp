#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> onlyNum;
    vector<string> onlyCommand;
    vector<int> last;

    vector<int> answer;
    for(int i=0; i<operations.size(); i++) {
        onlyNum.push_back(stoi(operations[i].substr(2)));
        onlyCommand.push_back(operations[i].substr(0, 1));

        if(onlyCommand[i]=="I") { last.push_back(onlyNum[i]); }
        else {
            if(last.size()==0) continue;
            else if(onlyNum[i]==1) last.erase(max_element(last.begin(), last.end()));
            else if(onlyNum[i]==-1) last.erase(min_element(last.begin(), last.end()));
        }
    }

    if(last.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }else {
        answer.push_back(*max_element(last.begin(), last.end()));
        answer.push_back(*min_element(last.begin(), last.end()));
    }

    return answer;
}

int main() {
    vector<string> exam1 = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
    vector<string> exam2 = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    
    solution(exam1);

    return 0;
}