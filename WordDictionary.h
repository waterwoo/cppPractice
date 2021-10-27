//
// Created by Waterwoo on 2021/10/19.
//

#ifndef CPPPRACTICE_WORDDICTIONARY_H
#define CPPPRACTICE_WORDDICTIONARY_H
#include <vector>
#include <string>

using namespace std;
class WordDictionary {
    public:
        WordDictionary() {
        }
    vector<string> s;

        void addWord(string word) {
            if (!search(word))
                s.push_back(word);
        }

        bool search(string word) {
            ;
        }
    };

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


#endif //CPPPRACTICE_WORDDICTIONARY_H
