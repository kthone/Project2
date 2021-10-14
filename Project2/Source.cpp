#include <time.h>
#include <iostream>
#include <vector>
using namespace std;


bool is_sol = false; //�ظ� ã�Ҵ����� ������ ����
vector<int> col(11); //ü������ ��. i-th element of col�� j��� i�� j�࿡ �� ��ġ

//���� ������ �ִ����� check
bool is_place_ok(int depth)
{
	for (int i = 0; i < depth; i++)
		if (col[i] == col[depth] || abs(col[depth] - col[i]) == depth - i) //���� ���̳� ��, �밢���� ��ġ�� ��� false ��ȯ
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
	} // ���� 11���� ���޽� �ظ� ã������ print �� return
	else{
		for (int i = 0; i < 11; i++) {
			//i �࿡ �� ��ġ
			col[x] = i;
			//������ ����� ���� ���� �Ѿ��
			if (is_place_ok(x))
				nqueen(x + 1);
			//�̹� �ظ� ã�Ҵٸ� �Լ��� ������
			if (is_sol)
				return;
		}
	}
	
}

int main() {
	double startTime = clock();
	//0���� ����
	nqueen(0);
	double endTime = clock();
	double elapsedTime = (double)(endTime - startTime);
	cout << "���α׷� ���� �ð� : " << elapsedTime << endl;
	return 0;
}