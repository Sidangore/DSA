/**
 * BASICS OF SINGLY LINKED LIST
*/

#include <iostream>
#include <iomanip>

class Node {
    public:
        int data;
        Node* next;        
};

/**
 * To push node at the front of a singly linked list
 * 
 * Time Complexity = O(1)
 * Auxiliary Space = O(1)
*/
void push_at_front(Node** head_ref, int new_data) {
    // 1. Allocate a New Node
    Node* new_node = new Node();

    // 2. Put data in the new node
    new_node->data = new_data;

    // 3. Reference the next of new node as head
    new_node->next = (*head_ref);

    // 4. Move head to point to the new node
    (*head_ref) = new_node;
}

/**
 * This will print the singly linked list till it encounters NULL,
 * As the last reference is made to NULL
*/
void print_list(Node* node) {
    while(node != NULL) {
        std::cout << " " << node->data;
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Start writing your code below...
    Node* head = NULL;

    for(int i = 6; i >= 2; i--) {
        push_at_front(&head, i);
    }

    std::cout << "SLL:" ;
    print_list(head);

    push_at_front(&head, 1);
    std::cout << "Now after adding one:" ;
    print_list(head);

    return 0;
}