
#include "tinyxml2.h"  
#include <iostream>  
 
using namespace tinyxml2 ; 


/*
xml文件工具   作者: sam 2017/4/26
命令格式 ./xmlproc.exe test.xml dest.xml 
从xml文件argv[1]读取，语法分析，过滤，将排版内容写入指定文件argv[2]中 ; 
（VSCode + MinGW64为调试环境）
*/
int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Command: ./xmlproc.exe Src.xml Dest.xml \r\n!");
        return 0;
    }

    char src[250],dest[250];

    strcpy(src, argv[1]);
    strcpy(dest, argv[2]);

    /*
    string src1(""), dest1("");
    src1 = argv[1];    dest1 = argv[2];

    for (int i= 0 ; i<= src1.size(); i++) src[i] = src1[i]
    */

    tinyxml2::XMLDocument  doc;  
	doc.LoadFile (src);  

	tinyxml2::XMLPrinter visitor;

    doc.Print(&visitor) ;
	doc.SaveFile(dest)	;

    return 1;
}