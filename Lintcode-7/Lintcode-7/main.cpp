//
//  main.cpp
//  Lintcode-7
//
//  Created by JINGLUO on 29/8/18.
//  Copyright © 2018 JINGLUO. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

class TreeNode {
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

std::vector<std::string> split(const std::string &str, std::string delim) {
    std::vector<std::string> results;
    int lastIndex = 0, index;
    while ((index = str.find(delim, lastIndex)) != std::string::npos) {
        results.push_back(str.substr(lastIndex, index - lastIndex));
        lastIndex = index + delim.length();
    }
    if (lastIndex != str.length()) {
        results.push_back(str.substr(lastIndex, str.length() - lastIndex));
    }
    return results;
}

/**
 * This method will be invoked first, you should design your own algorithm
 * to serialize a binary tree which denote by a root node to a string which
 * can be easily deserialized by your own "deserialize" method later.
 */
std::string serialize(TreeNode * root) {
    // write your code here
    std::vector<TreeNode *> nodeList;
    std::string result;
    
    nodeList.push_back(root);
    for (int i = 0; i < nodeList.size(); i ++) {
        TreeNode *node = nodeList[i];
        if (node == NULL) continue;
        nodeList.push_back(node->left);
        nodeList.push_back(node->right);
    }
    
    while (nodeList.size() > 0 && nodeList[nodeList.size()-1] == NULL) {
        nodeList.pop_back();
    }
    
    if (nodeList.size() == 0) return "{}";
    
    std::stringstream ss;
    ss << "{" << nodeList[0]->val;
    for (int i = 1; i != nodeList.size(); ++i) {
        if (nodeList[i] == NULL) ss << ",#";
        else ss << "," << nodeList[i]->val;
    }
    ss << "}";
    
    return ss.str();
}

/**
 * This method will be invoked second, the argument data is what exactly
 * you serialized at method "serialize", that means the data is not given by
 * system, it's given by your own serialize method. So the format of data is
 * designed by yourself, and deserialize it here as you serialize it in
 * "serialize" method.
 */
TreeNode * deserialize(std::string &data) {
    if (data == "{}") return NULL;
    
    std::vector<std::string> vals = split(data.substr(1, data.size() - 2), ",");
    std::queue<TreeNode *> Q;
    TreeNode *root = new TreeNode(atoi(vals[0].c_str()));
    Q.push(root);
    bool isLeftChild = true;
    for (int i = 1; i < vals.size(); i ++) {
        if (vals[i] != "#") {
            TreeNode *node = new TreeNode(atoi(vals[i].c_str()));
            if (isLeftChild) {
                Q.front()->left = node;
            } else {
                Q.front()->right = node;
            }
            Q.push(node);
        }
        if (!isLeftChild) {
            Q.pop();
        }
        isLeftChild = !isLeftChild;
    }
    
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string vals = "{1,2,3,11,#,4,5,#,#,6,7,#,10,#,#,8,9,#,#,12,13,#,#,#,#,#,14}";
    TreeNode * result = deserialize(vals);
    std::cout << result;
    std::cout << serialize(result);
    return 0;
}
