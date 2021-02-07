#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
void debug(string t,T input){
    cout<<t<<"->"<<input<<"\n";
}
//for loop
template<typename T>
void debug(int i,string t,T input){
    cout<<"Case#"<<i<<" "<<t<<"->"<<input<<"\n";
}

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define rep(i,a,b)      for(int i=a;i<b;i++)
#define rrep(i,a,b)     for(int i=a;i>=b;i--) 
#define all(z)          z.begin(),z.end()  
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

//pbds similar to sets
// two function are order_of_key(num)--> returns index of number after sorting
//*(itr).find_by_order(3) --> return the num after which the number is inserted
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// vector<int> adj[(int)1e6];
// queue<int> q;
// int col[(int)1e6];
// int vis[(int)1e6];
const int N = 1e5 + 5;
const int INF = 1e9;


/*
KEYNOTES:
------------------------------------------
merge(X,identity_element) = X
------------------------------------------
------------------------------------------
identity_transformation.combine(X) = X
------------------------------------------
------------------------------------------
ALWAYS: older_update.combine(newer_update)
------------------------------------------
*/



// example: addition: identity element is 0

// a + 0 = a or 0 + a = a

// min(x,INF) = x

struct my_node
{
	int sum = 0;
	// use more variables if you want more information
	// these default values should be identity_element
	my_node(){}
	my_node(int val){ //store value of leaf of seg tree
		sum = val;
	}
	void merge(const my_node &l,const my_node &r){ // store the thing you wanna query
		
		sum = l.sum + r.sum;
		
		// if we wanted the maximum, then we would do
		// like v = max(l.v,r.v)
	}
};

// example: add on a range: identity transformation = 0
// old += new

// if old is identity which is 0, then 0 + new which new

struct my_update
{
	int v = 0; // 4
	// use more variables if you want more information
	// these default values should be identity_transformation
	my_update(){}
	my_update(int val){
		v = val; // 5
	}
	// combine the current my_update with the other my_update (see keynotes)
    //for range update(lazy)
	void combine(my_update &other,const int32_t &tl,const int32_t &tr){
		 // 6
		
		// you can be sure that the "other" is newer than current
		
	}
	// store the correct information in the my_node x
    //for leaf node of my node
	void apply(my_node &x,const int32_t &tl,const int32_t &tr){
		//7
		x.sum = v;
		
	}
};

template<typename node,typename update>
struct segtree
{
	int len;
	vector<node> t;
	vector<update> u;
	vector<bool> lazy;
	node identity_element;
	update identity_transformation;
	segtree(int l){
		len = l;
		t.resize(4 * len);
		u.resize(4 * len);
		lazy.resize(4 * len);
		identity_element = node();
		identity_transformation = update();
	}
	
	void pushdown(const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(!lazy[v]) return;
		int32_t tm = (tl + tr) >> 1;
		apply(v<<1,tl,tm,u[v]);
		apply(v<<1|1,tm+1,tr,u[v]);
		u[v] = identity_transformation;
		lazy[v] = 0;
	}
	
	void apply(const int32_t &v, const int32_t &tl, const int32_t &tr, update upd){
		if(tl != tr){
			lazy[v] = 1;
			u[v].combine(upd,tl,tr);
		}
		upd.apply(t[v],tl,tr);
	}
	
	template<typename T>
	void build(const T &arr,const int32_t &v, const int32_t &tl, const int32_t &tr){
		if(tl == tr){
			t[v] = arr[tl];
			return;
		}
		int32_t tm = (tl + tr) >> 1;
		build(arr,v<<1,tl,tm);
		build(arr,v<<1|1,tm+1,tr);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	node query(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r){
		if(l > tr || r < tl){
			return identity_element;
		}
		if(tl >= l && tr <= r){
			return t[v];
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		node a = query(v<<1,tl,tm,l,r),b = query(v<<1|1,tm+1,tr,l,r),ans;
		ans.merge(a,b);
		return ans;
	}
	
	// rupd = range update
	void rupd(const int32_t &v,const int32_t &tl,const int32_t &tr,const int32_t &l,const int32_t &r,const update &upd){
		if(l > tr || r < tl){
			return;
		}
		if(tl >= l && tr <= r){
			apply(v,tl,tr,upd);
			return;
		}
		pushdown(v,tl,tr);
		int32_t tm = (tl + tr) >> 1;
		rupd(v<<1,tl,tm,l,r,upd);
		rupd(v<<1|1,tm+1,tr,l,r,upd);
		t[v].merge(t[v<<1],t[v<<1|1]);
	}
	
	public:
	template<typename T>
	void build(const T &arr){
		build(arr,1,0,len-1);
	}
	node query(const int32_t &l,const int32_t &r){
		return query(1,0,len-1,l,r);
	}
	void rupd(const int32_t &l,const int32_t &r,const update &upd){
		rupd(1,0,len-1,l,r,upd);
	}
};


segtree<my_node,my_update> t(N);
int a[N];

void solve(){
    int n,q;
    cin>>n>>q;
    rep(i,0,n){
        cin>>a[i];
    }
    t.build(a);
    rep(j,0,q){
        int type;
        cin>>type;
        if(type == 1){
            int i,v;
            cin>>i>>v;
            t.rupd(i,i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            r--;
            cout<<t.query(l,r).sum<<endl;
        }
    }
}



// int32_t main(){
//     FIO;
//     int t = 1;
//     // cin>>t;
    

//     while(t--){
//         solve();
//     }
    
//     return 0;
// }

// int32_t main(){
	
// 	segtree<my_node,my_update> s(1000); // create a segment tree of length 1000
// 	vector<int> v(1000);
// 	s.build(v);
// 	s.rupd(2,5,4);
// 	s.rupd(1,3,3);
	
// 	for(int i = 0; i < 15; i++){
// 		cout << s.query(i,i).v << " ";
// 	}
	
// 	// cout <<"\n\n" << s.query(2,4).v << " ";
	
// 	return 0;
// }




// how to define the behaviour or the nature of the 
// updates and queries


// this segtree was sum in range and add on range


// let's change it to -> (sum on range) and (set all values on range)



// let's make the one from the question earlier

// get min element and frequency of min element on a range AND add on a range