/*
*
*@author��Aver Jing
*@description��
*@date��
*
*/

#include<iostream>
#include <list>
#include <iterator>
#include "base_tool.h"

using namespace std;

void ex10_27() {
	vector<int> ivec{ 1,1,5,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9 };
	list<int> ilst;
	//ilst.resize(ivec.size());

	sort(ivec.begin(), ivec.end());
	//unique_copy(ivec.cbegin(), ivec.cend(), ilst.begin());
	/*��Ϊlst3���Ϊ��������˴�ʱlst3.begin()Ϊ��Ч��������
	������Ϊ��ʱ����Ϊ�գ�βǰ��β���������ͬ��
	��β���������ʼ�����õģ����Դ�ʱ���õ��ĵ�������Ĭ�ϱ����β�������*/
	unique_copy(ivec.cbegin(), ivec.cend(), inserter(ilst, ilst.begin()));
	Print(ilst);
}

int main() {
	ex10_27();
	return 0;
}