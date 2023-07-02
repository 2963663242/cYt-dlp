#include <Windows.h>
#include <iostream>
#include <python/Python.h>

using namespace std;

int main(int argc,char ** argv) {

	wstring wStrExeDir;
	wchar_t wszExeName[MAX_PATH] = { 0, };

	::GetModuleFileNameW(NULL, wszExeName, MAX_PATH);
	wStrExeDir = wszExeName;
	wStrExeDir = wStrExeDir.substr(0, wStrExeDir.find_last_of(L"\\"));

	//设置Home路径
	Py_SetPythonHome(wStrExeDir.c_str());

	//初始化
	Py_Initialize();

	//传递命令行参数
	PyObject* sys = PyImport_ImportModule("sys");
	PyObject* arglist = PyList_New(argc);
	for (int i = 0; i < argc; i++) {
		PyObject* arg = PyUnicode_DecodeFSDefault(argv[i]);
		PyList_SetItem(arglist, i, arg);
	}
	PyObject_SetAttrString(sys, "argv", arglist);
	Py_DECREF(arglist);
	Py_DECREF(sys);

	//调用目标函数
	char* result;
	PyObject* pModule = PyImport_ImportModule("yt_dlp");
	if (pModule == NULL) {
		PyErr_Print();
		cout << "module not found" << endl;
		return -1;
	}

	PyObject* pFunc = PyObject_GetAttrString(pModule, "main");
	if (!pFunc || !PyCallable_Check(pFunc)) {
		PyErr_Print();
		cout << "not found function init" << endl;
		return -1;
	}

	PyObject* pReturn = PyObject_CallObject(pFunc, NULL);
	PyErr_Print();


	//释放资源
	Py_Finalize();

	return 0;
}