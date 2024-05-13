#include <bits/stdc++.h>
using namespace std;
void fractionalKnapsack(int n, float weight[], float profit[], float capacity){
    float x[20], totalProfit=0;
    int cap=capacity,i;
    for(i=0;i<n;i++)
        x[i]=0.0;
    for(i=0;i<n;i++){
        if(weight[i]>cap)
            break;
        else{
            x[i]=1.0;
            totalProfit+=profit[i];
            cap-=weight[i];
        }
    }
    if(i<n)
        x[i]=cap/weight[i];
    totalProfit+=(x[i]*profit[i]);
    cout<<totalProfit<<endl;
}
int main(){
    float weight[20],profit[20],ratio[20],capacity;
    int n;
    cout<<"Enter no. of elements";
    cin>>n; 
    cout<<"Enter elements";
    for(int i=0;i<n;i++){
        cin>>weight[i]>>profit[i];
    }
    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]>ratio[j]){
                swap(ratio[i], ratio[j]);   
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }
    fractionalKnapsack(n, weight, profit, capacity);
}