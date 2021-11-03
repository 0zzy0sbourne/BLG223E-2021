void sortList() {  
//Current will point to head  
struct node *current = head, *index = NULL;  
int temp;  
if(head == NULL) {  
printf("List is empty");  
}  
else {  
do{  
//Index will point to node next to current  
index = current->next;  
while(index != head) {  
//If current node is greater than index data, swaps the data  
if(current->data > index->data) {  
temp =current->data;  
current->data= index->data;  
index->data = temp;  
}  
index= index->next;  
}  
current =current->next;  
}while(current->next != head);   
}  
}  



 Node *node = nullptr, *temp = nullptr;
    int tempvar; //temp variable to store node data
    node = head;
    //temp = node;//temp node to hold node data and next link
    while(true)
    {
        temp=node; 
        while (temp->next != head)//travel till the second last element 
        {
           if(temp->letter > temp->next->letter)// compare the data of the nodes 
            {
              tempvar = temp->letter;
              temp->letter = temp->next->letter;// swap the data
              temp->next->letter= tempvar;
            }
         temp = temp->next;    // move to the next element 
        }
        node = node->next;    // move to the next node
        if(node == head) break;
    }



void removeDuplicate()
/Current will point to head  
struct node *current = head, *index = NULL, *temp = NULL;  
if(head == NULL) {  
printf("List is empty");  
}  
else {  
do{  
//Temp will point to previous node of index.  
temp = current;  
//Index will point to node next to current  
index = current->next;  
while(index != head) {  
//If current node is equal to index data  
if(current->data == index->data) {  
//Here, index node is pointing to the node which is duplicate of current node  
//Skips the duplicate node by pointing to next node  
temp->next = index->next;  
}  
else{  
     //Temp will point to previous node of index.  
     temp = index;  
}  
index= index->next;  
}  
current =current->next;  
}while(current->next != head);   
}  
}  





void reverseList(struct node **head) 
{
    // Temporary helper variables
    struct node *prev, *cur, *next, *last;

    // Cannot reverse empty list
    if (*head == NULL)
    {
        printf("Cannot reverse empty list.\n");
        return;
    }


    // Head is going to be our last node after reversing list
    last = *head;

    prev  = *head;
    cur   = (*head)->next;
    *head = (*head)->next;

    // Iterate till you reach the initial node in circular list
    while (*head != last)
    {
        *head = (*head)->next;
        cur->next = prev;

        prev = cur;
        cur  = *head;
    }

    cur->next = prev;
    *head = prev;       // Make last node as head
}
