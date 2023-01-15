#include <stdlib.h>
#include <stdio.h>
struct node{
   int value;
   struct node *left;
   struct node *right;
};

struct node* root = NULL;

struct node *createNode(int value) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->value = value;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct node *temp){
   if(temp!=NULL){
       inorder(temp->left);
       printf("%d-",temp->value);
       inorder(temp->right);
   }
}
struct node *search(struct node *node,int value){
    if(node == NULL)
        {
        printf("%d is not in the tree\n",value);
        return 0;
    }
    else if(node->value == value)
    {
        printf("%d is in the tree\n",value);
        return 0;
    }
        
    else if(value < node->value)
        return search(node->left,value);
    else
        return search(node->right,value);
}
struct node *insert_node(struct node* node,int value){
   if(node == NULL)
        return createNode(value);
    if(value < node->value)
        node->left = insert_node(node->left,value);
    else
        node->right = insert_node(node->right,value);
    
    return node;
}
struct node *minValueNode(struct node *temp){
    while(temp && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
struct node *delete_node(struct node* node,int value){
    if(node == NULL) return node;

    //finding the node
    if(value < node->value)
        node->left = delete_node(node->left,value);
    else if(value > node->value)
        node->right = delete_node(node->right,value);

    // element found
    // case for deleting for one child and no child

    else{
        if(node->left == NULL){
            struct node *temp = node->right;
            free(node);
            return temp;
        }
        else if(node->right == NULL){
            struct node *temp = node->left;
            free(node);
            return temp;
        }
        // have two child
        else{
            struct node *temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = delete_node(node->right,temp->value);
        }
    }
    return node;
}


int main(){
    root = insert_node(root, 8);
   insert_node(root, 3);
   insert_node(root, 10);
   insert_node(root, 1);
   insert_node(root, 6);
   insert_node(root, 14);
   insert_node(root, 4);
   insert_node(root, 7);

   delete_node(root,11);

    search(root,18);
   inorder(root);
}

