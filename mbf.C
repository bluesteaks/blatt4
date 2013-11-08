// MBF

#include "wgraph.h"

using namespace std;

int main(int argc, char* argv[])
{
      if (argc > 1) 
      {
            Weighted_Graph g(argv[1],1);
            g.add_node();					//Zsatzknoten, falls nicht zshgd.

            int dist[g.num_nodes()];
            Graph::NodeId prev[g.num_nodes()];

            dist[g.num_nodes()-1]=0;

            for(int i=0;i<g.num_nodes()-1;i++)
   			{
   				g.add_edge(g.num_nodes()-1,i);		//Verbinde Zusatzknoten mit allen anderen, Gewicht 0.
            	g._weight.push_back(0);
   				dist[i]=2000000000;					//unendlich geht nicht...
   				prev[i]=-1;
   			}

	   		for(int i=0;i<g.num_nodes()-1;i++)		//alg. aus VL
	   			{
   				for(Graph::EdgeId e=0;e<g.num_edges();e++)
   				{
   					Graph::NodeId u=g.get_edge(e).get_tail();
   					Graph::NodeId v=g.get_edge(e).get_head();
   					if(dist[u]+g._weight[e]<dist[v])
   					{
   						dist[v]=dist[u]+g._weight[e];
   						prev[v]=u;
   					}
   				}
   			}

   			int cycle=0;
   			Graph::NodeId u,v;
   			for(Graph::EdgeId e=0;e<g.num_edges();e++)	//Suche nach neg. Kreis
   			{
   				u=g.get_edge(e).get_tail();
   				v=g.get_edge(e).get_head();
   				if(dist[u]+g._weight[e]<dist[v])
   				{
   					cycle=1;
   					break;
   				}  				
   					
   			}

   			if(cycle)
   			{
   				cout << "0\n";

   				for(int i=0;i<g.num_nodes();i++)//Gehe n-1 Schritte zurück (garantiert, dass wir im Kreis sind)
   				{	
   					v=prev[v];
   				}

   				Graph::NodeId a=v;

   				cout << a << "\n";
   				v=prev[v];
   				while(a!=v)	//durchlaufe Knoten so lange bis ein Knoten wieder auftaucht=> Kreis
	   			{
   					cout << v << "\n";
   					v=prev[v];   					
   				}

   			}
   			else
   			{
   				cout << "1\n";
   				for(int i=0;i<g.num_nodes();i++)
   				{
   					cout << dist[i] << "\n";
   				}
			}      		
}
      return 0;
}
