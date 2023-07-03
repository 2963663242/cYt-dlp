#ifdef _Win32
    #include <Windows.h>
#elif defined __APPLE__
    #include <CoreFoundation/CFBundle.h>
    #include <codecvt>
#endif

#include <iostream>
#include <python/Python.h>

using namespace std;

int main(int argc,char ** argv) {
#ifdef _Win32
	wstring wStrExeDir;
	wchar_t wszExeName[MAX_PATH] = { 0, };

	::GetModuleFileNameW(NULL, wszExeName, MAX_PATH);
	wStrExeDir = wszExeName;
	wStrExeDir = wStrExeDir.substr(0, wStrExeDir.find_last_of(L"\\"));
#elif defined __APPLE__
    wstring wStrExeDir;
    std::string bunddlePath;
    char resourcePath[PATH_MAX];
    CFURLRef resourceURL = CFBundleCopyExecutableURL(CFBundleGetMainBundle());
    CFURLGetFileSystemRepresentation(resourceURL, true,
                                    (UInt8 *)resourcePath,PATH_MAX);
    bunddlePath = resourcePath;
    bunddlePath = bunddlePath.substr(0,bunddlePath.find_last_of("/"));
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    wStrExeDir = converter.from_bytes(bunddlePath);
#endif
	//??Home·??
	Py_SetPythonHome(wStrExeDir.c_str());
    
   
	//??ʼ??
	Py_Initialize();
    
    
    PyObject* sys = PyImport_ImportModule("sys");
    PyObject* path = PyObject_GetAttrString(sys, "path");
    PyList_Insert(path, 0, PyUnicode_FromWideChar(wStrExeDir.c_str(), wStrExeDir.size()));

	//???????в??
	
	PyObject* arglist = PyList_New(argc);
	for (int i = 0; i < argc; i++) {
		PyObject* arg = PyUnicode_DecodeFSDefault(argv[i]);
		PyList_SetItem(arglist, i, arg);
	}
	PyObject_SetAttrString(sys, "argv", arglist);
	Py_DECREF(arglist);
	Py_DECREF(sys);
	Py_DECREF(path);

	//???Ŀ?꺯?
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


	//?????
	Py_Finalize();

	return 0;
}
