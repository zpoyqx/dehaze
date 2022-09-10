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
//iBmpField:需处理图像的文件路径，iOutFileId:处理后图像的输出的文件路径，a:大气光值，filter:滤波器宽度，offset为滤波器中间的那个元素，th:为一个用来进行   的常数，k:一个常数
//滤波器大小为3*3
//此算法的逻辑：首先对原图像rBmpData 进行暗通道处理，得到暗通道图darkchannel，再对暗通道进行最小值滤波，得到最小值滤波后的暗通道图dark，

reg [7:0] rBmpData [0:2000000];
//rBmpData为存储未处理图像的数组，大小为iBmpSize，包含开头的图片相关信息介绍和后面的图片真正的数据，图片真正数据的起始地址为iDataStartIndex
//是一个伪三位数组，深度为三（因为一个像素点占三个字节），宽度为iBmpWidth，长度为iBmpHight

reg [7:0] darkchannel[0:445600];//darkchannel为存放处理后的暗通道图像的数组，是一个伪二维数组
reg [7:0] dark[0:445600];//对暗通道进行最小值滤波，得到最小值滤波后的暗通道图dark的存放数组，是一个伪二维数组，大小与darkchannel相同
reg [7:0] temp;              //获取暗通道图时的中间变量
reg [31:0] rBmpCom; //输出时所用临时变量
reg rClk;
reg [7:0] rData;
integer iBmpWidth,iBmpHight,iDataStartIndex,iBmpSize,iBmpType;
 


initial begin                                                          //读取图片基本信息
	iBmpFileId = $fopen("C:\\Users\\86159\\Desktop\\6.bmp","rb+");
	iCode = $fread(rBmpData,iBmpFileId);//将路径中的文件图片信息读入到rBmpData中

	iBmpWidth = {rBmpData[21],rBmpData[20],rBmpData[19],rBmpData[18]};//读取图片真实数据的宽度
	iBmpHight = {rBmpData[25],rBmpData[24],rBmpData[23],rBmpData[22]};//读取图片真实数据的长度
	iDataStartIndex = {rBmpData[13],rBmpData[12],rBmpData[11],rBmpData[10]};//读取图片真实数据的起始地址
	iBmpSize = {rBmpData[5],rBmpData[4],rBmpData[3],rBmpData[2]};//读取图片真实数据的大小
	iBmpType = {rBmpData[29],rBmpData[28]};//读取图片真实数据的类型
	$fclose(iBmpFileId);
end



always@(*)begin
	for (iIndex = iDataStartIndex; iIndex < iBmpSize; iIndex = iIndex + 3) begin
        //比较每个像素点中三个字节中的最小值，用最小值构成暗通道图对应的点darkchannel[(iIndex-iDataStartIndex)/3]
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
	//两层循环,j是行数，ii是列数，iIndex是暗通道图中的对应坐标
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
	
	a=a/i/3;//大气光值
	
	
	
	
	for(iIndex=(filter-filter%2)/2*(iBmpWidth+1);iIndex <= iBmpWidth*(iBmpHight-filter)+(iBmpWidth-filter)+(filter-filter%2)/2*(iBmpWidth+1);iIndex=iIndex+1)begin			
			darkchannel[iIndex]=256-k*dark[iIndex]/a;//里面存的是透射率
	end
	
	
	//鏈?灏忓?兼护娉箣鍚庣殑darkchannel
	

	
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