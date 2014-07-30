#ifndef _JSONX_H_
#define _JSONX_H_

#include "cocos2d.h"

#include "rapidjson.h"
#include "document.h"
#include "writer.h"
#include "prettywriter.h"
#include "stringbuffer.h"

static const char *kTypeNames[] = { "NULL", "False", "True", "Object", "Array", "String", "Number" };

//rapidjson浅封装
class JsonX
{
public:
	typedef rapidjson::Value Value;

	JsonX();
	JsonX(JsonX &other);
	JsonX(std::string file_name);
	JsonX(const char *json_str);

	bool read(std::string file_name);

	//从字符串读取json数据
	bool readFromString(const char * json_str);

	//json数据存储为文件
	bool saveToFile(std::string file_name, bool pretty = true);

	//插入键值对
	Value& insert(const char *key, Value &value);
	Value& insert(Value &key, Value &value);
	template <typename T>
	Value& insert(const char *key, T value)
	{
		Value k(key, doc.GetAllocator());
		Value v(value, doc.GetAllocator());
		return insert(k, v);
	}
	//添加数组
	Value& insertArray(const char *key);
	Value& insertArray(Value &key);
	//删除操作
	bool remove(const char *key);
	//清除数据
	void clear();
	//计算大小
	int size();

	//查找成员
	Value& find(const char *name);
	bool has(const char *key);

	//获取文档对象
	rapidjson::Document& getDocument();

	//下标操作
	Value& operator[](const char *name);
	const Value& operator[](const char *name) const;

	//获取内存分配器
	rapidjson::Document::AllocatorType& getAllocator();

private:
	rapidjson::Document doc;
};

#endif