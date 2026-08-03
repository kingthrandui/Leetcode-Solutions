/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if (node == NULL) {
            return NULL;
        }

        unordered_map<Node*, Node*> mp;
        queue<Node*> q;

        Node* clone = new Node(node->val);

        mp[node] = clone;
        q.push(node);

        while (!q.empty()) {

            Node* curr = q.front();
            q.pop();

            for (Node* neb : curr->neighbors) {

                if (mp.find(neb) == mp.end()) {
                    mp[neb] = new Node(neb->val);
                    q.push(neb);
                }

                mp[curr]->neighbors.push_back(mp[neb]);
            }
        }

        return clone;
    }
};