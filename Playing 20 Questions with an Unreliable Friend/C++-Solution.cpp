#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//Reference to meelo's solution
//Page: http://www.cnblogs.com/meelo/p/6091490.html

const int num_balloon = 10;
const int num_color = 3;

void number2Colors(int number, vector<char> &colors) {
    for(int i=0; i<num_balloon; i++) {
        int color = number % num_color;
        number /= num_color;
        if(color == 0) colors[i] = 'r';
        else if(color == 1) colors[i] = 'g';
        else if(color == 2) colors[i] = 'b';
    }
}

struct Question {
    int type;
    int count, index;
    char color;
    
    bool isTrue(vector<char> colors) {
        bool truth;
        if(type == 1) {
            truth = colors[index] == color;
        }
        else if(type == 2) {
            int c = 0;
            for(int i=0; i<num_balloon; i++) {
                if(colors[i] == color) {
                    c++;
                }
            }
            truth = c == count;
        }
        return truth;
    }
};

struct Questions {
    int combine;
    bool truth;
    vector<Question> questions;
    
    Questions() {
        combine = 1;
    }
    
    bool isTrue(vector<char> &colors) {
        bool result;
        if(combine == 1) {
            result = true;
        }
        else if(combine == 2) {
            result = false;
        }
        
        for(int i=0; i<questions.size(); i++) {
            if(combine == 1) {
                result &= questions[i].isTrue(colors);
                if(!result) break;
            }
            else if(combine == 2){
                result |= questions[i].isTrue(colors);
                if(result) break;
            }
        }
        
        return result;
    }
    
    bool satisfy(vector<char> &colors) {
        return isTrue(colors) == truth;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++) {
        int Q, L;
        cin >> Q >> L;
        Questions lines[21];
        
        for(int q=0; q<Q; q++) {
            while(true) {
                Question question;
                string type, answer, color;
                int index, count;
                cin >> type;
                if(type == "color") {
                    cin >> index >> color;
                    question.type = 1;
                    question.color = color[0];
                    question.index = index-1;
                    
                }
                else if(type == "count") {
                    cin >> color >> count;
                    question.type = 2;
                    question.color = color[0];
                    question.count = count;
                }
                
                lines[q].questions.push_back(question);
                
                cin >> answer;
                if(answer == "yes") {
                    lines[q].truth = true;
                    break;
                }
                else if(answer == "no") {
                    lines[q].truth = false;
                    break;
                }
                else if(answer == "and") {
                    lines[q].combine = 1;
                }
                else if(answer == "or") {
                    lines[q].combine = 2;
                }
            }
        }
        
        vector<vector<bool> > answer(num_balloon, vector<bool>(num_color, 0));
        int maxNumber = pow(num_color,num_balloon);
        for(int c=0; c<maxNumber; c++) {
            vector<char> colors(num_balloon);
            number2Colors(c, colors);
            int numLies = 0;
            for(int q=0; q<Q; q++) {
                numLies += lines[q].satisfy(colors) == false;
            }
            if(numLies == L) {
                for(int i=0; i<num_balloon; i++) {
                    if(colors[i]=='r') answer[i][0] = true;
                    else if(colors[i]=='g') answer[i][1] = true;
                    else if(colors[i]=='b') answer[i][2] = true;
                }
            }
        }
        
        for(int i=0; i<num_balloon; i++) {
            if(answer[i][0]) cout << 'r';
            if(answer[i][1]) cout << 'g';
            if(answer[i][2]) cout << 'b';
            if(i != num_balloon-1) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
