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
 * PRINT
 * 
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

/**
 * INSERTING AFTER A NODE
 * 
 * Time Complexity = O(1)
 * Auxiliary Space = O(1)
*/
void insert_after_node(Node* prev_node, int new_data) {
    // 1. Check if the prev_node is NOT NULL
    if(prev_node == NULL) {
        std::cout << "Previous Node cannot be Null!" << std::endl;
        return;
    }

    // 2. Allocate a new Node
    Node* new_node = new Node();
    
    // 3. Add data to the new node
    new_node->data = new_data;

    // 4. Set the next of new_node to the next of prev_node
    new_node->next = prev_node->next;

    // 5. prev_node's next would be the new node
    prev_node->next = new_node;
}

int main() {
    // Start writing your code below...
    Node* head = NULL;

    // Pushing a node
    for(int i = 6; i >= 2; i--) {
        push_at_front(&head, i);
    }

    std::cout << "Initial SLL:" ;
    print_list(head);

    push_at_front(&head, 1);
    std::cout << "Adding 1 at front:" ;
    print_list(head);

    insert_after_node(head, 99);
    std::cout << "Inserting after head:" ;
    print_list(head);

    return 0;
}