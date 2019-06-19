#include "../include/DictProducer.h"
#include "../include/SplitTool.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
DictProducer::DictProducer(const string& dir)
:_dir(dir)
,_splitTool(nullptr)
{
    ifstream ifs;
    ifs.open(_dir);
    string paths;
    while(ifs >> paths)
    {
        _files.push_back(paths);
    }
}
DictProducer::DictProducer(const string &dir,pSplitTool splitTool)
:_dir(dir)
,_splitTool(splitTool)
{}
void DictProducer::build_dict()
{
    for(auto &file: _files)
    {
        ifstream ifs(file);
        string tmp;
        while(ifs >> tmp)
        {
            ++_dict[tmp];
        }
    }
}
void DictProducer::build_cn_dict()
{}
void DictProducer::store_dict(string &filename)
{
    
    ofstream odict(filename,ios_base::out|ios_base::trunc);
    for(auto item:_dict)
    {
        odict << item.first << " " << item.second << endl;
    }
    odict.close();
}
void DictProducer::store_index(string &filename)
{
    ofstream oidx(filename,ios_base::out|ios_base::trunc);
    int i = 0;
    for(auto pairword:_dict)
    {
        string word = pairword.first;
        for(auto c:word)
        {
            string ch;
            ch.push_back(c);
           _index[ch].insert(i); 
        }
        ++i;
    }
    for(auto c:_index)
    {
        oidx << c.first << " ";
        for(auto ch:c.second)
        {
            oidx << ch << " ";
        }
        oidx << endl;
    }
}
