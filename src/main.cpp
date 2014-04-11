/// @brief ���в��е����㷨ͳһ����ǰ��
///
/// -np ���̸�����-hostfile ����ڵ���Ϣ��-alg �㷨���ƣ�
/// -par ���ֲ��ԣ�-sch ���Ȳ��ԣ�[options...]�����㷨������
///
/// @ref AlgFactoryMan����-alg������@ref ParFactory����-par������
/// @ref SchFactory����-sch������@ref AlgFactory������Щ������
/// �㷨������������㷨�����������
/// 
/// hpgc framework��������ָ������ִ����Ӧ�����㷨��
/// ����Ӧ��Ϣû��ָ����ʹ��Ĭ��ֵ�������������˳�ִ�С�

#include "HpgcVectorAlgorithm.h"
#include "test.h"
#include "EfcPartition.h"
#include "P2pScheduler.h"
#include "vector.metadata.h"

using namespace hpgc;

int main(int argc, char ** argv)
{
	auto partition = new EfcPartition();
	auto scheduler = new P2pScheduler();
	auto vct = new Test();

	auto alg = new HpgcVectorAlgorithm(vct,scheduler,partition);

	alg->Run();

	return 1;
}