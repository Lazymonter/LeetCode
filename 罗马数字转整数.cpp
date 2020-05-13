#include <iostream>
#include <string>

using namespace std;

int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'I'){
            if(i == s.length() - 1){
                result += 1;
            }
            else{
                if(s[i + 1] == 'V'){
                    result += 4;
                    i++;
                }else if(s[i + 1] == 'X'){
                    result += 9;
                    i++;
                }else if(s[i + 1] == 'I'){
                    result += 1;
                }else{
                    return 0;
                }
            }
        }else if (s[i] == 'V'){
            result += 5;
        }else if (s[i] == 'X'){
            if(i == s.length() - 1){
                result += 10;
            }
            else{
                if(s[i + 1] == 'L'){
                    result += 40;
                    i++;
                }else if(s[i + 1] == 'C'){
                    result += 90;
                    i++;
                }else if (s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I'){
                    result += 10;
                }else{
                    return 0;
                }
            }

        }else if (s[i] == 'L'){
            result += 50;

        }else if (s[i] == 'C'){
            if(i == s.length() - 1){
                result += 100;
            }
            else{
                if(s[i + 1] == 'D'){
                    result += 400;
                    i++;
                }else if (s[i + 1] == 'M'){
                    result += 900;
                    i++;
                }else if(s[i + 1] == 'C' || s[i + 1] == 'L' || s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I'){
                    result += 100;
                }else{
                    return 0;
                }
            }
        }else if (s[i] == 'D'){
            result += 500;

        }else if (s[i] == 'M'){
            result += 1000;
        }else{
            return 0;
        }
    }
    return result;
        
}
int main(){
    string roman = "";
    cin >> roman;
    cout << romanToInt(roman) << endl;

}