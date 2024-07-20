#include <bits/stdc++.h>
using namespace std;

void updateweights(int dest,vector <vector <vector <int> > >& air_india,vector <vector <vector <int> > >& spiceget,vector <vector <vector <int> > >& indigo,vector <vector <vector <int> > >& vistara){
        for(int i =0;i<air_india.size();i++){
            for(int j = 0;j<air_india[i].size();j++){
                if(air_india[i][j][0] == dest){
                    air_india[i][j][1] = (air_india[i][j][1] * 0.005) +air_india[i][j][1];
                }else{
                    air_india[i][j][1] = (air_india[i][j][1] * (-0.00001)) +air_india[i][j][1];
                }
            }
        }
          for(int i =0;i<spiceget.size();i++){
            for(int j = 0;j<spiceget[i].size();j++){
                if(spiceget[i][j][0] == dest){
                    spiceget[i][j][1] = (spiceget[i][j][1] * 0.005) +spiceget[i][j][1];
                }else{
                    spiceget[i][j][1] = (spiceget[i][j][1] * (-0.00001)) +spiceget[i][j][1];
                }
            }
        }
        for(int i =0;i<indigo.size();i++){
            for(int j = 0;j<indigo[i].size();j++){
                if(indigo[i][j][0] == dest){
                    indigo[i][j][1] = (indigo[i][j][1] * 0.005) +indigo[i][j][1];
                }else{
                    indigo[i][j][1] = (indigo[i][j][1] * (-0.0001)) +indigo[i][j][1];
                }
            }
        }
        for(int i =0;i<vistara.size();i++){
            for(int j = 0;j<vistara[i].size();j++){
                if(vistara[i][j][0] == dest){
                   vistara[i][j][1] = (vistara[i][j][1] * 0.005) +vistara[i][j][1];
                }else{
                    vistara[i][j][1] = (vistara[i][j][1] * (-0.00001)) +vistara[i][j][1];
                }
            }
        }
}
vector <vector <vector <int> > > converttolist(vector <vector <vector <int> > > graph){
    vector <vector <vector <int> > > adj(12);
    for(int i = 0;i<graph.size();i++){
        for(int j = 0;j< graph.size();j++){
            if(graph[i][j][0] < 1e9){
                adj[i].push_back({j,graph[i][j][0],graph[i][j][1],graph[i][j][2]});
            }
        }
    }
    return adj;
}
vector <vector < vector < int > > >  mergegraphs(vector <vector <vector <int> > >&air_india ,vector <vector <vector <int> > >&spiceget,
vector <vector <vector <int> > >&indigo,vector <vector <vector <int> > >&vistara){
    vector<vector<vector<int> > > graph(12, vector< vector< int > > (12, vector< int > (3,1e9)));
    for(int i = 0;i<air_india.size();i++){
        for(int j = 0;j<air_india[i].size();j++){
            
            if(graph[i][j][0] > air_india[i][j][1]){
                graph[i][j][0] = air_india[i][j][1];
                graph[i][j][1] = air_india[i][j][2];
                graph[i][j][2] = air_india[i][j][3];
            }
         }
      }
      for(int i = 0;i<spiceget.size();i++){
        for(int j = 0;j<spiceget[i].size();j++){
            if(graph[i][j][0] > spiceget[i][j][1]){
                graph[i][j][0] = spiceget[i][j][1];
                graph[i][j][1] = spiceget[i][j][2];
                graph[i][j][2] = spiceget[i][j][3];
            }
         }
      }
      for(int i = 0;i<indigo.size();i++){
        for(int j = 0;j<indigo[i].size();j++){
            if(graph[i][j][0] > indigo[i][j][1]){
                graph[i][j][0] = indigo[i][j][1];
                graph[i][j][1] = indigo[i][j][2];
                graph[i][j][2] = indigo[i][j][3];
            }
         }
      }
      for(int i = 0;i<vistara.size();i++){
        for(int j = 0;j<vistara[i].size();j++){
            if(graph[i][j][0] > vistara[i][j][1]){
                graph[i][j][0] = vistara[i][j][1];
                graph[i][j][1] = vistara[i][j][2];
                graph[i][j][2] = vistara[i][j][3];
            }
         }
      }
    //       for(int i = 0;i<graph.size();i++){
    //     for(int j = 0;j<graph.size();j++){
    //         for(int k = 0;k<3;k++){
    //             if(graph[i][j][k] == 1e9)cout << -1<<" ";
    //             else cout << graph[i][j][k] <<" ";
    //         }
    //         cout <<"    ";
    //     }
    //     cout << endl;
    // }
    return graph;
}
vector <int> findshortestpath(vector <vector <vector <int> > > graph , int src){
    vector <int> dist(12,1e9);
    dist[src] = 0;
    priority_queue <pair < pair <int,int>,int > , vector <pair < pair <int,int>,int > > , greater < pair < pair <int,int>,int > > > pq;
    pq.push({{0,src},0});
    while(!pq.empty()){
        int cost = pq.top().first.first;
        int node = pq.top().first.second;
        int tim = pq.top().second;
        pq.pop();
        for(auto it : graph[node]){
            int adjnode = it[0];
            int wt = it[1];
            int dur = it[2];
            int dep_time = it[3];
            if(dist[adjnode] > cost + wt && tim < dep_time){
                //cout << node <<" " <<adjnode << " " <<wt << " "<<dur <<" " <<dep_time << endl;
                dist[adjnode] = cost + wt;
                pq.push({{cost+wt , adjnode},tim+dur});
            }
        }
    }
    return dist;
}

