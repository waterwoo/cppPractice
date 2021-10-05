//
// Created by waterwoo on 2021/10/4.
//

#include "licenseKeyFormatting.h"
#include <algorithm>
#include <string>

using std::string;


string licenseKeyFormatting::licenseKeyFormatting_(string s, int k) {
    auto l = s.size();
    int j = 0;
    string result;
    for (int i = l-1; i >= 0; --i) {
        if (s[i] == '-')
            continue;
        if ((j+1)%(k+1)==0){
            result += '-';;
            j++;
            i++;
            continue;
        }
        auto m = toupper(s[i]);
        result += m;
        j++;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
