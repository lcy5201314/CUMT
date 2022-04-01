////#include <iostream>
//#include <bits/stdc++.h>
////#include <string>
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */

//#include<bits/stdc++.h>
//using namespace std;
//
//string path;
//vector<string> result;
//vector<int> used;
//
//void backtrack(string &s,int index){
//	if(path.size() == s.size()) {
//		result.push_back(path);
//		return;
//	}
//	for(int i=0;i < s.size();i++){
//		if(used[i] == 1)
//			continue;
//		used[i] = 1;
//		path.push_back(s[i]);
//		backtrack(s,i+1);
//		path.pop_back();
//		used[i] = 0;
//	}
//}
//
//
//int main() {
//	string str;
//	cin >> str;
//	str.pop_back();
//	used.resize(str.size(),0);
//	sort(str.begin(),str.end());
//	backtrack(str,0);
//	for(int i=0;i < result.size();i++){
//		cout << result[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}



//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//  
//using namespace std;
//  
//int main()
//{
//    string s;
//    char s1[20];
//    cin.getline(s1,20,',');
//    s = s1;
//    sort(s.begin(), s.end());
//    vector<string> ans;
//    do ans.push_back(s);
//    while (next_permutation(s.begin(), s.end()));
//    for (auto i = 0; i < ans.size(); i++)
//    {
//        cout << ans[i] << " ";
//    }
//    system("pause");
//    return 0;
//}





