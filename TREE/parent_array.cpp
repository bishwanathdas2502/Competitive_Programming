//build parent array using hashmap
void build_par(Node* root,unordered_map<Node*,Node*> &par){
        queue<Node*> q;
        q.push(root);
        par[root] = NULL;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node->left){
                par[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            }
        }
    }
