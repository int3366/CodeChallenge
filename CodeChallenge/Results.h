#pragma once
#include "afxcmn.h"


// CResults dialog

class CResults : public CDialogEx
{
	DECLARE_DYNAMIC(CResults)

public:
	CResults(CWnd* pParent = NULL);   // standard constructor
	virtual ~CResults();

   int LivingYears[101];

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RESULTS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
   CListCtrl YearList;
   virtual BOOL OnInitDialog();
};
