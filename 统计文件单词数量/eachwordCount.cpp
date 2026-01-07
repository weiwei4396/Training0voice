// 2026.1.7
// eachwordCount.cpp 统计文本文件中每个单词的数量; 基于状态机; 
// 将每个单词所有字母加和做哈希值; 但问题是会出现哈希冲突;
// 最终还是将每个单词作为key;
// pan wei

#include <iostream>
#include <unordered_map>
#include <string>

#define IN 1
#define OUT 0
#define INIT OUT


bool isSplit(char c) {
    if (c == ' ' || c == '\n' || c == '\t' || c == '\"' || c == '\''
        || c == ',' || c == '.' || c == '!' || c == '?' || c == ';'
        || c == '+') {
        return true;
    } else {
        return false;
    }
}


void wordCount(char *filePath, std::unordered_map<std::string, int>& wordHash) {
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL) return;
    
    int status = INIT;
    std::string currentWord;
    int c;
    
    while ((c = fgetc(fp)) != EOF) {
        if (isSplit(c)) {
            if (status == IN) {
                wordHash[currentWord]++;
            }
            status = OUT;
            currentWord.clear(); 
        } else {
            status = IN;
            currentWord += (char)c;
        }
    }
    // 最后一个单词;
    if (!currentWord.empty()) {
        wordHash[currentWord]++;
    }    
}


int main(int argc, char *argv[]) {

    std::unordered_map<std::string, int> wordHashMap; 

    wordCount(argv[1], wordHashMap);
    
    for (const auto& word:wordHashMap) {
        std::cout << word.first << ": " << word.second << "\n";
    }
    
    return 0;
}



