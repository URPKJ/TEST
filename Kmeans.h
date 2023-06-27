#include<vector>
using namespace std;


struct Tuple
{
	float x;
	float y;

};//这里只将聚类对象的纬度定义为二维，事实上可以为任意大于零的纬度，可以用动态数组来表示

class K_means
{
private:
	vector<Tuple> basic_data;//初始数据
	int mean_number;//k的值
	vector<vector<Tuple>> result_data;//{ mean_number };//结果数据,也用来储存中间聚类数据
	vector<Tuple> means;//中间计算储存的聚类中心
	vector<float> mea_square_error;//每个簇的均方差


public:
	K_means(vector<Tuple> basic_data, int mean_number) : result_data(mean_number), mea_square_error(mean_number)
	{
		this->basic_data = basic_data;
		this->mean_number = mean_number;
	}
	//计算最后的聚类结果
	void get_fina_result_data();

private:
	//计算两个点间的距离
	float get_distxyz(Tuple tuple1, Tuple tuple2);
	//初始化k个聚类中心
	void prime_k_meansbase();
	//初始化得到k个簇
	void get_k_means();
	//得到当前每个簇类中心
	void get_basemean();
	//得到新的簇
	void get_new_k_means();
	//得到每一个簇的方差
	void get_k_mean_erro();



};
