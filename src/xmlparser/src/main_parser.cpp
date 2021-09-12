#include <iostream>

#include "tinyxml2.h"
#include "map_msg.h"
#include "header_xml_parser.h"
#include "roads_xml_parser.h"


bool LoadData(const char* xmlPath, string& strDecl) {
  XMLDocument doc;
  if (doc.LoadFile(xmlPath) != XML_SUCCESS) {
    cout << "fail to load file " << xmlPath << endl;
    return false;
  }

  //root
  XMLElement* root = doc.RootElement();  //获取根节点，即OpenDRIVE节点
  cout << "RootElement:" << root->Name() << endl;
  
  //header
  auto P_header = std::make_shared<xml_header>();
  Header_Parse(*root, P_header);

  //road
  auto P_road = std::make_shared<xml_road>();
  Road_Parse(*root, P_road);


  /*while(rootchild) {
    //获取rootchild的属性
    cout << "rootchild：" << rootchild->Name() << endl;
    const XMLAttribute * nameAttr = rootchild->FirstAttribute();
    cout<< "1:" << nameAttr->Name() << ":" << nameAttr->Value() << endl;   //road的name属性
    const XMLAttribute* idAttr = rootchild->FirstAttribute( "id" );
    //const XMLAttribute * lengthAttr = road->NextSiblingAttribute();
    //const XMLAttribute * idAttr = road->NextSiblingAttribute();
    //string roadid = idAttr->Value();   //取出road的id号

    //获取road中的planView子元素信息
    XMLElement* planViewchild = rootchild->FirstChildElement("planView");
    while(planViewchild)  
        {  
          cout << "planViewchild:" << rootchild->FirstChildElement("planView") << endl;
          XMLElement* geometry=planViewchild->FirstChildElement();
          const XMLAttribute * geometry_s = geometry->FirstAttribute();  
          cout<< "1:" << geometry_s->Name() << ":" << geometry_s->Value() << endl; 
          planViewchild =  planViewchild->NextSiblingElement();
        }  
    rootchild =  rootchild->NextSiblingElement();
  }
  */

  XMLNode* decl=doc.FirstChild(); 
    if (NULL!=decl)  
    {  
        XMLDeclaration* declaration =decl->ToDeclaration();  
        if (NULL!=declaration)  
        {  
              strDecl = declaration->Value();
              return true;
        } 
    }
    return false;
}


int main(int argc,char* argv[])
{
    //获取xml文件申明
    string strDecl;
    // string *xodrPath = argv[1]
    if(LoadData("/home/LSW/opendrive_test/map/junction_test_signals.xodr",strDecl))
    {
      cout<<"declaration:"<< strDecl <<endl;
    }
    return 0;
}