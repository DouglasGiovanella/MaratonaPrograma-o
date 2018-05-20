#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <list>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int,LL> PIL;
typedef set<int> SI;
typedef set<PIL> SPIL;
typedef list<int> LI;
typedef vector<bool> VB;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<PIL> VPIL;
typedef vector<LL> VL;
typedef vector<VL> VVL;
typedef vector<SI> VSI;
typedef vector<VI> VVI;
typedef vector<VPIL> VVPIL;


#include <limits>
LL INF_L = numeric_limits<LL>::max();
#define LEAF NULL



///=============================================================================///
///=============================================================================///
///=============================================================================///
#define LEAF NULL
template <class T>
class BinaryTreeNode{
    private:T element;
    private:BinaryTreeNode* left;
    private:BinaryTreeNode* right;

    ///////////////////////////////////////////////////////////////////////////////
    // Constructors
    public:BinaryTreeNode( const T value ){
        element = value;
        left = right = LEAF;
    }
    ///////////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////////
    // Getters & Setters
    public:T getElement(){ return element; }
    public:BinaryTreeNode** getLeftBranch(){ return &left; }
    public:BinaryTreeNode** getRightBranch(){ return &right; }
    public:void setElement( T value ){ element = value; }
    public:void setLeftBranch( BinaryTreeNode<T>* branch ){ left = branch; }
    public:void setRightBranch( BinaryTreeNode<T>* branch ){ right = branch; }
    ///////////////////////////////////////////////////////////////////////////////
};
///=============================================================================///
///=============================================================================///
///=============================================================================///






///=============================================================================///
///=============================================================================///
///=============================================================================///
#define LEAF NULL
template <class T>
class BinaryTree{
    private:BinaryTreeNode<T>* root;

    ///////////////////////////////////////////////////////////////////////////////
    // Constructors
    public:BinaryTree(  ){ root = LEAF; }
    ///////////////////////////////////////////////////////////////////////////////
    public:BinaryTree( const T value ){ root = new BinaryTreeNode<T>( value ); }
    ///////////////////////////////////////////////////////////////////////////////
    // Create a BinaryTree based on Pre-Order and In-Order paths
    // REQUIREMENT: createBT( )
    /// O( V log V )
    public:BinaryTree( vector<T> preOrder, vector<T> inOrder ){
        assert( preOrder.size() == inOrder.size() );
        unsigned n = preOrder.size()-1;
        map<T, unsigned> inOrderMap;
        for( unsigned i=0; i<inOrder.size(); i++ )
            inOrderMap[ inOrder[i] ] = i;
        root = createBT( preOrder, inOrder, inOrderMap, 0, n, 0, n );
    }
    ///////////////////////////////////////////////////////////////////////////////
    // USED BY: BinaryTree( ) #constructor#
    private:BinaryTreeNode<T>* createBT( vector<T>& pre, vector<T>& in,
                    map<T,unsigned>& inMap, unsigned ps, unsigned pe,
                    unsigned is, unsigned ie ){
        if( ps > pe || is > ie ) return LEAF;
        BinaryTreeNode<T>* node = new BinaryTreeNode<T>( pre[ps] );
        unsigned ip = inMap[ pre[ps] ];
        node->setLeftBranch( createBT(pre, in, inMap, ps+1, ps+(ip-is), is, ip-1) );
        node->setRightBranch( createBT(pre, in, inMap, ps+(ip-is)+1, pe, ip+1, ie ) );
        return node;
    }
    ///////////////////////////////////////////////////////////////////////////////




    ///////////////////////////////////////////////////////////////////////////////
    // Getters & Setters
    public:BinaryTreeNode<T> getRoot(){ return root; }
    ///////////////////////////////////////////////////////////////////////////////





