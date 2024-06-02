#pragma once

using namespace System::Data;
using namespace System::Data::SqlClient;

namespace TIMETABLE {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class coursewise : public System::Windows::Forms::Form
    {
    public:
        coursewise(void)
        {
            InitializeComponent();
            this->tsearchbtn->Click += gcnew System::EventHandler(this, &coursewise::tsearchbtn_Click);
        }

    protected:
        ~coursewise()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ StudentName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ TeacherName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomNumber;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ CourseName;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Day;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ StartTime;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ EndTime;
    private: System::Windows::Forms::DataGridViewTextBoxColumn^ Section;
    private: System::Windows::Forms::TextBox^ tsearchbox;
    private: System::Windows::Forms::Button^ tsearchbtn;

    private:
        System::ComponentModel::Container^ components;
        DataTable^ dataTable;

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
            this->tsearchbox = (gcnew System::Windows::Forms::TextBox());
            this->tsearchbtn = (gcnew System::Windows::Forms::Button());
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
            this->dataGridView1->Location = System::Drawing::Point(12, 82);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(926, 206);
            this->dataGridView1->TabIndex = 0;
            this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &coursewise::dataGridView1_CellContentClick);
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
            // tsearchbox
            // 
            this->tsearchbox->Location = System::Drawing::Point(24, 22);
            this->tsearchbox->Name = L"tsearchbox";
            this->tsearchbox->Size = System::Drawing::Size(308, 20);
            this->tsearchbox->TabIndex = 1;
            // 
            // tsearchbtn
            // 
            this->tsearchbtn->Location = System::Drawing::Point(360, 22);
            this->tsearchbtn->Name = L"tsearchbtn";
            this->tsearchbtn->Size = System::Drawing::Size(75, 23);
            this->tsearchbtn->TabIndex = 2;
            this->tsearchbtn->Text = L"search";
            this->tsearchbtn->UseVisualStyleBackColor = true;
            // 
            // coursewise
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(950, 300);
            this->Controls->Add(this->tsearchbtn);
            this->Controls->Add(this->tsearchbox);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"coursewise";
            this->Text = L"View Timetable";
            this->Load += gcnew System::EventHandler(this, &coursewise::coursewise_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
            
        }
#pragma endregion

    private: System::Void coursewise_Load(System::Object^ sender, System::EventArgs^ e) {
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
            dataTable = gcnew DataTable();

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

    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }

    private: System::Void tsearchbtn_Click(System::Object^ sender, System::EventArgs^ e) {
        // Get the search text from the textbox
        String^ searchText = tsearchbox->Text;

        // Filter the DataTable based on the search text in the TeacherName column
        DataView^ dv = dataTable->DefaultView;
        dv->RowFilter = String::Format("CourseName LIKE '%{0}%'", searchText);

        // Update the DataGridView with the filtered data
        dataGridView1->DataSource = dv;
    }
    };
}
