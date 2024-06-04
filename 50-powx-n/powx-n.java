class Solution {
    public double myPow(double x, int N) {
        long n = N;
        if(n==0){
            return 1;
        }
      double ans;
       if(n<0){
        ans=pow_p(1/x,-n,1/x);
       }
       else{
        ans=pow_p(x,n,x);
       }
      return ans;
    }
    public double pow_p(double x,long n,double initial_x){
        if(n==1){
            return x;
        }
         double a= pow_p(x,n/2,initial_x);
        if(n%2==0)
       {
        
         return a*a;
         }
         else{
           return a*a*x;
         }
    }
   
}