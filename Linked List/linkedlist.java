public class linkedlist{

    private class Node{
        //acc. to the industry we should not give access to the Node class 
        //to change the pointers
        private int data=0;
        private Node next=null;
        //next is used to store the address of the next node

        Node(int data){
            this.data=data;
        }
    }

    private Node head=null;
    private Node tail=null;
    private int NumberofNodes=0;
//...................................................................
    //Functions used by public for the Linked List
    public int size(){
        return this.NumberofNodes;
    }

//...................................................................
    public boolean isEmpty(){
        return (this.NumberofNodes==0); 
    }
//...................................................................
    protected handleSizeZero(Node node){
        this.head=node;
        this.tail=node;
    }
    protected addFirstNode(Node node){
        //keeping this fn protected because any develeper can access through its child class
        //this fn is actually used to insert the node in the starting of the linked List

        if(this.size()==0){
            this.handleSizeZero(node);
        }
        else{
          node.next=head;
        head=node;
      }
      this.NumberofNodes++;
    }

    public addFirst(int data){
        //this fn is only used to create a newNode 
        Node newNode=new Node(data);
        addFirstNode(newNode);

    }
//...........................................................................
    protected addLastNode(Node node){
        //used to add node to the last of linked List
        if(this.size()==0){
            this.handleSizeZero(node);
        }
        else{
            tail.next=node;
            tail=node;
        }
        this.NumberofNodes++;
    }

    public addLast(int data){
        //only used to create the new Node
        Node newNode=new Node(data);
        this.addLastNode(newNode);

    }
//........................................................................
    protected handleSize1(){
        //if only 1 node is present in the linked List
        head=null;
        tail=null;
    }

    protected Node removeFirstNode(){
        Node temp=head;
        if(this.size()==1) this.handleSize1();
        
        else{
            this.head=this.head.next;
        }
        temp.next=null;
        this.NumberofNodes--;
        return temp;
    }


    public int removeFirst() throws Exception{
        if(this.size()==0){
            throw new Exception("LInked List Empty");
        }
        Node temp=removeFirstNode();
        return temp.data;
    }
//.......................................................................

    protected Node getNodeAt(int index){
        Node temp=head;
        while(index>0){
            temp=temp.next;
            index--;
        }
        return temp;
    }
//......................................................................

    protected Node removeLastNode(){
        Node temp=tail;
        if(size()==1) this.handleSize1();
        else{
            Node nodeAt=getNodeAt(size()-2);
            nodeAt.next=null;
            tail=nodeAt;
        }
        this.NumberofNodes--;
        return temp;
    }


    public int removeLast() throws Exception{
        if(size()==0){
            throw new Exception("Linked List is Empty");
            //throw acts as return statement
        }
        Node temp=removeLastNode();
        return temp.data;
    }

//.................................................................

    protected void addNodeAt(Node node,int index){
        if(index==0){
            addFirstNode(newNode);
        }
        else if(index==this.size()){
            addLastNode(node);
        }
        else{
        Node nodeAt=getNodeAt(index-1);
        Node forward=nodeAt.next;
        nodeAt.next=newNode;
        newNode.next=forward;
        this.NumberofNodes++;
        }

    }


    public void addAt(int data,int index) throws Exception{
        if(index<0 || index>this.size()){
            throw new Exception("Invalid Index");
        }

        //creating a new node of data
        Node newNode=new Node(data);
        addNodeAt(newNode,index);

        
    }
//....................................................................

    protected Node removeNodeAt(int index){

        if(index==0){
            return removeFirstNode();
        }
        else if(index==this.size()-1){
            return removeLastNode();
        }
        else{
            Node getNode=getNodeAt(index-1);
            Node target=getNode.next;
            Node forward=target.next;
            getNode.next=forward;
            target.next=null;//breaking the link'
            //decreasing the length of the Linked List by 1
            this.NumberofNodes--;
            return target;
        }
    }

    public int removeAt(int index) throws Exception{
        if(size()==0){
            throw new Exception("Linked List is Empty");    
        }

        if(index<0 || index>=this.size()){
            throw new Excpetion("Invalid Index");
        }
        Node node=removeNodeAt(index);
        return node.data;
    }
//.....................................................................

public int getFirst() throws Exception{
    if(this.size()==0)
        throw new Exception("Linked List is Empty");

    else{
        return head.data;
    }
}

public int getLast() throws Exception{
    if(this.size()==0)
        throw new Excpetion("Linked List is Empty");
    return tail.data;
}

public int getAt(int index) throws Exception{
    if(index<0 || index>=this.size() )
        throw new Exception("Invalid Index");
    return getNodeAt(index).data;
}

}