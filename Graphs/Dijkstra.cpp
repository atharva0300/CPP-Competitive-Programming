#include<bits/stdc++.h>
using namespace std;

//defining the number of vertices inthe graph 
#define V 9

int minDistance(int dist[] , bool sptSet[]){
    // initialize the min value 
    int min = INT_MAX;
    int min_index;

    for(int i=0;i<V;i++){
        if(sptSet[i]==false && dist[i] <= min){
            min= dist[i];
            min_index = i;
        }
    }

    return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[]){
    cout<<"Vertex \t distance from the source\n";
    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<dist[i]<<"\n";
    }
}


// algo function 
// using adjacent matrix representation 
void dijkstra(int graph[V][V] , int src){
    // the output array 
    // the dist[i] will hold the shortest 
    // distance from the src to the i
    int dist[V];

    // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or the shortest distance from the src to i  is finalized 
    bool sptSet[V];

    // initialize all the distances as INFINITE and sptSet[] as false 
    for(int i=0;i<V;i++){
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }


    // distacne from the source vertex to itself is always 0 
    dist[src] = 0;

    // find the shortest path on all the vertices
    for(int count=0;count<V-1;count++){
        // pick the minimum distance vertex from the set of vertices not 
        // yet processed. u us always equal to src in the first iteration 
        int u = minDistance(dist , sptSet);

        // mark the picked vertex as processed 
        sptSet[u] = true;

        // update the dist value of the adjacent vertices of teh picked vertex 
        for(int i=0;i<V;i++){
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]

            if(!sptSet[i] && graph[u][i] && dist[u]!=INT_MAX && dist[u] + graph[u][i] < dist[i]){
                dist[i] = dist[i] + graph[u][i];
            }
        }

        printSolution(dist);
    }

}

int main(){

    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    dijkstra(graph , 0);
    // 0 is the value of the source vertex 
    // ie - the starting point 
    cout<<"\n";
    return 0;
}