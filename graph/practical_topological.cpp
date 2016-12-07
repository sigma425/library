#include <iostream>
#include <queue>
#include <vector>
using namespace std;
queue<int> que;
void tsort(){
	for(int i=0;i<d.size();i++) if(rev[i].empty()) que.push(i);
	while(!que.empty()){
		int q=que.front();
		que.pop();
		topod.push_back(q);
		for(int i=0;i<G[q].size();i++){
			int main(){
	