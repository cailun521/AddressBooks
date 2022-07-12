#include <iostream>
using namespace std;
#define MAX 10

// 设计联系人的结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

//  设计通讯录的结构体
struct AddressBooks
{
	// 通讯录中保存的联系人数组
	struct Person personArray[MAX];

	// 通讯录中当前记录联系人的个数
	int m_Size;

};

// 菜单界面
void showMenu()

{
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出通讯录" << endl;
}

// 1、添加联系人
void addPerson(AddressBooks* abs)
{
	// 判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		// 添加具体联系人

		// 姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		// 性别
		cout << "请输入性别： " << endl;
		cout << "1-----男" << endl;
		cout << "2-----女" << endl;
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
				cout << "输入有误，重新输入！";
			}
		}

		// 年龄
		cout << "请输入年龄： " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		// 电话
		cout << "请输入电话： " << endl;
		string phoneNum = "";
		cin >> phoneNum;
		abs->personArray[abs->m_Size].m_Phone = phoneNum;

		// 住址
		cout << "请输入住址： " << endl;
		string addr = "";
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
	}
	// 更新通讯录人数
	abs->m_Size++;
	cout << "添加成功！" << endl;

	system("pause");// 请按任意键继续
	system("cls");// 清屏
}

int isExist(AddressBooks* abs, string name);

//清空通讯录
void cleanAbs(AddressBooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！" << endl;
	system("pause");
	system("cls");
}

//修改联系人信息
void modifiedPerson(AddressBooks* abs)
{
	cout << "请输入要修改的联系人姓名： " << endl;
	string name;
	cin >> name;
	int pos = isExist(abs, name);
	if (pos == -1)
	{
		cout << "查无此人!" << endl;
	}
	else
	{
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[pos].m_Name = name;

		int sex;
		cout << "请输入性别： " << endl;
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
				cout << "输入有误，请重新输入： " << endl;
			}
		}

		int age;
		cout << "请输入年龄： " << endl;
		cin >> age;
		abs->personArray[pos].m_Age = age;

		string phoneNum;
		cout << "请输入电话： " << endl;
		cin >> phoneNum;
		abs->personArray[pos].m_Phone = phoneNum;

		string addr;
		cout << "请输入住址： " << endl;
		cin >> addr;
		abs->personArray[pos].m_Addr = addr;

		cout << "修改成功！" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(AddressBooks* abs)
{
	cout << "请输入要查找的联系人的姓名： " << endl;
	string name;
	cin >> name;
	int pos = isExist(abs, name);
	if (pos == -1)
	{
		cout << "查无此人！" << endl;
	}
	else
	{
		cout << "姓名： " << abs->personArray[pos].m_Name << endl;
		cout << "年龄： " << abs->personArray[pos].m_Age << endl;
		cout << "性别： " << abs->personArray[pos].m_Sex << endl;
		cout << "电话： " << abs->personArray[pos].m_Phone << endl;
		cout << "住址： " << abs->personArray[pos].m_Addr << endl;
	}
	system("pause");
	system("cls");
}

//删除联系人
void deletePerson(AddressBooks* abs)
{
	cout << "请输入要删除的联系人姓名: " << endl;
	string name;
	cin >> name;
	int pos = isExist(abs, name);
	if (pos == -1)
	{
		cout << "要删除的联系人不存在！" << endl;
	}
	else
	{
		for (int i = pos; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，存在返回下标，不存在返回-1
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

//显示所有联系人
void showPerson(AddressBooks * abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前通讯录为空！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名： " << abs->personArray[i].m_Name << endl;
			cout << "性别： " << abs->personArray[i].m_Sex << endl;
			cout << "年龄： " << abs->personArray[i].m_Age << endl;
			cout << "电话： " << abs->personArray[i].m_Phone << endl;
			cout << "住址： " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int main()
{
	// 创建通讯录结构体变量
	AddressBooks abs;
	// 初始化通讯录中当前人数
	abs.m_Size = 0;

	int select = 0;  //创建用户选择输入的变量

	while (true)
	{
		//菜单调用
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:    //1、添加联系人
			addPerson(&abs); //利用指针传递，修改通讯录
			break;
		case 2:    //2、显示联系人
			showPerson(&abs);
			break;
		case 3:   //3、删除联系人
			deletePerson(&abs);
			break;
		case 4:   //4、查找联系人
			findPerson(&abs);
			break;
		case 5:   //5、修改联系人
			modifiedPerson(&abs);
			break;
		case 6:   //6、清空联系人
			cleanAbs(&abs);
			break;
		case 0:   //0、退出通讯录
			cout << "欢迎下次使用!" << endl;
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