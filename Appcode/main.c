/********************************************************************
���ߣ�Songyimiao
��������: 20151129
�汾��V2.0
����ʵ���Ұ�Ȩ����
/********************************************************************/
#include "includes.h"

/***************************************************************
** ����  ��: Songyimiao
** ��    ����http://www.miaowlabs.com
** ��    ����http://miaowlabs.taobao.com
** �ա�  ��: 2015��11��29��
** ��������: main()
** ��������: ������            
** �䡡  ��:   
** �䡡  ��:   
** ��    ע: 
********************����ʵ���Ұ�Ȩ����**************************
***************************************************************/
void main()
{
	DisableInterrupts;//��ֹ���ж�

	CLK_DIV_1();	  //����MCU����Ƶ��Ϊ�ڲ�RCʱ��
	DriversInit();	
	MPU6050Init();	
	CarStandInit();
	
	Delaynms(1000);	 //��ʱ1s
	ON_LED0;
	Delaynms(3000);	 //��ʱ3s
									
	EnableInterrupts;//�������ж�	 

	while(1)
	{ 
		 
	BluetoothControl();
						 
#if DEBUG_UART  //�������� Ԥ��������

   	OutData[0] = g_fCarAngle;
   	OutData[1] = g_fGravityAngle;
   	OutData[2] = g_fGyroAngleSpeed ;
   	OutData[3] = 45;  
   	OutPut_Data();		
		 	  
#endif	 		
					
	}
}