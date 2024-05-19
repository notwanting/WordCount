#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
#include <string.h>  
  
int count_characters(const char *filename) {  
    FILE *file = fopen(filename, "r");  
    if (file == NULL) {  
        perror("Error opening file");  
        return -1;  
    }  
  
    int count = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        count++;  
    }  
  
    fclose(file);  
    return count;  
}  
  
int count_words(const char *filename) {  
    FILE *file = fopen(filename, "r");  
    if (file == NULL) {  
        perror("Error opening file");  
        return -1;  
    }  
  
    int count = 0;  
    int in_word = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (!isspace(ch) && !ispunct(ch)) { // 假设单词不包含标点符号  
            if (!in_word) {  
                in_word = 1;  
                count++;  
            }  
        } else {  
            in_word = 0;  
        }  
    }  
  
    fclose(file);  
    return count;  
}  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        fprintf(stderr, "Usage: %s (-c | -w) <filename>\n", argv[0]);  
        return 1;  
    }  
  
    const char *filename = argv[2];  
    int result = -1;  
  
    if (strcmp(argv[1], "-c") == 0) {  
        result = count_characters(filename);  
    } else if (strcmp(argv[1], "-w") == 0) {  
        result = count_words(filename);  
    } else {  
        fprintf(stderr, "Invalid option: %s\n", argv[1]);  
    }  
  
    if (result >= 0) {  
        printf("%s: %d\n", (strcmp(argv[1], "-c") == 0) ? "字符数" : "单词数", result);  
    }  
  
    return (result < 0) ? 1 : 0;  
}
