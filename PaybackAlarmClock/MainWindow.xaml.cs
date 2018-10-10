using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using PaybackAlarmClock.database;
using MySql.Data.MySqlClient;
using System.Diagnostics;

namespace PaybackAlarmClock
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        MySqlHandle m_sql=new MySqlHandle();
        public MainWindow()
        {
            InitializeComponent();
        }

        private void itm_btn_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                MySqlDataReader reader = m_sql.ExeQuery("select * from voice_2018");
                string result = "";
                while (reader.Read())
                {
                    for (int i = 0; i < reader.FieldCount; i++)
                    {
                        result += reader.GetName(i) + "\t" + reader.GetValue(i) + "\r\n";
                    }
                }
                Console.WriteLine("查询结果为:\r{0}", result);
            }
            catch(Exception ex)
            {
                Debug.WriteLine("\r{0}\r{1}\r", ex.Message, ex.StackTrace);
            }
        }

        private void home_radiobtn_Checked(object sender, RoutedEventArgs e)
        {
            try
            {
                if (null != main_tabcotrol)
                {
                    main_tabcotrol.SelectedIndex = (int)PACEnum.Page.MainPage;
                }
            }
            catch(Exception ex)
            {
                Debug.WriteLine("\r{0}\r{1}\r", ex.Message, ex.StackTrace);
            }
        }

        private void config_radiobtn_Checked(object sender, RoutedEventArgs e)
        {
            try
            {
                if (null != main_tabcotrol)
                {
                    main_tabcotrol.SelectedIndex = (int)PACEnum.Page.ConfigPage;
                }
            }
            catch (Exception ex)
            {
                Debug.WriteLine("\r{0}\r{1}\r", ex.Message, ex.StackTrace);
            }
        }
    }
}
