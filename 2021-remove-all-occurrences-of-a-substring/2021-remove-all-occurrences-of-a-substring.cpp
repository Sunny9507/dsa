class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int indx = s.find(part);

            if(indx == string::npos){
                break;
            }

            s.erase(indx, part.length());
        }    

        return s;
    }
};