void findallpaths(int src , int dest,vector <vector <vector <int> > >& air_india ,vector <vector <vector <int> > >&spiceget ,
 vector <vector <vector <int> > >&indigo ,vector <vector <vector <int> > >& vistara ,vector <int>& vis , vector <vector <int> > temp,int tim ,int cost,vector <vector < vector <int> > >&result){
     if(src == dest){
         result.push_back(temp);
         return;
     }
     vis[src] = 1;
     for(auto it : air_india[src]){
         int adjnode = it[0];
         int money = it[1];
         int dura = it[2];
         int dep_time = it[3];
         int atype = it[5];
         if(!vis[adjnode] && tim < dep_time){
             temp.push_back({adjnode,money , dura , dep_time,atype});
             findallpaths(adjnode,dest,air_india,spiceget,indigo,vistara,vis,temp,dep_time+dura,cost+money,result);
             temp.pop_back();
         }
     }
          for(auto it : spiceget[src]){
         int adjnode = it[0];
         int money = it[1];
         int dura = it[2];
         int dep_time = it[3];
         int atype = it[5];
         if(!vis[adjnode] && tim < dep_time){
             temp.push_back({adjnode,money , dura , dep_time,atype});
             findallpaths(adjnode,dest,air_india,spiceget,indigo,vistara,vis,temp,dep_time+dura,cost+money,result);
             temp.pop_back();
         }
     }
          for(auto it : indigo[src]){
         int adjnode = it[0];
         int money = it[1];
         int dura = it[2];
         int dep_time = it[3];
         int atype = it[5];
         if(!vis[adjnode] && tim < dep_time){
             temp.push_back({adjnode,money , dura , dep_time,atype});
             findallpaths(adjnode,dest,air_india,spiceget,indigo,vistara,vis,temp,dep_time+dura,cost+money,result);
             temp.pop_back();
         }
     }
          for(auto it : vistara[src]){
         int adjnode = it[0];
         int money = it[1];
         int dura = it[2];
         int dep_time = it[3];
         int atype = it[5];
         if(!vis[adjnode] && tim < dep_time){
             temp.push_back({adjnode,money , dura , dep_time,atype});
             findallpaths(adjnode,dest,air_india,spiceget,indigo,vistara,vis,temp,dep_time+dura,cost+money,result);
             temp.pop_back();
         }
     }
     vis[src] = 0;
 }
