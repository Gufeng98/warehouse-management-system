#include <iostream>
#include <cstring>
#include "warehouse.h"

using namespace std;

int main()
{
	Warehouse warehouse;
	warehouse.empty();
	char commond = '3';

	while( commond != '6' )//����ָ��6ʱ�˳�ϵͳ 
	{
		warehouse.direction();//Ϊ�û�������ʾ��������� 
		
		while(warehouse.input(&commond) == false);//��������Ƿ���ȷ 
		
		switch(commond)//����ʵ�ָ����ֿܷ�ѡ�� 
		{
			case '1' ://���� 
			{
				cout << endl << "    ������Ҫ������Ʒ���ƣ����Իس������� : " << endl;
				string name1;
				getline(cin, name1); 
				cin.sync();
				cin.clear();
				
				cout << endl << "   ������Ҫ������Ʒ���� : " << endl;
				string count;
				getline(cin, count);
				cin.sync();
				cin.clear();
				 
				warehouse.add_goods(name1, count);
				break;
			}
			case '2' ://���� 
			{
				cout << endl << "  ������Ҫ�������Ʒ���ƣ����Իس������� : " << endl;
				string name2;
				getline(cin, name2); 
				cin.sync();
				cin.clear();
				
				cout << endl << "   ������Ҫ�������Ʒ���� : " << endl;
				string count2;
				cin >> count2;
				cin.sync();
				cin.clear();
				
				warehouse.delete_goods(name2, count2);
				break;
			}
			case '3' ://��ʾ�嵥 
			{
				warehouse.show_goods();
				break;
			}
			case '4' ://ʵ�ֲ�ѯ 
			{
				cout << endl << "  ������Ҫ��ѯ����Ʒ���ƣ����Իس������� : " << endl;
				string name3;
				getline(cin, name3);
				cin.sync();
				cin.clear();
				
				warehouse.find_goods(name3);
				break;
			}
			case '5' ://��ղֿ� 
			{
				warehouse.empty();
			}
		}	
	}
	return 0; 
}  
