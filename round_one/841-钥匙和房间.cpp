#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;
/*
void visit(unordered_map<int, int> &isVisited, vector<vector<int>> &rooms, int num) {
    for (auto && i : rooms[num]) {
        if (isVisited.count(i)) {
            isVisited.erase(i);
            visit(isVisited, rooms, i);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int N = rooms.size();
    if (0 == N) {
        return false;
    }
    unordered_map<int,int> isVisited;
    for (int i = 0; i < N; ++i) {
        isVisited[i] = 0;
    }
    isVisited[0] = 1;
    visit(isVisited, rooms, 0);
    return isVisited.empty();
}
*/
//广度优先和深度优先

void dfs(vector<bool> &visit, vector<vector<int>> &rooms, int &num, int x) {
    visit[x] = true;
    num++;
    for (auto && i : rooms[x]) {
        if (!visit[i]) {
            dfs(visit, rooms, num, i);
        }
    }
}

bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<bool> visit(n, false);
    int num = 0;
    dfs(visit, rooms, num ,0);
    return num == n;

}

/*
bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size(), num = 0;
    vector<bool> visit(n, false);
    queue<int> que;
    visit[0] = true;
    que.emplace(0);
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        num++;
        for (auto && i : rooms[x]) {
            if (!visit[i]) {
                visit[i] = true;
                que.emplace(i);
            }
        }
    }
    return num == n;

}
*/
int main() {
    vector<vector<int>> v1 = {
        {1},
        {2},
        {3},
        {}
    }, v2 = {
        {1,3},
        {3, 0, 1},
        {2},
        {0}
    };
    cout << canVisitAllRooms(v1) << endl;
    cout << canVisitAllRooms(v2) << endl;
    return 0;
}