#pragma once
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include "SplitTool.h"
using std::string;
using std::vector;
using std::map;
using std::set;
using std::unordered_map;
class DictProducer
{
    using pSplitTool = SplitTool*;
public:
    DictProducer(const string &dir);
    DictProducer(const string &dir,pSplitTool splitTool);
    ~DictProducer() {}
    void build_dict();
    void build_cn_dict();
    void store_dict(string &filename);
    void store_index(string &filename);
private:
    string _dir;
    vector<string> _files;
    map<string,int> _dict;
    unordered_map<string,set<int>> _index;
    pSplitTool _splitTool;
};

