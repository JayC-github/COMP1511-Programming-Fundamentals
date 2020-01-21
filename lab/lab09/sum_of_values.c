#include<stdio.h>
#include<stdlib.h>

int main(void) {

}

struct node {
    struct node *next; // struct node is a type
    int data;
};

// creates a new linked list and return a pointer
// must be called before using list function
struct node *create_list(void){
    return NULL;
}


int sum_list_values(struct node *list) {
    int sum = 0;
    struct node *current = list;
    while (current != NULL) {
        sum = sum + current->data;
        current = current->next;
    }      
    return sum;
}

int list_length(struct node *list){
    int length = 0;
    struct node *current = list;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;

}

// prepend................
struct node *prepend(struct node *list, int data) {
    sturct node *temp = list;
    list = new_node(data, temp);
    
    return list;
}

struct node *new_node(int data, struct node *next) {
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = next;
    return new;
    
}

// append................
struct node *append(struct node *list , int data) {
    if (list == NULL) {
        return new_node(data,NULL);
    }
    
    
    
    struct node *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = new_node(data,NULL);
    return list;
}



struct node *sorted(struct node *list, int data) {
    if (list == NULL) {
        return new_node(data,NULL);
    }
    
    
    
    struct node *current = list;
    while (current->next != NULL) {
        if (data <= current->next->data) {
            struct node *temp = current->next;
            current 
        } 
        
        current = current->next;
    }
    
    current->next = new_node(data,NULL); 

    return list;
}
