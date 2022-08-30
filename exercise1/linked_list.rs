use std::io;
#[derive(Debug, Clone, PartialEq)]
struct Node {
    val: Option<i32>,
    next: Option<Box<Node>>
}
fn insert(mut root: Node, val: i32) -> Node {
    let mut new_node = Node {
        val: Some(val),
        next: None 
    };
    match root.next {
        Some(ref t) => {
            new_node.next = root.next;
            root.next = Some(Box::new(new_node));
            root
        },
        None => {
           root.next = Some(Box::new(new_node));
           root
        }
    }
}
fn print(root: &mut Node){
    let mut head = root;
    while head.next != None {
        let val = *head.next.clone().unwrap();
        println!("{:?}",val.val.unwrap());
        //Node {val: None, next: Option<Box<Node>>}
        *head = *head.next.clone().unwrap();
    }
}
fn main() {
    let mut root = Node{
        val: None,
        next: None
    };
    println!("hello world");
    root = insert(root, 32);
    root = insert(root, 45);
    root = insert(root, 55);
    root = insert(root, 21);
    print(&mut root);
}
