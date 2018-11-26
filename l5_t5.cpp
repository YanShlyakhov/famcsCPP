/*
Двумерная матрица задает высоты соседствующих клеток местности. Переход возможен в соседние клетки по горизонтали или по вертикали, если высота соседа меньше (как стекает вода).
1.	Определить все клетки, в которые можно попасть из заданной.
2.	Определить самую удаленную клетку, в которую можно попасть из заданной.
3.	Найти путь для подзадачи 2.
Зам.
1)	Используйте поиск в ширину для решения задачи.
2)	Для тестирования подготовить достаточно большие матрицы. При выводе показывать матрицу исходную и матрицу с результирующим путем (выделяя его, например, каким-то символом).


INPUT
3 3
1 1
0 0 0
0 0 0
0 0 0
OUTPUT

Task 1:
0 1 2
1 2 3
2 3 4
Task 2:
Max length = 4
Task 3:
@++
..+
..+

==============================
INPUT
5 5
1 1
0  10 10 10 10
10 10 10 10 10
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

OUTPUT
Task 1:
0 10000 10000 10000 10000
10000 10000 10000 10000 10000
10000 10000 10000 10000 10000
10000 10000 10000 10000 10000
10000 10000 10000 10000 10000
Task 2:
Max length = 0
Task 3:
@....
.....
.....
.....
.....


*/
#include <iostream>
#include<cstdlib>
#include "queue.h"

using namespace std;

const int UNDEF = 10000;
const int MAX_VAL = 1000;

char map[MAX_VAL][MAX_VAL];
int  len[MAX_VAL][MAX_VAL];

void makeMap(int maxX, int maxY){
    int i = maxX;
    int j = maxY;
    while(true){
        if(map[i][j]=='@'){
            break;
        }
        map[i][j] = '+';
        bool found = false;
        for(int dx = -1; dx<=1 && !found; dx++){
            for(int dy = -1; dy<=1 && !found; dy++){
                if(dx*dx + dy*dy == 1){
                    int ni = i+dx;
                    int nj = j+dy;
                    if(len[ni][nj] == len[i][j] - 1){
                        i=ni;
                        j=nj;
                        found = true;
                    }
                }
            }
        }
    }
}

struct myPair{
    int x;
    int y;
};

int main(){
    int n, m;
    int startX, startY;
    cin >> n >> m;
    cin >> startX >> startY;
    int a[n+2][n+2];

    for(int i=0; i<n+2; ++i){
        for(int j=0; j<m+2; ++j){
            len[i][j] = UNDEF; //не посетили
            a[i][j] = MAX_VAL;
            map[i][j] = '.';
        }
    }

    Queue< myPair> q(n * m); //максимум элементов в очереди n*m

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> a[i][j];
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    myPair start;
    start.x = startX;
    start.y = startY;
    q.push(start);
    len[startX][startY] = 0;

    while(!q.empty()){
        myPair cur = q.pop();
        for(int d = 0; d<4; d++){
                    int x = cur.x + dx[d];
                    int y = cur.y + dy[d];
                    if(x <= n && x>=1 && y <= m && y>=1){
                        if(a[x][y] <= a[cur.x][cur.y] && len[x][y] > len[cur.x][cur.y]+1){
                            myPair temp;
                            temp.x = x;
                            temp.y = y;
                            q.push(temp);
                            len[x][y] = len[cur.x][cur.y]+1;
                        }
                    }
        }
        //cout << q.sizeOf()<<"\n";
    }

    int maxX = startX, maxY = startY;

    cout <<"Task 1: \n";
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            if(len[i][j] == UNDEF){
                cout<<-1<<" ";
                continue;
            }
            cout<<len[i][j]<<" ";
            if(len[i][j] > len[maxX][maxY]){
                maxX = i;
                maxY = j;
            }
        }
        cout <<"\n";
    }
    cout <<"Task 2: \n";
    cout <<"Max length = "<<len[maxX][maxY];

    cout <<"\nTask 3: \n";

    map[startX][startY] = '@';

    makeMap(maxX, maxY);

    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cout<<map[i][j];
        }
        cout <<"\n";
    }

    system("pause");
    return 0;
}
