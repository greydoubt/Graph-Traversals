#ifndef GRAPHTRAVERSALS
#define GRAPHTRAVERSALS

template <typename V>
class graphType
{
private:
    int maxVertices; // added all at once
    int numEdges; // added incrementally
    std::vector<V> labels; // assumed to be string, can differ or even take compound objects
    std::list<int> *adjacencyList;
public:
    graphType(int numVertices, V labelsArray[]);  
    
    inline void printGraph(int index);
    
    // function to add an edge between two vertices, also increments edge count
    void createGraph(int v, int w);
    
    bool isEmpty(); // if there are no edges return true
    
    void breadthFirstTraversal(int index);

    void depthFirstTraversal(int index);
    
    inline void depthFirstTraversal(int index, bool visited[]);
};

template <typename V>
graphType<V>::graphType(int numVertices, V labelsArray[])
{
    // at the point where graph object has been constructed, it has an array of vertices' names/labels/keys
    // these are arbitrary types mapped to a (positive) integer
    // additionally, a List is made so that each vertice (index, not key) has an adjacency list
    // number of edges is set to 0, the initial state is a disconnected set of vertices
    
    
    this->labels.insert(labels.end(), &labelsArray[0], &labelsArray[numVertices]);
    
    this->maxVertices = numVertices;
    
    this->numEdges = 0;
    
    adjacencyList = new std::list<int>[numVertices];
}

template <typename V>
inline void graphType<V>::printGraph(int index){


    std::cout << labels[index];

    static int commaCounter = 0;
    //commaCounter++;

    if ((++commaCounter) % maxVertices){
      std::cout << ", ";
    }
    
    

    
}

template <typename V>
bool graphType<V>::isEmpty()
{
    return numEdges; // if empty then numEdges == 0
}

template <typename V>
void graphType<V>::createGraph(int v, int w)
{
    //std::cout << v << " added to list\n";
    adjacencyList[v].push_back(w); // Add w to v’s list
    adjacencyList[w].push_back(v); // Add v to w's list
    
    this->numEdges += 1;
    //std::cout << "graph now has " << numEdges << " edges!!\n";
}

// uses a queue-like list
template <typename V>
void graphType<V>::breadthFirstTraversal(int index)
{
    
    std::list<int> breadthList;
    
    bool *visited = new bool[maxVertices];
    
    for(int i = 0; i < maxVertices; i++){
        visited[i] = false;
        }
    
    visited[index] = true;

    breadthList.push_back(index);
    
    std::list<int>::iterator j;
    
    while(!breadthList.empty()){

        index = breadthList.front();

        printGraph(index);
        
        breadthList.pop_front();
        
        
        for (j = adjacencyList[index].begin(); j != adjacencyList[index].end(); ++j)
        {
            if (!visited[*j])
            {
                visited[*j] = true;
                breadthList.push_back(*j);
            }
        }
    }
    
    delete [] visited;
}

// this is based on the notes, uses a stack
template <typename V>
inline void graphType<V>::depthFirstTraversal(int index, bool visited[])
{
    visited[index] = true;
    
    printGraph(index);
    
    std::list<int>::iterator i;
    
    for (i = adjacencyList[index].begin(); i != adjacencyList[index].end(); ++i){
        if (!visited[*i]){
            depthFirstTraversal(*i, visited);
        }
    }
    
}

template <typename V>
void graphType<V>::depthFirstTraversal(int index)
{

    bool *visited = new bool[maxVertices]; 
    
    for (int i = 0; i < maxVertices; i++){
        visited[i] = false;
    }

    depthFirstTraversal(index, visited);
    
    delete [] visited;
}
#endif