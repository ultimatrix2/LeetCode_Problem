class Solution {
    vector <vector <int >> dir ={ { 1 , 0 }, {-1 , 0}, {0 , 1}, {0, -1}};
public:
    int minTimeToReach(vector<vector<int>>& move) {
        int Min = INT_MAX ; 
        int row= move.size();
        int col = move[0].size();

        vector <vector <bool >> seen( row , vector <bool > ( col , false ));
        vector <vector <int >> dis( row , vector <int > ( col , INT_MAX ));

         priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push( { 0, 0 , 0 });
        dis[0][0] = 0;
        while(  !pq.empty()) {
            auto [w , i , j ] = pq.top(); pq.pop();
            if( seen[i][j]) continue;
            seen[i][j] = true ;

            for( int x = 0 ; x < 4 ; x++  ){
                int  p= i + dir[x][0] , q= j + dir[x][1];
                if( p < 0 || p >= row || q <0 || q >= col ) continue;
                if( !seen[ p ][ q ]){
                    int extra = move[p][q] - w;
                    if( extra <  0) extra = 0;
                    if(  dis[p][q] > ( 1+ dis[i][j]  + extra)){
                         dis[p][q]  = ( 1+ dis[i][j]  + extra) ;
                         pq.push( { dis[p][q] , p ,q });
                    }
                }
            }
        }
        return dis[row -1 ] [ col - 1];
    }
};
