/**
 * Dynamic Programming (tabulation) of shortest-path problem
 * Demo for CSCI 235 - Software Design and Analysis course at Hunter College
 * This demo is meant to supplement the lecture and follows the lecture example
 * for pedagogical purposes. 
*/

#include<iostream>
#include<vector>
#include <limits>


enum node {S, C, A, B, D, E};


int shortestPath(std::vector<std::vector<int>> adj, node s, node e)
{
    int n = adj.size(); //the number of nodes
    std::vector<std::vector<int>> shortest_paths(n, std::vector<int>(n, -1)); //the shortest paths lookup table

    //populate the shortest paths lookup table from S (node 0) to E (node n-1) by computing
    // sol(S) = min{sol(A) + d(S,A), sol(C) + d(S,C)}
    // tabulating from smallest problem bottom up
    // we know that sol(E)  = 0 (no cost form destination to itself)
    shortest_paths[n-1][n-1]=0;

    for(int i = e-1; i >= s; i--) // consider each node (each row in adj) starting one level up from destination
    {
        int min_path = std::numeric_limits<int>::max(); //initialize min_path to this node, to infinity
        
        //consider every other node working backwards
        //this assumes that nodes are ordered such that there are no edges from node i to any node j < i
        for(int j = e; j > i; j--) 
        {
            if(adj[i][j] > 0) //if there is an edge from the current node to another node
                min_path = std::min(min_path,(adj[i][j] + shortest_paths[j][j]));   
        }
        //store the shortest path for this node in shortest_paths for node i
        shortest_paths[i][i] = min_path;
    }

    //output the shortest_paths matrix
    std::cout << "Shortest Paths lookup table" << std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            std::cout << shortest_paths[i][j] << " " ;
    
        std::cout << std::endl;
    }

    return shortest_paths[s][s];  

}


int main()
{
    int n{6}, e{8}; // the number of nodes and edges in the DAG from the lecture example
    //in the lecture example, we want to know the shortest path from S to E
    //encoding the nodes as int {0,5} we have S=0, C=1, A=2, B=3, D=4, E=5
 
    //build the adjacency matrix 
    std::vector<std::vector<int>> adj(n, std::vector<int>(n, -1)); //-1 means no edge
    
    //fill the diagonal
    for(int i = 0; i < n; i++)
        //diagonal is 0 - no loops in DAG
        adj[i][i] = 0;

  
    //populate the DAG with edges {u,v,w} from lecture example
    std::vector<std::tuple<node,node,int>> edges{{S,C,2},{S,A,1},{C,A,4},{C,D,3},{A,B,6},{B,D,1},{B,E,2},{D,E,1}};
    for(auto e : edges)
    {
        adj[std::get<0>(e)][std::get<1>(e)] = std::get<2>(e);
    }

    //output the adjacency matrix
    std::cout << "Adjacency Matrix" << std::endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            std::cout << adj[i][j] << " " ;
    
        std::cout << std::endl;
    }

    std::cout << shortestPath(adj,S,E) << std::endl;
           

}