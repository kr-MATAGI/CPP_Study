#include <iostream>
#include <vector>

#define MAX_STEP_SIZE 300

int main()
{
	int N = 0;
	std::cin >> N;

	std::vector<int> inputList;
	for (int n = 0; n < N; n++)
	{
		int input = 0;
		std::cin >> input;
		inputList.push_back(input);
	}

	/*
	* 1. ����� �� ���� �� ��ܾ� �Ǵ� �� ��ܾ� ���� �� �ִ�.
	* ��, �� ����� �����鼭 �̾ ���� ����̳�,
	* ���� ���� ������� ���� �� �ִ�.
	* 2. ���ӵ� �� ���� ����� ��� ��Ƽ��� �� �ȴ�.
	* ��, �������� ��ܿ� ���Ե��� �ʴ´�.
	* 3. ������ ���� ����� �ݵ�� ��ƾ� �Ѵ�.
	*/

	int dpArr[MAX_STEP_SIZE + 1] = { 0, };
	dpArr[0] = inputList[0];
	dpArr[1] = inputList[1] > inputList[0] + inputList[1] ?
		inputList[1] : inputList[0] + inputList[1];
	dpArr[2] = inputList[2] + inputList[1] > inputList[2] + inputList[0] ?
		inputList[2] + inputList[1] : inputList[2] + inputList[0];

	for (int step = 3; step < N; step++)
	{
		int combo = inputList[step] + inputList[step - 1] + dpArr[step - 3];
		int notCombo = inputList[step] + dpArr[step - 2];
		dpArr[step] = combo > notCombo ? combo : notCombo;
	}

	std::cout << dpArr[N - 1] << "\n";

	return 0;
}