//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main(){
//	string str1,str2;
//	cin >> str1 >> str2;
//	int m = str1.size();
//	int n = str2.size();
//	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			if(str1[i-1] == str2[j-1]){
//				dp[i][j] = dp[i-1][j-1]+1;
//			}
//			else{
//				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//			}
//		}
//	}
//	cout <<dp[m][n] << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	int curindex = 0;
//	int nextindex = 0;
//	int ans = 0;
//	for(int i=0;i<nums.size()-1 ;i++){
//		nextindex = max(nextindex,i+nums[i]);
//		if(i == curindex){
//			curindex = nextindex;
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	
//	
//	system("pause");
//	return 0;
//	
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//
//
//bool cmp(vector<int> a, vector<int> b){
//	return 1.0*(a[1])/a[0] > 1.0*(b[1])/b[0] ;
//}
//
//int main(){
//	int m ,n;
//	while(cin >> m >> n){
//		if(m == 0 && n == 0) 
//			break;
//		vector<vector<int>> homework(m,vector<int>(2, 0));
//		for(int i=0;i<m;i++){
//			cin >> homework[i][0] >> homework[i][1];
//		}
//		sort(homework.begin(),homework.end(),cmp);
//			double ans = 0;
//			for(int i=0;i< m;i++){
//				if(n > homework[i][0]){
//					ans += homework[i][1];
//					n -= homework[i][0];
//				}
//				else{
//					ans += n*1.0*(homework[i][1])/homework[i][0];
//					break;
//				}
//			}
//			printf("%.2lf\n",ans);
//		
//	}
//	return 0;	
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	int result = -999999;
//	int sum = 0;
//	for(int i=0;i<n;i++){
//		sum += nums[i];
//		if(sum > result){
//			result = sum;
//		}
//		if(sum < 0){
//			sum = 0;
//		}
//	}
//	cout << result << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int sum[3] = {0,0,0};
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//		sum[nums[i]-1]++;
//	}
//	int x=0,y=0,z=0;
//	for(int i=0;i<sum[0];i++){
//		if(nums[i] != 1){
//			x++;
//		}
//	}
//	for(int i=sum[0];i<sum[0]+sum[1];i++){
//		if(nums[i] == 3){
//			y++;
//		}
//	}
//	for(int i=sum[0]+sum[1];i<sum[0]+sum[1]+sum[2];i++){
//		if(nums[i] == 2){
//			z++;
//		}
//	}
//	cout << x+max(y,z) << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(vector<int> a, vector<int> b){
//	if(a[0] == b[0]){
//		return a[1] < b[1];
//	}
//	return a[0] < b[0];
//}
//
//
//int main(){
//	int n;
//	cin >> n;
//	vector<vector<int>> point(n,vector<int>(2,0));
//	for(int i=0;i<n;i++){
//		cin >> point[i][0] >> point[i][1];
//	}
//	sort(point.begin(),point.end(),cmp);
//	int start = point[0][0];
//	int end = point[0][1];
//	int maxx = 0;
//	int minn = 0;
//	for(int i=0;i< n-1;i++){
//		if(end >= point[i+1][0]){
//			end = max(point[i+1][1],end);
//		}
//		else{
//			maxx = max(maxx,end - start);
//			start = point[i+1][0];
//			minn = max(minn,start - end);
//			end = point[i+1][1];
//		}
//	}
//	cout << maxx << " " << minn <<endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<string> str(n," ");
//	for(int i=0;i<n;i++){
//		cin >> str[i];
//	}
//	sort(str.begin(),str.end());
//	for(int i=0;i<n;i++){
//		cout << str[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int num;
//	cin >> num;
//	vector<int> nums;
//	while(num){
//		nums.push_back(num%8);
//		num /= 8;
//	}
//	for(int i=nums.size()-1;i>=0;i--){
//		cout << nums[i];
//	}
//	cout << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	vector<int> nums(20,0);
//	for(int i=0;i<20;i++){
//		cin >> nums[i];
//	}
//	for(int i=0;i<20;i++){
//		bool flag = false;
//		for(int j=0;j<20;j++){
//			if(i == j){
//				continue;
//			}
//			if((nums[i] % nums[j]) == 0){
//				flag = true;
//			}
//		}
//		if(flag){
//			cout << nums[i] <<endl;
//		}
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(vector<int> a,vector<int> b){
//	return a[1] < b[1];
//}
//
//int main(){
//	int m ,n;
//	while(cin >> n >> m){
//		vector<vector<int>> nums(n,vector<int>(2,0));
//		for(int i=0;i<n;i++){
//			cin >> nums[i][0] >> nums[i][1];
//		}
//		sort(nums.begin(),nums.end(),cmp);
//		while(m--){
//			int start,end;
//			int l,r;
//			cin >> l >> r;
//			//scanf("%d%d",&start,&end);
//			start = l;
//			end = l;
//			int ans = 0;
//			for(int i=0;i<n;i++){
//				if(r < nums[i][1]){
//					break;
//				}
//				if(end <= nums[i][0]){
//					ans++;
//					start = nums[i][0];
//					end = nums[i][1];
//				}
//				
//			}
//			//cout << ans <<endl;
//			printf("%d\n",ans);		
//		}
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//long long nums[30000];
//long long mod = 1e8+7;
//
//long long quick_pow(long long x,long long n){
//	long long res = 1;
//	while(n > 0){
//		if(n & 1)	
//			res = res * x % mod;
//		x = x * x % mod;
//		n = n / 2;
//	}
//	return res;
//}
//
//void solve(int n){
//	nums[0] = 0;
//	for(int i=1;i<=n;i++){
//		nums[i] = quick_pow(i,i);
//	}
//}
//
//
//int main(){
//	int n;
//	while(cin >> n){
//		long long result = 1;
//		solve(n);
//		for(int i=0;i<=n;i++){
//			result = (result + nums[i]) % mod;
//		}
////		result = accumulate(nums,nums+n+1,1);
//		cout << result <<endl;
//		
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int point(vector<int> nums,int l,int r){
////	int l = 1,r = nums.size()-1;
//	int p = nums[0];
//	while(l <= r){
//		if(nums[l] <= p){
//			l++;
//		}
//		if(nums[r] > p){
//			r--;
//		}
//		swap(nums[r],nums[l]);
//	}
//	swap(nums[0],nums[min(r,l)]);
//	return min(r,l);
//}
//
//
//int findk(vector<int> nums,int k,int l,int r){
//	int ans = 0;
//	int n = point(nums,l,r);
//	if(n+1 == k)
//		return nums[n];
//	if(n+1 < k){
//		ans = findk(nums,k,l,n);
//	}
//	else{
//		ans = findk(nums,k,n,r);
//	}
//	return ans;
//}
//
//vector<int> getLeastNumbers(vector<int>& arr, int k) {
//        vector<int> vec(k, 0);
//        if (k == 0) { // 排除 0 的情况
//            return vec;
//        }
//        priority_queue<int> Q;
//        for (int i = 0; i < k; ++i) {
//            Q.push(arr[i]);
//        }
//        for (int i = k; i < (int)arr.size(); ++i) {
//            if (Q.top() > arr[i]) {
//                Q.pop();
//                Q.push(arr[i]);
//            }
//        }
//        for (int i = 0; i < k; ++i) {
//            vec[i] = Q.top();
//            Q.pop();
//        }
//        return vec;
//}
//
//
//
//
//
//
//int main(){
//	int n,k;
//	cin >> n >> k;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	//sort(nums.begin(),nums.end());
//	vector<int> ans = getLeastNumbers(nums,k);
//	cout << (*max_element(ans.begin(),ans.end())) <<endl;
//	return 0;
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//
//int a[1000001];
//  
//int partition(int a[],int p,int r)
//{
//    int x=a[r];
//    int middle=p;
//    int j;
//    for(j=p;j<r;j++)
//    {
//        if(a[j]<x)
//        {
//            if(j!=middle)
//              swap(a[middle],a[j]);
//            middle++;
//        } 
//    }
//    swap(a[middle],a[j]);
//    return middle;
//}
//  
//void select(int a[],int p,int r)
//{
//    if(p<r)
//    {
//        int q=partition(a,p,r);
//        select(a,p,q-1);
//        select(a,q+1,r);    
//    }
//}
//  
//int main()
//{
//    int n,k;
//    cin>>n>>k;
//    for(int i=0;i<n;i++)
//        scanf("%d",&a[i]);
//    select(a,0,n-1);
//    cout<<a[k-1]<<endl;
//    return 0;   
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//
//int nums[1000001];
//
//int point(int nums[],int left,int right){
//	int mid = left;
//	int pointt = nums[right];
//	for(int i=left;i<right;i++){
//		if(nums[i] < pointt){
//			if(i != mid){
//				swap(nums[i],nums[mid]);
//			}
//			mid++;
//		}
//	}
//	swap(nums[mid],nums[right]);
//	return mid;
//}
//
//void select(int nums[],int left,int right){
//	if(left < right){
//		int mid = point(nums,left,right);
//		select(nums,left,mid-1);
//		select(nums,mid+1,right);
//	}
//}
//
//int main(){
//	int n,k;
//	cin >> n >> k;
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	select(nums,0,n-1);
//	for(int i=n-1;i>n-k-1;i--){
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(8,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	vector<int> dp(n,1);
//	int result = 0; 
//	for(int i=0;i< n;i++){
//		for(int j=0;j<i;j++){
//			if(nums[i] < nums[j])
//				dp[i] = max(dp[i], dp[j]+1);
//			if(dp[i] > result){
//				result = dp[i];
//			}
//		}
//		
//	}
//	cout << result << endl;	
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//string path;
//vector<string> result;
//vector<int> used;
//
//void backtrack(string str){
//	if(path.size() == str.size()){
//		result.push_back(path);
//		return;
//	}
//	for(int i=0;i<str.size();i++){
//		if(used[i]){
//			continue;
//		}
//		used[i] = 1;
//		path.push_back(str[i]);
//		backtrack(str);
//		path.pop_back();
//		used[i] = 0;
//	}
//}
//
//int main(){
//	string str;
//	cin >> str;
//	str.pop_back();
//	sort(str.begin(),str.end());
//	used.resize(str.size(),0);
//	backtrack(str);
//	for(auto s : result){
//		cout << s << " ";
//	}
//	cout << endl;
//	return 0;
//}
//



//#include <bits/stdc++.h>
//using namespace std;
//
//const long long mod = 100000007;
//
//long long mypow(long long n,long long m){
//	long long ans = 1;
//	while(m){
//		if(m & 1){
//			ans = ans * n % mod;
//		}
//		m = m >> 1;
//		n = (n * n) % mod;
//	}
//	return ans;
//}
//
//
//int main(){
//	int n;
//	while(cin >> n){
//		long long ans = 0;
//		for(int i=1;i<=n;i++){
//			ans = (ans + mypow(i,i)) % mod;
//		}
//		cout << ans+1 << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int compare (const void * a, const void * b)
//{
//  return ( *(int*)a - *(int*)b );
//}
//int nums[1000011];
//int main(){
//	int n,k;
//	cin >> n >> k;
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	//sort(nums.begin(),nums.end());
//	qsort(nums,n,sizeof(int),compare);
//	cout << nums[k-1] << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int mypartition(vector<int> nums,int left,int right){
//	int mid = left;
//	int pointt = nums[right];
//	for(int i=left;i<right;i++){
//		if(nums[i] > pointt){
//			if(i != mid){
//				swap(nums[i],nums[mid]);
//			}
//			mid++;
//		}
//	}
//	swap(nums[mid],nums[right]);
//	return mid;
//	
//	
//}
//
//void mysort(vector<int> nums,int left,int right){
//	if(left < right){
//		int p = mypartition(nums,left,right);
//		mysort(nums,left,p-1);
//		mysort(nums,p+1,right);	
//	}
//}
//
//int main(){
//	int n,k;
//	cin >> n >> k;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	mysort(nums,0,n-1);
//	cout << nums[k-1] << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int nums[1000001];
//
//int point(int nums[],int left,int right){
//	int mid = left;
//	int pointt = nums[right];
//	for(int i=left;i<right;i++){
//		if(nums[i] < pointt){
//			if(i != mid){
//				swap(nums[i],nums[mid]);
//			}
//			mid++;
//		}
//	}
//	swap(nums[mid],nums[right]);
//	return mid;
//}
//
//void select(int nums[],int left,int right){
//	if(left < right){
//		int mid = point(nums,left,right);
//		select(nums,left,mid-1);
//		select(nums,mid+1,right);
//	}
//}
//
//int main(){
//	int n,k;
//	cin >> n >> k;
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	select(nums,0,n-1);
//	cout << nums[k-1] << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	while((cin >> n) && n){
//		vector<int> cf(n+1,0);
//		for(int i=0;i<= n;i++){
//			cin >> cf[i];
//		}
//		double min, max, ans, mid;
//		min = -1.0;
//        max = 1000000;
//        while(max - min > 1e-6){
//			ans = cf[0];
//            mid = (max-min) / 2 + min;
//            for(int i=1;i<=n;i++){
//				ans += cf[i] / pow(1 + mid, i);
//			}
//            if(ans > 0)
//            	min = mid;
//            else
//            	max = mid;
//		}
//		printf("%.2lf\n",mid);
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//const long long mod = 1000000007;
//int main(){
//	int n;
//	while(cin >> n){
//		if(n <= 1){
//			cout << n << endl;
//			continue;
//		}
//		vector<long long> dp(n+1,0);
//		dp[0] = 1;
//		dp[1] = 1;
//		for(int i=2;i<=n;i++){
//			dp[i] = (dp[i-1] + dp[i-2]) % mod;
//		}
//		cout << dp[n] << endl;
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//const long long mod = 1000000007;
//
//int main(){
//	int n;
//	while(cin >> n){
//		if(n <= 1){
//			cout << n << endl;
//			continue;
//		}
//		int dp[3];
//		dp[0] = 1;
//		dp[1] = 1;
//		for(int i=2;i<=n;i++){
//			dp[2] = (dp[0] + dp[1]) % mod;
//			dp[0] = dp[1];
//			dp[1] = dp[2];
//		}
//		cout << dp[2] << endl;
//	}
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<=0;i++){
//		cin >> nums[i];
//	}
//	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
//	for(int i=0;i<=n;i++){
//		dp[i][i] = 0;
//	}
//	for(int i=n;i<=0;i++){
//		for(int j=i;j<=n;j++){
//			 
//		}
//	}
//	cout << dp[0][n] << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string str1,str2;
//	cin >> str1 >> str2;
//	int m = str1.size();
//	int n = str2.size();
//	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			if(str1[i-1] == str2[j-1]){
//				dp[i][j] = dp[i-1][j-1] + 1;
//			}
//			else{
//				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//			}
//		}
//	}
//	cout << dp[m][n] << endl;
//	return 0;
//}




//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<vector<int>> mp(n,vector<int>(n,-1));
//	for(int i=0;i<n;i++){
//		for(int j=0;j<=i;j++){
//			cin >> mp[i][j];
//		}
//	}
//	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//	for(int i=n-1;i>=0;i--){
//		for(int j=0;j<=i;j++){
//			if(i == n-1){
//				dp[i][j] = mp[i][j];
//			}
//			else{
//				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + mp[i][j];
//			}
//		}
//	}
//	cout << dp[0][0] << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int a[1000000];
//
//int main(){
//	int n,k;
//	cin>>n>>k;
//	for(int i=0;i<n;i++){
//		cin >> a[i];
//	}
//	sort(a,a+n);
//	cout << a[k-1] << endl;
//	return 0;
//}



//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	int curDistance = 0;    // 当前覆盖的最远距离下标
//	int ans = 0;            // 记录走的最大步数
//	int nextDistance = 0;   // 下一步覆盖的最远距离下标
//	for(int i=0;i<n-1;i++){
//		nextDistance = max(nums[i]+i,nextDistance);
//		if(i == curDistance){
//			curDistance = nextDistance;
//			ans++;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string str;
//	cin >> str;
//	unordered_map<char,int> map;
//	for(int i=0;i<str.size();i++){
//		map[str[i]] = i;
//	}
//	while(cin >> str){
//		//里面就是最简单最大子序列
//		//这里初始化为1
//		vector<int> dp(str.size(),1);
//		int ans = 0;
//		for(int i=0;i<str.size();i++){
//			for(int j=0;j<i;j++){
//				if(map[str[i]] >= map[str[j]]){
//					dp[i] = max(dp[i],dp[j]+1);
//				}
//				if(ans < dp[i]){
//					ans = dp[i];
//				}
//			}
//		}
//		cout << ans;
//	}
//	cout << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	vector<int> sum(n+1,0);
//	vector<vector<int>> dp(n,vector<int>(n,0));
//	//先输入数组
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	//初始化sum，方便求i,j之间的代价
//	for(int i=0;i<n;i++){
//		sum[i+1] = sum[i] + nums[i];
//	}
//	//这是是遍历长度，2开始，1为0；
//	for(int len = 2;len<=n;len++){
//		//这里初始化i，j,这里要右端点小于n，防止越界，斜方向遍历
//		for(int i=0;i+len-1 < n;i++){
//			int j = i+len-1;
//			dp[i][j] = INT_MAX;
//			for(int k=i;k<j;k++){
//				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j+1]-sum[i]);
//			}
//		}
//	}
//	cout << dp[0][n-1] <<endl;
//	return 0;
//}
//
//
//

//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(vector<double>a,vector<double> b){
//	return a[2] > b[2];
//}
//
//int main(){
//	int m,n;
//	while(cin >> m >> n){
//		if(m == 0 && n ==0){
//			break;
//		}
//		vector<vector<double>> homework(m,vector<double>(3,0));
//		for(int i=0;i<m;i++){
//			cin >> homework[i][0] >> homework[i][1];
//			homework[i][2] = homework[i][1] / homework[i][0];
//		}
//		sort(homework.begin(),homework.end(),cmp);
//		double ans = 0; 
//		for(int i=0;i<n;i++){
//			if(n > homework[i][0]){
//				ans += homework[i][1];
//				n -= homework[i][0];
//			}
//			else{
//				ans += homework[i][2] * n;
//				break;
//			}
//		}
//		printf("%.2lf\n",ans);
//		
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(vector<int> a, vector<int> b){
//	return a[1] < b[1];
//}
//
//int main(){
//	int n, m;
//	while(cin >> n >> m){
//		vector<vector<int>> point(n,vector<int>(2,0));
//		for(int i=0;i<n;i++){
//			cin >> point[i][0] >> point[i][1];
//		}
//		sort(point.begin(),point.end(),cmp);
//		while(m--){
//			int left,right;
//			cin >> left >> right;
//			int ans = 0;
//			for(int i=0;i<n;i++){
//				if(point[i][1] > right){
//					break;
//				}
//				if(left <= point[i][0]){
//					left = point[i][1];
//					ans++;
//				}
//			}
//			cout << ans << endl;
//		}
//	}
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	int sum = 0;
//	int ans = INT_MIN;
//	for(int i=0;i<n;i++){
//		sum += nums[i];
//		if(sum > ans){
//			ans = sum;
//		}
//		if(sum < 0){
//			sum = 0;
//		}
//	}
//	cout << ans << endl;
//	return 0;
//}




//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	int sum[4] = {0,0,0,0};
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//		sum[nums[i]]++;
//	}
//	int x = 0,y = 0,z=0;
//	for(int i=0;i<sum[1];i++){
//		if(nums[i] != 1){
//			x++;
//		}
//	}
//	for(int i=sum[1];i<sum[1]+sum[2];i++){
//		if(nums[i] == 3){
//			y++;
//		}
//	}
//	for(int i=sum[1]+sum[2];i<n;i++){
//		if(nums[i] == 2){
//			z++;
//		}
//	}
//	cout << x + max(y,z) << endl;
//	return 0;
//}




//#include <bits/stdc++.h>
//using namespace std;
//
//bool cmp(vector<int> a, vector<int> b){
//	if(a[0] == b[0])
//		return a[1] < b[1];
//	return a[0] < b[0];
//}
//
//int main(){
//	int n;
//	cin >> n;
//	vector<vector<int>> point(n,vector<int>(2,0));
//	for(int i=0;i<n;i++){
//		cin >> point[i][0] >> point[i][1];
//	}
//	sort(point.begin(),point.end(),cmp);
//	int maxx = 0;
//	int minn = 0;
//	int start,end;
//	start = point[0][0];
//	end = point[0][1];
//	for(int i=1;i<n;i++){
//		if(point[i][0] <= end){
//			end =max(point[i][1],end);
//			maxx = max(maxx,end - start);
//		}
//		else{
//			start = point[i][0];
//			minn = max(minn,start - end);
//			end = point[i][1];
//		}
//	}
//	cout << maxx << " " << minn << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> num;
//	while(n){
//		num.push_back(n%8);
//		n /= 8;
//	}
//	for(int i=num.size()-1;i>=0;i--){
//		cout << num[i];
//	}
//	cout << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//vector<string> result;
//string path;
//vector<int> used;
//
//void backtrack(string str){
//	if(path.size() == str.size()){
//		result.push_back(path);
//		return;
//	}
//	for(int i=0;i<str.size();i++){
//		if(used[i] == 1){
//			continue;
//		}
//		used[i] = 1;
//		path.push_back(str[i]);
//		backtrack(str);
//		path.pop_back();
//		used[i] = 0;
//	}
//	
//}
//
//int main(){
//	string str;
//	cin >> str;
//	str.pop_back();
//	sort(str.begin(),str.end());
//	used.resize(str.size(),0);
//	backtrack(str);
//	for(int i=0;i < result.size();i++){
//		cout << result[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//const long long mod = 100000007;
//
//long long mypow(long long x,long long m){
//	long long ans = 1;
//	while(m){
//		if(m & 1){
//			ans = (ans * x) % mod;
//		}
//		m >>= 1;
//		x = (x * x) %mod;
//	}
//	return ans;
//}
//
//int main(){
//	int n;
//	while(cin >> n){
//		long long ans = 1;
//		for(int i=1;i<=n;i++){
//			ans =(ans + mypow(i,i)) % mod;
//		}
//		cout << ans <<endl;
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int nums[1000002];
//
//int main(){
//	int n,k;
//	cin >> n >> k;
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	sort(nums,nums+n);
//	cout << nums[k-1] << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	vector<int> sum(n+1,0);
//	for(int i=0;i<n;i++){
//		sum[i+1] = sum[i] + nums[i]; 
//	}
//	vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
//	for(int i=0;i<n;i++){
//		dp[i][i] = 0;
//	}
//	for(int len=2;len<=n;len++){
//		for(int i=0;i + len -1 < n;i++){
//			int j = i + len -1;
//			for(int k=i;k<j;k++){
//				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j] + sum[j+1]-sum[i]);
//			}
//		}
//	}
//	cout << dp[0][n-1] << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string str1,str2;
//	cin >> str1 >> str2;
//	int m = str1.size();
//	int n = str2.size();
//	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=n;j++){
//			if(str1[i-1] == str2[j-1]){
//				dp[i][j] = dp[i-1][j-1] + 1;
//			}
//			else{
//				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
//			}
//		}
//	}
//	cout << dp[m][n] << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int nums[1000001];
//
//bool cmp(int a,int b){
//	return a > b;
//}
//
//int main(){
//	int n,m;
//	cin >> n >> m;
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	sort(nums,nums+n,cmp);
//	for(int i=0;i<m;i++){
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//
//int nums[1000001];
//
//
//int main(){
//	int n,m;
//	cin >> n >> m;
//	map<int,int> mp;
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//		if(mp.find(nums[i]) != mp.end()){
//			mp[nums[i]]++;
//		}
//		mp.insert(pair<int,int>(nums[i],1));
//	}
//	int i = 0;
//	for(auto num : mp){
//		while(num.second){
//			nums[i] = num.first;
//			num.second--;
//			i++;
//		}
//	}
//	for(int i=n-1;i>n-m-1;i--){
//		cout << nums[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//const int offset = 500000;
//int Hash[1000001] = {0};
//int main(){
//	int m,n;
//	while(cin >> n >> m){
//		for(int i=0;i<n;i++){
//			int x;
//			cin >> x;
//			Hash[x+offset]++;
//		}
//		for(int i=offset;i>=-offset && m > 0;i--){
//			while(Hash[i+offset] > 0 && m > 0){
//				cout << i << " ";
//				Hash[i+offset]--;
//				m--;
//			}
//		}
//		cout << endl;
//	}
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//bool check(int m,int k){
//	int res = 0;
//	for(int i=1;i<=k;i++){
//		res = (res + m -1) % (2*k-i+1);
//		if(res < k){
//			return false;
//		}
//	}
//	return true;
//}
//
//int main(){
//	int k;
//	while((cin >> k) && k){
//		for(int i=k+1;;i++){
//			if(check(i,k) == true){
//				cout << i << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}


//
//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	while((cin >> n) && n){
//		
//	}
//	
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<string> strs;
//	for(int i=0;i<n;i++){
//		string str;
//		cin >> str;
//		strs.push_back(str);
//	}
//	sort(strs.begin(),strs.end());
//	for(int i=0;i<n;i++){
//		cout << strs[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	vector<int> dp(n,1);
//	int result = 0;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<i;j++){
//			if(nums[i] < nums[j]){
//				dp[i] = max(dp[i], dp[j]+1);
//			}
//			if(dp[i] > result){
//				result = dp[i];
//			}
//		}
//	}
//	vector<int> ans;
//	for(int i=n-1;i>=0;i--){
//		if(dp[i] == result){
//			ans.push_back(nums[i]);
//			result--;
//		}
//	}
//	for(int i=ans.size()-1;i>=0;i--){
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
// 
//int main(){
//    vector<int> nums(20,0);
//    for(int i=0;i<20;i++){
//        cin >> nums[i];
//    }
//    for(int i=0;i<20;i++){
//        bool flag = false;
//        for(int j=0;j<20;j++){
//            if(i == j){
//                continue;
//            }
//            if((nums[i] % nums[j]) == 0){
//                flag = true;
//            }
//        }
//        if(flag){
//            cout << nums[i] <<endl;
//        }
//    }
//    return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	vector<int> nums(n,0);
//	for(int i=0;i<n;i++){
//		cin >> nums[i];
//	}
//	vector<int> dp(n,1);
//	vector<int> track(n,-1);
//	int result = 0;
//	int rp = -1;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<i;j++){
//			if((nums[i] < nums[j]) && dp[j]+1 > dp[i]){
//				dp[i] = dp[j] + 1;
//				track[i] = j;
//			}
//			if(dp[i] > result){
//				result = dp[i];
//				rp = i;
//			}
//		}
//	}
//	vector<int> ans;
//	for(int i=result;i>0;i--){
//		ans.push_back(nums[rp]);
//		if(track[rp] == -1)
//			break;
//		rp = track[rp];
//	}
//	for(int i=ans.size()-1;i>=0;i--){
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//struct node{
//	int x;
//	int y;
//	int n;
//};
//
//bool cmp(node a,node b)
//{
//    return a.n<b.n;
//}
//
////node nums[100005];
//
//int main(){
//	int m,n;
//	cin >> m >> n;
//	vector<node> nums(m*n);
//	int index = 0;
//	for(int i=0;i<m;i++){
//		for(int j=0;j<n;j++){
//			cin >> nums[index].n;
//			nums[index].x = i;
//			nums[index].y = j;
//			index++;
//		}
//	}
//	sort(nums.begin(),nums.end(),cmp);
//	//大型的最长递减子序列
//	int result = 0;
//	vector<int> dp(index,1);
//	for(int i=0;i<index;i++){
//		for(int j=0;j<i;j++){
//			//这里判断条件改成前后左右
//			if(((nums[i].x==nums[j].x && abs(nums[i].y-nums[j].y)==1) || (nums[i].y==nums[j].y && abs(nums[i].x-nums[j].x)==1)) && nums[i].n > nums[j].n){
//				dp[i] = max(dp[i],dp[j]+1);
//			}
//			if(dp[i] > result){
//				result = dp[i];
//			}
//
//		}
//	}
//	cout << result << endl;
//	return 0;
//}
 
 
//#include<bits/stdc++.h>
//using namespace std;
//
//int r,c;
//int result = 0;
//vector<vector<int>> mp;
//vector<vector<int>> dp;
//
//bool inmap(int x,int y){
//     return x>=0&&x<r&&y>=0&&y<c;
//}
//int dfs(int x,int y){
//	if(dp[x][y] != -1){
//		return dp[x][y];
//	}
//	int ans = 1;
//	for(int dx=-1;dx<=1;dx++) {
//	    for(int dy=-1;dy<=1;dy++) {
//	        if(dx!=dy&&dx+dy!=0&&(dx!=0||dy!=0))
//	        	if(inmap(x+dx,y+dy)&&mp[x][y]>mp[x+dx][y+dy])
//	                ans = max(ans,dfs(x+dx,y+dy)+1);
//		}
//	}
//	return ans;
//}
//
//int main(){
// 	cin >> r >> c;
// 	mp.resize(r,vector<int>(c,0));
// 	dp.resize(r,vector<int>(c,-1));
// 	for(int i=0;i<r;i++){
//	 	for(int j=0;j<c;j++){
//		 	cin >> mp[i][j];
//		 }
//	}
//	for(int i=r;i<r;i++){
//	 	for(int j=0;j<c;j++){
//		 	result = max(result,dfs(i,j));
//		 }
//	}
//	cout << result << endl;
// 	return 0;
// }


//#include<bits/stdc++.h>
//using namespace std;
//
//struct node{
//	int x,y,h;
//};
//
//bool cmp(node a,node b){
//	return a.h < b.h;
//}
//
//node nums[999999];
//
//
//int main(){
//	int r,c;
//	cin >> r >> c;
//	int n = 0;
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			cin >> nums[n].h;
//			nums[n].x = i;
//			nums[n].y = j;
//			n++;
// 		}
//	}
//	sort(nums,nums+n,cmp);
//	vector<int> dp(n,1);
//	int result = 0;
//	for(int i=0;i<n;i++){
//		for(int j=0;j<i;j++){
//			if((nums[i].h > nums[j].h) && (abs(nums[i].x-nums[j].x) + abs(nums[i].y-nums[j].y)) == 1){
//				dp[i] = max(dp[i],dp[j]+1);
//			}
//			if(dp[i] > result){
//				result = dp[i];
//			}
//		}
//	}
//	cout << result << endl;
//	return 0;
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	while((cin >> n) && n){
//		vector<int> a(n,0);
//		vector<int> b(n,0);
//		for(int i=0;i<n;i++){
//			cin >> a[i];
//		}
//		for(int i=0;i<n;i++){
//			cin >> b[i];
//		}
//		sort(a.begin(),a.end());
//		sort(b.begin(),b.end());
//		int cnt1 =0, cnt2 = 0;
//		int j = 0;
//		for(int i=0;i<n;i++){
//			if(a[i] > b[j]){
//				cnt1++;
//				j++;
//			}
//			else{
//				cnt2++;
//			}
//		}
//		if(cnt1 > cnt2){
//			cout << "YES" << endl;
//		}
//		else{
//			cout << "NO" << endl;
//		}		
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//
//int main(){
//	int t;
//	cin >> t;
//	while(t--){
//		int l,n;
//		cin >> l >> n;
//		vector<int> ants(n,0);
//		for(int i=0;i<n;i++){
//			cin >> ants[i];
//		}
//		int Max = 0, Min = 0;
//		for(int i=0;i<n;i++){
//			Min = max(Min,min(ants[i],l-ants[i]));
//			Max = max(Max,max(ants[i],l-ants[i]));
//		}
//		cout << Min << " " << Max << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int m;
//	while(~scanf("%d",&m)){
//		int flag = 0;
//		long long x;
//		for(int i=0;i<m;i++){
//			cin >> x;
//			flag ^= x;
//		}
//		if(flag) 
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl; 
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	while((cin >> n) && n){
//		double  a = log2(4.0);
//		for (int i = 1960; i <= n; i += 10)
//			a *= 2;
//		double  f = 0;
//		int i = 0;
//		while(f < a)
//		{
//			++i;
//			f += log2(double(i));
//		}
//		cout << i - 1 << endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string str;
//	while(1){
//		cin >> str;
//		if(str == "ENDOFINPUT"){
//			break;
//		}
//		else if(str == "START"){
//			cin >> str;
//			string s;
//			getline(cin,s);
//			s = str + s;
//			string c;
//			for(int i=0;i < s.size();i++){
//				if(s[i] >= 'A' && s[i] <= 'Z'){
//					c.push_back((s[i] - 'A'+26-5)%26 + 'A');
//				}
//				else{
//					c.push_back(s[i]);
//				}
//			}
//			cout << c << endl;
//		}
//		else if(str == "END"){
//			continue;
//		}
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int t;
//	cin >> t;
//	while(t--){
//		string str;
//		cin >> str;
//		long long n;
//		cin >> n;
//		n = n % 26;
//		for(int i=0;i<=str.size();i++){
//			if(str[i] >= 'A' && str[i] <= 'Z'){
//				str[i] = 'A' + (str[i] - 'A' + 26 - n) % 26;
//			}
//			if(str[i] >= 'a' && str[i] <= 'z'){
//				str[i] = 'a' + (str[i] - 'a' + 26 - n) % 26;
//			}
//		}
//		cout << str << endl;
//	}
//}



//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string strc,strm,strk;
//	cin >> strk >> strm;
//	for(int i=0;i<strk.size();i++){
//		if(strk[i] >= 'A' && strk[i] <= 'Z'){
//			strk[i] = 'a' + strk[i] - 'A';
//		}
//	}
//	for(int i=0;i<=strm.size();i++){
//		if(strm[i] >= 'A' && strm[i] <= 'Z'){
//			strm[i] = 'A' + (strm[i] - 'A' - (strk[i % strk.size()] - 'a')+26) % 26;
//		}
//		if(strm[i] >= 'a' && strm[i] <= 'z'){
//			strm[i] = 'a' + (strm[i] - 'a' - (strk[i % strk.size()] - 'a')+26) % 26;
//		}
//	}
//	cout << strm << endl;
//	return 0;
//}

//#include<bits/stdc++.h>
//using namespace std;
//
//
//void Print(string str,vector<vector<int>> mark,int l,int r)//输出递归函数
//{
//    if(l>r)
//        return;
//    if(l==r)
//    {
//        if(str[l-1]=='['||str[l-1]==']')
//            printf("[]");
//        else
//            printf("()");
//        return;
//    }
//    if(!mark[l][r])
//    {
//        printf("%c",str[l-1]);
//        Print(str,mark,l+1,r-1);
//        printf("%c",str[r-1]);
//    }
//    else
//    {
//        Print(str,mark,l,mark[l][r]);
//        Print(str,mark,mark[l][r]+1,r);
//    }
//}
//
//
//int main(){
//	string str;
//	cin >> str;
//	int n =str.size();
//	vector<vector<int>> dp;
//	vector<vector<int>> mark;
//	dp.resize(n,vector<int>(n,0));
//	mark.resize(n,vector<int>(n,0));
//	for(int i=0;i<n;i++){
//		dp[i][i] = 1;
//	}
//	for(int len=2;len<n;len++){
//		for(int i=0;i+len-1<n;i++){
//			int j = i+len-1;
//			if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']'))
//            {
//                dp[i][j]=dp[i+1][j-1];
//                mark[i][j]=0;
//            }
////            else{
////				for(int k=i;k<j;k++){
////					if(dp[i][j]>(dp[i][k]+dp[k+1][j]))
////					{
////					    dp[i][j]=dp[i][k]+dp[k+1][j];
////					    mark[i][j]=k;
////					}
////				}
////			}
//			for(int k=i;k<j;k++){
//				if(dp[i][j]>(dp[i][k]+dp[k+1][j]))
//				{
//				    dp[i][j]=dp[i][k]+dp[k+1][j];
//				    mark[i][j]=k;
//				}
//			}
//		}
//	}
//	Print(str,mark,1,n);
//	cout << endl;
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	int n;
//	cin >> n;
//	unordered_map<int,int> mp;
//	//vector<int> cmpp(n,0);
//	for(int i=1;i<=n;i++){
//		int x = 0;
//		cin >> x;
//		mp[x] = i;
//	}
//	int x = 0;
//	while(cin >> x){
//		vector<int> nums(n,0);
//		nums[0] = x;
//		for(int i=1;i<n;i++){
//			cin >> nums[i];
//		}
//		vector<int> dp(n,1);
//		int result = 0;
//		for(int i=0;i<n;i++){
//			for(int j=0;j<i;j++){
//				if(mp[nums[i]] > mp[nums[j]]){
//					dp[i] = max(dp[i],dp[j]+1);
//				}
//				if(result < dp[i]){
//					result = dp[i];
//				}
//			}
//		}
//		cout << result << endl;
//	}
//	return 0;
//}

//
//#include<bits/stdc++.h>
//using namespace std;
//
//int dollars[12] = {0,10000,5000,2000,1000,500,200,100,50,20,10,5};
//
//int main(){
//	double val;
//	while((cin >> val) && val){
//		int dollar = int(val * 100);
//		vector<long long> dp(dollar+1,0);
//		dp[0] = 1;
//		for(int i=1;i<12;i++){
//			for(long long j=dollars[i];j<=dollar;j++){
//				dp[j] += dp[j-dollars[i]];
//			}
//		}
//		cout<<setiosflags(ios::right)<<setw(6)<<fixed<<setprecision(2)<<val;
//		cout<<setiosflags(ios::right)<<setw(17)<<dp[dollar]<<endl;
//	}
//	return 0;
//}


//#include<bits/stdc++.h>
//using namespace std;
//
//int main(){
//	string str;
//	cin >> str;
//	str.pop_back();
//	sort(str.begin(),str.end());
//	do{
//		cout << str << " ";
//	}while(next_permutation(str.begin(),str.end()));
//	return 0;
//}


#include<bits/stdc++.h>
using namespace std;
