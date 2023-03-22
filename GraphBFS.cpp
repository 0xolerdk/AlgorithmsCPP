#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

class Graph {

public:

    int numberOfVills;
    int numberOfEnds;
    int s;
    vector<int> end;
    
    map<string, int> mapOfVills;
    vector < vector<int> > g;
    
    int BFS(){
        
        int max = 0;
        int c = 0;
        
        queue<int> q;
        q.push (s);
        vector<bool> used (numberOfVills);
        vector<int> d (numberOfVills), p (numberOfVills);
        used[s] = true;
        p[s] = -1;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i=0; i<g[v].size(); ++i) {
                int to = g[v][i];
                if (!used[to]) {
                    used[to] = true;
                    q.push (to);
                    d[to] = d[v] + 1;
                    p[to] = v;
                    
                    for (int j = 0; j<numberOfEnds; j++) {
                        if (to == end[j]&&max<d[to]) {
                            max = d[to];
                            c++;
                        }
                    }
//                    if (c==numberOfEnds) {
//                        return max;
//                    }
                }
            }
        }
        return  max;
    }
    void addVill(string nameOfVill, int id){
        mapOfVills[nameOfVill] = id;
    }
    void addStart(string nameOfVill){
        s = mapOfVills[nameOfVill];
    }
    
    void addEnd(string nameOfVill){
        end.push_back(mapOfVills[nameOfVill]);
    }
    
    int getId(string nameOfVill){
        return mapOfVills[nameOfVill];
    }
    
    Graph(int numberOfVills, int numberOfEnds){
        this->numberOfVills = numberOfVills;
        this->numberOfEnds = numberOfEnds;
        
    }
    
};

int main(int argc, const char * argv[]) {
    
    string villageName;
    int numberOfVills;
    int numberOfEnds;
    
    cin>>numberOfVills>>numberOfEnds;
    
    Graph villages(numberOfVills, numberOfEnds);
    
    for (int i = 0; i<numberOfVills; i++) {
        cin>>villageName;
        villages.addVill(villageName, i);
    }
    vector<int> v;
    for (int i = 0; i<numberOfVills;) {
        int countX = 0;

        cin >> villageName;
        if (villageName == "X") {
            countX++;
            i++;
            villages.g.push_back(v);
            v.clear();
        }
        else{
            
            v.push_back(villages.getId(villageName));
        }
    }
    
    cin>>villageName;
    
    villages.addStart(villageName);
    
    while (numberOfEnds--) {
        cin>>villageName;
        villages.addEnd(villageName);
    }
    
    cout<<villages.BFS();
    
    
    
    
    
    
    
    return 0;
}