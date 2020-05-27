#include <iostream>
#include <list>
#include <vector>
#include "graph.h"

int main()
{

    short citySelection;

    char continueSelection;

    // Create a graph given a label set and diagram
    
    std::string vertices[] = {
        "Seattle", //0: SF1, Denv3, Chi5
        "San Francisco", //1: STL0, LA2, Denv3,
        "Los Angeles", //2: SF1, Denv3, KC4, Dal10
        "Denver", //3: STL0, SF1, LA2, KC4, Chi5
        "Kansas", //4: LA2, Denv3, Chi5, NY7, ATL8, Dal10
        "Chicago", //5: STL0, Den3, KC4, Bost6, NY7
        "Boston", //6: Chi5, NY7
        "New York", //7: KC4, Chi5, Bost6, ATL8
        "Atlanta", //8: NY7, Dal10, Hous11, Miam9
        "Miami", //9: Atl8, Houst11
        "Dallas", //10: LA2, KC4, ATL8, Houston11
        "Houston" //11: Dal10, ATL8, Mia9
    };
    
    int numVertices = *(&vertices + 1) - vertices;
    
    graphType<std::string> cityGraph(numVertices, vertices);
    
    cityGraph.createGraph(0, 1);
    cityGraph.createGraph(0, 3);
    cityGraph.createGraph(0, 5);

    cityGraph.createGraph(1, 2);
    cityGraph.createGraph(1, 3);
    
    cityGraph.createGraph(2, 3);
    cityGraph.createGraph(2, 4);
    cityGraph.createGraph(2, 10);
    
    cityGraph.createGraph(3, 4);
    cityGraph.createGraph(3, 5);
    
    cityGraph.createGraph(4, 5);
    cityGraph.createGraph(4, 7);
    cityGraph.createGraph(4, 8);
    cityGraph.createGraph(4, 10);
    
    cityGraph.createGraph(5, 6);
    cityGraph.createGraph(5, 7);
    
    cityGraph.createGraph(6, 7);
    
    cityGraph.createGraph(7, 8);
    
    cityGraph.createGraph(8, 9);
    cityGraph.createGraph(8, 10);
    cityGraph.createGraph(8, 11);
    
    cityGraph.createGraph(9, 11);
    
    cityGraph.createGraph(10, 11);
    
    
    /* test program without user input:
    std::cout << "Following is Depth-First Traversal:\n";

    cityGraph.depthFirstTraversal(2);
    std::cout << '\n';
    std::cout << '\n';
    
    std::cout << "Following is Breadth-First Traversal:\n";
    cityGraph.breadthFirstTraversal(2);
    std::cout << '\n';
    */
    
    
    
    do{
    
        std::cout << "Graph Traversals" << std::endl;
        
        std::cout << "Enter starting city using number from 0 - " << numVertices - 1 << ": ";
        
        std::cin >> citySelection;
        
        std::cout << "You entered city name: " << vertices[citySelection] << std::endl << std::endl;
    
        std::cout << "Starting at " << vertices[citySelection] << ", " << numVertices << " cities are searched in this Depth-First Search order:\n";
    
        cityGraph.depthFirstTraversal(citySelection);
        
        std::cout << std::endl << std::endl;
    
        std::cout << "Starting at " << vertices[citySelection] << ", " << numVertices << " cities are searched in this Breadth-First Search order:\n";
        
        cityGraph.breadthFirstTraversal(citySelection);
        
        std::cout << std::endl;
        
        std::cout << "Try another city (Y/N) ";
        
        std::cin >> continueSelection;
        
    } while (tolower(continueSelection) == 'y');
        
    
    return 0;
}




/*
 Sample output:
 
 Graph Traversals
 Enter starting city using number from 0 - 11: 2
 You entered city name: Los Angeles
 
 Starting at Los Angeles, 12 cities are searched in this Depth-First Search order:
 Los Angeles, San Francisco, Seattle, Denver, Kansas, Chicago, Boston, New York, Atlanta, Miami, Houston, Dallas,
 Starting at Los Angeles, 12 cities are searched in this Breadth-First Search order:
 Los Angeles, San Francisco, Denver, Kansas, Dallas, Seattle, Chicago, New York, Atlanta, Houston, Boston, Miami,
 
 Try another city (Y/N) Y
 
 Enter starting city using number from 0 - 11: 5
 You entered city name: Chicago
 
 Starting at Chicago, 12 cities are searched in this Depth-First Search order:
 Chicago, Seattle, San Francisco, Los Angeles, Denver, Kansas, New York, Boston, Atlanta, Miami, Houston, Dallas,
 
 Starting at Chicago, 12 cities are searched in this Breadth-First Search order:
 Chicago, Seattle, Denver, Kansas, Boston, New York, San Francisco, Los Angeles, Atlanta, Dallas, Miami, Houston,
 Try another city (Y/N) N
 
 
 */
