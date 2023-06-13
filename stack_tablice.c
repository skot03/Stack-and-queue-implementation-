#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define size 3

typedef struct {
    char name[30];
    char surname[30];
    unsigned byear;
} Student;

typedef struct{
    Student students[size];
    unsigned counter;
} Stack;

void push(Stack* l, Student s){
    l->students[l->counter] = s;
    ++l->counter;
}

void showTop(Stack* l){
        if(l->counter == 0){
            puts("Stack is empty");
            return;
        }
        Student s = l->students[l->counter-1];
        printf("%s %s %u\n", s.name, s.surname, s.byear);
}

void pop(Stack* l){
    if(l->counter == 0){
        puts("Stack is empty");
        return;
    }
    --l->counter;
}

int main()
{
    Stack students;
    students.counter = 0;
    Student tmp;
    char answer;
    while(1){
        printf("1. Add student\n2. Remove Student\n3. Show Student\n4. Exit\n\nAnswer: ");
        answer = getchar();
        getchar();
        switch(answer){
        case '1':
            if(students.counter == size){
                printf("Stack is full\n");
                break;;
            }
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
