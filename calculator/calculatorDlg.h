
// calculatorDlg.h : 头文件
//

#pragma once
#include <math.h>

// CcalculatorDlg 对话框
class CcalculatorDlg : public CDialogEx
{
// 构造
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double  m_display;
	int     m_count;
	BOOL    m_dotFlag;
	BOOL    m_continueFlag;
	BOOL    m_strFlag;//有没按运算符标志
    CString m_str;//记录当前按的运算符
    double  m_result; //num1和num2运算的结果
    double  m_num1; //按运算符之前的第一个数
    double  m_num2; //按运算符之后的第二个数

	double buttonDownNum(int numSize);

	afx_msg void OnBnClickedButtonNum7();
	afx_msg void OnBnClickedButtonNum8();
	afx_msg void OnBnClickedButtonNum9();
	afx_msg void OnBnClickedButtonNum4();
	afx_msg void OnBnClickedButtonNum5();
	afx_msg void OnBnClickedButtonNum6();
	afx_msg void OnBnClickedButtonNum1();
	afx_msg void OnBnClickedButtonNum2();
	afx_msg void OnBnClickedButtonNum3();
	afx_msg void OnBnClickedButtonNum0();
	afx_msg void OnBnClickedButtonOperatorDiv();
	afx_msg void OnBnClickedButtonOperatorMul();
	afx_msg void OnBnClickedButtonOperatorSub();
	afx_msg void OnBnClickedButtonOperatorAdd();
	afx_msg void OnBnClickedButtonCalculate();
	afx_msg void OnBnClickedButtonClear();
	afx_msg void OnBnClickedButtonDecimalPoint();
};
