#include<stdio.h>
#include<string.h>
typedef struct word {
    char* data;
}Word;
typedef struct Sentence {
    struct word* data;
    int word_count;//the number of words in a sentence
}Sentence;
typedef struct Paragraph {
    struct sentence* data  ;
    int sentence_count;//the number of sentences in a paragraph
}Paragraph;
typedef struct Document {
    struct paragraph* data;
    int paragraph_count;//the number of paragraphs in a document
}Document;
Paragraph kth_paragraph(int k){

}
int main(){
    int n;
    Document* doc = malloc(sizeof(Document));
    scanf("%d", &n);
    doc->data = malloc(n*sizeof(Paragraph));
    doc->paragraph_count = n;
    Paragraph* p = malloc(n * sizeof(Paragraph));
    for(int i = 0; i < n; i++){
        p->sentence_count = 0;
        Sentence* sentences = malloc(1000*sizeof(Sentence));
        sentences->data = malloc(1000*sizeof(Word));
        sentences->word_count = 0;
        Word* words = malloc(1000*sizeof(Word));
        words->data = malloc(1000*sizeof(char));
        char c;
        scanf("%c", &c);
        while(c != '\n' && c != '\0'){
            if(c != " " && (c != '.')) {
                words->data = c;
            }
            if(c == ' ' || c == '.'){
                sentences->word_count++;
            }
            if(c == '.'){
                p->sentence_count++;
            }
            words++;
            scanf("%c", &c);
        } 
    }
    return 0;
}