
// CodeChallengeDlg.h : header file
//

#pragma once

// CCodeChallengeDlg dialog
class CCodeChallengeDlg : public CDialogEx
{
// Construction
public:
	CCodeChallengeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CODECHALLENGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On_BtnClicked_Data1();
	afx_msg void On_BtnClicked_Data2();
	afx_msg void On_BtnClicked_Data3();

private:
   int Years[101];
	void LogLivingYears(int birth, int death);
};
