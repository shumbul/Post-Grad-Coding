// Dijkstra

int dijkstra(int src, int dest) {
    vector<int> dist(V, INT_MAX);   // V=no. of vertices
    set<pair<int, int>> s;

    dist[src]=0;
    s.insert({0, src});

    while(!s.empty()){
        auto it=s.begin();
        int node=it->second;
        int nodeDist=it->first;
        s.erase(it);

        for(auto &nbr: graph[node]){
            int nbrNode=nbr->second;
            int nbrDist=nbr->first;

            if(nodeDist+nbrDist<dist[nbr]){
                auto f=s.find({dist[nbr], nbr});
                if(f!=s.end())
                    s.erase(f);
                dist[nbr]=nodeDist+nbrDist;
                s.insert({dist[nbr], nbr});
            }
        }
    }
    return dist[dest];
}