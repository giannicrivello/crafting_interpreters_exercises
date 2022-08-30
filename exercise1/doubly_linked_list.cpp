#include<iostream>
#include<vector>
// ROOTPTR-> NULL 
// NULL<->[val]<->[val]<->[val]<->NULL
// Implementing a doubly linked list with insert(), search(), and delete() interfaces.
struct Node {
	Node* head;
	std::string val;
	Node* tail;
};
Node* root = NULL;
void insert(std::string val) {
	//allocate the new node
	Node* new_node = new Node();
	new_node -> head = NULL;
	new_node -> val = val;
	new_node -> tail = NULL;
	//update the list
	//first case. root points at NULL
	if(root == NULL) {
		root = new_node;
		return;
	}
	//second case. list has contents and root points to a node
	root -> head = new_node;
	new_node -> tail = root;
	root = new_node;
}
void print_list() {
	Node* head = root;
	while(head != NULL){
		std::cout << head -> val << std::endl;
		head = head -> tail;
	}
}
void delete_search(std::string search_term) {
	Node* head = root;
	while(head != NULL){
		if(head -> val == search_term){
			Node *temp = head -> head;
			temp->tail = head->tail;
			std::cout << "Deleted: " << head-> val << std::endl;
			delete(head);
			return;
		} 
		head = head -> tail;
	}
}

void search_list(std::string search_term) {
	Node* head = root;
	while(head != NULL){
		if(head -> val == search_term) {
			Node *prev = head -> head;
			Node *next = head -> tail;
			std::cout << "found your search grouping: " << head->val << ", " << prev -> val << ", " << next -> val <<std::endl;
			return;
		}
		head = head -> tail;
	}
}
int main(){
	std::vector<std::string> list;
	list.push_back("foo");
	list.push_back("bar");
	list.push_back("baz");
	list.push_back("bas");
	for(std::vector<std::string>::iterator it=list.begin(); it != list.end(); it++){
		insert(*it);
	}
	print_list();
	search_list("bar");
	delete_search("bar");
	print_list();

}
