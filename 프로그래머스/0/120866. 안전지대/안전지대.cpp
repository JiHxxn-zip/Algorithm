#include <string>
#include <vector>

using namespace std;
// 자기 자신 포함 9방 탐색 
int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1 };
int dy[] = {-1, 0, 1, -1, 0, 1, -1 ,0 ,1 };

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    // n * n 배열이므로
    int n = board.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            
            // 만약 지뢰를 발견했다면
            if (board[i][j] == 1)
            {
                // 자기 자신을 2로 바꾸고 카운트 +1
                board[i][j] = 2;
                answer++;
                
                // 8방 탐색을 시작
                for(int k = 0; k < 9; k++)
                {
                    // 살펴볼 방향
                    int x_dx = i + dx[k];
                    int y_dy = j + dy[k];
                    
                    // x와 y가 board안이면서,
                    // 지뢰가 없는 구역을 위험지역으로 분류
                    // 만약 이미 위험지역이라면 넘어가게 됨.
                    if((-1 < x_dx && x_dx < n) 
                      && (-1 < y_dy && y_dy < n)
                      && (board[x_dx][y_dy] == 0))
                    {
                        // 위험지역 분류
                        board[x_dx][y_dy] = 2;
                        answer++;
                    }
                }
            }
        }
    }
    
    // 전체 지역에서 위험지역을 빼준다.
    return n * n - answer;
}