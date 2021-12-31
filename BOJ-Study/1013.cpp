//https://www.acmicpc.net/problem/1013
//아레시보 천체 망원경


#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
    int numofcomputer = 0;
    cin >> numofcomputer;
    int numofedge = 0;
    cin >> numofedge;
    vector<vector<int>> adjmatrix(numofcomputer + 2,vector<int>(numofcomputer + 2,0)); // 인접리스트 선언
    vector<int> vertex(numofcomputer+2,0);
    int front;
    int end;
    for(int i = 0; i < numofedge; i++)
    {
        cin >> front >> end; // ex) 1 6
        // front = 1 end = 6
        adjmatrix[front][end] = 1; // true
        adjmatrix[end][front] = 1; // true
    }
    // adjlist
    // 1번 컴퓨터가 감염
    int numofinf = 0; // 1번은 감염되어있음
    stack<int> dfs;
    dfs.push(1);
    vertex[1] = 1;
    while(!dfs.empty())
    {
        int cur = dfs.top();
        dfs.pop();
        for(int i = 0; i < numofcomputer; i++)
        {
            if(adjmatrix[cur][i] == 1 && vertex[i] != 1)
            {
                dfs.push(i);
                vertex[i] = 1;
                numofinf++;
            }
        }
    }
    cout << numofinf << endl;
    return 0;
}
