/*
* @ by Surya Thakur
*
*/

#include <stdio.h>
#define INF 99999
#include <limits.h>
#include<stdbool.h>

int V=9;

int distMinimum(int distance[], bool boolArray[])
{
int min = INF, min_index,i,j,v;

for ( v = 0; v < V; v++)
	if (boolArray[v] == false && distance[v] <= min)
		min = distance[v], min_index = v;

return min_index;
}


int OutputAns(int distance[], int n)
{
printf("Vertex distance from Source\n");
int i;
for (i = 0; i < V; i++)
	printf("%d \t %d\n", i, distance[i]);
}


void OutputPath(int Nodes_Space[V][V], int distance[V], int destination, int source)
{
    int i,de;
    printf("Enter the destination\n");
    scanf("%d",&de);
    destination = de;
    int temp=distance[destination];
    printf("\n%d ( %d )->", destination, temp);
    for(i=0;i<V,temp>0;i++)
        {
            temp=temp-Nodes_Space[i][destination];
            if(distance[i]== temp && i!=destination)
            {
                printf("%d( %d ) -> ",i, temp);
                if(i==source)
                    break;
                destination=i;
                i=-1;
            }
            else {temp=temp+Nodes_Space[i][destination];}
        }
    printf("Reached (destination to source). \n");
}





void Algo_Dijkstra(int Nodes_Space[V][V], int source)
{
	int distance[V];
	int i,count;	 
	bool boolArray[V]; 
					
		for (i = 0; i < V; i++)
		distance[i] = INF, boolArray[i] = false;

		distance[source] = 0;

		for (count = 0; count < V-1; count++)
	{
		int u = distMinimum(distance, boolArray);

		boolArray[u] = true;
	    int v;

		for (v = 0; v < V; v++)
		  if (!boolArray[v] && Nodes_Space[u][v] && distance[u] != INF && distance[u]+Nodes_Space[u][v] < distance[v])
			  distance[v] = distance[u] + Nodes_Space[u][v];
	}

	OutputAns(distance, V);
	OutputPath(Nodes_Space, distance, 3, source);
}

void algo_War (int space2D[V][V])
{
    int distance2D[V][V], i, j, k;
    int source, destination;
    for (i = 0; i < V; i++)
      {
	    for (j = 0; j < V; j++)
            distance2D[i][j] = space2D[i][j];
      }

    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (distance2D[i][k] + distance2D[k][j] < distance2D[i][j])
                    distance2D[i][j] = distance2D[i][k] + distance2D[k][j];
            }
        }
    }
    
    printf(" Enter the source node and the destination node number: ");
    scanf("%d %d", &source, &destination);
    
    print(distance2D, source, destination);
    pathprint(space2D, distance2D, source , destination);
}


void print(int distance2D[V][V],int source, int destination)
{
    int i,j;
    printf ("\n\nDistance between the entered source and destination is : ");

    printf ("%d \n\n", distance2D[source][destination]);
}



void pathprint(int space2D[V][V], int distance2D[V][V], int source, int destination)
{
    int i;
    int temp=distance2D[source][destination];
    printf(" %d( %d ) -> ", destination, temp);
    for(i=0;i<V,temp>0;i++)
        {
            temp=temp-space2D[i][destination];
            if(distance2D[source][i]== temp && i!=destination)
            {
                printf(" %d( %d ) -> ",i, temp);
                if(i==source)
                    break;
                destination=i;
                i=-1;
            }
            else {temp=temp+space2D[i][destination];}
        }
    printf(" Reached ( from destination to source) \n");
}



int main()
{
   int source, alg;
    char c;
   printf("\n***Welcome to the SHORTEST PATH ALGORITHMS PROGRAM***\n");
   again:
   	fflush(stdin);
   printf("\nWant to enter your space2D? Y/N \n");
   scanf("%c", &c);
   switch (c)
       {
          case 'Y':
          case 'y':
             {
                 int size,val;
                 int i, j;
                 printf("Enter the no. of nodes: ");
	    		scanf("%d",&size);
	    		int space2D[size][size];
                V=size;
		    	printf("\nEnter the values of the weights and 0 for the infinite\n");
		    	for(i=0;i<size;i++){
			      	for(j=0; j<size;j++){
                            if(i==j)
                            {
                                space2D[i][j]=0;
                            }
                            else
                            {
				             	printf("\nEnter the weight for edge from %d to %d\n",i,j);
				             	scanf("%d",&val);
				             	if(val==0)
                                    space2D[i][j]=INF;
                                else
                                    space2D[i][j]=val;
                            }
			      	}
		    	}
		    	printf("Which Algorithm you want to use? 1.Dijkstra 2.Warshall: ");
		    	scanf("%d", &alg);
		    	switch (alg)
		    	{
		    		case 1:
		    			{
		    				printf("Enter the value of Source\n");
	                        scanf("%d",&source);

	                        Algo_Dijkstra(space2D, source);
	                        break;
						}
				    case 2:
				    	{
		             	  algo_War(space2D);
		                	break;
						}
				}
				break;
       }
       
          case 'n':
          case'N':
             {
            	int space2D[9][9]={{0, 4, INF, INF, INF, INF, INF, 8, INF},
                     {4, 0, 8, INF, INF, INF, INF, 11, INF},
				     {INF, 8, 0, 7, INF, 4, INF, INF, 2},
				     {INF, INF, 7, 0, 9, 14, INF, INF, INF},
                     {INF, INF, INF, 9, 0, 10, INF, INF, INF},
				     {INF, INF, 4, 14, 10, 0, 2, INF, INF},
				     {INF, INF, INF, INF, INF, 2, 0, 1, 6},
				     {8, 11, INF, INF, INF, INF, 1, 0, 7},
				     {INF, INF, 2, INF, INF, INF, 6, 7, 0}};
				     
			    	printf("Which Algorithm you want to use? 1.Dijkstra 2.Warshall: ");
		         	scanf("%d", &alg);	     
				    switch (alg)
		    	{
		    		case 1:
		    			{
		    				printf("Enter the value of Source\n");
	                        scanf("%d",&source);

	                        Algo_Dijkstra(space2D, source);   
	                        break;
						}
				    case 2:
				    	{
		             	  algo_War(space2D);
		                	break;
						}
				}
             }
       }
       char rep;
       printf("\n Want to use again? Y/N:\n");
       fflush(stdin);    // this is for cleaning character values.
       scanf("%c", &rep);
       if(rep=='Y'|| rep=='y')
           goto again;
       else 
           printf("\n***THANK YOU FOR USING THE PROGRAM.***\n");
        
}
