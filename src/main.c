#include <stdio.h>
#include <string.h>

typedef struct stack_s stack;

struct stack_s{               //структура стека
    char data;
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


stack *push(stack *head, stack *node){ // добавление операции в стек
    if (node)
        node->next = head;
    else
        node = head;
    return node;
};

stack *delete(stack *head, char *ch){ // удаление элемента из стека
    stack *stack = head->next;
    if (head == NULL)
        *ch = '\0';
    else
        *ch = head->data;
    free(head);
    return stack;
}

void free_stack(stack *head) {  // функция очистки стека
    for (stack *tmp; head; head = tmp) {
        tmp = head->next;
        free(head);
    }
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


// int calculate()
// array[80];
// for( i=0; i<80;i++){
// int x=i*PI/20;
// array[i]= ;  
// }

