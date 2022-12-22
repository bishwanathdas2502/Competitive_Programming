int ans = 0LL;
rep(i,0,k){
  int dx,dy;cin>>dx>>dy;
  //if certain cof is satisfied increse till we can and half the coef and repeat
  for(int cof = 1100000000;cof;cof/=2){
    while(onField(xc + cof*dx,yc + cof*dy)){
      xc = xc + cof*dx;
      yc = yc + cof*dy;
      ans += cof;
    }
  }
}
