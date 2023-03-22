#include<iostream>
#include <vector>
using namespace std;


short sum, minSUM=9999;
short crabs[30][30];

vector<short> row(30),res, bufres;
vector<bool> one(30),two(30);

void Nqueen(int n,int col)
{
    if(col >= n){
        
        
        if (sum<minSUM) {
            minSUM = sum;
            res = bufres;

        }

        return;
        
    }

    for(int i=0;i<n;i++){
        

        if((sum+crabs[col][i])<minSUM){
                if(!row[i]){
                if(!one[i-col+n-1]){
                if(!two[i+col])
                {
                    row[i] = one[i-col+n-1] = two[i+col] = 1;

                    bufres.push_back(i);
                    sum += crabs[col][i];

                    Nqueen(n,col+1);
                    sum -= crabs[col][i];
                    bufres.pop_back();

                    row[i] = one[i-col+n-1] = two[abs(i+col)] = 0;
                }}}}
    }
}

int main()
{
    
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin>>crabs[i][j];
        }
    }

    Nqueen(n,0);
    for (int i = 0; i<n; i++) {
        cout<<res[i]<<" ";
    }
}