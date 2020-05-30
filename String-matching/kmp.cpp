

/*
	KMP
*/

#include<bits/stdc++.h>

using namespace std;


vector<int> lps(string s){
	int m = s.size();
	int i=1,j=0;
	vector<int>lps(m-1,0);
	lps.push_back(0);
	while(i<m){
		if(s[i]==s[j]){
			lps[i++] = ++j;
		}
		else{
			if(j!=0) j = lps[j-1];
			else lps[i++]=0;
		}
	}
	return lps;
}


void kmp(string s,string pattern){
	vector<int> lp = lps(pattern);

	int i = 0;
	int j = 0;
	bool f = false;
	while(i<s.size()){
		if(s[i]==pattern[j]){
			i++;
			j++;
		}
		else if(i<s.size()){
			if(j!=0) j = lp[j-1];
			else i++;
		}
		if(j==pattern.size()){
			f = true;
			cout<<"found at "<<i-j<<endl;
		}
	}
	if(!f) cout<<"Not Found";
}

int main(){
	string s = "HelloHunnyBunnyHunny";
	string pattern = "Hungny";
	kmp(s,pattern);
}
