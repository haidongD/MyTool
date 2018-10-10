using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Configuration;
using System.Data;
using System.Diagnostics;

namespace PaybackAlarmClock.database
{
    public class MySqlHandle
    {
        private string conn = ConfigurationManager.AppSettings["conn"];
        private string conn_mysql = ConfigurationManager.AppSettings["conn_mysql"];
        private string database = ConfigurationManager.AppSettings["database"];
        public MySqlHandle()
        {
            try
            {
                MySqlConnection sql_conn = new MySqlConnection(conn_mysql);
                MySqlCommand cmd = new MySqlCommand("CREATE DATABASE " + database + ";", sql_conn);
                try
                {
                    sql_conn.Open();
                    cmd.ExecuteNonQuery();
                    Console.WriteLine("数据库{0}创建成功", database);
                }
                catch
                {
                    Console.WriteLine("数据库{0}已存在", database);
                }
                sql_conn.Close();
                InitTable();
            }
            catch (Exception ex)
            {
                Debug.WriteLine("\r{0}\r{1}\r", ex.Message, ex.StackTrace);
            }
        }

        /// <summary>
        /// 创建表
        /// </summary>
        private void InitTable()
        {
            try
            {
                string sql = "CREATE TABLE IF NOT EXISTS `plan` (" +
                    "`id` INT NOT NULL AUTO_INCREMENT," +
                    "`name` VARCHAR(45) NOT NULL," +
                    "`money` INT NOT NULL," +
                    "`day` INT NOT NULL," +
                    "PRIMARY KEY (`id`)," +
                    "UNIQUE INDEX `id_UNIQUE` (`id` ASC)," +
                    "UNIQUE INDEX `name_UNIQUE` (`name` ASC))" +
                    "ENGINE = InnoDB DEFAULT CHARSET = utf8 AUTO_INCREMENT = 1; ";
                this.ExeUpdate(sql);

                sql = "CREATE TABLE IF NOT EXISTS `excute` (" +
                    "`id` INT NOT NULL AUTO_INCREMENT," +
                    "`plan` INT NOT NULL," +
                    "`periods` VARCHAR(45) NOT NULL," +
                    "`status` INT NOT NULL," +
                    "`overdue` INT NOT NULL DEFAULT 0," +
                    "PRIMARY KEY (`id`)," +
                    "UNIQUE INDEX `id_UNIQUE` (`id` ASC)," +
                    "INDEX `fk_e_p_idx` (`plan` ASC)," +
                    "CONSTRAINT `fk_e_p`" +
                    "FOREIGN KEY (`plan`)" +
                    "REFERENCES `paybackalarmclock`.`plan` (`id`)" +
                    "ON DELETE CASCADE " +
                    "ON UPDATE CASCADE)" +
                    "ENGINE = InnoDB DEFAULT CHARSET = utf8 AUTO_INCREMENT = 1; ";
                this.ExeUpdate(sql);
            }
            catch(Exception ex)
            {
                Debug.WriteLine("\r{0}\r{1}\r", ex.Message, ex.StackTrace);
            }
        }

        #region  建立MySql数据库连接
        /// <summary>
        /// 建立数据库连接.
        /// </summary>
        /// <returns>返回MySqlConnection对象</returns>
        private MySqlConnection GetMysqlConnection()
        {
            //string M_str_sqlcon = string.Format("server={0};user id={1};password={2};database={3};port={4};Charset={5}", server, userid, password, database, port, charset);
            MySqlConnection myCon = new MySqlConnection(conn);
            return myCon;
        }
        #endregion

        #region  执行MySqlCommand命令
        /// <summary>
        /// 执行MySqlCommand
        /// </summary>
        /// <param name="M_str_sqlstr">SQL语句</param>
        public void ExeUpdate(string M_str_sqlstr)
        {
            MySqlConnection mysqlcon = this.GetMysqlConnection();
            mysqlcon.Open();
            MySqlCommand mysqlcom = new MySqlCommand(M_str_sqlstr, mysqlcon);
            mysqlcom.ExecuteNonQuery();
            mysqlcom.Dispose();
            mysqlcon.Close();
            mysqlcon.Dispose();
        }
        #endregion

        #region  创建MySqlDataReader对象
        /// <summary>
        /// 创建一个MySqlDataReader对象
        /// </summary>
        /// <param name="M_str_sqlstr">SQL语句</param>
        /// <returns>返回MySqlDataReader对象</returns>
        public MySqlDataReader ExeQuery(string M_str_sqlstr)
        {
            Console.WriteLine(M_str_sqlstr);
            MySqlConnection mysqlcon = this.GetMysqlConnection();
            MySqlCommand mysqlcom = new MySqlCommand(M_str_sqlstr, mysqlcon);
            mysqlcon.Open();
            MySqlDataReader mysqlread = mysqlcom.ExecuteReader(CommandBehavior.CloseConnection);
            return mysqlread;
        }
        #endregion

    }
}
