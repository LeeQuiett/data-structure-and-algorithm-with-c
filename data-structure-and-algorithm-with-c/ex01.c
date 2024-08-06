#include <stdio.h>

struct Node {
    int data;
    double value;
};

int main(void) {
    struct Node node;
    struct Node* node_ptr;

    printf("sizeof(Node): %zu\n", sizeof(node));
    printf("sizeof(Node*): %zu\n", sizeof(node_ptr));

    return 0;
}