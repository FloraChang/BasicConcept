#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

#define MAX 50

using namespace std;

class vertex
{
public:
    vertex( string aLable, int aIndex )
    {
        lable = aLable;
        index = aIndex;
        visited = false;
    }
    
    string getId(){ return lable; }
    bool visited;

private:
    string lable;
    int index;
};

// vector of vertices
vector<vertex> vertices;

// adjacent marrix of vertices
int adjMatrix[MAX][MAX];

void initAdjMatrix()
{
    // initialize adjMatrix
    for( int i = 0; i < MAX; i++ )
    {
        for( int j = 0; j < MAX; j++ )
        {
            adjMatrix[i][j] = false;
        }
    }
}

void resetVertices()
{
    for( int i = 0; i < (int)vertices.size(); i++ )
    {
        vertices[i].visited = false;
    }
}

void displayVertex( int idx )
{
    cout << vertices[idx].getId() << endl;
}

void setVisisted( stack<int>& stack, int idx )
{
    stack.push( idx );
    vertices[ idx ].visited = true;
    displayVertex( idx );
}

void setVisisted( queue<int>& queue, int idx )
{
    queue.push( idx );
    vertices[ idx ].visited = true;
    displayVertex( idx );
}

int getUnvisitedAdj( int idx )
{
    for( int adj = 0; adj < (int)vertices.size(); adj++ )
    {
        if( adjMatrix[idx][adj] == true && vertices[adj].visited == false )
        {
            return adj;
        }
    }

    return -1;
}

void DepthFirstSearch( int root )
{
    cout<<"DFS starts from " << vertices[root].getId() << endl;
    
    stack<int> stack;

    setVisisted( stack, root );

    while ( !stack.empty() )
    {
        int next = getUnvisitedAdj( stack.top() );
        
        if( next == -1 )
        {
            stack.pop();
        }
        else
        {
            setVisisted( stack, next );
        }
    }
    
    resetVertices(); // reset visited flag to false
}

void BreadthFirstSearch( int root )
{
    cout<<"BFS starts from " << vertices[root].getId() << endl;
    
    queue<int> queue;
    
    setVisisted( queue, root );
    
    while ( !queue.empty() )
    {
        int next = getUnvisitedAdj( queue.front() );
        
        if( next == -1 )
        {
            queue.pop();
        }
        else
        {
            setVisisted( queue, next );
        }
    }
    
    resetVertices(); // reset visited flag to false
}

void addVertex( string aLable )
{
    int size = (int)vertices.size();
    vertex newVertex( aLable, size );
    vertices.push_back( newVertex );
    
    cout<< size <<". "<<aLable<<" is added."<<endl;
}

bool addEdge( int idx1, int idx2 )
{
    adjMatrix[idx1][idx2] = true;
    adjMatrix[idx2][idx1] = true;
    
    cout<< "add edge: " << vertices[idx1].getId() << " - " << vertices[idx2].getId() << endl;
    return true;
}

int main()
{
    initAdjMatrix();
    
    addVertex( "Flora" );     // 0
    addVertex( "Larry" );     // 1
    addVertex( "Jade" );      // 2
    addVertex( "Jacky" );     // 3
    addVertex( "Charles" );   // 4
    addVertex( "Elsa" );      // 5
    addVertex( "Chocolate" ); // 6
    
    addEdge( 0, 1 );
    addEdge( 0, 2 );
    addEdge( 0, 5 );
    addEdge( 0, 6 );
    addEdge( 1, 4 );
    addEdge( 2, 5 );
    addEdge( 3, 4 );
    
    DepthFirstSearch( 0 );
    BreadthFirstSearch( 0 );
    
    return 1;
}
