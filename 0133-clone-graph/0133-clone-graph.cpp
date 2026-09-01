class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;

        Node* head = new Node(node->val);

        // original node -> cloned node
        unordered_map<Node*, Node*> copy;

        unordered_map<Node*, bool> visited;

        queue<Node*> q;

        copy[node] = head;
        visited[node] = true;
        q.push(node);

        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();

            for(int i = 0; i < temp->neighbors.size(); i++) {

                Node* neighbor = temp->neighbors[i];

                // If clone doesn't exist, create it
                if(copy.find(neighbor) == copy.end()) {
                    Node* temp2 = new Node(neighbor->val);
                    copy[neighbor] = temp2;
                }

                // Connect clone of temp -> clone of neighbor
                copy[temp]->neighbors.push_back(copy[neighbor]);

                // Traverse original neighbor if not visited
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return head;
    }
};