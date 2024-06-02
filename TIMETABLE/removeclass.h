#pragma once

using namespace System::Data;
using namespace System::Data::SqlClient;

namespace TIMETABLE {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class removeclass : public System::Windows::Forms::Form
    {
    public:
        removeclass(void)
        {
            InitializeComponent();
        }

    protected:
        ~removeclass()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
        System::Windows::Forms::DataGridViewTextBoxColumn^ StudentName;
        System::Windows::Forms::DataGridViewTextBoxColumn^ TeacherName;
        System::Windows::Forms::DataGridViewTextBoxColumn^ RoomNumber;
        System::Windows::Forms::DataGridViewTextBoxColumn^ CourseName;
        System::Windows::Forms::DataGridViewTextBoxColumn^ Day;
        System::Windows::Forms::DataGridViewTextBoxColumn^ StartTime;
        System::Windows::Forms::DataGridViewTextBoxColumn^ EndTime;
        System::Windows::Forms::DataGridViewTextBoxColumn^ Section;

        System::Windows::Forms::Label^ labelClassID;
        System::Windows::Forms::TextBox^ textBoxClassID;
        System::Windows::Forms::Button^ buttonRemove;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->StudentName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->TeacherName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->RoomNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->CourseName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Day = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->StartTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->EndTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->Section = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
            this->labelClassID = (gcnew System::Windows::Forms::Label());
            this->textBoxClassID = (gcnew System::Windows::Forms::TextBox());
            this->buttonRemove = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToOrderColumns = true;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
                this->ID, this->StudentName,
                    this->TeacherName, this->RoomNumber, this->CourseName, this->Day, this->StartTime, this->EndTime, this->Section
            });
            this->dataGridView1->Location = System::Drawing::Point(34, 50);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(900, 248);
            this->dataGridView1->TabIndex = 0;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &removeclass::dataGridView1_CellContentClick);
            // 
            // ID
            // 
            this->ID->DataPropertyName = L"ID";
            this->ID->HeaderText = L"ID";
            this->ID->Name = L"ID";
            // 
            // StudentName
            // 
            this->StudentName->DataPropertyName = L"StudentName";
            this->StudentName->HeaderText = L"Student Name";
            this->StudentName->Name = L"StudentName";
            // 
            // TeacherName
            // 
            this->TeacherName->DataPropertyName = L"TeacherName";
            this->TeacherName->HeaderText = L"Teacher Name";
            this->TeacherName->Name = L"TeacherName";
            // 
            // RoomNumber
            // 
            this->RoomNumber->DataPropertyName = L"RoomNumber";
            this->RoomNumber->HeaderText = L"Room Number";
            this->RoomNumber->Name = L"RoomNumber";
            // 
            // CourseName
            // 
            this->CourseName->DataPropertyName = L"CourseName";
            this->CourseName->HeaderText = L"Course Name";
            this->CourseName->Name = L"CourseName";
            // 
            // Day
            // 
            this->Day->DataPropertyName = L"Day";
            this->Day->HeaderText = L"Day";
            this->Day->Name = L"Day";
            // 
            // StartTime
            // 
            this->StartTime->DataPropertyName = L"StartTime";
            this->StartTime->HeaderText = L"Start Time";
            this->StartTime->Name = L"StartTime";
            // 
            // EndTime
            // 
            this->EndTime->DataPropertyName = L"EndTime";
            this->EndTime->HeaderText = L"End Time";
            this->EndTime->Name = L"EndTime";
            // 
            // Section
            // 
            this->Section->DataPropertyName = L"Section";
            this->Section->HeaderText = L"Section";
            this->Section->Name = L"Section";
            // 
            // labelClassID
            // 
            this->labelClassID->AutoSize = true;
            this->labelClassID->Location = System::Drawing::Point(34, 25);
            this->labelClassID->Name = L"labelClassID";
            this->labelClassID->Size = System::Drawing::Size(67, 13);
            this->labelClassID->TabIndex = 1;
            this->labelClassID->Text = L"Enter Class ID";
            // 
            // textBoxClassID
            // 
            this->textBoxClassID->Location = System::Drawing::Point(107, 22);
            this->textBoxClassID->Name = L"textBoxClassID";
            this->textBoxClassID->Size = System::Drawing::Size(100, 20);
            this->textBoxClassID->TabIndex = 2;
            // 
            // buttonRemove
            // 
            this->buttonRemove->Location = System::Drawing::Point(213, 20);
            this->buttonRemove->Name = L"buttonRemove";
            this->buttonRemove->Size = System::Drawing::Size(75, 23);
            this->buttonRemove->TabIndex = 3;
            this->buttonRemove->Text = L"Remove";
            this->buttonRemove->UseVisualStyleBackColor = true;
            this->buttonRemove->Click += gcnew System::EventHandler(this, &removeclass::buttonRemove_Click);
            // 
            // removeclass
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(950, 330);
            this->Controls->Add(this->buttonRemove);
            this->Controls->Add(this->textBoxClassID);
            this->Controls->Add(this->labelClassID);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"removeclass";
            this->Text = L"Remove Class";
            this->Load += gcnew System::EventHandler(this, &removeclass::removeclass_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void removeclass_Load(System::Object^ sender, System::EventArgs^ e) {
        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");

        try {
            sqlConn->Open();

            // Create a SQL command to select all rows from the "Timetable" table with joins
            SqlCommand^ cmd = gcnew SqlCommand(
                "SELECT " +
                "t.ID, " +
                "s.Name AS StudentName, " +
                "te.Name AS TeacherName, " +
                "r.RoomNumber, " +
                "c.CourseName, " +
                "t.Day, " +
                "t.StartTime, " +
                "t.EndTime, " +
                "t.Section " +
                "FROM dbo.Timetable t " +
                "LEFT JOIN dbo.Students s ON t.StudentID = s.ID " +
                "LEFT JOIN dbo.Teachers te ON t.TeacherID = te.ID " +
                "LEFT JOIN dbo.Rooms r ON t.RoomID = r.ID " +
                "LEFT JOIN dbo.Courses c ON t.CourseID = c.ID;", sqlConn);

            // Execute the SQL command and retrieve the data
            SqlDataReader^ dr = cmd->ExecuteReader();

            // Create a DataTable to store the data
            DataTable^ dataTable = gcnew DataTable();

            // Load data directly into DataTable
            dataTable->Load(dr);

            // Set the DataTable as the DataSource for the DataGridView
            dataGridView1->DataSource = dataTable;

            // Close the SqlDataReader and the database connection
            dr->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("An error occurred: " + ex->Message);
        }
        finally {
            if (sqlConn->State == ConnectionState::Open) {
                sqlConn->Close();
            }
        }
    }

    private: System::Void buttonRemove_Click(System::Object^ sender, System::EventArgs^ e) {
        // Retrieve Class ID from the TextBox
        String^ classID = textBoxClassID->Text;

        // Create a connection to the database
        SqlConnection^ sqlConn = gcnew SqlConnection("Server=DESKTOP-Q37VPK2;Database=TimetableManagement;Integrated Security=True;");
        sqlConn->Open();

        // Create a SQL command to delete the class from the Timetable table
        SqlCommand^ cmd = gcnew SqlCommand("DELETE FROM Timetable WHERE ID = @ID", sqlConn);
        cmd->Parameters->AddWithValue("@ID", Int32::Parse(classID));

        // Execute the SQL command to delete the class
        try {
            int rowsAffected = cmd->ExecuteNonQuery();
            if (rowsAffected > 0) {
                MessageBox::Show("Class removed successfully!");
                // Refresh the DataGridView
                removeclass_Load(sender, e);
            }
            else {
                MessageBox::Show("Class not found!");
            }
        }
        catch (SqlException^ ex) {
            MessageBox::Show("Error removing class: " + ex->Message);
        }

        // Close the database connection
        sqlConn->Close();
    }

    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
    };
}
