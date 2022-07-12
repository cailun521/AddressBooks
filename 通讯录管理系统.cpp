#include <iostream>
using namespace std;
#define MAX 10

// �����ϵ�˵Ľṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//  ���ͨѶ¼�Ľṹ��
struct AddressBooks
{
	// ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	// ͨѶ¼�е�ǰ��¼��ϵ�˵ĸ���
	int m_Size;

};

// �˵�����
void showMenu()

{
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�ͨѶ¼" << endl;
}

// 1�������ϵ��
void addPerson(AddressBooks* abs)
{
	// �ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
		return;
	}
	else
	{
		// ��Ӿ�����ϵ��

		// ����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		// �Ա�
		cout << "�������Ա� " << endl;
		cout << "1-----��" << endl;
		cout << "2-----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "���������������룡";
			}
		}

		// ����
		cout << "���������䣺 " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		// �绰
		cout << "������绰�� " << endl;
		string phoneNum = "";
		cin >> phoneNum;
		abs->personArray[abs->m_Size].m_Phone = phoneNum;

		// סַ
		cout << "������סַ�� " << endl;
		string addr = "";
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
	}
	// ����ͨѶ¼����
	abs->m_Size++;
	cout << "��ӳɹ���" << endl;

	system("pause");// �밴���������
	system("cls");// ����
}

int isExist(AddressBooks* abs, string name);

//���ͨѶ¼
void cleanAbs(AddressBooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�" << endl;
	system("pause");
	system("cls");
}

//�޸���ϵ����Ϣ
void modifiedPerson(AddressBooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�������� " << endl;
	string name;
	cin >> name;
	int pos = isExist(abs, name);
	if (pos == -1)
	{
		cout << "���޴���!" << endl;
	}
	else
	{
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personArray[pos].m_Name = name;

		int sex;
		cout << "�������Ա� " << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[pos].m_Sex = sex;
				break;
			}
			else
			{
				cout << "�����������������룺 " << endl;
			}
		}

		int age;
		cout << "���������䣺 " << endl;
		cin >> age;
		abs->personArray[pos].m_Age = age;

		string phoneNum;
		cout << "������绰�� " << endl;
		cin >> phoneNum;
		abs->personArray[pos].m_Phone = phoneNum;

		string addr;
		cout << "������סַ�� " << endl;
		cin >> addr;
		abs->personArray[pos].m_Addr = addr;

		cout << "�޸ĳɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(AddressBooks* abs)
{
	cout << "������Ҫ���ҵ���ϵ�˵������� " << endl;
	string name;
	cin >> name;
	int pos = isExist(abs, name);
	if (pos == -1)
	{
		cout << "���޴��ˣ�" << endl;
	}
	else
	{
		cout << "������ " << abs->personArray[pos].m_Name << endl;
		cout << "���䣺 " << abs->personArray[pos].m_Age << endl;
		cout << "�Ա� " << abs->personArray[pos].m_Sex << endl;
		cout << "�绰�� " << abs->personArray[pos].m_Phone << endl;
		cout << "סַ�� " << abs->personArray[pos].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

//ɾ����ϵ��
void deletePerson(AddressBooks* abs)
{
	cout << "������Ҫɾ������ϵ������: " << endl;
	string name;
	cin >> name;
	int pos = isExist(abs, name);
	if (pos == -1)
	{
		cout << "Ҫɾ������ϵ�˲����ڣ�" << endl;
	}
	else
	{
		for (int i = pos; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ���" << endl;
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ����ڷ����±꣬�����ڷ���-1
int isExist(AddressBooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

//��ʾ������ϵ��
void showPerson(AddressBooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰͨѶ¼Ϊ�գ�" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������ " << abs->personArray[i].m_Name << endl;
			cout << "�Ա� " << abs->personArray[i].m_Sex << endl;
			cout << "���䣺 " << abs->personArray[i].m_Age << endl;
			cout << "�绰�� " << abs->personArray[i].m_Phone << endl;
			cout << "סַ�� " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int main()
{
	// ����ͨѶ¼�ṹ�����
	AddressBooks abs;
	// ��ʼ��ͨѶ¼�е�ǰ����
	abs.m_Size = 0;

	int select = 0;  //�����û�ѡ������ı���

	while (true)
	{
		//�˵�����
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:    //1�������ϵ��
			addPerson(&abs); //����ָ�봫�ݣ��޸�ͨѶ¼
			break;
		case 2:    //2����ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:   //3��ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:   //4��������ϵ��
			findPerson(&abs);
			break;
		case 5:   //5���޸���ϵ��
			modifiedPerson(&abs);
			break;
		case 6:   //6�������ϵ��
			cleanAbs(&abs);
			break;
		case 0:   //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}