#include<iostream>
#include<vector>
#include<cmath>
#include"标头.h"
using namespace std;



float K_means::get_distxyz(Tuple tuple1, Tuple tuple2)//这里采用欧氏距离度量
{
	double distance = pow(pow((tuple1.x - tuple2.x), 2) + pow((tuple1.y -
		tuple2.y), 2), 0.5);
	return distance;
}
//初始化k个聚类中心
void K_means::prime_k_meansbase()
{
		Tuple T;
		T.x = 43.45;
		T.y = 66.13;
		means.push_back(T);
		Tuple T2;
		T2.x = 41.49;
		T2.y = 71.31;
		means.push_back(T2);
}

//初始化得到k个簇
void K_means::get_k_means()
{


	for (int i = 0; i != basic_data.size(); ++i)
	{
		float min_distance = 0x3f3f3f3f;
		double static temp;
		for (int j = 0; j != mean_number; ++j)
		{
			if (min_distance > get_distxyz(basic_data[i], means[j]))
			{
				min_distance = get_distxyz(basic_data[i], means[j]);
				temp = j;
				cout << temp << endl;;
			}
		}
		result_data[temp].push_back(basic_data[i]);
	}
}

//得到当前每个簇类中心
void K_means::get_basemean()
{
	vector<Tuple> A_mean;
	for (int j = 0; j < mean_number; j++)
	{
		float sumx = 0;
		float sumy = 0;
		int num = result_data[j].size();
		A_mean = result_data[j];
		cout << num << endl;
		for (int i = 0; i < num; i++)
		{
			sumx += A_mean[i].x;
			sumy += A_mean[i].y;
		}
		Tuple basemean = { sumx / num,sumy / num };
		means[j] = basemean;
		cout << basemean.x << " " << basemean.y << endl;
	}
}

//得到新的簇
void K_means::get_new_k_means()
{
	result_data.clear();//清除迁移过程结果
	result_data = vector<vector<Tuple>>(mean_number);//分配结果储存容器
	for (int i = 0; i != basic_data.size(); ++i)//每个点与每个簇类中心的距离进行比较
	{
		float min_distance = 0x3f3f3f3f;//表示无穷大
		double static temp2;
		for (int j = 0; j != mean_number; ++j)
		{
			if (min_distance > get_distxyz(basic_data[i], means[j]))
			{
				//选距离最近的簇中心作为中心
				min_distance = get_distxyz(basic_data[i], means[j]);
				temp2 = j;
			}
		}
		result_data[temp2].push_back(basic_data[i]);
	}
}

//得到每一个簇的方差
void K_means::get_k_mean_erro()
{
	vector<float> square_error;
	for (int j = 0; j < mean_number; j++)
	{
		float sum = 0;//方差
		int num = result_data[j].size();//方差的被除数，得到均方差

		vector<Tuple> A_mean = result_data[j];
		Tuple basemean = means[j];

		for (int i = 0; i < num; i++)
		{
			sum += pow(get_distxyz(A_mean[i], basemean), 2);
		}
		float result = sum / num;
		mea_square_error[j] = result;
	}
}



//计算最后的聚类结果

void K_means::get_fina_result_data()
{
	//初始化
	prime_k_meansbase();
	get_k_means();
	get_k_mean_erro();//得到每一个簇的方差

	int i = 1;
	while (i)
	{
		i = 0;
		vector<float> last_k_mean_erro = mea_square_error;
		get_basemean();//得到当前每个簇的中心
		get_new_k_means();//得到新的聚类
		get_k_mean_erro();//得到每一个簇的方差

		for (int j = 0; j != mean_number; ++j)
		{
			cout << mea_square_error[j] << '\t' << last_k_mean_erro[j] << endl;
			if (mea_square_error[j] != last_k_mean_erro[j])
			{
				i = 1;

			}
		}
	}

	//打印分类结果
	for (int j = 0; j != mean_number; ++j)
	{
		cout << "****************************************************************" << endl;
		for (vector<Tuple>::iterator m = result_data[j].begin(); m != result_data[j].end(); ++m)
		{
			cout << (*m).x << '\t' << "w" << (*m).y << endl;
		}

	}

}

void test()
{
	vector<Tuple> basic_data_test;
	Tuple temp_data;
	double x = 0, y = 0;
	int k;//分类数量
	int n;//样本数量
	cout << "请输入类别数量:" << endl;
	cin >> k;
	cout << "请输入数据量" << endl;
	cin >> n;
	for (int i = 0; i != n; ++i)
	{
		cout << "请输入x,y" << endl;
		cin >> x >> y;
		temp_data.x = x;
		temp_data.y = y;
		basic_data_test.push_back(temp_data);

	}
	K_means a(basic_data_test, k);
	a.get_fina_result_data();
}

int main()
{
	test();
	return 0;
}