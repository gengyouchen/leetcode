class Solution {
public:
	/* time: O(|V|+|E|), space: O(|V|) auxiliary (i.e. does not count output itself) */
	UndirectedGraphNode *cloneGraph(const UndirectedGraphNode *node) {
		if (!node)
			return NULL;

		queue<const UndirectedGraphNode*> S;
		unordered_map<const UndirectedGraphNode*, UndirectedGraphNode*> in2out;
		in2out[node] = new UndirectedGraphNode(node->label), S.push(node);
		while (!S.empty()) {
			auto in = S.front();
			S.pop();
			for (auto p : in->neighbors) {
				if (!in2out.count(p))
					in2out[p] = new UndirectedGraphNode(p->label), S.push(p);
			}
		}

		for (const auto& it : in2out) {
			auto in = it.first;
			auto out = it.second;
			for (auto p : in->neighbors)
				out->neighbors.push_back(in2out[p]);
		}
		return in2out[node];
	}
};
