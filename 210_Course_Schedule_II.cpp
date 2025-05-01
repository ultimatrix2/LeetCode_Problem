
class Solution {
public:
    vector <int > findOrder(int n, vector<vector<int>>& pre) {
        vector <int> indeg( n, 0 );
         vector <vector <int>> adj ( n);
         for(  auto & v : pre ){
            adj[v[0]].push_back ( v[1] );
            indeg[v[1]]++;
         } 
            queue <int> qu;
         for( int  i = 0 ; i< n ; i ++){
            if( indeg[i] == 0){
                qu.push(  i );}
         }
        int ct = 0;
        vector <int > ans;
         while( !qu.empty()){
            int cur = qu.front(); qu.pop();
            // cout<<cur <<" ";
           ans.push_back( cur );
            for( auto&  node : adj[cur]){
                indeg[ node] --;
                if( indeg[node] == 0)
                    qu.push( node );
            }
         }
        if( ans.size() != n) return {} ;
        reverse( ans.begin() , ans.end());
         return ans;
    }
};
