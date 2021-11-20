//
// Created by waterwoo on 2021/11/15.
//

#ifndef CPPPRACTICE_BULBSWITCH_H
#define CPPPRACTICE_BULBSWITCH_H
#include <vector>
#include <math.h>
class bulbSwitch {
public:
    int bulbswitch(int n) {

        return sqrt(n);
//        // 暴力
//        if(n<2)
//            return n;
//        int ans=0;
//        std::vector<int> vec(n, 1);
//        for (int i=2;i<=n;i++){
//            for (int j = 1; j <= n; ++j) {
//                if(j%i==0){
//                    if(vec[j-1]==1)
//                        vec[j-1]=0;
//                    else
//                        vec[j-1]=1;
//                }
//            }
//        }
//        for (auto s:vec) {
//            ans+=s;
//        }
//        return ans;
    }
};


#endif //CPPPRACTICE_BULBSWITCH_H
