/*Comments added*/


unordered_map <Node*,int> mp;

void mapper(Node *root,int n)
{
    if(root==NULL)
    return;
    mp[root]=n;
    mapper(root->left,n-1);
    mapper(root->right,n+1);
}

    void topView(Node * root) {
        mapper(root,0);
        
        queue <Node*> q1;
        map <int,int> ans;
        ans[0]=root->data;
        q1.push(root);
        while(!q1.empty())
        {
            Node* temp= q1.front();
            int k=mp[temp];
            if(ans.find(k)==ans.end())
            ans[k]=temp->data;
            q1.pop();
            if(temp->left!=NULL)
            {
                q1.push(temp->left);
            }
            if(temp->right!=NULL)
            {
              
                q1.push(temp->right);
            }
        }
        for(auto i:ans)
        cout<<i.second<<" ";
        
        
    }
