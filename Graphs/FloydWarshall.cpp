#include<bits/stdc++.h>
using namespace std;

#define V 4
// number of vertices in the graph 

// define infinite as a large enough value 
// this, value will be used for 
// vertices not connected to each other
#define INF 99999

// a function to print the solutoin matrix 
void printSolution(int dist[][V]);

// solves the all-pairs shortest path 
// problem using Floyd Warshall algorithm
void floydWarshall(int graph[][V]){
    /*
    dist[][] will be the output matrix
    that will finally have the shortest 
    distance between every pair of the vertices 
    */
   int dist[V][V] , i , j , k;

   /* initialize the solution matrix same 
   as the input graph matrix. Or we can say the initial values 
   values of the shortest distances are based on shortest distances 
   are based on shortest paths considering no inermediate vertex */
   for(i=0;i<V;i++){
       for(j=0;j<V;j++){
           dist[i][j] = graph[i][j];
       }
   }


   /* And all the vertices one by one to the set
   of intermediate vertices. --> Before start of an iteration 
   we have shortest distances between all
    pairs of vertices such that the
    shortest distances consider only the
    vertices in set {0, 1, 2, .. k-1} as
    intermediate vertices.
    ----> After the end of an iteration,
    vertex no. k is added to the set of
    intermediate vertices and the set becomes {0, 1, 2, ..
    k} */

    for(k=0;k<V;k++){
        // pick all the vertices as source one by one 
        for(i=0;i<V;i++){
            // pick all vertices as destination for the 
            // above picked source 
            for(j=0;j<V;j++){
                // if vertex k is on the shortest path from 
                // i to j, then update the value of 
                // dist[i][j]
                if(dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j]!=INF && dist[i][k]!=INF)){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    // printing the shortest distacne matrix 
    printSolution(dist);
}

void printSolution(int dist[][V]){
    cout<<"The following matrix shows the shortest distances between every pair of the vertices\n";
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF){
                cout<<"INF  ";
            }else{
                cout<<dist[i][j]<<"   ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    
    // print the solution
    floydWarshall(graph);

    cout<<"\n";


    // complexity => O(V^3);
    
    return 0;
}