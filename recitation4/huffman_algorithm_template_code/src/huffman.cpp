#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "huffman.h"

using namespace std;

int Huffman::findindex(Token *arr,string elem){
	// YOU HAVE TO COMPLETE THIS PART
	// THIS FUNCTION RETURNS THE INDEX OF STRING ON TOKEN ARRAY, IF STRING IS NOT IN TOKEN ARRAY, RETURNS -1
    int index = 0; 
    while(arr != nullptr)
    { 
        if(elem != arr->symbol){
            index++; 
        }
        else {
            index++;            
            break; 
        }
        arr++; 
    }
    return index; 
}

void Huffman::find_frequencies()
{
    int index = -1;
    ifstream file_obj; //object to read file
    file_obj.open("../input.txt",ifstream::in);
    char symbol = 0;
    if (!file_obj.is_open()) {
        file_obj.open("input.txt",ifstream::in);
        if (!file_obj.is_open()) {
            cerr << "Could not open the file" << endl;
            exit(1);
        }
    }
    while (file_obj.get(symbol)) 
    {
        string s;
        s.push_back(symbol);
        // YOU HAVE TO COMPLETE THIS PART
        
        
        

    }
    file_obj.close();
}

PriorityQueue::PriorityQueue()
{ 
    head = NULL;
    token_count = 0;
}

void PriorityQueue::push(Node *newnode)
{    
	// YOU HAVE TO COMPLETE THIS PART
    // Create a leaf node for each symbol and add it to the priority queue
    
    // leaf node is already created and pushed to function 
    // only add it to the queue
    
    Node* traverse = head; 
    
    if(traverse == nullptr) 
    { 
        head = newnode; 
        return ; 
    }
    while(traverse != nullptr)
    {
        if(traverse->next == nullptr && traverse->token.count >  newnode->token.count )
        {
            traverse->next = newnode; 
        }
        else if( traverse->next != nullptr && traverse->token.count >  newnode->token.count && traverse->next->token.count)
        {
                    Node* temp = traverse->next ;
                    traverse->next = newnode; 
                    newnode->next = temp ;               
        }
        else if(traverse == head) 
        { 
            if(traverse->token.count < newnode->token.count)
            {
                newnode->next = head;
                head = newnode;    
            }     
            else if(traverse->token.count > newnode->token.count &&  traverse->next->token.count < newnode->token.count)
            {
                Node* temp = traverse->next; 
                traverse->next = newnode; 
                newnode->next = temp ; 
            }
        }
        

        traverse = traverse->next;
    }
}

Node* PriorityQueue::pop()
{
    // YOU HAVE TO COMPLETE THIS PART

    //  behaves like a front() ; 
    // do not delete the node, delete it after you call this function
    if(head == nullptr) return nullptr; 
    else{
        if(head->next == nullptr) 
        {
            Node* result = head; 
            head = nullptr; 
            return result;
            // returned the head node, delete it after  
            // it is used in the function that we call pop() 
        }
        else{
            Node* result = head;
            head = head->next;
            return result;
            // returned the head node, delete it after 
            // it is used in the function that we call pop()
        }
    } 

}
void Huffman::reverseString(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
void Huffman::get_priority_queue()
{
    // YOU HAVE TO COMPLETE THIS PART 
    
    Token* ptr = token_array; 
    
    // create a new node for each token and add them to the priority queue
    while(ptr != nullptr)
    {
        
        Node* newnode = new Node(); 
        newnode->token.code = ptr->code ;
        newnode->token.count = ptr->count; 
        newnode->token.symbol = ptr->symbol;  
        // node created 
        
        priority_queue.push(newnode); 
        // node pushed
    }


}

HuffmanBinaryTree::HuffmanBinaryTree()
{
    root = NULL;
}

Node * HuffmanBinaryTree::merge(Node *node1, Node *node2)
{
    // YOU HAVE TO COMPLETE THIS PART

    // merge two nodes and place the new node conveniently 

    Node* newNode = new Node();

    // merge two nodes 
    newNode->token.count = node1->token.count + node2->token.count; 
    newNode->token.symbol = node1->token.symbol + node2->token.symbol; 

    // place the new node conveniently 

    // return the new node 
    return newNode;
    // newNode->token.code = ;
    
}

void HuffmanBinaryTree::delete_postorder_traversal(Node *traversal)
{
    if(traversal!=NULL) 
    {
        delete_postorder_traversal(traversal->left);
        delete_postorder_traversal(traversal->right);
        delete traversal;
    }
}

HuffmanBinaryTree::~HuffmanBinaryTree()
{
    delete_postorder_traversal(root);
    cout<<"Code with no memory leak ;)"<<endl;
    root = NULL;
}

void Huffman::get_huffman_tree()
{
    // YOU HAVE TO COMPLETE THIS PART 

    while(priority_queue.token_count >= 2) // While there is more than one node in the queue
    {
        // Remove the two nodes of highest priority (lowest frequency) from the queue
            Node* firstnode = priority_queue.pop();
            Node* secondnode = priority_queue.pop();
            Node* parentNode = new Node();
            // with probability equal to the sum of the
            // two nodes’ probabilities 
            parentNode->token.count = firstnode->token.count + secondnode->token.count; 

            // merge symbol of two child nodes and assign it to parent node
            parentNode->token.symbol = firstnode->token.symbol + secondnode->token.symbol; 

            // assign the code of parent node
            // parentNode->token.code = ; 

            // Place the new node as parent of its components in the tree.
            parentNode->left = firstnode; 
            parentNode->right = secondnode;
            

            // add the new node to the queue 
            priority_queue.push(parentNode);


            // what is node->next 
    }
    if(priority_queue.token_count == 0)
    {
        return; 
    }
    else if(priority_queue.token_count == 1)
    {
        // remaining node is the root node and the tree is complete
        Node* rootNode = priority_queue.pop();

    }


}

int Huffman::get_codes(Node *traversal,string codepart)
{    
    // YOU HAVE TO COMPLETE THIS PART
    // A RECURSIVE FUNCTION APPENDS CODEPART STRING 1 OR 0 ACCORDING TO THE HUFFMAN BINARY TREE
    
    // traversal points to root of the tree? (if it doesn't, it should)

    // push the node's value to the codepart
    
    // calculate the codes for each leaf in the binary tree
    // get the leafs from token_array

    for(int i = 0;i<token_count;i++)
    {
        codepart += traversal->token.code; 

        

        if(traversal->token.symbol == token_array[i].symbol)
        {
            // if we finished, reverse the codepart and 
            reverseString(codepart);
            
            // assign it to current token's code 
            token_array[i].code = codepart;  

            return true;
        }

        // else check whether the required node lies

        if(get_codes(traversal->left, codepart))
        {
            codepart += "0"; 
            return true;
        }
        else if(get_codes(traversal->right, codepart))
        {
            codepart += "1";
            return true;
        }

        // else the node we wanna reach does not lie 
        // at the left or right of the current node
        codepart.pop_back();
        return false; 


        codepart = ""; // not sure if this is correct
    }

 
    return false ; // does not correct 
}

string Huffman::return_code(string target)
{
    int index = findindex(token_array,target);
    return token_array[index].code;
}

double Huffman::calculate_compression_ratio()
{
    double bit_required_before = 0;
    for(int i=0;i<token_count;i++)
        bit_required_before += token_array[i].count * 8;
    double bit_required_after = 0;
    for(int i=0;i<token_count;i++)
        bit_required_after += token_array[i].count * token_array[i].code.length();
    return bit_required_before / bit_required_after;
}
