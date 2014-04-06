#include "hpgc.h"
using namespace hpgc;

/// @brief ���в��е����㷨ͳһ����ǰ��
///
/// -np ���̸�����-hostfile ����ڵ���Ϣ��-alg �㷨���ƣ�
/// -par ���ֲ��ԣ�-sch ���Ȳ��ԣ�[options...]�����㷨������
///
/// @ref ServiceCenter����-alg������@ref ParFactory����-par������
/// @ref SchFactory����-sch������@ref AlgFactory������Щ������
/// �㷨������������㷨�����������
/// 
/// hpgc framework��������ָ������ִ����Ӧ�����㷨��
/// ����Ӧ��Ϣû��ָ����ʹ��Ĭ��ֵ�������������˳�ִ�С�
void main(int argc, char ** argv)
{
	AlgFactory * pfactory = ServiceCenter.Create(argc, argv);
	HpgcAlgorithm * palg = pfactory->Create(argc, argv);
	palg->Run();
}