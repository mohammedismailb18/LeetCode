/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> res;
        Node* tmp;
        
        if(root == NULL)
            return res;
        
        st.push(root);
        
        while(!st.empty()){
            tmp = st.top();
            st.pop();
            res.push_back(tmp->val);
            
            for(int i=(tmp->children).size()-1; i>=0; i--){
                if(tmp->children[i]!=NULL)
                    st.push(tmp->children[i]);
            }
        }
        
        return res;
    }
};
