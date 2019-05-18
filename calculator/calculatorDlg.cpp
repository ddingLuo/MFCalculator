
// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CcalculatorDlg::IDD, pParent)
	, m_display(0)
{
	m_num1 = 0;
    m_num2 = 0;
    m_result = 0.0;
    m_str = "";
    m_strFlag = FALSE;
    m_continueFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_DIAPLAY, m_display);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NUM7, &CcalculatorDlg::OnBnClickedButtonNum7)
	ON_BN_CLICKED(IDC_BUTTON_NUM8, &CcalculatorDlg::OnBnClickedButtonNum8)
	ON_BN_CLICKED(IDC_BUTTON_NUM9, &CcalculatorDlg::OnBnClickedButtonNum9)
	ON_BN_CLICKED(IDC_BUTTON_NUM4, &CcalculatorDlg::OnBnClickedButtonNum4)
	ON_BN_CLICKED(IDC_BUTTON_NUM5, &CcalculatorDlg::OnBnClickedButtonNum5)
	ON_BN_CLICKED(IDC_BUTTON_NUM6, &CcalculatorDlg::OnBnClickedButtonNum6)
	ON_BN_CLICKED(IDC_BUTTON_NUM1, &CcalculatorDlg::OnBnClickedButtonNum1)
	ON_BN_CLICKED(IDC_BUTTON_NUM2, &CcalculatorDlg::OnBnClickedButtonNum2)
	ON_BN_CLICKED(IDC_BUTTON_NUM3, &CcalculatorDlg::OnBnClickedButtonNum3)
	ON_BN_CLICKED(IDC_BUTTON_NUM0, &CcalculatorDlg::OnBnClickedButtonNum0)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_DIV, &CcalculatorDlg::OnBnClickedButtonOperatorDiv)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_MUL, &CcalculatorDlg::OnBnClickedButtonOperatorMul)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_SUB, &CcalculatorDlg::OnBnClickedButtonOperatorSub)
	ON_BN_CLICKED(IDC_BUTTON_OPERATOR_ADD, &CcalculatorDlg::OnBnClickedButtonOperatorAdd)
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CcalculatorDlg::OnBnClickedButtonCalculate)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &CcalculatorDlg::OnBnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL_POINT, &CcalculatorDlg::OnBnClickedButtonDecimalPoint)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

double CcalculatorDlg::buttonDownNum(int numSize)
{
	if (!m_strFlag) //�����û�б����£��Ǿ���num1
    {
        if (!m_continueFlag) //����һ��
        {
            m_num1 = numSize;
            m_continueFlag =TRUE;
        }
        else
        {
            m_num1 = m_num1*pow(10.0,m_count) + numSize;
            if (m_dotFlag)
            {
                m_num1 = m_num1/(pow(10.0,m_count));
                m_count++;
            }
        }
        
        return m_num1;
    }
    else  //�������������
    {
        if (!m_continueFlag) //�Ƿ���������
        {
            m_num2 = numSize;
            m_continueFlag =TRUE;
        }
        else
        {
            m_num2 = m_num2*pow(10.0,m_count) + numSize;
            if (m_dotFlag)
            {
                m_num2 = m_num2/(pow(10.0,m_count));
                m_count++;
            }
        }
        
        return m_num2;
    }
}

void CcalculatorDlg::OnBnClickedButtonNum7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(7);    
    UpdateData(FALSE); 
}


void CcalculatorDlg::OnBnClickedButtonNum8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(8);    
    UpdateData(FALSE); 
}


void CcalculatorDlg::OnBnClickedButtonNum9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(9);    
    UpdateData(FALSE); 
}


void CcalculatorDlg::OnBnClickedButtonNum4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(4);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(5);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(6);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(1);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(2);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(3);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_display = buttonDownNum(0);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonOperatorDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_strFlag)
	{
		OnBnClickedButtonCalculate();
		m_num1 = m_result;
	}
	m_str = "/";    
    m_strFlag = TRUE;
    m_continueFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonOperatorMul()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_strFlag)
	{
		OnBnClickedButtonCalculate();
		m_num1 = m_result;
	}
	m_str = "*";    
    m_strFlag = TRUE;
    m_continueFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonOperatorSub()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_strFlag)
	{
		OnBnClickedButtonCalculate();
		m_num1 = m_result;
	}
	m_str = "-";    
    m_strFlag = TRUE;
    m_continueFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonOperatorAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_strFlag)
	{
		OnBnClickedButtonCalculate();
		m_num1 = m_result;
	}
	m_str = "+";    
    m_strFlag = TRUE;
    m_continueFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonCalculate()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_str == "+")
	{
        m_result = m_num1 + m_num2;
	}
    else if(m_str == "-")
	{
		m_result = m_num1 - m_num2;
	}        
    else if(m_str == "*")
	{
		m_result = m_num1 * m_num2;
	}
    else if(m_str == "/")
    {
        m_result = double(m_num1) / double(m_num2);
    }

    m_num1 = m_result;
    m_display = m_result;
    m_strFlag = FALSE;
    m_continueFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_num1 = 0;
    m_num2 = 0;
    m_display = 0;
    m_continueFlag = FALSE;
    m_strFlag = FALSE;
    m_dotFlag = FALSE;
    m_count = 1;
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonDecimalPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_dotFlag = TRUE;
	//    GetDlgItem(IDC_DISPLAY)->SetWindowText("С����"); //�������øú����ڱ༭������ʾ��Ϣ

}
