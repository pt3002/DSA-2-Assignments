vector<int> dijkstra(vector<pair<int,int>> adj[],int vertex,int starting_node)
{
        //FOR EXPLANATION==>JENNY
        //For CODE==>Take U Forward

        //adj contains vector of pair==>adj[2](4,10)
        // staring node:2  Ending node:4  Weight between them:10
    vector<int> visited(vertex,0);          //To keep track of visited nodes
    vector<int>distance(vertex,INT_MAX);    //distance array keep track of distance from source,,  initially it is infinity
        //We will make priority queue of pairs such that the node with shortest distance which is not visited yet will be at the top of queue
        //pair<distance,node>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  //Acending Order

    distance[starting_node]=0;
    pq.push(make_pair(0,starting_node));//Pushing the source node into queue from where we have to find all nodes distance
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int prev_node=pq.top().second;  //The one with the shortest cuurent distance will be at top of queue
        pq.pop();
        visited[prev_node]=1;
        for(auto it:adj[prev_node]) //Traversing its adjacent(BFS)
        {
            int next_node=it.first;
            int weight=it.second;
            if(visited[next_node]==0)
            {
                if(distance[next_node]>distance[prev_node]+weight)  //If the distance of current vertex is bigger than Sum of weight and previous node distance 
                {                                                   
                    distance[next_node]=distance[prev_node]+weight; //then we update the disatnce of cuurent node
                    pq.push(make_pair(distance[next_node],next_node));//Pusing into priority queue
                }
            }
            // if(it==destination_node)     //When we want tto find the shortest path we break the llop once we reach the destination node
            //     return distance;
        }
    }
    return distance;
}
