#include "MsgSub.h"
#include "cqp.h"
#include <string.h>
//����ȫ�ֱ��� ac   ��appmain.h �ж���
extern int ac;


void GroupMsgSub::threadMain()
{
	while (!m_quit)
	{
		if (m_groupMsgBuffer.size() > 0)
		{
			m_mutex.lock();
			GroupMsg msg = m_groupMsgBuffer.front();
			m_groupMsgBuffer.pop();
			m_mutex.unlock();
			
			
			if (msg.msg=="test!!!")
			{
				CQ_sendGroupMsg(ac, msg.fromGroup, "��Ӧ���Գɹ���c++���µ�һ��");
			}
			else if (msg.msg == "����С����") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "wwwwww");
			}
			else if (msg.msg == "С����" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "���˺ã�����Ҳ������");
			}
			else if (msg.msg == "!stats me" && msg.fromQQ == 982957484) {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��...���ˣ����Ҳ������Stats�� QAQ");
			}
			else if (msg.msg == "!stats me") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Stats����д�ˣ��ȸ�Mc����·��");
			}


		/*
				#######################�����Ⱥ����ϰ��##############			
		
																					*/

			
			else if (msg.msg == "�� ���ϰ� ��") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���ϰ� ��");
				CQ_sendPrivateMsg(ac, 416575098, "�� ���ϰ� ��");
			}
			else if (msg.msg == "�� ���ϰ� ��") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "�� ���ϰ� ��");
				CQ_sendPrivateMsg(ac, 416575098, "�� ���ϰ� ��");
			}
			else if (msg.msg == "�Ⱥ����ϰ�") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Ůװ  ���ϰ�  Ůװ");
			}
			else if (msg.msg == "�Ⱥ�") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��������� Ůװ����");
			}
			else if (msg.msg == "Ůװ") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "Kou��~~~~Ůװ����");
			}
			else if (msg.fromQQ == 416575098 && msg.msg == "ܳ") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "ܳ�����ϰ� ܳ��");

			}
			else if (msg.fromQQ == 416575098 && msg.msg == "��") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "? Kou�� ?");
			}
			else if (msg.fromQQ == 416575098 && msg.msg == "������") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "??? Kou�� ???");
			}
			else if (msg.msg == "!sleep") {
				//CQ_setGroupBan(ac, msg.fromGroup, fromQQ, 12000);
				CQ_sendGroupMsg(ac, msg.fromGroup, "���䤹�ߤʤ����������˘���");
			}

			/*
			
					#################### MC���߱����� ##############
			
																				*/


			else if (msg.msg == "!����������") {
				//CQ_sendGroupMsg(ac, msg.fromGroup, "��˽��InkBot���������ID");
				CQ_sendGroupMsg(ac, msg.fromGroup, "�Զ�����ϵͳ������(�Уߩ�)������ȥ�����д�ˣ��鷳���ˣ�https://docs.qq.com/form/fill/DUmVZekRqRGJUYVRp");
			}
			else if (msg.msg == "!github") { 
				CQ_sendGroupMsg(ac, msg.fromGroup, "����д�Ĵ���̫���ˣ��Ų����㿴�ء���������"); 
			}
			else if (msg.msg == "!�����ϰ�") {
				CQ_sendGroupMsg(ac, msg.fromGroup, "��(>^��^<)�����ϰ����ص�ַ�� https://cola.sayobot.cn/inkcake/Minecraft%201.12.2%20IC2%20forge2768%20Shaders.zip");
				CQ_sendGroupMsg(ac, msg.fromGroup, "ллҹ���������֧�֣�");
			}



			/* 
			
								####  ����  ###
			
																		*/
			else if (msg.msg == "���" || msg.msg == "��㣡") {
				CQ_sendPrivateMsg(ac, 982957484, "���˽��㣡");
			}
		
		}
		else
		{
			ThreadBase::mSleep(10);
		}
	}
	return;
}

GroupMsgSub::GroupMsgSub()
{
	m_quit = false;
}

GroupMsgSub::~GroupMsgSub()
{
}

void GroupMsgSub::start()
{
	m_quit = false;
	ThreadBase::start();
}

void GroupMsgSub::quite()
{
	ThreadBase::quit();
	m_quit = true;
}


void GroupMsgSub::pushMsg(int32_t msgId, int64_t fromGroup, int64_t fromQQ, std::string msg)
{
	//����������Ϣ����100��  ��ֱ�������µ�����Ϣ
	if (m_groupMsgBuffer.size() < 100)
	{
		m_mutex.lock();
		m_groupMsgBuffer.push(GroupMsg(msgId, fromGroup, fromQQ, msg));
		m_mutex.unlock();
	}
}


