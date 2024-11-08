/*
 실전 문제2: 게임 개발
*/

int n, m, x, y, dir;
int d[50][50];
int arr[50][50];

// 방향에 따른 이동
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

// 왼쪽으로 회전
void turn_left() {
    dir -= 1;
    if (dir == -1) dir = 3;
}

int main(void) {
    cin >> n >> m;
    cin >> x >> y >> dir;
    d[x][y] = 1;

    //맵 정보 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }

    int cnt = 1;
    int turn_time = 0;
    while (true) {
        //왼쪽으로 회전
        turn_left();
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        //회전 이후 가보지 않은 칸이 존재하는 경우 이동
        if (d[nx][ny] == 0 && arr[nx][ny] == 0) {
            d[nx][ny] = 1;
            x = nx;
            y = ny;
            cnt += 1;
            turn_time = 0;
            continue;
        }
        //회전한 이후 가보지 않은 칸이 없거나 바다인 경우
        else turn_time += 1;
        //네 방향 모두 바다인 경우
        if (turn_time == 4) {
            nx = x - dx[dir];
            ny = y - dy[dir];
            //뒤로 이동 시도
            if (arr[nx][ny] == 0) {
                x = nx;
                y = ny;
            }
            else break;
            turn_time = 0;
        }
    }

    cout << cnt << '\n';
}
