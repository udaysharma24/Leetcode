class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        deque<char> dq;
        bool carry=false;
        while(!a.empty() && !b.empty()){
            if(a.back()=='1' && b.back()=='1'){
                if(carry==false){
                    dq.push_front('0');
                    carry=true;
                }
                else
                    dq.push_front('1');
                a.pop_back();
                b.pop_back();
            }
            else if(a.back()=='1' && b.back()=='0'){
                if(carry==false)
                    dq.push_front('1');
                else
                    dq.push_front('0');
                a.pop_back();
                b.pop_back();
            }
            else if(a.back()=='0' && b.back()=='1'){
                if(carry==false)
                    dq.push_front('1');
                else
                    dq.push_front('0');
                a.pop_back();
                b.pop_back();
            }
            else if(a.back()=='0' && b.back()=='0'){
                if(carry==false)
                    dq.push_front('0');
                else{
                    dq.push_front('1');
                    carry=false;
                }
                a.pop_back();
                b.pop_back();
            }
        }
        while(!a.empty()){
            if(a.back()=='1'){
                if(carry==false)
                    dq.push_front('1');
                else
                    dq.push_front('0');
                a.pop_back();
            }
            else if(a.back()=='0'){
                if(carry==false)
                    dq.push_front('0');
                else{
                    dq.push_front('1');
                    carry=false;
                }
                a.pop_back();
            }
        }
        while(!b.empty()){
            if(b.back()=='1'){
                if(carry==false)
                    dq.push_front('1');
                else
                    dq.push_front('0');
                b.pop_back();
            }
            else if(b.back()=='0'){
                if(carry==false)
                    dq.push_front('0');
                else{
                    dq.push_front('1');
                    carry=false;
                }
                b.pop_back();
            }
        }
        if(carry==true)
            dq.push_front('1');
        string s(dq.begin(),dq.end());
        return s;
    }
};