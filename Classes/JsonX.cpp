//
//  JsonX.cpp
//  test-json
//
//  Created by 游戏程序 on 14-6-6.
//
//

#include "JsonX.h"

USING_NS_CC;

JsonX::JsonX()
{
    doc.SetObject();
}

JsonX::JsonX(std::string file_name)
{
    read(file_name);
}

JsonX::JsonX(const char *json_str)
{
	readFromString(json_str);
}

bool JsonX::read(std::string file_name)
{
	unsigned long size;
    unsigned char *data = CCFileUtils::sharedFileUtils()->getFileData(file_name.c_str(), "r", &size);
    if(data) return false;
    readFromString((char*)data);
    return true;
}

bool JsonX::readFromString(const char *json_str)
{
    doc.Parse<0>(json_str);
    if(doc.IsNull()) return false;
    return true;
}

bool JsonX::saveToFile(std::string file_name)
{
    if(CCFileUtils::sharedFileUtils()->isFileExist(file_name))
        return false;
    if(!CCFileUtils::sharedFileUtils()->isAbsolutePath(file_name))
        file_name += CCFileUtils::sharedFileUtils()->getWritablePath();
    
    FILE *fp = NULL;
    if( !(fp = fopen(file_name.c_str(), "w")) )
        return false;
    
    rapidjson::StringBuffer buf;
    rapidjson::PrettyWriter<rapidjson::StringBuffer> w(buf);
    doc.Accept(w);
    fwrite(buf.GetString(), 1, buf.Size(), fp);
    fclose(fp);
    return true;
}

JsonX::Value& JsonX::insert(Value &key, Value &value)
{
    return doc.AddMember(key, value, doc.GetAllocator());
}

JsonX::Value& JsonX::insert(const char *key, Value &value)
{
	Value k(key, doc.GetAllocator());
	return insert(k, value);
}

JsonX::Value& JsonX::insertArray(const char *key)
{
	Value k(key, doc.GetAllocator());
    Value v(rapidjson::kArrayType);
    return insert(k, v);
}


JsonX::Value& JsonX::insertArray(Value &key)
{
    Value v(rapidjson::kArrayType);
    return insert(key, v);
}

bool JsonX::remove(const char *key)
{
    return doc.RemoveMember(key);
}

rapidjson::Document::AllocatorType& JsonX::getAllocator()
{
    return doc.GetAllocator();
}

JsonX::Value& JsonX::operator[](const char *name)
{
    return doc[name];
}

const JsonX::Value& JsonX::operator[](const char *name) const
{
    return doc[name];
}

rapidjson::Value& JsonX::find(const char *name)
{
	return doc[name];
}

bool JsonX::has(const char *key)
{
	return doc.HasMember(key);
}

rapidjson::Document& JsonX::getDocument()
{
	return doc;
}

void JsonX::clear()
{
	//删除将导致迭代器失效
	for (auto iter = doc.MemberonBegin(); iter != doc.MemberonEnd(); iter = doc.MemberonBegin())
		remove(iter->name.GetString());
}

int JsonX::size()
{
	int size = 0;
	for (auto iter = doc.MemberonBegin(); iter != doc.MemberonEnd(); iter++)
		size += 1;
	return size;
}

JsonX::JsonX(JsonX &other)
{
	doc.SetObject();
	rapidjson::StringBuffer buf;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buf);
	other.getDocument().Accept(writer);
	readFromString(buf.GetString());
}

