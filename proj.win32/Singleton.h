#ifndef __SINGLETON_H__
#define __SINGLETON_H__

//µ¥ÀýÄ£°å
template <class T>
class Singleton
{
public:
	static T* getInstance()
	{
		if (!_pInstance) 
		{ 
			_pInstance = new T(); 
			_pInstance->init(); 
		} 
		return _pInstance;
	}
	virtual bool init() { return true; }
	Singleton(){}
protected:
	static T *_pInstance;
};

template <class T>
T *Singleton<T>::_pInstance = NULL;

#endif