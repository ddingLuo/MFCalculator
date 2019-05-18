
// calculatorDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CcalculatorDlg 对话框



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


// CcalculatorDlg 消息处理程序

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

double CcalculatorDlg::buttonDownNum(int numSize)
{
	if (!m_strFlag) //运算符没有被按下，那就是num1
    {
        if (!m_continueFlag) //按下一次
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
    else  //有运算符被按下
    {
        if (!m_continueFlag) //是否连续按下
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
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(7);    
    UpdateData(FALSE); 
}


void CcalculatorDlg::OnBnClickedButtonNum8()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(8);    
    UpdateData(FALSE); 
}


void CcalculatorDlg::OnBnClickedButtonNum9()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(9);    
    UpdateData(FALSE); 
}


void CcalculatorDlg::OnBnClickedButtonNum4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(4);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum5()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(5);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(6);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(1);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum2()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(2);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum3()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(3);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonNum0()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display = buttonDownNum(0);    
    UpdateData(FALSE);
}


void CcalculatorDlg::OnBnClickedButtonOperatorDiv()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	m_dotFlag = TRUE;
	//    GetDlgItem(IDC_DISPLAY)->SetWindowText("小数点"); //可以利用该函数在编辑框中显示信息

}
