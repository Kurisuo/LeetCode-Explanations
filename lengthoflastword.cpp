#include <string>
using namespace std;

class Solution {
public:
    //my solution fixed
    int lengthOfLastWord(string s) {

        if (s.empty()){
            return 0;
        }

        bool notSpace = false;
        int count = 0;
        for(int i = s.length() - 1; i >= 0; i--){ 
            if (s[i] != ' ') { 
                notSpace = true;
                count++;
            }
            else if (notSpace){
                break;
            }
        }
   
        return count;
    }
};


//my old idea

//My initial idea was to use .rfind() & .substr()
//.rfind() would locate the LAST instance of the trailing whitespace and return its position
//.substr() would use our position returned from rfind to get the last word 
//the outcome of substr would be fed into .length() to return the length
//this does not work when we have trailing whitespaces AFTER the last word 

      //  if(s.back() == ' '){ 
       //     s.back() = '';
       // }
       
       // auto pos = s.rfind(' '); //find last occurence position
       // string str = s.substr(pos); //get last word
       // return str.length() - 1;