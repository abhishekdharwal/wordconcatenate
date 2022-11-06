#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* link[26];
    bool  endNode = false;
    bool  containsKey(char ch) {
        return (link[ch - 'a'] != NULL);
    }
    Node* getNode(char ch) {
        return link[ch - 'a'];
    }
    void put(char ch, Node* node) {
        link[ch - 'a'] = node;
    }
    void setEnd() {
        this->endNode = true;
    }
    bool isEnd() {
        return this->endNode;
    }
};
bool cmp(string& s1, string s2) {
    return (int)s1.length() < (int)s2.length();
}

class WordConcatenate {
private: Node* root;
public:
    WordConcatenate() {
        root = new Node();
    }
    void insert(string s) {
        Node* node = root;
        for (int i = 0; i < (int)s.length(); i++) {
            if (!node->containsKey(s[i])) {
                node->put(s[i], new Node());
            }
            node = node->getNode(s[i]);
        }
        node->setEnd();
    }
    bool search(string s) {
        Node* node = root;
        for (int i = 0; i < (int)s.length(); i++) {
            if (!node->containsKey(s[i])) return false;
            node = node->getNode(s[i]);
        }
        return node->isEnd();
    }
    bool util(Node* root, string s, int pos, vector<int>& dp) {
        int n = s.length();
        if (pos >= n) {
            return true;
        }
        if (dp[pos] != -1) return dp[pos];
        bool check = false;
        Node* node = root;
        for (int i = pos; i < n; i++) {
            if (!node->containsKey(s[i])) break;
            node = node->getNode(s[i]);
            if (node->isEnd()) {
                check |= util(root, s, i + 1, dp);
            }
        }
        return dp[pos] = check;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        int n = words.size();
        string max_word_1 = "", max_word_2 = "";
        for (int i = 0; i < n; i++) {
            if (words[i] == "") continue;
            vector<int>dp((int)words[i].length(), -1);
            if (util(root, words[i], 0, dp)) {
                if (words[i].size() > max_word_1.size()) {
                    max_word_2 = max_word_1;
                    max_word_1 = words[i];
                }
            }
            else {
                insert(words[i]);
            }

        }
        
        return { max_word_1, max_word_2 };
    }
};


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Input File Not Detected\n";
        exit(1);
    }

    auto start = chrono::high_resolution_clock::now();

    WordConcatenate* curr = new WordConcatenate();

    string inFileName = argv[1];

    fstream inFile;
    inFile.open(inFileName, ios::in);
    // vector<string> words;
    // for (int i = 0; i < 9; i++) {
    //     string s;
    //     cin >> s;
    //     words.push_back(s);
    // }

    vector<string> words;
    string temp;
    while (getline(inFile, temp))
        words.push_back(temp);
    inFile.close();
    vector<string> res = curr->findAllConcatenatedWordsInADict(words);

    auto stop = chrono::high_resolution_clock::now();
    auto diff = chrono::duration_cast<chrono::microseconds>(stop - start);

    string outputText = "";

    if (res[0].size())
        outputText += "1. Longest Compound Word: " + res[0] + "\n";
    if (res[1].size())
        outputText += "2. Second Longest Compound Word: " + res[1] + "\n";

    outputText += "\n\n Time taken for code to run : " + to_string(diff.count()) + " micro seconds";

    // cout << outputText << "\n";

    int idx = inFileName.find_last_of(".");
    string outFileName = inFileName.substr(0, idx) + "-solution.txt";

    fstream outFile;
    outFile.open(outFileName, ios::out);
    outFile << outputText;
    outFile.close();

    return 0;
}