using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using static System.Net.Mime.MediaTypeNames;
using System.Threading;
using System.Reflection.Emit;

namespace CarWashingAdminPanelWinForm
{
    public partial class Form1 : Form
    {

        string serialDataIn;
       bool recived = false;    

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            btnOpen.Enabled = true;
            btnClose.Enabled= false;
            grpAdmin.Enabled = false;
            prgStatus.Value = 0;
            lblConnStatus.Text = "DISCONNECTED";
            lblConnStatus.ForeColor = Color.Red;
            cmbBaudRate.Text = "9600";
            string[] portList = SerialPort.GetPortNames();
            cmbComPort.Items.AddRange( portList);

        }

        private void btnOpen_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.PortName = cmbComPort.Text;
                serialPort1.BaudRate = int.Parse(cmbBaudRate.Text);
                serialPort1.Open();

                btnOpen.Enabled = false;
                btnClose.Enabled = true;
                grpAdmin.Enabled = true;
                prgStatus.Value = 100;
                lblConnStatus.Text = "CONNECTED";
                lblConnStatus.ForeColor = Color.Green;

                new Thread(() =>
                {
                    Thread.CurrentThread.IsBackground = true;
                    Thread.Sleep(3000);
                    if (!recived)
                    {
                        serialPort1.Close();
                        if (btnOpen.InvokeRequired)
                        {
                            btnOpen.Invoke(new Action(() => btnOpen.Enabled = true));
                        }
                        else
                        {
                            btnOpen.Enabled = true;
                        } 

                        if (btnClose.InvokeRequired)
                        {
                            btnClose.Invoke(new Action(() => btnClose.Enabled = false));
                        }
                        else
                        {
                            btnOpen.Enabled = false;
                        }

                        if (grpAdmin.InvokeRequired)
                        {
                            grpAdmin.Invoke(new Action(() => grpAdmin.Enabled = false));
                        }
                        else
                        {
                            grpAdmin.Enabled = false;
                        }
                        
                        if (prgStatus.InvokeRequired)
                        {
                            prgStatus.Invoke(new Action(() => prgStatus.Value = 0));
                        }
                        else
                        {
                            prgStatus.Value = 0;
                        }
                        
                        if (lblConnStatus.InvokeRequired)
                        {
                            lblConnStatus.Invoke(new Action(() => lblConnStatus.Text = "DISCONNECTED"));
                            lblConnStatus.Invoke(new Action(() => lblConnStatus.ForeColor = Color.Red));
                        }
                        else
                        {

                            lblConnStatus.Text = "DISCONNECTED";
                            lblConnStatus.ForeColor = Color.Red;
                        }
                        
                       
                        
                        MessageBox.Show("Connection Timeout");
                    }
                    
                }).Start();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                try
                {
                    serialPort1.Close();

                    btnOpen.Enabled = true;
                    btnClose.Enabled = false;
                    grpAdmin.Enabled = false;
                    prgStatus.Value = 0;
                    lblConnStatus.Text = "DISCONNECTED";
                    lblConnStatus.ForeColor = Color.Red;

                }
                catch(Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                try
                {
                    serialPort1.Close();

                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);

                }
            }
        }

        private void btnAlert_Click(object sender, EventArgs e)
        {
            try
            {
                serialPort1.Write("1\n");

            }
            catch(Exception ex)
            {
                MessageBox.Show(ex.Message);

            }
        }

        private StringBuilder buffer = new StringBuilder();

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            buffer.Append(serialPort1.ReadExisting());

            // Process the data only if it contains at least one complete JSON object
            while (buffer.Length > 0)
            {
                int lastIndexOpenBrace = buffer.ToString().LastIndexOf('{');
                int lastIndexCloseBrace = buffer.ToString().LastIndexOf('}');

                if (lastIndexOpenBrace >= 0 && lastIndexCloseBrace >= 0 && lastIndexOpenBrace < lastIndexCloseBrace)
                {
                    recived = true;
                    string extractedJson = buffer.ToString().Substring(lastIndexOpenBrace, lastIndexCloseBrace - lastIndexOpenBrace + 1);

                    // Replace escaped double quotes with regular double quotes
                    extractedJson = extractedJson.Replace("\\\"", "\"");

                    try
                    {
                        // Parse the JSON object
                        JObject jsonObject = JObject.Parse(extractedJson);

                        // Convert the JSON object to a string without backslashes
                        string cleanedJson = jsonObject.ToString(Newtonsoft.Json.Formatting.None);

                        // Deserialize the JSON to a dictionary
                        var values = JsonConvert.DeserializeObject<Dictionary<string, string>>(cleanedJson);

                        UpdateUIWithValues(values);
                    }
                    catch (Exception ex)
                    {
                        // Handle specific exceptions if needed
                        Console.WriteLine("Error parsing JSON: " + ex.Message);
                    }

                    // Remove the processed data from the buffer
                    buffer.Remove(0, lastIndexCloseBrace + 1);
                }
                else
                {
                    // If no complete JSON object is found, exit the loop
                    break;
                }
            }
        }

        private void UpdateUIWithValues(Dictionary<string, string> values)
        {
            UpdateLabelValue(lblTemp, "temperature", values);
            UpdateLabelValue(lblStatus, "state", values);
        }

        private void UpdateLabelValue(System.Windows.Forms.Label label, string key, Dictionary<string, string> values)
        {
            if (values.TryGetValue(key, out string value))
            {
                if (label.InvokeRequired)
                {
                    label.Invoke(new Action(() => label.Text = value));
                }
                else
                {
                    label.Text = value;
                }
            }
        }


        private void lblConnStatus_Click(object sender, EventArgs e)
        {

        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            string[] portList = SerialPort.GetPortNames();
            cmbComPort.Items.Clear();
            cmbComPort.Items.AddRange(portList);
        }
    }
}
