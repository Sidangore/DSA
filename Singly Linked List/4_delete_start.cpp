#include <iostream>
#include <iomanip>

class Node {
    public:
        int data;
        Node* next;        
};

void delete_at(Node** head_ref, int position) {
    
    if(*head_ref == NULL) {
        std::cout << "No nodes in SLL" << std::endl;
        return;
    }

    Node* temp = *head_ref, *prev = *head_ref;

    for(int i = 0; i < position; i++) {
        if(i == 0 && position == 1) {
            *head_ref = (*head_ref)->next;
            free(temp);
            free(prev);
        } else {
            if(i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            } else {
                prev = temp;
                
                if(prev == NULL) break;
                temp = temp->next;
            }
        }
    }




}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

void print_list(Node* node) {
    while(node != NULL) {
        std::cout << " " << node->data;
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = NULL;

    for(int i = 1; i <= 6; i++) {
        append(&head, i);
    }

    std::cout << "Initial SLL:";
    print_list(head);

    delete_at(&head, 2);
    std::cout << "Delete at 2:";
    print_list(head);

    return 0;
}