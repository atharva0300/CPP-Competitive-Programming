#include<bits/stdc++.h>
using namespace std;


class DSU {
     int* parent;
     int* rank;

     public : 
        DSU(int n){
            parent = new int[n];
            // creating a new int array 
            rank  = new int[n];
            // creating a new array of integers for the rank

            for(int i=0;i<n;i++){
                // assigning the parent[i] as -1 and the rank as 1
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        // find function 
        int find(int i){
            if(parent[i] == -1){
                return i;
            }

            return parent[i] = find(parent[i]);
        }

        // union function 
        void unite(int x , int y){
            int s1 = find(x);
            int s2 = find(y);


            if(s1!=s2){
                if(rank[s1] < rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }
        }

};

class Graph{
    vector<vector<int>>edgeList;
    int V;

    public : 
        Graph(int V){
            this->V = V;
        }

        void addEdge(int x , int y , int w){
            edgeList.push_back({w,x,y});
        }

        void kruskalsMast(){
            // sort all the edges
            sort(edgeList.begin() , edgeList.end());

            DSU s(V);
            // creating a DSU and passign the int V 

            int ans = 0;
            // the value of the minnimum sum will be stored here

            cout<<"Following are the edges in the constructed MST : \n";

            for(auto edge : edgeList){
                int w = edge[0];
                int x = edge[1];
                int y = edge[2];

                // take that edge in MST if it does form a cycle 
                if(s.find(x)!=s.find(y)){
                    s.unite(x,y);

                    ans += w;
                    cout<<x<<" -- "<<y<<" == "<<w<<"\n";
                }
            }
            cout<<"\nMinimum cost spanning tree : "<<ans;


        }
};


int main(){


    Graph g(4);
    // creating a graph with 4 vertices 

    g.addEdge(0,1, 10);
    g.addEdge(1,3,15);
    g.addEdge(2,3,4);
    g.addEdge(2,0,6);
    g.addEdge(0,3,5);

    g.kruskalsMast();
    cout<<"\n";

    return 0;  
}