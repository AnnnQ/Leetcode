#include "common.h"

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        for(int i = 0; i < words.size(); i++)
        {
            int icurlen = 0;
            int j = i;
            for(j; j < words.size(); j++)
            {
                icurlen += words[j].size() + 1;
                if(icurlen > maxWidth + 1)
                {
                    icurlen -= words[j].size() + 1;
                    break;
                }
            }

            int ispacecount = 0;
            for(int k = i; k < j; k++)
            {
                ispacecount += words[k].size();
            }
            ispacecount = maxWidth - ispacecount;

            int ispacebetween = 0;
            int ispaceextra = 0;
            if(j - i > 1)
            {
                ispacebetween = ispacecount / (j - 1 - i);
                ispaceextra = ispacecount % (j - 1 - i);
            }

            string curline;
            if(j < words.size() && j - i > 1)
            {
                for(int k = i; k < j; k++)
                {
                    curline += words[k];
                    if(k < i + ispaceextra)
                    {
                        string strspace(ispacebetween + 1, ' ');
                        curline += strspace;
                    }
                    else if(k < j - 1)
                    {
                        string strspace(ispacebetween, ' ');
                        curline += strspace;
                    }
                }
            }
            else if(j < words.size() && j - i == 1)
            {
                curline += words[i];
                string strspace(ispacecount, ' ');
                curline += strspace;
            }
            else
            {
                for(int k = i; k < j; k++)
                {
                    curline += words[k];
                    if(k < j - 1)
                    {
                        curline += ' ';
                    }
                    else
                    {
                        string strspace(maxWidth - curline.size(), ' ');
                        curline += strspace;
                    }
                }
            }

            result.push_back(curline);
            
            i = j - 1;
        }

        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> words1 = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth1 = 16;
    vector<string> result1 = sol.fullJustify(words1, maxWidth1);
    for(const string& line : result1)
    {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words2 = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth2 = 16;
    vector<string> result2 = sol.fullJustify(words2, maxWidth2);
    for(const string& line : result2)
    {
        cout << "\"" << line << "\"" << endl;
    }

    vector<string> words3 = {"Science","is","what","we","understand","well","enough","to","explain",
                             "to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth3 = 20;
    vector<string> result3 = sol.fullJustify(words3, maxWidth3);
    for(const string& line : result3)
    {
        cout << "\"" << line << "\"" << endl;
    }

    return 0;
}
