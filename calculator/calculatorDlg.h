
// calculatorDlg.h : ͷ�ļ�
//

#pragma once
#include <math.h>

// CcalculatorDlg �Ի���
class CcalculatorDlg : public CDialogEx
{
// ����
public:
	CcalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CALCULATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
	BOOL    m_strFlag;//��û���������־
    CString m_str;//��¼��ǰ���������
    double  m_result; //num1��num2����Ľ��
    double  m_num1; //�������֮ǰ�ĵ�һ����
    double  m_num2; //�������֮��ĵڶ�����

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
