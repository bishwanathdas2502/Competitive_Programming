int dp[11][2][11];
  int f(int index,int tight,int sum,string &s){
      if(index >= s.size()){
          return sum;
      }

      if(dp[index][tight][sum] != -1){
          return dp[index][tight][sum];
      }

      int limit = (tight)?s[index]-'0':9;

      int cnt = 0;

      for(int d = 0;d<=limit;d++){
          int newTight = (tight)&(d == limit);

          if(d == 1){
              cnt += f(index + 1,newTight,sum + 1,s);
          }
          else{
              cnt += f(index+1,newTight,sum,s);
          }
      }


      return dp[index][tight][sum] = cnt;
  }

  int countDigitOne(int n) {

      memset(dp,-1,sizeof(dp));
      string h = to_string(n);

      int cnt = f(0,1,0,h);
      return cnt;
  }
