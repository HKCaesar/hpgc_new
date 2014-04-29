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
#include "vector.metadata.h"
#include "M2sScheduler.h"

#include <mpiobject.h>
#include <geoalgorithm.format.h>
#include "port.debug.h"

using namespace hpgc;

int main(int argc, char ** argv)
{
	BUG("ok");

	MPIObject::CreateMPI(argc, argv);
	MPIObject mo;

	BUG("ok1");

	const char * pszSrcFile;
	const char * pszDstFile;


	for (int i = 1; i < argc; i++)
	{
		if (EQUAL(argv[i], "-s") && i < argc - 1)
		{
			pszSrcFile = argv[++i];
		}

		else if (EQUAL(argv[i], "-d") && i < argc - 1)
		{
			pszDstFile = argv[++i];
		}
	}

	BUG(pszDstFile);
	BUG(pszSrcFile);

	auto metadata = new VectorMetaData(pszSrcFile, pszDstFile);
	auto partition = new EfcPartition(2);
	auto scheduler = new M2sScheduler();
	auto vct = new Test();
	auto alg = new HpgcVectorAlgorithm(vct,scheduler,partition,metadata);

	alg->Run();

	MPIObject::DestoryMPI();

	return 0;
}