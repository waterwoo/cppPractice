//
// Created by waterwoo on 2021/11/14.
//

#ifndef CPPPRACTICE_MAPSUM_H
#define CPPPRACTICE_MAPSUM_H
#include <string>
#include <unordered_map>

using namespace std;
class MapSum {
//     暴力扫描
public:
    MapSum() = default;

    void insert(const string& key, int val) {
        cnt[key] = val;
    }

    int sum(string prefix) {
        int res=0;
        for (auto & [key, val]: cnt) {
            if (key.substr(0, prefix.size())==prefix)
                res+=val;
        }
        return res;
    }
    unordered_map<string, int> cnt;
};


#endif //CPPPRACTICE_MAPSUM_H
