#include<vector>
using namespace std;


struct Tuple
{
	float x;
	float y;

};//����ֻ����������γ�ȶ���Ϊ��ά����ʵ�Ͽ���Ϊ����������γ�ȣ������ö�̬��������ʾ

class K_means
{
private:
	vector<Tuple> basic_data;//��ʼ����
	int mean_number;//k��ֵ
	vector<vector<Tuple>> result_data;//{ mean_number };//�������,Ҳ���������м��������
	vector<Tuple> means;//�м���㴢��ľ�������
	vector<float> mea_square_error;//ÿ���صľ�����


public:
	K_means(vector<Tuple> basic_data, int mean_number) : result_data(mean_number), mea_square_error(mean_number)
	{
		this->basic_data = basic_data;
		this->mean_number = mean_number;
	}
	//�������ľ�����
	void get_fina_result_data();

private:
	//�����������ľ���
	float get_distxyz(Tuple tuple1, Tuple tuple2);
	//��ʼ��k����������
	void prime_k_meansbase();
	//��ʼ���õ�k����
	void get_k_means();
	//�õ���ǰÿ����������
	void get_basemean();
	//�õ��µĴ�
	void get_new_k_means();
	//�õ�ÿһ���صķ���
	void get_k_mean_erro();



};
