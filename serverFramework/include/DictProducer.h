#pragma once
#include <string>
#include <vector>
#include <map>
#include "SplitTool.h"
#include <memory>
using std::string;
using std::vector;
using std::map;
class DictProducer
{
    using pSplitTool = std::weak_ptr<SplitTool>;
public:
    DictProducer(const string &dir);
    DictProducer(const string &dir,pSplitTool splitTool);
    ~DictProducer() {}
    void build_dict();
    void build_cn_dict();
    void store_dict(string &filename);
private:
    void get_files();
    void push_dict(const string &word);
    string _dir;
    vector<string> _files;
    map<string,int> _dict;
    pSplitTool _splitTool;
};

