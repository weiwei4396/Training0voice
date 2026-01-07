// 2026.1.6
// wordCount.cpp 统计文本文件中单词的数量; 状态机;
// pan wei

#include <iostream>
#include <cstdio>
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


int wordCount(char *filePath) {
    FILE *fp = fopen(filePath, "r");
    if (fp == NULL) return -1;
    
    int status = INIT;
    char c;
    int wordc {0};

    while ((c = fgetc(fp)) != EOF) {
        if (isSplit(c)) {
            status = OUT;
        } else {
            if (status == OUT) {
                status = IN;
                wordc++;
            }
        }
    }
    return wordc;
}


int main(int argc, char *argv[]) {

    int txt_word_number = wordCount(argv[1]);
    
    std::cout << "The number of words in the file is: " << txt_word_number << "\n";
    
    return 0;
}



