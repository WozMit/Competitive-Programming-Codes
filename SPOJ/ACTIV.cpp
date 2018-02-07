    /* Using principle of Inclusion - Exclusion 
       Recusive Hint 
        rec( set<int> s , int index )
         if index >= n 
            return 1 ;
         if( interval.at(index) overlaps any.interval.in.s)
           return 0;
         
         return rec(s.insert(interval.at.i) , index + 1)  + rec(s,index + 1 )   */
      
    #include <bits/stdc++.h>
    using namespace std;
    int n ;
    #define MAX 100003
    #define MOD 100000000
    vector<pair<int,int> >arr ( MAX );
    vector<int>::iterator it;
    int dp[MAX][2] ;
    using namespace std;
    void solve ()
    {
       memset(dp, 0 , sizeof(dp[0][0]) * MAX * 2);
        //  creating a dp using a recursive function described in the notes that is defibne in
        // the notebook where dp[i][state]
       vector<int>entim;
        /* dp[i][0] stores that total combinations in which ith interval is not included
           and dp[i][1] means total number of combinations in which ith interval is included
           so our answer will be dp[n][0]  + dp[n][i];
           we have used the principle of inclusion-  exclusion here  */
       dp[0][1] = 1;
       entim.push_back(arr[0].first);
       for(int  i = 1 ; i< n ; i++)
         {  // If the ith element is not included
            dp[i][0] = dp[i - 1][ 0 ] + dp [ i-1 ][ 1 ] ;
              if( dp[i][0] >= MOD ) dp[i][0] -= MOD;
            // if the ith elements is to be included
            if ( arr[i].second < entim[0] )
                 {
                   dp[i][1] = 1;
                   /*  this is done because intervals are sorted according to the entime therefore
                       ith interval will have maximum endtime in entim vector therefore
                       if start time is less than the least finish time and its endtime is greater than
                       all the intervals in the vector therefore it overlaps with all the intervals
                       and hence its answer will be one because in this case the subset will contain
                       only the interval under consideration.
                    Case One                                      Case Two
               (x1st) ____                                    (X1st) ________
                          ____                                            ______
                         _________ (ith interval)            ________________________ (ith interavl)
                    arr[i].second > x1st                       arr[i].second < x1st
                    */
                    }
             else{
                     it =  upper_bound(entim.begin() , entim.end() , arr[i].second );
                     /* doing the samething again finding the first interval whose
                        endtime is strictly greater start time of this interval
                        so all the intervals from this index to last index will overalapp
                        therefore no subset can contain intervals after this indx containg the
                        given interval */
                     int diff =  it - entim.begin(); --diff; // indexing nthing else
                     dp[ i ][ 1 ] = 1  + dp[diff][ 0 ] + dp[ diff ][ 1 ] ;
                     if(dp[i][1] >= MOD)
                        dp[i][1] -= MOD;
                 }
             entim.push_back( arr[i].first );
         }
       printf("%0.8d\n", (dp[ n-1 ][ 0 ] + dp[ n-1 ][  1 ])%MOD );
    }
    int main()
    {  cin.tie(0);
      while(true)
       {
           n ;
          cin>>n;
          if(n==-1)
           break;
         for(int i=0 ;i < n; i ++)
          {
            cin>>arr[i].second ;//  start time ;
            cin>>arr[i].first ;  //  end time
          }
         sort(arr.begin(), arr.begin() + n ); //  sorting according to the end points;
        /* general Procedure ::
            1) First we sorted all the points according to their end points
               so all lines are of form
                (x1s) ______ (x1e)
                    (x2s) _____(x2e)
                                  (x3s)_______(x3e) */
         solve();
       }
    }