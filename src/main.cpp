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
#include "v2vproj.h"
#include "EfcPartition.h"
#include "vector.metadata.h"
#include "M2sScheduler.h"
#include "port.debug.h"
#include "common.h"

#include <mpiobject.h>
#include <geoalgorithm.format.h>

using namespace hpgc;

int main(int argc, char ** argv) {
    hpgc::HPGCInit(argc, argv);
    const char * pszSrcFile = NULL;
    const char * pszDstFile = NULL;
    const char * pszSrcLayer = NULL;
    const char * pszDstLayer = NULL;
    for (int i = 1; i < argc; i++) {
        if (EQUAL(argv[i], "-s") && i < argc - 1) {
            pszSrcFile = argv[++i];
        }
        else if (EQUAL(argv[i], "-d") && i < argc - 1) {
            pszDstFile = argv[++i];
        }
    }
    auto metadata = new VectorMetaData(pszSrcFile, pszSrcLayer, pszDstFile,
                                       pszDstLayer);
    auto partition = new EfcPartition(2);
    auto scheduler = new M2sScheduler();
    auto vct = new V2vProj(argc, argv);
    auto alg = new HpgcVectorAlgorithm(vct, scheduler, partition, metadata);
    alg->Run();
    return 0;
}