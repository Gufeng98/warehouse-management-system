#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <vector>
#define ALL 1500
using namespace std;

class Goods{
public:
	Goods();
	void setName(string name_i);
	string getName();
	void setCount(int count_i);
	int getCount();
private:
	string name;
	int count;
}; 

class Warehouse {
public:
	Warehouse();
	void empty();//��ʼ��������Ʒ��Ϣ��vector 
	void direction();//�����ʾ������û����� 
	bool input(char *commond);//��������Ƿ���ȷ 
	int inputCheck(string &name, string count);//����û��������Ʒ���������Ƿ�Ϸ�
	//������ 
	//��������Ӧ����ģ�飬��ʾ��ǰ����һ������Ϊcount��name��Ʒ
	bool add_goods(string name, string count);

	//���¿���б���Ӧ������Ʒ�ӹ��ܣ�����name��Ʒ�ҳ�ʼ����Ϊcount
	bool add_to_list(string name, int count);

	//������
	//��������Ӧ����ģ�飬��ʾ��ǰ����һ������Ϊcount��name��Ʒ
	bool delete_goods(string name, string count);

	//��ѯ��
	///��ʾ��ǰ����б�������Ʒ����������
	void show_goods();
	//�鿴�ֿ��е�name��Ʒ
	void find_goods(string name);
private:
	vector<Goods> goods;
	template <class Type>
	Type stringToNum(const string& str)
	{
		istringstream iss(str);
		Type num;
		iss >> num;
		return num;
	} //ģ�壬���ַ������͵ı�����Ϊint�� 
};

 
 
