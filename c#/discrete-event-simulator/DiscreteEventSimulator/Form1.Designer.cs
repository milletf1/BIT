namespace DiscreteEventSimulator
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnStart = new System.Windows.Forms.Button();
            this.tabContainer = new System.Windows.Forms.TabControl();
            this.dispayTab = new System.Windows.Forms.TabPage();
            this.carDisplay = new System.Windows.Forms.ListBox();
            this.label3 = new System.Windows.Forms.Label();
            this.otherDisplay = new System.Windows.Forms.ListBox();
            this.label2 = new System.Windows.Forms.Label();
            this.eventDisplay = new System.Windows.Forms.ListBox();
            this.label1 = new System.Windows.Forms.Label();
            this.tabGraphics = new System.Windows.Forms.TabPage();
            this.displayPanel = new System.Windows.Forms.Panel();
            this.statsTab = new System.Windows.Forms.TabPage();
            this.label21 = new System.Windows.Forms.Label();
            this.statsDisplay = new System.Windows.Forms.RichTextBox();
            this.tabOptions = new System.Windows.Forms.TabPage();
            this.selectEventPause = new System.Windows.Forms.NumericUpDown();
            this.selectSimTime = new System.Windows.Forms.NumericUpDown();
            this.label20 = new System.Windows.Forms.Label();
            this.label24 = new System.Windows.Forms.Label();
            this.selectPercentCarStereo = new System.Windows.Forms.NumericUpDown();
            this.label5 = new System.Windows.Forms.Label();
            this.groupOther = new System.Windows.Forms.GroupBox();
            this.rbCompleteOther636 = new System.Windows.Forms.RadioButton();
            this.rbCompleteOther530 = new System.Windows.Forms.RadioButton();
            this.rbCompleteOther424 = new System.Windows.Forms.RadioButton();
            this.rbCompleteOther318 = new System.Windows.Forms.RadioButton();
            this.rbCompleteOther212 = new System.Windows.Forms.RadioButton();
            this.rbCompleteOther16 = new System.Windows.Forms.RadioButton();
            this.groupCarStereo = new System.Windows.Forms.GroupBox();
            this.rbCompleteCarStereo636 = new System.Windows.Forms.RadioButton();
            this.rbCompleteCarStereo530 = new System.Windows.Forms.RadioButton();
            this.rbCompleteCarStereo424 = new System.Windows.Forms.RadioButton();
            this.rbCompleteCarStereo318 = new System.Windows.Forms.RadioButton();
            this.rbCompleteCarStereo212 = new System.Windows.Forms.RadioButton();
            this.rbCompleteCarStereo16 = new System.Windows.Forms.RadioButton();
            this.groupIvr = new System.Windows.Forms.GroupBox();
            this.rbCompleteIvr636 = new System.Windows.Forms.RadioButton();
            this.rbCompleteIvr530 = new System.Windows.Forms.RadioButton();
            this.rbCompleteIvr424 = new System.Windows.Forms.RadioButton();
            this.rbCompleteIvr318 = new System.Windows.Forms.RadioButton();
            this.rbCompleteIvr212 = new System.Windows.Forms.RadioButton();
            this.rbCompleteIvr16 = new System.Windows.Forms.RadioButton();
            this.groupArrival = new System.Windows.Forms.GroupBox();
            this.rbArrival636 = new System.Windows.Forms.RadioButton();
            this.rbArrival530 = new System.Windows.Forms.RadioButton();
            this.rbArrival424 = new System.Windows.Forms.RadioButton();
            this.rbArrival318 = new System.Windows.Forms.RadioButton();
            this.rbArrival212 = new System.Windows.Forms.RadioButton();
            this.rbArrival16 = new System.Windows.Forms.RadioButton();
            this.label8 = new System.Windows.Forms.Label();
            this.selectExcessWait = new System.Windows.Forms.NumericUpDown();
            this.selectOtherReps = new System.Windows.Forms.NumericUpDown();
            this.selectCarStereoReps = new System.Windows.Forms.NumericUpDown();
            this.selectMaxHoldLen = new System.Windows.Forms.NumericUpDown();
            this.label19 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.label15 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label999 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnStop = new System.Windows.Forms.Button();
            this.tabContainer.SuspendLayout();
            this.dispayTab.SuspendLayout();
            this.tabGraphics.SuspendLayout();
            this.statsTab.SuspendLayout();
            this.tabOptions.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.selectEventPause)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectSimTime)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectPercentCarStereo)).BeginInit();
            this.groupOther.SuspendLayout();
            this.groupCarStereo.SuspendLayout();
            this.groupIvr.SuspendLayout();
            this.groupArrival.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.selectExcessWait)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectOtherReps)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectCarStereoReps)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectMaxHoldLen)).BeginInit();
            this.SuspendLayout();
            // 
            // btnStart
            // 
            this.btnStart.Location = new System.Drawing.Point(605, 3);
            this.btnStart.Name = "btnStart";
            this.btnStart.Size = new System.Drawing.Size(75, 23);
            this.btnStart.TabIndex = 7;
            this.btnStart.Text = "Start";
            this.btnStart.UseVisualStyleBackColor = true;
            this.btnStart.Click += new System.EventHandler(this.btnStart_Click);
            // 
            // tabContainer
            // 
            this.tabContainer.Controls.Add(this.dispayTab);
            this.tabContainer.Controls.Add(this.tabGraphics);
            this.tabContainer.Controls.Add(this.statsTab);
            this.tabContainer.Controls.Add(this.tabOptions);
            this.tabContainer.Location = new System.Drawing.Point(-1, 12);
            this.tabContainer.Name = "tabContainer";
            this.tabContainer.SelectedIndex = 0;
            this.tabContainer.Size = new System.Drawing.Size(768, 648);
            this.tabContainer.TabIndex = 8;
            // 
            // dispayTab
            // 
            this.dispayTab.Controls.Add(this.carDisplay);
            this.dispayTab.Controls.Add(this.label3);
            this.dispayTab.Controls.Add(this.otherDisplay);
            this.dispayTab.Controls.Add(this.label2);
            this.dispayTab.Controls.Add(this.eventDisplay);
            this.dispayTab.Controls.Add(this.label1);
            this.dispayTab.Location = new System.Drawing.Point(4, 22);
            this.dispayTab.Name = "dispayTab";
            this.dispayTab.Padding = new System.Windows.Forms.Padding(3);
            this.dispayTab.Size = new System.Drawing.Size(760, 622);
            this.dispayTab.TabIndex = 0;
            this.dispayTab.Text = "Watch";
            this.dispayTab.UseVisualStyleBackColor = true;
            // 
            // carDisplay
            // 
            this.carDisplay.Enabled = false;
            this.carDisplay.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.carDisplay.FormattingEnabled = true;
            this.carDisplay.ItemHeight = 14;
            this.carDisplay.Location = new System.Drawing.Point(79, 451);
            this.carDisplay.Name = "carDisplay";
            this.carDisplay.Size = new System.Drawing.Size(607, 158);
            this.carDisplay.TabIndex = 12;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("MS Reference Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(75, 422);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(229, 26);
            this.label3.TabIndex = 4;
            this.label3.Text = "Car Stereo Queue:";
            // 
            // otherDisplay
            // 
            this.otherDisplay.Enabled = false;
            this.otherDisplay.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.otherDisplay.FormattingEnabled = true;
            this.otherDisplay.ItemHeight = 14;
            this.otherDisplay.Location = new System.Drawing.Point(79, 247);
            this.otherDisplay.Name = "otherDisplay";
            this.otherDisplay.Size = new System.Drawing.Size(607, 158);
            this.otherDisplay.TabIndex = 11;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("MS Reference Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(74, 218);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(170, 26);
            this.label2.TabIndex = 2;
            this.label2.Text = "Other Queue:";
            // 
            // eventDisplay
            // 
            this.eventDisplay.Enabled = false;
            this.eventDisplay.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.eventDisplay.FormattingEnabled = true;
            this.eventDisplay.ItemHeight = 14;
            this.eventDisplay.Location = new System.Drawing.Point(79, 56);
            this.eventDisplay.MultiColumn = true;
            this.eventDisplay.Name = "eventDisplay";
            this.eventDisplay.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.eventDisplay.Size = new System.Drawing.Size(607, 144);
            this.eventDisplay.TabIndex = 10;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("MS Reference Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(75, 27);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(99, 26);
            this.label1.TabIndex = 0;
            this.label1.Text = "Events:";
            // 
            // tabGraphics
            // 
            this.tabGraphics.Controls.Add(this.displayPanel);
            this.tabGraphics.Location = new System.Drawing.Point(4, 22);
            this.tabGraphics.Name = "tabGraphics";
            this.tabGraphics.Padding = new System.Windows.Forms.Padding(3);
            this.tabGraphics.Size = new System.Drawing.Size(760, 622);
            this.tabGraphics.TabIndex = 3;
            this.tabGraphics.Text = "Graphics";
            this.tabGraphics.UseVisualStyleBackColor = true;
            // 
            // displayPanel
            // 
            this.displayPanel.BackColor = System.Drawing.Color.White;
            this.displayPanel.Location = new System.Drawing.Point(27, 6);
            this.displayPanel.Name = "displayPanel";
            this.displayPanel.Size = new System.Drawing.Size(704, 608);
            this.displayPanel.TabIndex = 0;
            // 
            // statsTab
            // 
            this.statsTab.Controls.Add(this.label21);
            this.statsTab.Controls.Add(this.statsDisplay);
            this.statsTab.Location = new System.Drawing.Point(4, 22);
            this.statsTab.Name = "statsTab";
            this.statsTab.Padding = new System.Windows.Forms.Padding(3);
            this.statsTab.Size = new System.Drawing.Size(760, 622);
            this.statsTab.TabIndex = 1;
            this.statsTab.Text = "Statistics";
            this.statsTab.UseVisualStyleBackColor = true;
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Font = new System.Drawing.Font("MS Reference Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label21.Location = new System.Drawing.Point(21, 3);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(129, 26);
            this.label21.TabIndex = 1;
            this.label21.Text = "Statistics:";
            // 
            // statsDisplay
            // 
            this.statsDisplay.Enabled = false;
            this.statsDisplay.Font = new System.Drawing.Font("Courier New", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.statsDisplay.Location = new System.Drawing.Point(26, 32);
            this.statsDisplay.Name = "statsDisplay";
            this.statsDisplay.Size = new System.Drawing.Size(705, 542);
            this.statsDisplay.TabIndex = 0;
            this.statsDisplay.Text = "";
            // 
            // tabOptions
            // 
            this.tabOptions.Controls.Add(this.selectEventPause);
            this.tabOptions.Controls.Add(this.selectSimTime);
            this.tabOptions.Controls.Add(this.label20);
            this.tabOptions.Controls.Add(this.label24);
            this.tabOptions.Controls.Add(this.selectPercentCarStereo);
            this.tabOptions.Controls.Add(this.label5);
            this.tabOptions.Controls.Add(this.groupOther);
            this.tabOptions.Controls.Add(this.groupCarStereo);
            this.tabOptions.Controls.Add(this.groupIvr);
            this.tabOptions.Controls.Add(this.groupArrival);
            this.tabOptions.Controls.Add(this.label8);
            this.tabOptions.Controls.Add(this.selectExcessWait);
            this.tabOptions.Controls.Add(this.selectOtherReps);
            this.tabOptions.Controls.Add(this.selectCarStereoReps);
            this.tabOptions.Controls.Add(this.selectMaxHoldLen);
            this.tabOptions.Controls.Add(this.label19);
            this.tabOptions.Controls.Add(this.label18);
            this.tabOptions.Controls.Add(this.label17);
            this.tabOptions.Controls.Add(this.label16);
            this.tabOptions.Controls.Add(this.label15);
            this.tabOptions.Controls.Add(this.label14);
            this.tabOptions.Controls.Add(this.label13);
            this.tabOptions.Controls.Add(this.label12);
            this.tabOptions.Controls.Add(this.label11);
            this.tabOptions.Controls.Add(this.label10);
            this.tabOptions.Controls.Add(this.label9);
            this.tabOptions.Controls.Add(this.label7);
            this.tabOptions.Controls.Add(this.label6);
            this.tabOptions.Controls.Add(this.label999);
            this.tabOptions.Controls.Add(this.label4);
            this.tabOptions.Location = new System.Drawing.Point(4, 22);
            this.tabOptions.Name = "tabOptions";
            this.tabOptions.Padding = new System.Windows.Forms.Padding(3);
            this.tabOptions.Size = new System.Drawing.Size(760, 622);
            this.tabOptions.TabIndex = 2;
            this.tabOptions.Text = "Options";
            this.tabOptions.UseVisualStyleBackColor = true;
            // 
            // selectEventPause
            // 
            this.selectEventPause.Increment = new decimal(new int[] {
            100,
            0,
            0,
            0});
            this.selectEventPause.Location = new System.Drawing.Point(321, 143);
            this.selectEventPause.Maximum = new decimal(new int[] {
            5000,
            0,
            0,
            0});
            this.selectEventPause.Name = "selectEventPause";
            this.selectEventPause.Size = new System.Drawing.Size(44, 20);
            this.selectEventPause.TabIndex = 64;
            this.selectEventPause.Value = new decimal(new int[] {
            500,
            0,
            0,
            0});
            // 
            // selectSimTime
            // 
            this.selectSimTime.Increment = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.selectSimTime.Location = new System.Drawing.Point(321, 86);
            this.selectSimTime.Maximum = new decimal(new int[] {
            720,
            0,
            0,
            0});
            this.selectSimTime.Minimum = new decimal(new int[] {
            30,
            0,
            0,
            0});
            this.selectSimTime.Name = "selectSimTime";
            this.selectSimTime.Size = new System.Drawing.Size(44, 20);
            this.selectSimTime.TabIndex = 63;
            this.selectSimTime.Value = new decimal(new int[] {
            60,
            0,
            0,
            0});
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Font = new System.Drawing.Font("MS Reference Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label20.Location = new System.Drawing.Point(88, 41);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(230, 26);
            this.label20.TabIndex = 62;
            this.label20.Text = "Simulation Options";
            // 
            // label24
            // 
            this.label24.AutoSize = true;
            this.label24.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label24.Location = new System.Drawing.Point(90, 86);
            this.label24.Name = "label24";
            this.label24.Size = new System.Drawing.Size(182, 16);
            this.label24.TabIndex = 61;
            this.label24.Text = "Simulation time (minutes):";
            // 
            // selectPercentCarStereo
            // 
            this.selectPercentCarStereo.Location = new System.Drawing.Point(602, 206);
            this.selectPercentCarStereo.Name = "selectPercentCarStereo";
            this.selectPercentCarStereo.Size = new System.Drawing.Size(46, 20);
            this.selectPercentCarStereo.TabIndex = 60;
            this.selectPercentCarStereo.Value = new decimal(new int[] {
            17,
            0,
            0,
            0});
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(380, 206);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(197, 16);
            this.label5.TabIndex = 59;
            this.label5.Text = "Car-stereo call percentage: ";
            // 
            // groupOther
            // 
            this.groupOther.Controls.Add(this.rbCompleteOther636);
            this.groupOther.Controls.Add(this.rbCompleteOther530);
            this.groupOther.Controls.Add(this.rbCompleteOther424);
            this.groupOther.Controls.Add(this.rbCompleteOther318);
            this.groupOther.Controls.Add(this.rbCompleteOther212);
            this.groupOther.Controls.Add(this.rbCompleteOther16);
            this.groupOther.Location = new System.Drawing.Point(286, 538);
            this.groupOther.Name = "groupOther";
            this.groupOther.Size = new System.Drawing.Size(341, 28);
            this.groupOther.TabIndex = 58;
            this.groupOther.TabStop = false;
            // 
            // rbCompleteOther636
            // 
            this.rbCompleteOther636.AutoSize = true;
            this.rbCompleteOther636.Location = new System.Drawing.Point(318, 9);
            this.rbCompleteOther636.Name = "rbCompleteOther636";
            this.rbCompleteOther636.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteOther636.TabIndex = 55;
            this.rbCompleteOther636.TabStop = true;
            this.rbCompleteOther636.UseVisualStyleBackColor = true;
            // 
            // rbCompleteOther530
            // 
            this.rbCompleteOther530.AutoSize = true;
            this.rbCompleteOther530.Location = new System.Drawing.Point(261, 9);
            this.rbCompleteOther530.Name = "rbCompleteOther530";
            this.rbCompleteOther530.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteOther530.TabIndex = 55;
            this.rbCompleteOther530.TabStop = true;
            this.rbCompleteOther530.UseVisualStyleBackColor = true;
            // 
            // rbCompleteOther424
            // 
            this.rbCompleteOther424.AutoSize = true;
            this.rbCompleteOther424.Location = new System.Drawing.Point(201, 10);
            this.rbCompleteOther424.Name = "rbCompleteOther424";
            this.rbCompleteOther424.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteOther424.TabIndex = 55;
            this.rbCompleteOther424.TabStop = true;
            this.rbCompleteOther424.UseVisualStyleBackColor = true;
            // 
            // rbCompleteOther318
            // 
            this.rbCompleteOther318.AutoSize = true;
            this.rbCompleteOther318.Location = new System.Drawing.Point(138, 10);
            this.rbCompleteOther318.Name = "rbCompleteOther318";
            this.rbCompleteOther318.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteOther318.TabIndex = 55;
            this.rbCompleteOther318.TabStop = true;
            this.rbCompleteOther318.UseVisualStyleBackColor = true;
            // 
            // rbCompleteOther212
            // 
            this.rbCompleteOther212.AutoSize = true;
            this.rbCompleteOther212.Location = new System.Drawing.Point(73, 10);
            this.rbCompleteOther212.Name = "rbCompleteOther212";
            this.rbCompleteOther212.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteOther212.TabIndex = 1;
            this.rbCompleteOther212.TabStop = true;
            this.rbCompleteOther212.UseVisualStyleBackColor = true;
            // 
            // rbCompleteOther16
            // 
            this.rbCompleteOther16.AutoSize = true;
            this.rbCompleteOther16.Location = new System.Drawing.Point(13, 10);
            this.rbCompleteOther16.Name = "rbCompleteOther16";
            this.rbCompleteOther16.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteOther16.TabIndex = 0;
            this.rbCompleteOther16.TabStop = true;
            this.rbCompleteOther16.UseVisualStyleBackColor = true;
            // 
            // groupCarStereo
            // 
            this.groupCarStereo.Controls.Add(this.rbCompleteCarStereo636);
            this.groupCarStereo.Controls.Add(this.rbCompleteCarStereo530);
            this.groupCarStereo.Controls.Add(this.rbCompleteCarStereo424);
            this.groupCarStereo.Controls.Add(this.rbCompleteCarStereo318);
            this.groupCarStereo.Controls.Add(this.rbCompleteCarStereo212);
            this.groupCarStereo.Controls.Add(this.rbCompleteCarStereo16);
            this.groupCarStereo.Location = new System.Drawing.Point(286, 504);
            this.groupCarStereo.Name = "groupCarStereo";
            this.groupCarStereo.Size = new System.Drawing.Size(341, 28);
            this.groupCarStereo.TabIndex = 57;
            this.groupCarStereo.TabStop = false;
            // 
            // rbCompleteCarStereo636
            // 
            this.rbCompleteCarStereo636.AutoSize = true;
            this.rbCompleteCarStereo636.Location = new System.Drawing.Point(318, 9);
            this.rbCompleteCarStereo636.Name = "rbCompleteCarStereo636";
            this.rbCompleteCarStereo636.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteCarStereo636.TabIndex = 55;
            this.rbCompleteCarStereo636.TabStop = true;
            this.rbCompleteCarStereo636.UseVisualStyleBackColor = true;
            // 
            // rbCompleteCarStereo530
            // 
            this.rbCompleteCarStereo530.AutoSize = true;
            this.rbCompleteCarStereo530.Location = new System.Drawing.Point(261, 9);
            this.rbCompleteCarStereo530.Name = "rbCompleteCarStereo530";
            this.rbCompleteCarStereo530.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteCarStereo530.TabIndex = 55;
            this.rbCompleteCarStereo530.TabStop = true;
            this.rbCompleteCarStereo530.UseVisualStyleBackColor = true;
            // 
            // rbCompleteCarStereo424
            // 
            this.rbCompleteCarStereo424.AutoSize = true;
            this.rbCompleteCarStereo424.Location = new System.Drawing.Point(201, 10);
            this.rbCompleteCarStereo424.Name = "rbCompleteCarStereo424";
            this.rbCompleteCarStereo424.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteCarStereo424.TabIndex = 55;
            this.rbCompleteCarStereo424.TabStop = true;
            this.rbCompleteCarStereo424.UseVisualStyleBackColor = true;
            // 
            // rbCompleteCarStereo318
            // 
            this.rbCompleteCarStereo318.AutoSize = true;
            this.rbCompleteCarStereo318.Location = new System.Drawing.Point(138, 10);
            this.rbCompleteCarStereo318.Name = "rbCompleteCarStereo318";
            this.rbCompleteCarStereo318.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteCarStereo318.TabIndex = 55;
            this.rbCompleteCarStereo318.TabStop = true;
            this.rbCompleteCarStereo318.UseVisualStyleBackColor = true;
            // 
            // rbCompleteCarStereo212
            // 
            this.rbCompleteCarStereo212.AutoSize = true;
            this.rbCompleteCarStereo212.Location = new System.Drawing.Point(73, 10);
            this.rbCompleteCarStereo212.Name = "rbCompleteCarStereo212";
            this.rbCompleteCarStereo212.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteCarStereo212.TabIndex = 1;
            this.rbCompleteCarStereo212.TabStop = true;
            this.rbCompleteCarStereo212.UseVisualStyleBackColor = true;
            // 
            // rbCompleteCarStereo16
            // 
            this.rbCompleteCarStereo16.AutoSize = true;
            this.rbCompleteCarStereo16.Location = new System.Drawing.Point(13, 10);
            this.rbCompleteCarStereo16.Name = "rbCompleteCarStereo16";
            this.rbCompleteCarStereo16.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteCarStereo16.TabIndex = 0;
            this.rbCompleteCarStereo16.TabStop = true;
            this.rbCompleteCarStereo16.UseVisualStyleBackColor = true;
            // 
            // groupIvr
            // 
            this.groupIvr.Controls.Add(this.rbCompleteIvr636);
            this.groupIvr.Controls.Add(this.rbCompleteIvr530);
            this.groupIvr.Controls.Add(this.rbCompleteIvr424);
            this.groupIvr.Controls.Add(this.rbCompleteIvr318);
            this.groupIvr.Controls.Add(this.rbCompleteIvr212);
            this.groupIvr.Controls.Add(this.rbCompleteIvr16);
            this.groupIvr.Location = new System.Drawing.Point(286, 470);
            this.groupIvr.Name = "groupIvr";
            this.groupIvr.Size = new System.Drawing.Size(341, 28);
            this.groupIvr.TabIndex = 56;
            this.groupIvr.TabStop = false;
            // 
            // rbCompleteIvr636
            // 
            this.rbCompleteIvr636.AutoSize = true;
            this.rbCompleteIvr636.Location = new System.Drawing.Point(318, 9);
            this.rbCompleteIvr636.Name = "rbCompleteIvr636";
            this.rbCompleteIvr636.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteIvr636.TabIndex = 55;
            this.rbCompleteIvr636.TabStop = true;
            this.rbCompleteIvr636.UseVisualStyleBackColor = true;
            // 
            // rbCompleteIvr530
            // 
            this.rbCompleteIvr530.AutoSize = true;
            this.rbCompleteIvr530.Location = new System.Drawing.Point(261, 9);
            this.rbCompleteIvr530.Name = "rbCompleteIvr530";
            this.rbCompleteIvr530.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteIvr530.TabIndex = 55;
            this.rbCompleteIvr530.TabStop = true;
            this.rbCompleteIvr530.UseVisualStyleBackColor = true;
            // 
            // rbCompleteIvr424
            // 
            this.rbCompleteIvr424.AutoSize = true;
            this.rbCompleteIvr424.Location = new System.Drawing.Point(201, 10);
            this.rbCompleteIvr424.Name = "rbCompleteIvr424";
            this.rbCompleteIvr424.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteIvr424.TabIndex = 55;
            this.rbCompleteIvr424.TabStop = true;
            this.rbCompleteIvr424.UseVisualStyleBackColor = true;
            // 
            // rbCompleteIvr318
            // 
            this.rbCompleteIvr318.AutoSize = true;
            this.rbCompleteIvr318.Location = new System.Drawing.Point(138, 10);
            this.rbCompleteIvr318.Name = "rbCompleteIvr318";
            this.rbCompleteIvr318.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteIvr318.TabIndex = 55;
            this.rbCompleteIvr318.TabStop = true;
            this.rbCompleteIvr318.UseVisualStyleBackColor = true;
            // 
            // rbCompleteIvr212
            // 
            this.rbCompleteIvr212.AutoSize = true;
            this.rbCompleteIvr212.Location = new System.Drawing.Point(73, 10);
            this.rbCompleteIvr212.Name = "rbCompleteIvr212";
            this.rbCompleteIvr212.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteIvr212.TabIndex = 1;
            this.rbCompleteIvr212.TabStop = true;
            this.rbCompleteIvr212.UseVisualStyleBackColor = true;
            // 
            // rbCompleteIvr16
            // 
            this.rbCompleteIvr16.AutoSize = true;
            this.rbCompleteIvr16.Location = new System.Drawing.Point(13, 10);
            this.rbCompleteIvr16.Name = "rbCompleteIvr16";
            this.rbCompleteIvr16.Size = new System.Drawing.Size(14, 13);
            this.rbCompleteIvr16.TabIndex = 0;
            this.rbCompleteIvr16.TabStop = true;
            this.rbCompleteIvr16.UseVisualStyleBackColor = true;
            // 
            // groupArrival
            // 
            this.groupArrival.Controls.Add(this.rbArrival636);
            this.groupArrival.Controls.Add(this.rbArrival530);
            this.groupArrival.Controls.Add(this.rbArrival424);
            this.groupArrival.Controls.Add(this.rbArrival318);
            this.groupArrival.Controls.Add(this.rbArrival212);
            this.groupArrival.Controls.Add(this.rbArrival16);
            this.groupArrival.Location = new System.Drawing.Point(286, 436);
            this.groupArrival.Name = "groupArrival";
            this.groupArrival.Size = new System.Drawing.Size(341, 28);
            this.groupArrival.TabIndex = 50;
            this.groupArrival.TabStop = false;
            // 
            // rbArrival636
            // 
            this.rbArrival636.AutoSize = true;
            this.rbArrival636.Location = new System.Drawing.Point(318, 9);
            this.rbArrival636.Name = "rbArrival636";
            this.rbArrival636.Size = new System.Drawing.Size(14, 13);
            this.rbArrival636.TabIndex = 55;
            this.rbArrival636.TabStop = true;
            this.rbArrival636.UseVisualStyleBackColor = true;
            // 
            // rbArrival530
            // 
            this.rbArrival530.AutoSize = true;
            this.rbArrival530.Location = new System.Drawing.Point(261, 9);
            this.rbArrival530.Name = "rbArrival530";
            this.rbArrival530.Size = new System.Drawing.Size(14, 13);
            this.rbArrival530.TabIndex = 55;
            this.rbArrival530.TabStop = true;
            this.rbArrival530.UseVisualStyleBackColor = true;
            // 
            // rbArrival424
            // 
            this.rbArrival424.AutoSize = true;
            this.rbArrival424.Location = new System.Drawing.Point(201, 10);
            this.rbArrival424.Name = "rbArrival424";
            this.rbArrival424.Size = new System.Drawing.Size(14, 13);
            this.rbArrival424.TabIndex = 55;
            this.rbArrival424.TabStop = true;
            this.rbArrival424.UseVisualStyleBackColor = true;
            // 
            // rbArrival318
            // 
            this.rbArrival318.AutoSize = true;
            this.rbArrival318.Location = new System.Drawing.Point(138, 10);
            this.rbArrival318.Name = "rbArrival318";
            this.rbArrival318.Size = new System.Drawing.Size(14, 13);
            this.rbArrival318.TabIndex = 55;
            this.rbArrival318.TabStop = true;
            this.rbArrival318.UseVisualStyleBackColor = true;
            // 
            // rbArrival212
            // 
            this.rbArrival212.AutoSize = true;
            this.rbArrival212.Location = new System.Drawing.Point(73, 10);
            this.rbArrival212.Name = "rbArrival212";
            this.rbArrival212.Size = new System.Drawing.Size(14, 13);
            this.rbArrival212.TabIndex = 1;
            this.rbArrival212.TabStop = true;
            this.rbArrival212.UseVisualStyleBackColor = true;
            // 
            // rbArrival16
            // 
            this.rbArrival16.AutoSize = true;
            this.rbArrival16.Location = new System.Drawing.Point(13, 10);
            this.rbArrival16.Name = "rbArrival16";
            this.rbArrival16.Size = new System.Drawing.Size(14, 13);
            this.rbArrival16.TabIndex = 0;
            this.rbArrival16.TabStop = true;
            this.rbArrival16.UseVisualStyleBackColor = true;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(95, 477);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(167, 16);
            this.label8.TabIndex = 4;
            this.label8.Text = "IVR Service Completion:";
            // 
            // selectExcessWait
            // 
            this.selectExcessWait.Location = new System.Drawing.Point(321, 259);
            this.selectExcessWait.Maximum = new decimal(new int[] {
            30,
            0,
            0,
            0});
            this.selectExcessWait.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.selectExcessWait.Name = "selectExcessWait";
            this.selectExcessWait.Size = new System.Drawing.Size(46, 20);
            this.selectExcessWait.TabIndex = 45;
            this.selectExcessWait.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // selectOtherReps
            // 
            this.selectOtherReps.Location = new System.Drawing.Point(602, 86);
            this.selectOtherReps.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.selectOtherReps.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.selectOtherReps.Name = "selectOtherReps";
            this.selectOtherReps.Size = new System.Drawing.Size(46, 20);
            this.selectOtherReps.TabIndex = 44;
            this.selectOtherReps.Value = new decimal(new int[] {
            3,
            0,
            0,
            0});
            // 
            // selectCarStereoReps
            // 
            this.selectCarStereoReps.Location = new System.Drawing.Point(602, 139);
            this.selectCarStereoReps.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.selectCarStereoReps.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.selectCarStereoReps.Name = "selectCarStereoReps";
            this.selectCarStereoReps.Size = new System.Drawing.Size(46, 20);
            this.selectCarStereoReps.TabIndex = 43;
            this.selectCarStereoReps.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // selectMaxHoldLen
            // 
            this.selectMaxHoldLen.Location = new System.Drawing.Point(321, 206);
            this.selectMaxHoldLen.Maximum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.selectMaxHoldLen.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.selectMaxHoldLen.Name = "selectMaxHoldLen";
            this.selectMaxHoldLen.Size = new System.Drawing.Size(46, 20);
            this.selectMaxHoldLen.TabIndex = 42;
            this.selectMaxHoldLen.Value = new decimal(new int[] {
            5,
            0,
            0,
            0});
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Font = new System.Drawing.Font("MS Reference Sans Serif", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label19.Location = new System.Drawing.Point(93, 367);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(262, 26);
            this.label19.TabIndex = 15;
            this.label19.Text = "Delay Time (minutes)";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label18.Location = new System.Drawing.Point(587, 411);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(49, 16);
            this.label18.TabIndex = 14;
            this.label18.Text = "6 - 36";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label17.Location = new System.Drawing.Point(529, 411);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(49, 16);
            this.label17.TabIndex = 13;
            this.label17.Text = "5 - 30";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label16.Location = new System.Drawing.Point(467, 411);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(49, 16);
            this.label16.TabIndex = 12;
            this.label16.Text = "4 - 24";
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label15.Location = new System.Drawing.Point(405, 411);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(49, 16);
            this.label15.TabIndex = 11;
            this.label15.Text = "3 - 18";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label14.Location = new System.Drawing.Point(341, 411);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(54, 16);
            this.label14.TabIndex = 10;
            this.label14.Text = "2 - 12 ";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.Location = new System.Drawing.Point(283, 411);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(41, 16);
            this.label13.TabIndex = 9;
            this.label13.Text = "0 - 3";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(90, 143);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(190, 16);
            this.label12.TabIndex = 8;
            this.label12.Text = "Event pause (milliseconds):";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(90, 259);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(212, 16);
            this.label11.TabIndex = 7;
            this.label11.Text = "Excessive wait time (minutes):";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(95, 510);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(137, 16);
            this.label10.TabIndex = 6;
            this.label10.Text = "Car-stereo service:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(95, 545);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(103, 16);
            this.label9.TabIndex = 5;
            this.label9.Text = "Other service:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(95, 444);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(123, 16);
            this.label7.TabIndex = 3;
            this.label7.Text = "Between arrivals:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(380, 143);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(164, 16);
            this.label6.TabIndex = 2;
            this.label6.Text = "Car-stereo service reps";
            // 
            // label999
            // 
            this.label999.AutoSize = true;
            this.label999.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label999.Location = new System.Drawing.Point(380, 86);
            this.label999.Name = "label999";
            this.label999.Size = new System.Drawing.Size(136, 16);
            this.label999.TabIndex = 1;
            this.label999.Text = "Other service reps:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("MS Reference Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(90, 206);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(162, 16);
            this.label4.TabIndex = 0;
            this.label4.Text = "Max entities in queues:";
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(685, 3);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 23);
            this.btnStop.TabIndex = 9;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(767, 662);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.btnStart);
            this.Controls.Add(this.tabContainer);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form1";
            this.Text = "Call Center Discrete Event Simulator";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.tabContainer.ResumeLayout(false);
            this.dispayTab.ResumeLayout(false);
            this.dispayTab.PerformLayout();
            this.tabGraphics.ResumeLayout(false);
            this.statsTab.ResumeLayout(false);
            this.statsTab.PerformLayout();
            this.tabOptions.ResumeLayout(false);
            this.tabOptions.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.selectEventPause)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectSimTime)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectPercentCarStereo)).EndInit();
            this.groupOther.ResumeLayout(false);
            this.groupOther.PerformLayout();
            this.groupCarStereo.ResumeLayout(false);
            this.groupCarStereo.PerformLayout();
            this.groupIvr.ResumeLayout(false);
            this.groupIvr.PerformLayout();
            this.groupArrival.ResumeLayout(false);
            this.groupArrival.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.selectExcessWait)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectOtherReps)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectCarStereoReps)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.selectMaxHoldLen)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.TabControl tabContainer;
        private System.Windows.Forms.TabPage dispayTab;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TabPage statsTab;
        private System.Windows.Forms.TabPage tabOptions;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label999;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.NumericUpDown selectExcessWait;
        private System.Windows.Forms.NumericUpDown selectOtherReps;
        private System.Windows.Forms.NumericUpDown selectCarStereoReps;
        private System.Windows.Forms.NumericUpDown selectMaxHoldLen;
        private System.Windows.Forms.GroupBox groupArrival;
        private System.Windows.Forms.GroupBox groupOther;
        private System.Windows.Forms.RadioButton rbCompleteOther636;
        private System.Windows.Forms.RadioButton rbCompleteOther530;
        private System.Windows.Forms.RadioButton rbCompleteOther424;
        private System.Windows.Forms.RadioButton rbCompleteOther318;
        private System.Windows.Forms.RadioButton rbCompleteOther212;
        private System.Windows.Forms.RadioButton rbCompleteOther16;
        private System.Windows.Forms.GroupBox groupCarStereo;
        private System.Windows.Forms.RadioButton rbCompleteCarStereo636;
        private System.Windows.Forms.RadioButton rbCompleteCarStereo530;
        private System.Windows.Forms.RadioButton rbCompleteCarStereo424;
        private System.Windows.Forms.RadioButton rbCompleteCarStereo318;
        private System.Windows.Forms.RadioButton rbCompleteCarStereo212;
        private System.Windows.Forms.RadioButton rbCompleteCarStereo16;
        private System.Windows.Forms.GroupBox groupIvr;
        private System.Windows.Forms.RadioButton rbCompleteIvr636;
        private System.Windows.Forms.RadioButton rbCompleteIvr530;
        private System.Windows.Forms.RadioButton rbCompleteIvr424;
        private System.Windows.Forms.RadioButton rbCompleteIvr318;
        private System.Windows.Forms.RadioButton rbCompleteIvr212;
        private System.Windows.Forms.RadioButton rbCompleteIvr16;
        private System.Windows.Forms.RadioButton rbArrival636;
        private System.Windows.Forms.RadioButton rbArrival530;
        private System.Windows.Forms.RadioButton rbArrival424;
        private System.Windows.Forms.RadioButton rbArrival318;
        private System.Windows.Forms.RadioButton rbArrival212;
        private System.Windows.Forms.RadioButton rbArrival16;
        private System.Windows.Forms.NumericUpDown selectPercentCarStereo;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label24;
        private System.Windows.Forms.NumericUpDown selectEventPause;
        private System.Windows.Forms.NumericUpDown selectSimTime;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.TabPage tabGraphics;
        private System.Windows.Forms.Panel displayPanel;
        private System.Windows.Forms.RichTextBox statsDisplay;
        private System.Windows.Forms.Button btnStop;
        private System.Windows.Forms.ListBox eventDisplay;
        private System.Windows.Forms.ListBox otherDisplay;
        private System.Windows.Forms.ListBox carDisplay;
        private System.Windows.Forms.Label label21;

    }
}

