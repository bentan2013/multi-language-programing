using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;
using System.Diagnostics;
using System.IO;
using System.Threading;

using System.Runtime.InteropServices;//必须的
using CSharpLibrary;

namespace CSharpInvoke
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            // add handler
            //AppDomain.CurrentDomain.UnhandledException += new System.UnhandledExceptionEventHandler(DumpHelper.CurrentDomain_UnhandledException);
            InitializeComponent();
        }

        //声明回调的函数
        public void FunA(string buf, int size)
        {
            MessageBox.Show(buf);
            return;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //try
            //{
                //调用
                CSharpInvokeLib.SetCallback(FunA);
                // 目前对于cppdll中已经存在内存方面的错误
                int ab = CSharpInvokeLib.AddCalc(521, 31);

                // 以下的部分为测试c#中的dump文件的问题
                //string a = "";
                //a = null;
                //if (a.ToString() == "1")
                //    Console.WriteLine("a is 1");

                // 目前存在的问题，c++中捕获的错误不能反馈给c#端
            //}
            //catch
            //{
            //}
            return;
        }
    }
}
