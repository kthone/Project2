#include <time.h>
#include <iostream>
#include <vector>
using namespace std;


bool is_sol = false; //해를 찾았는지를 저장할 변수
vector<int> col(11); //체스판의 열. i-th element of col이 j라면 i열 j행에 퀸 위치

//퀸을 놓을수 있는지를 check
bool is_place_ok(int depth)
{
	for (int i = 0; i < depth; i++)
		if (col[i] == col[depth] || abs(col[depth] - col[i]) == depth - i) //같은 행이나 열, 대각선상에 위치할 경우 false 반환
			return false;
	return true;
}


void nqueen(int x)
{
	if (x == 11) {
		for (int i = 0; i < 11; i++)
			cout << col[i] << " ";
		is_sol = true;
		return;
	} // 만약 11까지 도달시 해를 찾았으며 print 후 return
	else{
		for (int i = 0; i < 11; i++) {
			//i 행에 퀸 위치
			col[x] = i;
			//가능한 수라면 다음 열로 넘어간다
			if (is_place_ok(x))
				nqueen(x + 1);
			//이미 해를 찾았다면 함수를 끝낸다
			if (is_sol)
				return;
		}
	}
	
}

int main() {
	double startTime = clock();
	//0에서 시작
	nqueen(0);
	double endTime = clock();
	double elapsedTime = (double)(endTime - startTime);
	cout << "프로그램 수행 시간 : " << elapsedTime << endl;
	return 0;
}