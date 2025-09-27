#include <iostream>
#include <vector>
#include "algorithm"
using namespace std;

struct Seat 
{
    int x, y;
    int likeCount, emptyCount;
};

struct Student_Info 
{
    int myIndex;
    int like[4];
};
int board[21][21];  

int dx[4]{ 0, 0, -1, 1 };
int dy[4]{ 1, -1, 0, 0 };

int n;

vector<Student_Info> students;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    students.reserve(n * n);

    Student_Info st;
    for (size_t i = 0; i < n*n; i++)
    {
        cin >> st.myIndex;
        for (size_t j = 0; j < 4; j++)
            cin >> st.like[j];
        
        students.push_back(st);
    }

    // 계산
    for (size_t i = 0; i < n*n; i++)    // 학생 수
    {
        int student = students[i].myIndex;
        vector<Seat> candidates;

        for (size_t j = 0; j < n; j++) // 2중 for는 borad
        {
            for (size_t k = 0; k < n; k++)
            {
                if (board[j][k] != 0)
                    continue;

                int likeCount = 0, emptyCount = 0;

                for (size_t d = 0; d < 4; d++) // 상하좌우
                {
                    int nx = k + dx[d];
                    int ny = j + dy[d];
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;

                    // 상하좌우 검사 후 빈자리 + 좋아하는 사람 자리 카운트 체크
                    if (board[ny][nx] == 0)
                        emptyCount++;
                    else
                        for (int like : students[i].like)
                            if (board[ny][nx] == like)
                                likeCount++;
                }

                Seat seat{ j, k, likeCount, emptyCount };
                candidates.push_back(seat);
            }
        }

        // 정렬
        sort(candidates.begin(), candidates.end(), [](Seat& a, Seat& b)
        {
            if (a.likeCount != b.likeCount)         // 첫 번째 조건 : 좋아하는 사람의 수
                return a.likeCount > b.likeCount;   
            if (a.emptyCount != b.emptyCount)       // 두 번째 조건 : 주위에 빈 공간이 많은 수
                return a.emptyCount > b.emptyCount;
            if (a.x != b.x)                         // 세 번째 조건 : 행이 낮은 수
                return a.x < b.x;
            if (a.y != b.y)                         // 네 번째 조건 : 열이 낮은 수
                return a.y < b.y;

            return false;
        });

        // 첫 번째 후보 좌석에 앉히기
        board[candidates[0].x][candidates[0].y] = student;
    }
     
    // 점수 계산
    int result = 0;
    for (int j = 0; j < n; j++) 
    {
        for (int k = 0; k < n; k++) 
        {
            int student = board[j][k];
            int likeCount = 0;

            // 학생 번호 -> 좋아하는 배열 찾기
            Student_Info st;
            for (auto& s : students)            
            {
                if (s.myIndex == student) 
                {
                    st = s;
                    break;
                }
            }

            // 상하좌우 확인
            for (int d = 0; d < 4; d++) 
            {
                int nx = k + dx[d];
                int ny = j + dy[d];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                for (int l = 0; l < 4; l++) 
                    if (board[ny][nx] == st.like[l]) 
                        likeCount++;
            }

            // result 누적
            result +=   likeCount == 1 ? 1 :
                        likeCount == 2 ? 10 :
                        likeCount == 3 ? 100 :
                        likeCount == 4 ? 1000 : 0;
        }
    }

    cout << result;
    return 0;
}