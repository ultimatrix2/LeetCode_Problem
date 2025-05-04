class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        map <pair <int , int >  , int> mp ;
        int n = dom.size();
        int ct =0 ;
        
        for( auto &  a:  dom ){
            int p = a[0] , q = a[1];
            if( p > q ) swap( a[0], a[1]);
            
                mp[{a[0] ,a[1]}] ++ ;
            
        }

        for( const auto & [a,b] : mp )
            ct += ( b* ( b- 1 )) /2 ;
        
        return ct ;

        // int ct = 0;
        // vector <bool >  pos( n , false );
        // for( int i = 0 ;i <   n - 1; i ++ ){
        //     int p = dom [i][0] , q = dom [i][1];
        //     int z =  1;
        //     pos[ i] = true ;
        //     for( int   j =  i + 1 ; j< n ;  j ++ ) {
        //         if( pos[j]) continue;
        //         if(( p == dom[j][0] && q == dom[j][1] ) || ( p == dom[j][1] && q == dom[j][0] ) ){
        //             z  ++;
        //             pos[j] = true;
        //             }
        //     }
        //     cout<<z<<endl;
        //     ct += ( z * ( z - 1)) / 2;
        // }
        // return ct;
    }
};
