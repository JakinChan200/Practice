//dfs tree
dfs(root, target){
    if(root == nullptr){
        return nullptr;
    }

    if(root->val == target){
        return root;
    }

    left = dfs(root->left, target);
    if(left != nullptr){
        return left;
    }
    return dfs(root->right, target);
}

//dfs graph
dfs(root, visited){
    for(auto neighbor : neighbors){
        if(neightbor in visited){
            continue;
        }
        visited.add(neighbor)
        dfs(neighbor, visited)
    }
}

int minDistance(string word1, string word2){
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= m; i++){
        dp[i][0] = i;
    }

    for(int j = 1; j <= n; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(word1[i-1] == word2[j-1]){ //If same letter
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }                   //replace       delete       insert
        }
    }

    return dp[m][n];
}