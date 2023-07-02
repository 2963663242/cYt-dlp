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

	//����Home·��
	Py_SetPythonHome(wStrExeDir.c_str());

	//��ʼ��
	Py_Initialize();

	//���������в���
	PyObject* sys = PyImport_ImportModule("sys");
	PyObject* arglist = PyList_New(argc);
	for (int i = 0; i < argc; i++) {
		PyObject* arg = PyUnicode_DecodeFSDefault(argv[i]);
		PyList_SetItem(arglist, i, arg);
	}
	PyObject_SetAttrString(sys, "argv", arglist);
	Py_DECREF(arglist);
	Py_DECREF(sys);

	//����Ŀ�꺯��
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


	//�ͷ���Դ
	Py_Finalize();

	return 0;
}