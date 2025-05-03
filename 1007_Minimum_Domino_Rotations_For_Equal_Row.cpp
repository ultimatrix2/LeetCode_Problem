class Solution {
    int check ( int val ,vector<int>& tops, vector<int>& bottoms ) 
    {
        int n = tops.size();
        int t1 = 0 , t2 =0 ;
        // bool f1 = true , f2 = true ;

        for( int i =   0 ; i < n ; i ++ ){
            if (val != tops[i] && val != bottoms[i ] ) return -1;
            if( tops[i] != val ){
                if(val == bottoms[i]  ) t1 ++;
                
            }
            if( bottoms[i] != val ){
                if(val == tops[i]  ) t2 ++;
                
            }
        }
        return min ( t1 ,t2);
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
         int a = tops[0] ;
        int b = bottoms[0] ;
        
        int val = check ( a, tops, bottoms );
        if ( val != -1 ) return val ;
        return  check ( b, tops, bottoms );
   
    }
};
