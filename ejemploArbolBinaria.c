#include <stdio.h>
#include <stdlib.h>

/* ----------- Estructura del nodo ----------- */
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

/* ----------- Crear un nuevo nodo ----------- */
struct Node* create_node(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    if (node == NULL) {
        fprintf(stderr, "Error: memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* ----------- Insertar en el árbol ----------- */
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return create_node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

/* ----------- Recorridos ----------- */
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

/* ----------- Liberar memoria ----------- */
void free_tree(struct Node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

/* ----------- Programa principal ----------- */
int main(void) {
    struct Node* root = NULL;
    int value;

    printf("=== Árbol Binario de Búsqueda ===\n");
    printf("Ingrese números para agregar al árbol.\n");
    printf("Para terminar, escriba un número negativo o una letra.\n\n");

    // Entrada de datos del usuario
    while (1) {
        printf("Ingrese un número: ");
        if (scanf("%d", &value) != 1) { // Si el usuario ingresa algo no numérico
            printf("Entrada no válida. Finalizando ingreso...\n");
            break;
        }
        if (value < 0) { // Si el usuario ingresa un número negativo
            printf("Ingreso terminado.\n");
            break;
        }
        root = insert(root, value);
    }

    // Mostrar los recorridos
    printf("\nRecorrido Inorder (orden ascendente): ");
    inorder(root);
    printf("\n");

    printf("Recorrido Preorder: ");
    preorder(root);
    printf("\n");

    printf("Recorrido Postorder: ");
    postorder(root);
    printf("\n");

    // Liberar memoria
    free_tree(root);

    return 0;
}
