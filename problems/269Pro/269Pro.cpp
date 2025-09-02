#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution269 {
public:
    const int VISITING = 1, VISITED = 2;
    unordered_map <char, vector<char>> edges;
    unordered_map<char, int> states;
    bool valid = true;
    string order;

    string alienOrder(vector<string>& words);
    void dfs(char ch);
    void edge_build(string pre, string next);
};

string Solution269::alienOrder(vector<string>& words)
{
    
}
void Solution269::dfs(char ch)
{
}

void Solution269::edge_build(string pre, string next)
{
}