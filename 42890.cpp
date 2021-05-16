#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    auto features = vector<unordered_map<string, int8_t>>(relation[0].size(), unordered_map<string, int8_t>());
    auto encoded = vector<long long>(relation.size(), 0);
    
    for(int i = 0; i < relation.size(); i++) {
        for(int j = 0; j < relation[i].size(); j++) {
            features[j][relation[i][j]] = i;
        }
    }
    
    for(int i = 0; i < relation.size(); i++) {
        for(int j = 0; j < relation[i].size(); j++) {
            encoded[i] = encoded[i]<<8;
            encoded[i] += features[j][relation[i][j]];
        }
    }
    
    auto permutation = vector<bool>(relation[0].size(), true);
    vector<vector<int>> found;
    for(int i = 0; i < relation[0].size(); i++) {
        permutation[i] = false;
        auto temp = permutation;
        
        do {
            bool skip = false;
            
            for(int j = 0; j < found.size(); j++) {
                vector<bool> subsetChecker;
                for(int k = 0; k < found[j].size(); k++) {
                    if(temp[found[j][k]]) {
                        subsetChecker.push_back(false);
                    } else {
                        subsetChecker.push_back(true);
                    }
                }
                if(!subsetChecker.empty() && all_of(subsetChecker.begin(), subsetChecker.end(), [](bool a) { return a; })) {
                    skip = true;
                    break;
                }
            }
            
            if(skip) continue;
            
            set<long long> candidates;
            
            long long mask = 0;
            
            for(int j = 0; j < temp.size(); j++) {
                if(temp[j] == false) {
                    long long tempMask = static_cast<long long>(0xff) << ((temp.size() - 1 - j) * 8);
                    mask += tempMask;
                }
            }
            
            for(int j = 0; j < encoded.size(); j++) {
                long long masked = encoded[j] & mask;
                if(candidates.find(masked) != candidates.end()) {
                    continue;
                }
                candidates.insert(masked);
            }
            
            if(candidates.size() == relation.size()) {
                vector<int> index;
                for(int i = 0; i < temp.size(); i++) {
                    if(!temp[i]) {
                        index.push_back(i);
                    }
                }
                found.push_back(index);
                answer++;
            }
            
        } while (next_permutation(temp.begin(), temp.end()));
    }
    return answer;
}
