using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyToolCSharp
{
    public class MToolCSharp
    {
        static System.Threading.Mutex mutex;
        public static void RunUnique(string name="")
        {
            try
            {
                /*保证当前是唯一启动的程序*/
                if (0 == name.Count())
                {
                    string exeDir = System.Windows.Forms.Application.ExecutablePath;
                    name = System.IO.Path.GetFileNameWithoutExtension(exeDir);
                }
                mutex = new System.Threading.Mutex(true, name);
                if (!mutex.WaitOne(0, false))
                {
                    /*关闭当前*/
                    System.Windows.Application.Current.Shutdown();
                }
                else
                {
                    mutex.ReleaseMutex();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("set RunUnique fail {0}", ex.Message);
                throw ex;
            }
        }
        public static void AutoRun()
        {
            try
            {
                string exeDir = System.Windows.Forms.Application.ExecutablePath;
                RegistryKey rgkRun = Registry.LocalMachine.OpenSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", true);
                if (rgkRun == null)
                {
                    rgkRun = Registry.LocalMachine.CreateSubKey("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run");
                }
                rgkRun.SetValue(System.IO.Path.GetFileNameWithoutExtension(exeDir), exeDir);
            }
            catch (Exception ex)
            {
                Console.WriteLine("set AutoRun fail {0}", ex.Message);
            }
        }
    }
}
