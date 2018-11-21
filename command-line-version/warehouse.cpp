#include "warehouse.h"
Goods::Goods()
{
	this->name = "";
	this->count = 0;
}
void Goods::setName(string name_i)
{
	this->name = name_i;
}
string Goods::getName()
{
	return this->name;
}
void Goods::setCount(int count_i)
{
	this->count = count_i;
}
int Goods::getCount()
{
	return this->count;
}

Warehouse::Warehouse()
{
	this->goods.clear();
}
void Warehouse::empty()//�������ֿ��еĻ������� 
{
	this->goods.clear();
	cout << endl << "              �ֿ�տ���Ҳ���촢�����ɣ�    \n" << endl
		<< endl << endl << "          ע�⣺" << endl << endl
		<< "            ��Ʒ����Ӧ����100���ַ�������С��100000��" << endl << endl;
}

void Warehouse::direction()
{
	cout << "------------------ ��ѡ��Ҫ���еĲ��� ----------------" << endl
		<< "*                                                    *" << endl
		<< "*                      1 ����                        *" << endl
		<< "*                                                    *" << endl
		<< "*                      2 ����                        *" << endl
		<< "*                                                    *" << endl
		<< "*                      3 �����嵥                    *" << endl
		<< "*                                                    *" << endl
		<< "*                      4 ��ѯ����                    *" << endl
		<< "*                                                    *" << endl
		<< "*                      5 ��ղֿ�                    *" << endl
		<< "*                                                    *" << endl
		<< "*                      6 �˳�ϵͳ                    *" << endl
		<< "------------------------------------------------------" << endl;
}

bool Warehouse::input(char *commond)
{
	cin >> *commond;
	cin.get();
	cin.sync();
	cin.clear();
	if (*commond < '1' || *commond > '6') //ָ�����ʱ����������Ĳ��� 
	{
		cout << endl << "                   ����ָ��������������룡" << endl << endl;
		return false;
	}
	else
	{
		return true;
	}
}  //��ָ��Ϸ���Ҫ���������룬ֱ������Ϸ�ָ�� 

int Warehouse::inputCheck(string &name, string count)
{
	while (name.length() > 100 || name.length() == 0)
	{
		cout << endl << "         ���������Ʒ�����������������룡 " << endl << endl;
		cin >> name;
		cin.sync();
		cin.clear();
	}

	int number;
	while (!0)
	{
		while (count.length() >= 10)
		{
			cout << endl << "         ���������Ʒ�����������������룡 " << endl << endl;
			cin >> count;
			cin.sync();
			cin.clear();
		}
		int coun = 0;
		for (coun = 0; coun < count.length(); coun++)
		{
			if (!isdigit(count[coun]))
			{
				cout << endl << "         ���������Ʒ�����������������룡 " << endl << endl;
				break;
			}
		}
		if (coun < count.length())
		{
			cin >> count;
			cin.sync();
			cin.clear();
			continue;
		}
		else
		{
			number = stringToNum<int>(count);//������� 
			if (number > 0 && number < 100000)
				break;
			else
			{
				cout << endl << "         ���������Ʒ�����������������룡 " << endl << endl;
				cin >> count;
				cin.sync();
				cin.clear();
				continue;
			}

		}
	}
	return number;
}
bool Warehouse::add_goods(string name, string count)
{
	int number = inputCheck(name, count);
	vector<Goods>::iterator it;
	for (it = goods.begin(); it != goods.end();it++)
	{
		if (it->getName() == name)
		{
			it->setCount(it->getCount() + number);
			cout << endl << "�����Ѵ��棬Ŀǰ���Ļ���" << name
				<< "������Ϊ��" << it->getCount() << endl << endl;
			return true;
		}
	} //���Ѵ���Ҫ������Ʒ����ֻ������������ 
	if (it ==  goods.end())
	{
		add_to_list(name, number);
		return true;
	} //��Ŀǰ�ֿ���û�и���Ʒ�����������Ʒ�б� 

}



bool Warehouse::add_to_list(string name, int count)
//���б��м����µ���Ʒ���ú����ں���add_goods(string name, int count)�ڲ����� 
{
	if (this->goods.size() < ALL)//�ֿ�δ��ֱ�Ӵ洢
	{
		Goods good;
		good.setName(name);
		good.setCount(count);

		this->goods.push_back(good);
		cout << endl << "�����Ѵ��棬Ŀǰ���Ļ���" << name
			<< "������Ϊ��" << count << endl << endl;
		return true;
	} 
	else
	{
		cout << endl << "                    �ֿ�����!            " << endl << endl;
		return false;
	} //������λ���Ѿ����˵�ʱ����ʾ���ֿ������� 
}

bool Warehouse::delete_goods(string name, string count)
//���� 
{
	int number = inputCheck(name, count);
	vector<Goods>::iterator it;
	for (it = goods.begin(); it != goods.end(); it++)
	{
		if (it->getName() == name)
		{
			if ((it->getCount() - number) < 0)
			{
				cout << endl << "                  ��治�㣬�����ѱ��ܾ���" << endl << endl;
				return false;
			} //�����������ڿ��ʱ���ܾ����� 
			else if ((it->getCount() -number) == 0)
			{
				this->goods.erase(it);
				cout << endl << "                    ����ɹ����û�����ȫ�����⣬���Ϊ�㣡" << endl << endl;
				return true;
			} //���������պõ��ڿ��ʱ����������������Ʒ�������Ƴ� 
			else if ((it->getCount() - number) > 0)
			{
				it->setCount(it->getCount() - number);
				cout << endl << "�����ѱ�����Ŀǰ��Ʒ" << name
					<< "������Ϊ��" << it->getCount() << endl << endl;
				return true;
			}
			return true;
			break;
		}
	} 
	if (it == goods.end())
	{
		cout << endl << "               δ�ҵ�����Ʒ����������" << endl << endl;
		return false;
	} //��Ŀǰ�ֿ���û�и���Ʒ����ʾδ�ҵ�

}

void Warehouse::show_goods()
//��ʾĿǰ�ֿ���������Ʒ�������� 
{
	cout << setw(100) << left << "��Ʒ" << setw(8) << left << "����" << endl;
	vector<Goods>::iterator it;
	for (it = goods.begin(); it != goods.end(); it++)
	{
		cout << setw(100) << left << it->getName()
			<< setw(8) << left << it->getCount()<< endl;
	}  
	
}
void Warehouse::find_goods(string name)
//��������Ʒ�н��в���Ŀ����Ʒ 
{
	vector<Goods>::iterator it;
	for (it = goods.begin(); it != goods.end(); it++)
	{
		if (it->getName() == name)
		{
			cout << "��Ʒ " << name << " ������Ϊ" << it->getCount() << "��" << endl << endl;
			break;
		}
	}
	if (it == goods.end())
	{
		cout << endl << "                      Ŀǰ�ֿ���û�и���Ʒ��" << endl << endl;
	}
}