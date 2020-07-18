Hint: use dfs and modify it.
Explnation: Create a function that return treenode, in that function check if left node exist.
            
            If exist then check if right node exist and if exist store it.
            
            Flatten it:
                node->right = flatten(node->left);
                node->left = NULL;
            
            again call flatten function and put the right node in place.
            
            else if left node not exist 
              Then call flatten function for right node.
              Repeat until no node exist.
            
            
