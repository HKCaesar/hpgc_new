/**
* @file hpgc.h
* @brief ����hpgc framework�����ֽӿ�
*
* hpgc framework ��Ŀ����Ϊ�˼򻯸����ܵ����㷨�Ŀ����Ѷȣ�ʹ�����㷨ͨ��ʵ��һЩ�ӿڲ��л���
* Ϊ�����úͽ������������hpgc framework �����Partiton, Scheduler, HpgcAlgotithm, AlgFactory�������
* Partition�������ݻ��֣�Scheduler������̵��ȣ�HpgcAlgorithm��װһ�������㷨��AlgFactory���ڴ���һ�������㷨��
* hpgc framework ������MPI��GDAL���֮�ϣ�ϣ���ﵽ����Ŀ�ģ�
* ��1�����㷨ͨ��ʵ����Щ�ӿڿ��Ժ����׵Ľ��벢�п����ȥ��
* ��2�����д�����̵���ģʽ�������չ��
* ��3�����ݻ��ֲ����������չ��
* ��4����������ܵ�������װMPI����MPI�ĵ��ù��̡�
*
* @author mongogis@gmail.com
* @version 0.1
* @date 2014
*/


#include <list>
#include <stdlib.h>

/// @brief ����hpgc framework �Ǽܡ�
///
/// �����ռ�hpgc��ֻframework�Ǽ���Ķ�����Ϊ���е����㷨�����õĲ��֡�
/// ��MPIObject, framework�Ĺ����ӿڣ���������㷨��ʵ�ֵ��಻���������С�
namespace hpgc
{
	
class Role
{

};

class Process
{
	Role role;
	public:
	bool isRole(Role role);
};

class MetaData
{
	public:
};

class Cellar
{

};

class Barrel
{
public:


};

class GeoAlgorithm{
public:
	bool Computing();
};

class Scheduler
{
	std::list<Role> roles;
	std::list<Process> processes;
	std::list<Cellar> cellars;
public:
	void Start();
};

class SchFactory
{
public:
	Scheduler * Create(int argc, char ** argv);
};

/// @brief ���ݻ���ʵ��ִ����
/// 
/// Partition���������ݻ��ֳ��ӿ飬ÿ���ӿ�ʹ��Barrel���������������������Cellar�С�
/// Partitionͨ������Ԫ���ݻ������ݣ����廮�ֹ�������������ɡ�
class Partition
{
public:
	Cellar * Partitioning();
};

class ParFactory
{
public:
	Partition * Create(int argc, char ** argv);
};
/// @brief ���е����㷨����Scheduler��Partition��GeoAlgorithm����
///
/// HpgcAlgorithm�ǲ����㷨��������������࣬�ǲ����㷨��ʵ��ִ���ߣ������Ų��е����㷨��
/// HpgcAlgorithm����Ҫ�ķ�����@ref Run, �䰴��һ����˳����֯�㷨�����ֵĵ��á�
class HpgcAlgorithm
{
private:
	Scheduler m_scheduler;
	Partition m_partition;
	GeoAlgorithm m_geoalgorithm;
protected:
	virtual bool init();
	virtual bool PreAlg();
public:
	std::list<Barrel> Cellar;
	bool Run()
	{
		/// @todo ��̬��������

		// �㷨�������� init();
		// ����׼�� PreAlg();
		// ���ݻ��� Cellar=m_partition.partitioning();
		// ���̵��� m_scheduler.start();
	};
};

/// @brief ���������в���ʵ�������е����㷨
/// 
/// AlgFactory���ȶԲ�������Ԥ�ж�@ref ParaValidation, ���������˳���
/// ��AlgFactory����Ҫ�Ĺ�����ʵ������Ӧ�Ĳ��е����㷨(@ref HpgcAlgorithm)�����һ�������㷨
/// ���ݻ��ֲ���(@ref ParFactory)�ͽ��̵��Ȳ���(@ref SchFactory)�Ľ�����ѡ��
/// 
/// ÿ�������㷨����ʵ�����Ӧ��factory���̳���AlgFactory������д��Ӧ���㷨����������
/// ÿ�������㷨��factory����ָ��һ������Ψһ�ı�ʶ��(ID)�Լ�����(Name),
/// hpgc framework�����㷨�ı�ʶ���������ʶ��͵�����Ӧ�㷨��
class AlgFactory
{
protected:
	virtual bool ParaValidation(int argc, char ** argv); ///< ������֤�������
public:
	long GetID();
	bool SetID();

	char * GetName();
	bool SetName();

	char *	GetDescription();
	bool SetDescription();

	HpgcAlgorithm * Create(int argc, char ** argv)
	{
		// ������֤ ParaValidation
		// ���̵��Ȳ��Խ�����scheduler = SchFactory.Create(argc,argv);
		// ���ݻ��ֲ��Խ�����partition = ParFactory.Create(argc,argv);
		// ʵ�������е����㷨��HpgcAlgorithm hpgcAlgorithm = new HpgcScanline(); HpgcScanline��HpgcAlgorithm����
	};
	AlgFactory();
};

/// @brief ���������в����ҳ���Ӧ�����㷨�Ĵ�������
///
/// ServiceCenter��ά��һ������hpgc framework��֧�ֵĲ����㷨���������м�¼��ÿ���㷨�ı�ʶ������ơ�
/// ServiceCenter���ݴ��������ͨ�������㷨������ʵ������Ӧ�����㷨�Ĵ���������
/// hpgc frameworkͨ��ServiceCenter�����Ʋ������ʽ��̬��ά����֧�ֵĲ��е����㷨��
class ServiceCenter
	{
	private:
		std::list<AlgFactory *> m_factory_list;
		static ServiceCenter * m_instance;
		ServiceCenter();
	public:
		bool AddFactory(AlgFactory *);
		bool RemoveFactory(char * );
		static AlgFactory * Create(int argc, char ** argv)
		{
			// ����m_factory_list���ҳ���Ӧ��AlgFactory
		};
	};

}