#include <stdio.h>
#include <string.h>
#define M_PI

typedef struct stack_s stack;

struct stack_s{               //структура стека
    char data;
    double number;
    stack *next;
};

typedef struct queue_s queue;

struct queue{               //структура очереди
    char data;
    queue *next;
};

stack *init(char data) {                    // инициация стека
    stack *stack = malloc(sizeof(stack)); 
    if (stack) {
        stack->data = data;
        stack->next = NULL;;
    }
    else
        stack = NULL;
    return stack;
}


// stack *push(stack *head, stack *node){ // добавление операции в стек
//     if (node)
//         node->next = head;
//     else
//         node = head;
//     return node;
// };

stack *push(stack *HEAD, char a, double new_number) {
    struct st *PTR;
    if ((PTR = malloc(sizeof(struct st))) == NULL) {
        puts("Sorry, not today:(");
        exit(-1);
    }
    PTR->c = a;
    PTR->number=new_number;
    PTR->next = HEAD;
    return PTR;
};

int delete(stack *head){ // удаление элемента из стека
    char ch;
    stack *stack = head->next;
    if (head == NULL)
        ch = '\0';
    else
        ch = head->data;
    free(head);
    return ch;
}

void free_stack(stack *head) {  // функция очистки стека
    for (stack *tmp; head; head = tmp) {
        tmp = head->next;
        free(head);
    }
}

stack pop(stack *head){


}

// int priority_calc(char symbol){
//     int priority = 0;
//     if (symbol == '('){
//         priority = 1;
//     }else if (symbol == '-' || symbol == '+'){
//         priority = 2;
//     }else if (symbol == '*' || symbol == '/'){
//         priority = 3;
//     // }else if (symbol == 'sin' || symbol == 'cos' || symbol == 'tan' || symbol == 'ctg' ){
//         // priority = 4;
//     }
// return priority;
// }



// char get_token(char *function){
//     queue *head = NULL;
//     char symbol;
//     for (int i = 0; function != '\0'; i++){
//         symbol = getchar();
//     }
//     if (symbol >= 'a' && symbol <= 'z'){
//     }

// }



char output[80];  // где-то там далеко живет аутпут

int calculate(*output){
stack *head;
int length = strlen(output);
int x;
double m = 0;
double result;
for (int x = 0; x<4*M_PI; x+=x*M_PI/20){
    for (int i=0;i<length;i++){
       if (sscanf(output, "%lf",&m)){
        push(head," ",m);
       }
       if (output[i] == '+'){
        result = delete(head);
        result += delete(head);
       }else if(output[i] == '-'){
        result = delete(head);
        result -= delete(head);
       }else if(output[i] == '*'){
        result = delete(head);
        result *= delete(head);
       }else if(output[i] == '/'){
        result = delete(head);
        result /= delete(head);
       }else if(output[i] == '!'){
        result = sin(delete(head));
       }else if(output[i] == '?'){
        result = cos(delete(head));
       }else if(output[i] == ':'){
        result = tan(delete(head));
       }else if(output[i] == ';'){
        result = ctg(delete(head));
       }else if(output[i] == '&'){
        result = ln(delete(head));
       }else if(output[i] == '@'){
        result = sqrt(delete(head));
       }else if(output[i] == '~'){
        result = -(delete(head));
       }

    }
}
}
