struct node *list_append(struct node* list1, struct node*list2) {
    struct node *last = list1; // new pointer name last
    while (last != NULL) {
        last= last->next;
    }

    last->next = list2;
    
    return list1;
}

struct node*copy(struct node*head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *newhead = malloc(sizeof(struct node)); //create a n
    newhead->data = head->data;    
    newhead->next = copy(head->next);

    return newhead;   
    /*struct node *newhead;
    struct node *s;    
    struct node *prev;
    while (s != NULL) {
        
    
    }
    
    */   
}


int identical(struct node *head1, struct node *head2) {
    struct node *n1 = head1;
    struct node *n2 = head2;
    while (n1->data == n2->data && n1!= NULL && n2 != NULL) {
        n1 = n1->next;
        n2 = n2->next;
    }
    
    return (n1 == NULL && n2 == NULL); // 1 means euqal , 0 means not

    return ngfuygikuhb // recursive
}

int ordered(struct node *head) {
    if (head == NULL) {
     return 1;
    }
    struct node *prev = head;
    struct node *current = head->next;
    while (current != NULL) {
        if (current->data <= prev->data) {
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return 1;       // 1 means it's order, 0 means not

    struct node *current = head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data <= current->data) {
            return 0;
        }
        current = current->next;
    }
    return 1; // 1 means it's order, 0 means not
 
}


struct node *set_union(struct node *set1, struct node *set2) {
    if (set1 == NULL && set2 == NULL) {
        return NULL;
    }
    struct node *s1 = set1;
    struct node *s2 = set2;
    struct node *prev;
    while (s1 != NULL && s2 != NULL) {
        if (s1->data < s2->data) {
            struct node *c1 = malloc (sizeof(struct node)); // make a new struct name copy1;
            c1->data = s1->data;
            prev->next = c1;
            s1 = s1->next;
            prev = c1;
        } else if (s1->data > s2->data){
            struct node *c2 = mallocc (sizeof(struct node));
            prev->next =c2;
            c2->data = s2->data;
            prev= c2;
        }
    }
    if (s1 != NULL) {
        struct node copy1 = copy_list(s1);
        list append(prev, copy1);
    if (s2 != NULL) {
        struct node copy2 = copy_list(s2);
        list append(prev, copy2);
    }
    return NULL;
}







