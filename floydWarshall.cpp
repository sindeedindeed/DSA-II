#include <bits/stdc++.h>
using namespace std;
#define nV 4 // defines number of vertices
const int INF=1e9; // declaring infinity as 1 billion

void printMatrix(int matrix[][nV]){
    for(int i=0;i<nV;i++){
        for(int j=0;j<nV;j++){
            if(matrix[i][j]==INF) 
                cout<<"INFINITY ";
            else
                cout<<matrix[i][j]<<" ";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][nV]){
    int matrix[nV][nV],i,j,k;
    
    for(i=0;i<nV;i++)
        for(j=0;j<nV;j++)
            matrix[i][j]=graph[i][j];   

    for(k=0;k<nV;k++){
        for(i=0;i<nV;i++){
            for(j=0;j<nV;j++){
                if(matrix[i][k]+matrix[k][j]<matrix[i][j])
                    matrix[i][j]=matrix[i][k]+matrix[k][j];
            }
        }
    }
    printMatrix(matrix);
}                                      
                                        
int main(){                             
    int graph[nV][nV]={{0,3,INF,5},
                        {2,0,INF,4},
                        {INF,1,0,INF},
                        {INF,INF,2,0}};
    floydWarshall(graph);
    return 0;
}
