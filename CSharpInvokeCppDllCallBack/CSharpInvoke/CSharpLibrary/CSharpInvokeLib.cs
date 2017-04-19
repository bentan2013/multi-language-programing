using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;//必须的

namespace CSharpLibrary
{
    public class CSharpInvokeLib
    {

        [DllImport("C:\\projects\\CSharpInvokeCppDllCallBack\\CSharpInvoke\\Release\\CppDll.dll", EntryPoint = "AddCalc")]      //"WebService.dll"为dll名称,UserLogin 为函数名
        //        [DllImport("C:\\projects\\CSharpInvokeCppDllCallBack\\CppDll\\Release\\CppDll.dll")]      //"WebService.dll"为dll名称,UserLogin 为函数名
        static extern public int AddCalc(int plus1, int plus2);


        //声明
        public delegate void MyDllCall(string buf, int size);

        //设置回调函数
        [DllImport("C:\\projects\\CSharpInvokeCppDllCallBack\\CSharpInvoke\\Release\\CppDll.dll", EntryPoint = "SetCallback")]
        //        [DllImport("C:\\projects\\CSharpInvokeCppDllCallBack\\CppDll\\Release\\CppDll.dll", EntryPoint = "SetCallback")]
        static extern public bool SetCallback(MyDllCall fa);


    }
}
