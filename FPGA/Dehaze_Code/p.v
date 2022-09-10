`timescale 1ns / 1ns
 module p #(
// --------------------------------------------------------------------------
// Parameters
// --------------------------------------------------------------------------
 )
 (
  // Inputs
  input  wire                     CLK         ,
  input  wire [AW-1:0]     ADDR      ,
  input  wire [31:0]          WDATA   ,
  input  wire [3:0]            WREN     ,
  input  wire                    CS           ,

  // Outputs
  output wire [31:0]   RDATA
  );

module p;
 
integer iBmpFileId,iOutFileId,iIndex=0,iCode,a,i,j,ii,filter=3,offset,th=210,k=214;
//iBmpField:�账��ͼ����ļ�·����iOutFileId:�����ͼ���������ļ�·����a:������ֵ��filter:�˲�����ȣ�offsetΪ�˲����м���Ǹ�Ԫ�أ�th:Ϊһ����������   �ĳ�����k:һ������
//�˲�����СΪ3*3
//���㷨���߼������ȶ�ԭͼ��rBmpData ���а�ͨ�������õ���ͨ��ͼdarkchannel���ٶ԰�ͨ��������Сֵ�˲����õ���Сֵ�˲���İ�ͨ��ͼdark��

reg [7:0] rBmpData [0:2000000];
//rBmpDataΪ�洢δ����ͼ������飬��СΪiBmpSize��������ͷ��ͼƬ�����Ϣ���ܺͺ����ͼƬ���������ݣ�ͼƬ�������ݵ���ʼ��ַΪiDataStartIndex
//��һ��α��λ���飬���Ϊ������Ϊһ�����ص�ռ�����ֽڣ������ΪiBmpWidth������ΪiBmpHight

reg [7:0] darkchannel[0:445600];//darkchannelΪ��Ŵ����İ�ͨ��ͼ������飬��һ��α��ά����
reg [7:0] dark[0:445600];//�԰�ͨ��������Сֵ�˲����õ���Сֵ�˲���İ�ͨ��ͼdark�Ĵ�����飬��һ��α��ά���飬��С��darkchannel��ͬ
reg [7:0] temp;              //��ȡ��ͨ��ͼʱ���м����
reg [31:0] rBmpCom; //���ʱ������ʱ����
reg rClk;
reg [7:0] rData;
integer iBmpWidth,iBmpHight,iDataStartIndex,iBmpSize,iBmpType;
 


initial begin                                                          //��ȡͼƬ������Ϣ
	iBmpFileId = $fopen("C:\\Users\\86159\\Desktop\\6.bmp","rb+");
	iCode = $fread(rBmpData,iBmpFileId);//��·���е��ļ�ͼƬ��Ϣ���뵽rBmpData��

	iBmpWidth = {rBmpData[21],rBmpData[20],rBmpData[19],rBmpData[18]};//��ȡͼƬ��ʵ���ݵĿ��
	iBmpHight = {rBmpData[25],rBmpData[24],rBmpData[23],rBmpData[22]};//��ȡͼƬ��ʵ���ݵĳ���
	iDataStartIndex = {rBmpData[13],rBmpData[12],rBmpData[11],rBmpData[10]};//��ȡͼƬ��ʵ���ݵ���ʼ��ַ
	iBmpSize = {rBmpData[5],rBmpData[4],rBmpData[3],rBmpData[2]};//��ȡͼƬ��ʵ���ݵĴ�С
	iBmpType = {rBmpData[29],rBmpData[28]};//��ȡͼƬ��ʵ���ݵ�����
	$fclose(iBmpFileId);
end



always@(*)begin
	for (iIndex = iDataStartIndex; iIndex < iBmpSize; iIndex = iIndex + 3) begin
        //�Ƚ�ÿ�����ص��������ֽ��е���Сֵ������Сֵ���ɰ�ͨ��ͼ��Ӧ�ĵ�darkchannel[(iIndex-iDataStartIndex)/3]
		if(rBmpData[iIndex+2]>rBmpData[iIndex+1]) temp=rBmpData[iIndex+1];
		else temp=rBmpData[iIndex+2];
		
		if(rBmpData[iIndex]>temp) begin darkchannel[(iIndex-iDataStartIndex)/3]=temp; // rBmpData[iIndex]=temp;  rBmpData[iIndex+2]=0;rBmpData[iIndex+1]=0;
		end
		else begin darkchannel[(iIndex-iDataStartIndex)/3]=rBmpData[iIndex];// rBmpData[iIndex+2]=0;rBmpData[iIndex+1]=0; 
		end
	end
	//get darkchannel image
	
	
	a=0;i=0;
	
	for (ii = 0; ii <= iBmpWidth-filter; ii = ii + 1) begin
	//����ѭ��,j��������ii��������iIndex�ǰ�ͨ��ͼ�еĶ�Ӧ����
		for(j=0;j<=iBmpHight-filter;j=j+1) begin
		iIndex=j*iBmpWidth+ii;
		offset=iIndex+(filter-filter%2)/2*(iBmpWidth+1);
		temp=darkchannel[iIndex];
		if(temp>darkchannel[iIndex+1]) temp=darkchannel[iIndex+1];
		if(temp>darkchannel[iIndex+2]) temp=darkchannel[iIndex+2];
		if(temp>darkchannel[iIndex+iBmpWidth]) temp=darkchannel[iIndex+iBmpWidth];
		if(temp>darkchannel[iIndex+iBmpWidth+1]) temp=darkchannel[iIndex+iBmpWidth+1];
		if(temp>darkchannel[iIndex+iBmpWidth+2]) temp=darkchannel[iIndex+iBmpWidth+2];
		if(temp>darkchannel[iIndex+iBmpWidth*2]) temp=darkchannel[iIndex+iBmpWidth*2];
		if(temp>darkchannel[iIndex+iBmpWidth*2+1]) temp=darkchannel[iIndex+iBmpWidth*2+1];

		if(temp>darkchannel[iIndex+iBmpWidth*2+2]) dark[offset]=darkchannel[iIndex+iBmpWidth*2+2];
		else  dark[offset]=temp;
		
		if(dark[offset]>th)begin i=i+1;a=a+rBmpData[offset*3+ iDataStartIndex]+rBmpData[offset*3+1+iDataStartIndex]+rBmpData[offset*3+ iDataStartIndex+2];end
		
		end
	end
	
	a=a/i/3;//������ֵ
	
	
	
	
	for(iIndex=(filter-filter%2)/2*(iBmpWidth+1);iIndex <= iBmpWidth*(iBmpHight-filter)+(iBmpWidth-filter)+(filter-filter%2)/2*(iBmpWidth+1);iIndex=iIndex+1)begin			
			darkchannel[iIndex]=256-k*dark[iIndex]/a;//��������͸����
	end
	
	
	//�?小�?�滤波之后的darkchannel
	

	
	for (iIndex = iDataStartIndex; iIndex < iBmpSize; iIndex = iIndex + 3) begin  
	
		if(a>rBmpData[iIndex  ])begin rBmpData[iIndex  ]= (a-((a-rBmpData[iIndex])<<8)/darkchannel[(iIndex-iDataStartIndex)/3]);end
		else  begin rBmpData[iIndex  ]= (a+((rBmpData[iIndex]-a)<<8)/darkchannel[(iIndex-iDataStartIndex)/3]);end
		
		
		if(a>rBmpData[iIndex+1])begin rBmpData[iIndex+1]= (a-((a-rBmpData[iIndex+1])<<8)/darkchannel[(iIndex-iDataStartIndex)/3]);end
		else  begin rBmpData[iIndex  ]= (a+((rBmpData[iIndex]-a)<<8)/darkchannel[(iIndex-iDataStartIndex)/3]);end
		
		if(a>rBmpData[iIndex+2])begin rBmpData[iIndex+2]= (a-((a-rBmpData[iIndex+2])<<8)/darkchannel[(iIndex-iDataStartIndex)/3]);end
		else  begin rBmpData[iIndex  ]= (a+((rBmpData[iIndex]-a)<<8)/darkchannel[(iIndex-iDataStartIndex)/3]);end
		/*
		 rBmpData[iIndex  ]=0;
		 rBmpData[iIndex+1]=darkchannel[(iIndex-iDataStartIndex)/3];
		 rBmpData[iIndex+2]=0;
			*/
		
		      
	end
	
	
	iOutFileId = $fopen("C:\\Users\\86159\\Desktop\\output1.bmp","wb+");
	
	for (iIndex = 0; iIndex < iBmpSize; iIndex = iIndex + 4) begin
		rBmpCom = {rBmpData[iIndex+3],rBmpData[iIndex+2],rBmpData[iIndex+1],rBmpData[iIndex]};
		$fwrite(iOutFileId,"%u",rBmpCom);
	end 
	$fclose(iOutFileId);
	
end

 
endmodule