vector <vector <vector <int> > > get_graph(vector <string> airportcodes , int airlinetype){
    vector <vector <vector <int> > > adj(12);
    vector <vector <int> > graph(12 , vector <int> (12 , 0));
    for(int i = 0;i<30;i++){
        int src = (rand() % (12));
        int dest =  (rand() % (12));
        if(graph[src][dest]){
            i--;
            continue;
        }
        else{
            vector <int> temp;
            graph[src][dest] = 1;
            int cost =  (rand() % (15000 - 5000 + 1)) + 5000;
            int duration = 60+ (420 - 60) * (random() % 420)/420;
            int dep_time = rand() % 1440;
            int arr_time  = (dep_time + duration) % 1440;
            adj[src].push_back({dest , cost , duration , dep_time , arr_time,airlinetype});
            
        }
    }
    return adj;
}
int main(){
    int n = 12;
    map <string,string> Airportnames;
   Airportnames["DEL"] = "Chhatrapati Shivaji Maharaj International Airport";
   Airportnames["BOM"] = "Kempegowda International Airport, Bengaluru";
   Airportnames["CCU"] = "Netaji Subhash Chandra Bose International Airport,Kolkata";
   Airportnames["HYD"] = "Rajiv Gandhi International Airport, Hyderabad";
   Airportnames["MAA"] = "Chennai International Airport, Chennai";
   Airportnames["COK"] = " Cochin International Airport, Kerala";
   Airportnames["GOI"] = " Dabolim Airport, Goa";
   Airportnames["TRV"] = "Trivandrum International Airport, Kerala";
   Airportnames["GWI"] = "Lokpriya Gopinath Bordoloi International Airport, Guwahati";
   Airportnames["RPR"] = "Swami Vivekananda Airport, Raipur";
   Airportnames["JAI"] = " Jaipur International Airport, Jaipur:";
   Airportnames["AMD"] = "Sardar Vallabhbhai Patel International Airport";
   vector <string> airportcodes = {"DEL" ,"BOM" , "CCU","HYD" , "MAA" , "COK", "GOI" , "TRV" ,"GWI","RPR","JAI" , "AMD"};
   map <int,string >  airlinetype;
   
   vector <vector <vector <int> > >air_india = get_graph(airportcodes,0);
   vector <vector <vector <int> > >spiceget = get_graph(airportcodes,1);
   vector <vector <vector <int> > >indigo = get_graph(airportcodes,2);
   vector <vector <vector <int> > >vistara = get_graph(airportcodes,3);
   airlinetype[0] = "air_india";
   airlinetype[1] = "spiceget";
   airlinetype[2] = "indigo";
   airlinetype[3] = "vistara";
  
   map <int,string> ac;
   int index = 0;
   for(auto it : airportcodes){
       ac[index] = it;
       index++;
   }
   map <string,int> ac1;
   int index1 = 0;
   for(auto it : airportcodes){
       ac1[it] = index1;
       index1++;
   }
   while(true){
   int src,dest;
   cout << " Enter Src" << endl;
   string sr;
   cin >> sr;
   src = ac1[sr];
   if(src == -1)break;
   cout << " Enter Dest" << endl;
   string dt;
   cin>>dt;
   dest = ac1[dt];
   if(src == dest){
       cout << "Enter Again" << endl;
       
   }
   
   vector <int> vis(12,0);
   vector <vector <vector <int> > >result;
   vector <vector <int> > temp;
   findallpaths(src,dest,air_india,spiceget,indigo,vistara,vis,temp,0,0,result);
   cout <<" Stops " << " Price " << "Duration " << " Dep_time " << "Company" << endl;
   cout <<"--------------------------------------------------------------------------------------------------" << endl;
   
   for(auto it : result){
       
       for(auto it1 : it){
           for(int i = 0;i<it1.size();i++){
               if(i == 0)cout << ac[it1[i]] << "      ";
               if(i == 1)cout << it1[i] << "     ";
               if(i == 2)cout << it1[i] << "    ";
               if(i ==3)cout << (it1[i]/60) << ":" << (it1[i] % 60) << "   ";
               if(i == 4)cout << airlinetype[it1[i]] <<"   ";
           }
           cout << endl;
       }
       cout << endl;
       cout << endl;
   }
   int ans = 1e9;
   vector <vector <int> > as;
   for(int i = 0;i<result.size();i++){
       int sum = 0;
       for(int j = 0;j<result[i].size();j++){
           sum += result[i][j][1];
       }
       if(sum < ans){
           ans = sum;
           as.clear();
           for(int k = 0;k<result[i].size();k++){
               as.push_back(result[i][k]);
           }
       }
   }
  vector <vector <vector <int> > > graph = mergegraphs(air_india,spiceget,indigo,vistara);
  vector <vector <vector <int> > > adj = converttolist(graph);
  vector <int> dist = findshortestpath(adj,src);
  cout << "Shortest path according to Cost" << endl;
  cout << ans << endl;
  for(int i = 0;i<as.size();i++){
      for(int j = 0;j<as[i].size();j++){
            if(j == 0)cout << ac[as[i][j]] << "      ";
              if(j == 1)cout << as[i][j] << "     ";
              if(j == 2)cout << as[i][j] << "    ";
              if(j ==3)cout << (as[i][j]/60) << ":" << (as[i][j] % 60) << "   ";
              if(j == 4)cout << airlinetype[as[i][j]] <<"   ";
      }
      cout << endl;
  }
  cout << endl;
  cout << "Shortest path according to the time"<< endl;
   vector <vector <int> > as1;
   int ans1 = 1e9;
      for(int i = 0;i<result.size();i++){
       int sum1 = 0;
       for(int j = 0;j<result[i].size();j++){
           if(j+1<result[i].size()){
               sum1 += result[i][j+1][3] - (result[i][j][3]);
           }
       }
       if(sum1 < ans1){
           ans1 = sum1;
           as1.clear();
           for(int k = 0;k<result[i].size();k++){
               as1.push_back(result[i][k]);
           }
       }
   }
     for(int i = 0;i<as1.size();i++){
      for(int j = 0;j<as1[i].size();j++){
            if(j == 0)cout << ac[as1[i][j]] << "      ";
              if(j == 1)cout << as1[i][j] << "     ";
              if(j == 2)cout << as1[i][j] << "    ";
              if(j == 3)cout << (as1[i][j]/60) << ":" << (as[i][j] % 60) << "   ";
              if(j == 4)cout << airlinetype[as1[i][j]] <<"   ";
      }
      cout << endl;
    }
    updateweights(dest,air_india,spiceget,indigo,vistara);
   }
}
  