    ///////////////////////////////////////////////////////////////////////////////
    // ADD ELEMENT
    // Add a new element in the the binary tree keeping it sorted
    // PARAMETER equal_value_option: used when the new element already exists in the BT
    //      less than 0   => put the new element in the left branch
    //      bigger than 0 => put the new element in the right branch
    //      equals to 0   => does not add new element in the BT
    // REQUIREMENT: addElementInTree
    /// O( V + E )
    public:void addElement( const T value, int equal_value_option=0 ){
        addElementInTree( &root, value, equal_value_option );
    }
    ///////////////////////////////////////////////////////////////////////////////
    // USED BY: addElement( )
    private:void addElementInTree( BinaryTreeNode<T>** bt, const T value, int option ){
        // if the tree is a LEAF
        if( *bt == LEAF ){ *bt = new BinaryTreeNode<T>( value ); }
        // if it's the same element
        else if( value == (*bt)->getElement() ){
            if( option < 0 )
                addElementInTree( (*bt)->getLeftBranch(), value, option );
            else if( option > 0 )
                addElementInTree( (*bt)->getRightBranch(), value, option );
        }
        // if value is lower than element then add to the left
        else if( value < (*bt)->getElement() )
            addElementInTree( (*bt)->getLeftBranch(), value, option );
        // if value is bigger than element then add to the right
        else if( value > (*bt)->getElement() )
            addElementInTree( (*bt)->getRightBranch(), value, option );
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // PRE ORDER PATH
    // Generates the path visiting: node element, left branch, then right branch
    // REQUIREMENTS: preOrder()
    /// O( V + E )
    public:vector<T> pathPreOrder( ){
        vector<T> path;
        preOrder( path, root );
        return path;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // used by: pathPreOrder()
    private:void preOrder( vector<T>& path, BinaryTreeNode<T>* node ){
        if( node == LEAF ) return;
        path.push_back( node->getElement() );
        preOrder( path, *(node->getLeftBranch()) );
        preOrder( path, *(node->getRightBranch()) );
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // IN ORDER PATH
    // Generates the path visiting: left branch, node element, then right branch
    // REQUIREMENTS: inOrder()
    /// O( V + E )
    public:vector<T> pathInOrder( ){
        vector<T> path;
        inOrder( path, root );
        return path;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // used by: pathInOrder()
    private:void inOrder( vector<T>& path, BinaryTreeNode<T>* node ){
        if( node == LEAF ) return;
        inOrder( path, *(node->getLeftBranch()) );
        path.push_back( node->getElement() );
        inOrder( path, *(node->getRightBranch()) );
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // POS ORDER PATH
    // Generates the path visiting: left branch, right branch, then node element
    // REQUIREMENTS: posOrder()
    /// O( V + E )
    public:vector<T> pathPosOrder( ){
        vector<T> path;
        posOrder( path, root );
        return path;
    }
    ///////////////////////////////////////////////////////////////////////////////
    // used by: pathPosOrder()
    private:void posOrder( vector<T>& path, BinaryTreeNode<T>* node ){
        if( node == LEAF ) return;
        posOrder( path, *(node->getLeftBranch()) );
        posOrder( path, *(node->getRightBranch()) );
        path.push_back( node->getElement() );
    }
    ///////////////////////////////////////////////////////////////////////////////
};












///=============================================================================///
///=============================================================================///
///=============================================================================///
typedef long long LL;
typedef pair<int,LL> PIL;
typedef list<int> LI;
typedef vector<int> VI;
typedef vector<PIL> VPIL;
typedef vector<LL> VL;
typedef vector<VPIL> VVPIL;
class Graph{
    private:VVPIL graph;    // the graph as an adjacency list
    private:VL dists;		// the distances from a specific origin
    private:VI parents;     // node parent in a path
    private:LI path;        // list of nodes from origin to dest

    public:Graph( unsigned nodes ){ graph = VVPIL( nodes, VPIL() ); }
    public:LI getPath(){ return path; }


    ///////////////////////////////////////////////////////////////////////////////
    // Add a new edge for the graph.
    // cost represent the cost form source to dest (default cost = 1);
    // directed dictates if the edge is directed (source -> dest)
    // or undirected (source <-> dest);
    // Requirements: none
    /// O( 1 )
    public:void addEdge( unsigned source, unsigned dest, LL cost=1, bool directed=false ){
        graph[source].push_back( make_pair(dest,cost) );
        if( !directed ) graph[dest].push_back( make_pair(source,cost) );
    }
    ///////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////////
	// Create and return a transposed graph (a transposed graph is
	// a graph with all edges inverted; e.g. a->b  =>  a<-b)
	// Requirements: none
	/// O( V + E )
    private:Graph transpose( ){
    	Graph new_graph = Graph( graph.size() );
    	for( unsigned i=0; i<graph.size(); i++ ){
    		for( unsigned j=0; j<graph[i].size(); j++ ){
    			PIL aux = graph[i][j];
    			new_graph.addEdge( aux.first, i, aux.second, true );
			}
		}
		return new_graph;
	}
	///////////////////////////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////////////////////////////
	// Fills the path list starting from a node and ending at
	// a node without parent.
	// Requirements: none
	/// O( E )
    private:void makePath(int start){
        path.clear();
        while(start != -1){
            path.push_front(start);
            start = parents[start];
        }
    }
    ///////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////////
    // Breadth-First Search
    // Tries to find a path from an origin to a destination in the graph.
    // If the method return true, then path will contain a possible path from
    // origin to dest, dists will contain the distances to reach each node,
    // and parents will contain the parents of each node during the search.
    // Requirements: function "makePath"
    /// O( V + E)
	public:bool bfs(unsigned origin, unsigned dest){
        path.clear();
		dists = VL( graph.size(), INF_L );
		parents = VI( graph.size(), -1 );
		dists[origin] = 0;
		queue<int> to_visit;
		to_visit.push( origin );
		while (!to_visit.empty()){
			unsigned node = to_visit.front();
			to_visit.pop();
			for (unsigned i=0; i<graph[node].size(); ++i){
				unsigned neighboor = graph[node][i].first;
				if (dists[neighboor] < INF_L ){
					continue; // already visited
				}
				to_visit.push( neighboor );
				dists[neighboor] = dists[node] + 1;
                parents[neighboor] = node;
                if (neighboor == dest){ // if it is the dest node
					makePath( dest );
					return true;
				}
			}
		}
		return false; // there is no path from origin to dest
	}



	///////////////////////////////////////////////////////////////////////////////
    // Depth-First Search
    // Tries to find a path from an origin to a destination in the graph.
    // If the method return true, then 'path' will contain a possible path from
    // origin to dest, dists will contain the distances to reach each node,
    // and parents will contain the parents of each node during the search.
    // Requirements: function "makePath" and "_dfs"
    /// O( V + E )
    typedef vector<bool> VB;
	public:bool dfs(unsigned origin, const unsigned dest){
	    path.clear();
	    dists = VL( graph.size(), INF_L );
		parents = VI( graph.size(), -1 );
		dists[origin] = 0;
	    return _dfs( origin, dest );
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Perform a Depth-First Search in the graph looking for the given destination.
    // Used by: dfs( )
    /// O( V + E )
    private:bool _dfs( unsigned origin, const unsigned dest ){
        if( origin==dest ){ // found the destination
            makePath( dest );
            return true;
        }

		for(unsigned i=0; i<graph[origin].size(); i++ ){
			unsigned node = graph[origin][i].first;
            if ( dists[node] < INF_L ){
                continue; // already visited
            }
            dists[node] = dists[origin] + 1;
            parents[node] = origin;
            if( _dfs( node, dest ) ) return true;
		}
		return false; // there is no path from origin to dest
	}
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // DIJKSTRA
    // Finds the minimum path from a origin to a destination.
    // To get the minimum distance use the VI dists.
	// Return false if a path was not found.
    /// O( E + V log V )
    public:bool dijkstra( unsigned origin, unsigned dest ){
        unsigned n = graph.size();
        dists   = VL( n, INF_L );
        parents = VI( n, -1 );
        SPIL to_visit; // pair( cost, node )
        to_visit.insert( make_pair(0,origin) );
        while( to_visit.size() > 0 ){
            unsigned node = (*to_visit.begin()).first;
            unsigned cost = (*to_visit.begin()).second;
            to_visit.erase( to_visit.begin() );
            if ( node == dest ) return true;
            for (unsigned i=0; i<graph[node].size(); ++i) {
                unsigned neighboor = graph[node][i].first;
                LL dst = cost + graph[node][i].second;
                if ( dst < dists[neighboor] ) {
                    if( dst != INF_L ) //erase the old best adjency to this node
                        to_visit.erase( make_pair(dists[neighboor], neighboor) );
                    to_visit.insert( make_pair(dst, neighboor) );
                    dists[neighboor] = dst;
                    parents[neighboor] = node;
                }
            }
        }
        return false;
    }
    ///////////////////////////////////////////////////////////////////////////////



	///////////////////////////////////////////////////////////////////////////////
    // FLOYDWARSHALL
    // Finds the shortest path between every node pair. Allows
    // negative-distance paths, but is slower than O(V) BFS's.
    // Usually slower than NDijkstra too.
    /// O( V³ )
	public:void floydWarshall( VVL &dist, VVI &inPath ) {
    	// dist   (dist of shortest path between nodes)
        // inPath (next node in path between nodes)
    	dist = VVL( graph.size(), VL(graph.size(),0 ) );
    	for(int i=0; i<graph.size(); i++){
    		for(int j=0; j<graph[i].size(); j++){
    			dist[i][j] = graph[i][j].second;
			}
		}
        inPath = VVI( graph.size(), VI(graph.size()) );
         // v = dist.size();
        for(int i=0; i<graph.size(); i++)
            inPath[i].assign(graph.size(), i);
        for(int mid=0; mid<graph.size(); mid++){
            for(int a=0; a<graph.size(); a++) {
                for(int b=0; b<graph.size(); b++){
                    if( dist[a][mid] != INF_L and dist[mid][b] != INF_L) {
                        int d = dist[a][mid] + dist[mid][b];
                        if(d < dist[a][b]) {
                            dist[a][b] = d;
                            inPath[a][b] = inPath[mid][b];
                        }
                    }
                }
            }
        }
    }



    ///////////////////////////////////////////////////////////////////////////////
    // GRAPH HAS CYCLE
    // Checks if there is a cycle in the graph. If a cycle of any size is found,
    // then the method returns true and the parameter size will contain the cycle.
    // If no cycle is found, then the method returns false
    // Requirements: function "search"
    /// O( V + E )
    public:bool hasCycle( VI& cycle ){
        #define NON_VIZITED -1  // a node that was not vizited yet
        #define VIZITED 0       // a node that was vizited during a check
        #define VERIFIED 1      // a node that was checked and doesn't lead to a cycle
        cycle.clear();
        VI state = VI( graph.size(), NON_VIZITED );
        // We try to initiallize from every non-vizited node
        for( unsigned v=0; v<graph.size(); v++){
            // if the node was already verified, then goes to the next one
            if( state[v] == VERIFIED ) continue;
            // if not, we mark this node as vizited
            state[v] = VIZITED;
            cycle.push_back( v );
            if ( search( v, state, cycle ) ) return true;
            cycle.pop_back( );
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Try to found a cycle in a graph using depth-search-first
    // Used by: hasCycle
    /// O( V + E )
    private:bool search( int node, VI& state, VI& cycle ){
        VPIL::iterator it;
        for (it = graph[node].begin(); it != graph[node].end(); ++it) {
            int neighboor = (*it).first;
            switch( state[neighboor] ){
                case VERIFIED: continue;
                case VIZITED:
                    cycle.push_back( neighboor );
                    return true;
            }
            state[neighboor] = VIZITED;
            cycle.push_back( neighboor );
            if ( search(neighboor, state, cycle) ) return true;
            cycle.pop_back( );
        }
        state[node] = VERIFIED;
        return false;
    }
    //////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////////
    // Checks if there is a cycle in the graph. If a cycle of any size is found,
    // then the method returns true and the parameter size will contain the cycle.
    // If no cycle is found, then the method returns false
    // Requirements: function "searchDepth"
    /// O( V + E )
    public:bool hasCycle( unsigned n, VI& cycle ){
        #define NON_VIZITED -1  // a node that was not vizited yet
        #define VIZITED 0       // a node that was vizited during a check
        #define VERIFIED 1      // a node that was checked and doesn't lead to a cycle
        // it's impossible to have a cycle biggest than the number of nodes in the graph
        if( n > graph.size() ) return false;
        cycle.clear();
        VI state = VI( graph.size(), NON_VIZITED );
        // We try to initiallize from every non-vizited node
        for( unsigned v=0; v<graph.size(); v++){
            // if the node was already verified, then goes to the next one
            if( state[v] == VERIFIED ) continue;
            // if not, we mark this node as vizited
            state[v] = VIZITED;
            cycle.push_back( v );
            if ( searchDepth( v, state, cycle, n-1 ) ) return true;
            cycle.pop_back( );
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////////////
    // Try to find a cycle of a given size in a graph using limited depth-search-first
    // Used by: hasCycle(n)
    /// O( E + cycle_size )
    private:bool searchDepth( int node, VI& state, VI& cycle, int depth ){
        if( depth <= 0 ) return false;
        VPIL::iterator it;
        for (it = graph[node].begin(); it != graph[node].end(); ++it) {
            int neighboor = (*it).first;
            switch( state[neighboor] ){
                case VERIFIED: continue;
                case VIZITED:
                    if( depth != 1 ) continue;
                    cycle.push_back( neighboor );
                    return true;
            }
            state[neighboor] = VIZITED;
            cycle.push_back( neighboor );
            if ( searchDepth(neighboor, state, cycle, depth-1) ) return true;
            cycle.pop_back( );
        }
        state[node] = VERIFIED;
        return false;
    }
    ///////////////////////////////////////////////////////////////////////////////




    ///////////////////////////////////////////////////////////////////////////////
    // Try to find any bridge in the graph returning then as a vector of pairs
    // DFS based function to find all bridges (recursive)
    // Requirements: function "bridgeUtil"
    /// O( V + E )
    public:VPII findBridges(){
        #define NIL -1
        VPII bridges;
        VB visited = VB( graph.size(), false ); // Mark all the vertices as not visited
        VI discovery = VI( graph.size() );
        VI low = VI( graph.size() );
        VI parent = VI( graph.size(), NIL );
        unsigned time = 0;

        // Call the recursive function to find Bridges starting from each vertex
        for (unsigned i=0; i<graph.size(); i++){
            if ( !visited[i] )
                bridgeUtil(i, time, visited, discovery, low, parent, bridges);
        }
        return bridges;
    }

    // DFS traversal
    // u -> The vertex to be visited next
    // visited -> keeps track of visited vertices
    // discovery -> Stores discovery times of visited vertices
    // parent -> Stores parent vertices in DFS tree
    private:void bridgeUtil(unsigned u, unsigned& time, VB& visited,
                        VI& discovery, VI& low, VI& parent, VPII& bridges){
        visited[u] = true; // Mark the current node as visited
        discovery[u] = low[u] = ++time; // Initialize discovery time and low value

        for (unsigned i=0; i<graph[u].size(); ++i){
            int node = graph[u][i].first;
            if ( !visited[node] ){ // If v is not visited yet, then recur for it
                parent[node] = u;
                bridgeUtil(node, time, visited, discovery, low, parent, bridges);

                // Check if the subtree rooted with v has a
                // connection to one of the ancestors of u
                low[u] = min(low[u], low[node]);

                // If the lowest vertex reachable from subtree under v is
                // below u in DFS tree, then edge u-v is a bridge
                if ( low[node] > discovery[u] )
                    bridges.push_back( make_pair(u,node) );
            }

            // Update low value of u for parent function calls.
            else if (node != parent[u]){
                low[u] = min(low[u], discovery[node]);
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////////////




    ///////////////////////////////////////////////////////////////////////////////
    // ==> TOPOLOGICAL SORT <==
    // Returns a sequence of node indices according to requirements
    // (The fathers of a node are his requirements)
    // (nodes in a cycle excluded from returned vector)
    /// O(V + E)
    public:bool topologicalSort( VI& tseq ) {
        VI nParents( graph.size(), 0 );
        tseq.clear();
        int neighboor;
        for(unsigned from=0; from<graph.size(); from++ ){
            for(unsigned to=0; to<graph[from].size(); to++){
                neighboor = graph[from][to].first;
                nParents[neighboor]++;
            }
        }
        for(unsigned node=0; node<graph.size(); node++){
            if( nParents[node] == 0 )
                tseq.push_back( node );
        }
        for(unsigned i=0; i<tseq.size(); i++){
            int node = tseq[i];
            for(unsigned ch=0; ch<graph[node].size(); ch++){
                neighboor = graph[node][ch].first;
                nParents[ neighboor ]--;
                if( nParents[neighboor] == 0 )
                    tseq.push_back( neighboor );
            }
        }
        return (tseq.size() == graph.size());
    }
    ///////////////////////////////////////////////////////////////////////////////



    ///////////////////////////////////////////////////////////////////////////////
    // ==> PRIM <==
    // Finds the minimum spanning tree - a tree that connects every graph's
    // vertex and has the minimum tree cost.
    // IMPORTANT: Must be a conected graph (can't have subgraphs)
    /// O( V + E )
    public:Graph Prim( unsigned origin = 0 ){
        unsigned n = graph.size();
        dists      = VL( n, INF_L );
        parents    = VI( n, -1 );
        VB vizited = VB( n, false );

        Graph min_spanning_tree = Graph( n );
        SPIL to_visit; // pair( cost, node )
        to_visit.insert( make_pair(0,origin) );
        dists[ origin ] = 0;

        while( to_visit.size() > 0 ){
            unsigned node = (*to_visit.begin()).second;
            to_visit.erase( to_visit.begin() );
            vizited[ node ] = true; // mark as vizited
            if( parents[node] != -1 )
                min_spanning_tree.addEdge( parents[node], node, dists[node] );
            for (unsigned i=0; i<graph[node].size(); ++i) {
                unsigned neighboor = graph[node][i].first;
                // if a neighboor node was already visited we can skip it
                if( vizited[ neighboor ] ) continue;
                LL dst = graph[node][i].second;
                if ( dst < dists[neighboor] ) {
                    if( dst != INF_L ) //erase the old best adjency to this node
                        to_visit.erase( make_pair(dists[neighboor], neighboor) );
                    to_visit.insert( make_pair(dst, neighboor) );
                    dists[neighboor] = dst;
                    parents[neighboor] = node;
                }
            }
        }
        return min_spanning_tree;
    }
    ///////////////////////////////////////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////////
    // ==> TREE COST <==
    // Sums every edge in a tree (just one time,
    // even for graphs with undirected edges)
    /// O( V + E)
    public:LL treeCost( ){
        LL tree_cost = 0;
        int n = (int) graph.size();
        for( int i=0; i<n; i++ ){
            for( unsigned j=0; j<graph[i].size(); j++ ){
                // to avoid duplicated costs in undirected edges
                if( graph[i][j].first > i )
                    tree_cost += graph[i][j].second;
            }
        }
        return tree_cost;
    }
    ///////////////////////////////////////////////////////////////////////////////







    ///////////////////////////////////////////////////////////////////////////////
    // ==> STRONGLY CONNECTED COMPONENTS <==
    // Kosaraju algorithm - assign an ID for each node.
    // A directed graph is called strongly connected if there is a path
    // from each vertex in the graph to every other vertex. In particular,
    // this means paths in each direction: a path from 'a' to 'b' and also
    // a path from 'b' to 'a'.
    // Requirements: functions "dfs1", "dfs2" and "transpose"
    /// O( V + E )
	public:VI stronglyConnectedComponents() {
 		VI compID = VI(graph.size(), -2); // output  (nodes in same component share same ID)
 		Graph graph_transp = transpose();
 		stack<int> visited;

        for( unsigned node=0; node < graph.size(); node++)
			dfs1(node, visited, compID);
        for(int id=0; !visited.empty(); visited.pop())
            if( compID[ visited.top() ] == -1 ){
            	dfs2(id, visited.top(), compID, graph_transp);
            	id++;
			}
		return compID;
    }
 	/// O( V + E )
    private:void dfs1(unsigned v, stack<int> &visited, VI &compID) {
        if(compID[v] == -2) {
            compID[v] = -1;
            for(unsigned index=0; index<graph[v].size(); index++)
                dfs1( graph[v][index].first, visited, compID );
            visited.push(v);
        }
    }
    /// O( V + E )
    private:void dfs2(int id, int v, VI &compID, Graph &transp) {
        if(compID[v] == -1) {
            compID[v] = id;
            for(unsigned index=0; index<transp.graph[v].size(); index++)
                dfs2(id, transp.graph[v][index].first, compID, transp);
        }
    }



    ///////////////////////////////////////////////////////////////////////////////
    // ==> CONNECTED / DISCONNECTED GRAPH <==
    // A graph is connected when there is a path between every pair of vertices.
    // In a connected graph, there are no unreachable vertices. A graph that
    // is not connected is disconnected.
    /// O( V + E )
    public:bool isConnected(){
        VI comps = stronglyConnectedComponents();
        int id = comps[0];
        for( unsigned i=1; i<comps.size(); i++ )
            if( id!=comps[i] ) return false;
        return true;
    }

};

int main(){
	
	int casos, numNos;
	string s1, s2;
	vector<char> vec1, vec2, posOrder;
	
	cin >> casos;
	
	for(int i=0;i<casos;i++){
		cin >> numNos;
		getchar();
		cin >> s1;
		cin >> s2;
		for(int j=0;j<s1.size();j++){
			vec1.push_back(s1[j]);
			vec2.push_back(s2[j]);
		}
		Graph g = Graph(numNos);
    	BinaryTree<char> bt = BinaryTree<char>(vec1, vec2);
		posOrder = bt.pathPosOrder();
		for(int j=0;j<posOrder.size();j++){
			cout << posOrder[j];
		}				
		cout << endl;
		vec1.clear();
		vec2.clear();
	}
	
	return 0;
}