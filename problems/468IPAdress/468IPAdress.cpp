/* leetcode 468 */
#include "iostream"
#include "string"
#include "regex"
#include "vector"
using namespace std;
class Solution {
public:
    bool validIPv4Part(const string str) {
        int istr = stoi(str);
        if (istr < 0 || istr > 255) return false;
        int strlen = str.length();
        char strfirst = str.at(0);
        if (strfirst == '0' && strlen > 1) return false;
        return true;
    }

    bool validIPv6Part(const string str) {
        if(str.length() > 4) return false;
        int strlen = str.length();
        for (int i = 0; i < strlen; i++) {
            char ch = str.at(i);
            if(ch < '0' || ch > '9' || ch < 'a' || ch > 'z' || ch < 'A' || ch > 'Z') return false;
        }
        return true;
    }

    void Stringsplit(const string& str, const string& split, vector<string>& res) {
        std::regex reg(split);
        std::sregex_token_iterator pos(str.begin(), str.end(), reg, -1);
        decltype(pos) end;
        for(; pos != end; ++pos) {
            res.push_back(pos->str());
        }
    }

    string validIPAddress(string queryIP) {
        if (queryIP.find(".")) { //ipv4
            vector<string> strIPPart;
            Stringsplit(queryIP, ".", strIPPart);
            int IPPartNum = 0;
            for(auto s : strIPPart) {
                bool ret = validIPv4Part(s);
                if(!ret) return "Neither";
                IPPartNum++;
                if(IPPartNum > 4) return "Neither";
            }
            if(IPPartNum < 4) return "Neither";
        } else if(queryIP.find(":")){   //ipv6
            vector<string> strIPPart;
            Stringsplit(queryIP, ":", strIPPart);
            int IPPartNum = 0;
            for(auto s : strIPPart) {
                bool ret = validIPv6Part(s);
                if(!ret) return "Neither";
                IPPartNum++;
                if(IPPartNum > 8) return "Neither";
            }
            if(IPPartNum < 8) return "Neither";
        }
    }
};

int main()
{
    Solution test;
    string ret = test.validIPAddress("172.16.254.1");
    printf("IP:%s\n", &ret);
    return 0;
}