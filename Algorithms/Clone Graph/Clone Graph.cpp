/**
    Description: Clone Graph
    Author:Shelldream
    Date:2016-03-18
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void BFS(UndirectedGraphNode* start_node)
{
    set<UndirectedGraphNode*> visited;
    queue<UndirectedGraphNode* > node_queue;
    if(start_node != NULL)
    {
        node_queue.push(start_node);
        visited.insert(start_node);
    }
    while(!node_queue.empty())
    {
        UndirectedGraphNode* current_node = node_queue.front();
        cout<<current_node->label<<endl;
        vector<UndirectedGraphNode *> current_neighbors = current_node->neighbors;
        for(size_t i = 0; i < current_neighbors.size(); ++i)
        {
            if(visited.count(current_neighbors[i]) == 0)
            {
                node_queue.push(current_neighbors[i]);
                visited.insert(current_neighbors[i]);
            }
        }
        node_queue.pop();
    }
}

UndirectedGraphNode* create_graph(string init_str)//node只能用0——9之间的数字表示
{
    UndirectedGraphNode* start_node = NULL;
    map<int, UndirectedGraphNode*> node_map;
    int node_num = -1;
    for(size_t i = 0; i < init_str.size(); ++i)
    {
        if(init_str[i] == ',')
            continue;
        else if(init_str[i] == '#')
            node_num = -1;
        else
        {
            int current_node_num = init_str[i] - '0';
            if(node_map.count(current_node_num) == 0)
            {
                UndirectedGraphNode* tmp = new UndirectedGraphNode(current_node_num);
                node_map[current_node_num] = tmp;
                if(start_node == NULL)
                    start_node = tmp;
            }
            if(node_num == -1)
            {
                node_num = current_node_num;
            }
            else
            {
                UndirectedGraphNode* current_node = node_map[current_node_num];
                UndirectedGraphNode* front_node = node_map[node_num];
                front_node->neighbors.push_back(current_node);
                current_node->neighbors.push_back(front_node);
            }
        }
    }
    return start_node;
}

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;
        set<UndirectedGraphNode*> visited;
        UndirectedGraphNode* clone = NULL;
        if(node == NULL)
            return NULL;
        queue<UndirectedGraphNode*> node_queue;
        node_queue.push(node);
        while(!node_queue.empty())
        {
            UndirectedGraphNode* front_node = node_queue.front();
            if(visited.count(front_node) == 0)
            {
                visited.insert(front_node);
                UndirectedGraphNode* tmp = NULL;
                if(node_map.count(front_node) == 0)
                {
                    tmp = new UndirectedGraphNode(front_node->label);
                    node_map[front_node] = tmp;
                    if(clone == NULL)
                        clone = tmp;
                }
                else tmp = node_map[front_node];
                for(size_t i = 0; i < front_node->neighbors.size(); ++i)
                {
                    UndirectedGraphNode* neighbor_node = front_node->neighbors[i];
                    node_queue.push(neighbor_node);
                    UndirectedGraphNode* tmp_neigh = NULL;
                    if(node_map.count(neighbor_node) > 0)
                        tmp_neigh = node_map[neighbor_node];
                    else{
                            tmp_neigh = new UndirectedGraphNode(neighbor_node->label);
                            node_map[neighbor_node] = tmp_neigh;
                    }
                    tmp->neighbors.push_back(tmp_neigh);
                }
            }
            node_queue.pop();
        }
        return clone;
    }
};

int main()
{
    string str = "0,1,2,3#1,5#2,4#3,4#4,5";
    UndirectedGraphNode* start = create_graph(str);
    BFS(start);
    cout<<"##################################"<<endl;
    Solution test;
    UndirectedGraphNode* clone = test.cloneGraph(start);
    BFS(clone);
}

