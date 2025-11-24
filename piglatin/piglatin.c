#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_word(){
    char* word = malloc(100);
    int capacity = 100;
    int length = 0;
    int c;

    printf("Enter word or type 1111 to quit: ");

    while((c = getchar()) != '\n' && c != ' ' && c != EOF){
        if (length >= capacity - 1){
            capacity *= 2;
            word = realloc(word, capacity);
            if (!word){
                printf("Memory allocation failed\n");
                return NULL;
            }
        }
        word[length++] = c;
    }
    word[length] = '\0';
    return word;

}
char* pig_latin_convert(char* word){
    const char vowels[] = "aeiouy";
    int starts_with_vowel = 0;

    for (int i = 0; i < 6; i++){
        if (word[0] == vowels[i]){
            starts_with_vowel = 1;
            break;
        }
    }

    char* result = malloc(strlen(word) + 4);

    if (starts_with_vowel){
        sprintf(result, "%sway", word);
    }
    else{
        sprintf(result, "%s%cay", &word[1], word[0]);
    }
    return result;
}
int main(){
    char *word;
    char **sentence = malloc(100 * sizeof(char*));
    int word_count = 0;
    int capacity = 100;


    while(1){
        word = read_word();
        if (!word) break;
        
        if (strcmp(word, "1111") == 0){ 
            free(word); break; 
        }

        char* converted = pig_latin_convert(word);

        if (word_count >= capacity){
            capacity *= 2;
            sentence = realloc(sentence, capacity * sizeof(char*));
        }

        sentence[word_count] = converted;
        word_count++;

        free(word);
    }
    printf("Output: ");
    for (int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if (i < word_count - 1){
            printf(" ");
        }
        free(sentence[i]);

    }
    printf(".\n");

    free(sentence);
    return 0;
}
