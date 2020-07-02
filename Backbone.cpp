void makeBackbone(){

    void helperFunction(Node** grandParent_child){
        Node* parent = (*grandParent_child);
        if(parent == null){
            //we have reached the end of the backbone, stop here
            return;
        }
        Node* leftChild = parent->left;
        if(leftChild != null){
            //if current node has no left child, no need to rotate
            //otherwise right rotate
            //notice a slight change in the follwing line fixing a small error 
            RotateRight(grandParent_child);
            //previously had RotateRight(parent);
            //instead we need to pass address of the parent not the parent itself
            //so it should be RotatRight(&parent); or the one mentioned above.
            //both are equivalent
        }
        //move on to the right child
        helperFunction(&(parent->right));
    }

    //Now the following line creates the backbone
    //it gets automatically called on call to makeBackbone()
    //We can pass the address to the root as a parameter if it's not defined globally
    helperFunction(&root);
}

void makeBackbone(){
    Node parent = root;
    while(parent != null){
        Node leftChild = parent.left;
        if(leftChild == null){
            //no left child.. just move on to the right child
            parent = parent.right;
        }
        else{
            //left child present. rotate right
            RotateRight(&parent);
            //now left child comes in place of parent
            parent = leftChild;
        }
    }
}
