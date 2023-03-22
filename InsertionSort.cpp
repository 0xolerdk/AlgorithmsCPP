#include <iostream>
using namespace std;

bool isPowOfTwo(long b){
    return b > 0 && (b & (b - 1)) == 0;
}

void towersSort(long arr[], int ids[], int n)
{

    if (n <= 1)
        return;
 
    towersSort(arr, ids, n-1);
 
    long last = arr[n-1];
    int last2 = ids[n-1];
    int j = n-2;
 
    while (j >= 0 && arr[j] > last)
    {
        arr[j+1] = arr[j];
        ids[j+1] = ids[j];
        j--;
    }
    arr[j+1] = last;
    ids[j+1] = last2;
}
 

 
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
        int towersnum,testnum;
        int count=0;
        cin >> testnum;
        for (int i = 0; i<testnum; i++) {
            cin>>towersnum;
            long towers[towersnum];
            int ids[towersnum];
            string names[towersnum];
            for (int j = 0; j<towersnum; j++) {
                cin>>names[j];
                cin>>towers[j];
                ids[j]=j;
            }
            towersSort(towers, ids, towersnum);
            
            for (int i =0; i<towersnum; i++) {
                if (isPowOfTwo(towers[i])) {
                    cout<<names[ids[i]]<<"-"<<towers[i]<<" ";
                }
            }
            for (int i =0; i<towersnum; i++) {
                if (!isPowOfTwo(towers[i])) {
                    cout<<names[ids[i]]<<"-"<<towers[i]<<" ";
                }
            }
            
            cout<<"\n";
            
        }
    
    
    
     

     
        return 0;
    }