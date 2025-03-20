#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int n,temp;
	scanf("%d",&n);
	int top =-1;
	vector<int> v;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		switch (temp)
		{
		case 1:
			scanf("%d",&temp);
			v.push_back(temp);
			top++;
			break;
		case 2:
			if(top == -1)printf("-1\n");
			else{
				printf("%d\n",v[top]);
				v.pop_back();
				top --;
			}
			break;
		case 3:
			printf("%d\n",top+1);
			break;
		case 4:
			if(top == -1)printf("1\n");
			else printf("0\n");
			break;
		case 5:
		if(v.empty())printf("-1\n");
		else{
			printf("%d\n",v[top]);
			}
			break;
		
		default:
			break;
		}
	}
	return 0;
}