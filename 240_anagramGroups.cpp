#include<bits/stdc++.h>
using namespace std;

//Anagram Groups

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // Create a map to store groups of anagrams
    // The key is a sorted version of the word
    // The value is a list of words that are anagrams of each other
    unordered_map<string, vector<string>> anagramGroups;

    // Iterate over each word in the input vector
    for (const string& word : strs) {
        // Create a copy of the word and sort its characters
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        
        // Add the original word to the list of its anagram group
        anagramGroups[sortedWord].push_back(word);
    }

    // Create a result vector to store the groups of anagrams
    vector<vector<string>> result;
    
    // Iterate over the map and add each group of anagrams to the result
    for (auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}



int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    for (const auto& group : result) {
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

return 0;
}