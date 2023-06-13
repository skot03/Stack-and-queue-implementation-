#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct {
    char name[30];
    char surname[30];
    unsigned byear;
} Student;

typedef struct _Node{
    Student data;
    struct _Node* next;
} Node;

typedef struct{
    Node* head;
} Queue;

void push(Queue* l, Student s){

    if(!l->head) {
        l->head = (Node*)malloc(sizeof(Node));
        l->head->data = s;
        l->head->next = NULL;
        return;
    }

    Node* t = l->head;
    while(t->next){
        t=t->next;
    }

    t->next = (Node*)malloc(sizeof(Node));
    t->next->data = s;
    t->next->next = NULL;
}

void showTop(Queue* l){
        if(!l->head){
            puts("Queue is empty");
            return;
        }
        Student s = l->head->data;
        printf("%s %s %u\n", s.name, s.surname, s.byear);
}

void pop(Queue* l){
    if(!l->head) {
        puts("Queue is empty");
        return;
    }
    if(l->head->next){
        Node* newHead = l->head->next;
        free(l->head);
        l->head = newHead;
        return;
    }
    free(l->head);
    l->head = NULL;

}

int main()
{
    Queue students;
    students.head = NULL;
    Student tmp;
    char answer;
    while(1){
        printf("1. Add student\n2. Remove Student\n3. Show Student\n4. Exit\n\nAnswer: ");
        answer = getchar();
        getchar();
        switch(answer){
        case '1':
            printf("name: ");
            scanf("%s", tmp.name);
            getchar();

            printf("surname: ");
            scanf("%s", tmp.surname);
            getchar();

            printf("byear: ");
            scanf("%u", &tmp.byear);
            getchar();

            push(&students, tmp);
            break;

         case '2':
            putchar('\n');
            pop(&students);
            putchar('\n');
            break;

         case '3':
            showTop(&students);
            break;

         case '4':
            exit(0);
            break;
        }

        system("pause");
        system("cls");
    }
    return 1;
}
