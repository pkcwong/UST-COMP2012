/*
 * bt.cpp
 *
 */

#ifndef BT_CPP
#define BT_CPP


/* TODO
 * Goal: Do preorder traversal on the tree
 * Remark: print both value and key fields of each node
 */
template <typename T, typename K>
void BT<T,K>::preorder_traversal() const{
    //write your codes here
}

/* TODO:
 * Clear the node stack and set current pointer to the root 
 */
template<typename T, typename K>
void BT<T,K>::iterator_init(){
    //write your codes here
	while(!istack.empty()){
		istack.pop();
	}
	current = root;
}

/* TODO:
 * Check whether the next smallest node exists 
 */
template<typename T, typename K>
bool BT<T,K>::iterator_end(){
     //write your codes here
	if(!this->left_subtree().is_empty() && !this->right_subtree().is_empty()){
		if(this->left_subtree().node.key > this->node.key && this->left_subtree().node.key > this->right_subtree().node.key){
			return false;
		}else if(this->right_subtree().node.key > this->node.key && this->right_subtree().node.key > this->left_subtree().node.key){
			return false;
		}else{
			return true;
		}
	}else if(this->left_subtree().is_empty() && !this->right_subtree().is_empty()){
		if(this->right_subtree().node.key > this->node.key){
			return false;
		}else{
			return true;
		}
	}else if(!this->left_subtree().is_empty() && this->right_subtree().is_empty()){
		if(this->left_subtree().node.key > this->node.key){
			return false;
		}else{
			return true;
		}
	}else{
		return true;
	}
}

/* TODO:
 * Return the value of next smallest node from the tree 
 */
template<typename T, typename K>
T& BT<T,K>::iterator_next(){
    //write your codes here
	if(!this->left_subtree().is_empty() && !this->right_subtree().is_empty()){
		if(this->left_subtree().node.key > this->node.key && this->left_subtree().node.key > this->right_subtree().node.key){
			return this->left_subtree().node.value;
		}else if(this->right_subtree().node.key > this->node.key && this->right_subtree().node.key > this->left_subtree().node.key){
			return this->right_subtree().node.value;
		}else{
			return this->node.value;
		}
	}else if(this->left_subtree().is_empty() && !this->right_subtree().is_empty()){
		if(this->right_subtree().node.key > this->node.key){
			return this->right_subtree().node.value;
		}else{
			return this->node.value;
		}
	}else if(!this->left_subtree().is_empty() && this->right_subtree().is_empty()){
		if(this->left_subtree().node.key > this->node.key){
			return this->left_subtree().node.value;
		}else{
			return this->node.value;
		}
	}else{
		return this->node.value;
	}
}

#endif /* BT_CPP */
