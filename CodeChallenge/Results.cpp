// Results.cpp : implementation file
//

#include "stdafx.h"
#include "CodeChallenge.h"
#include "Results.h"
#include "afxdialogex.h"


// CResults dialog

IMPLEMENT_DYNAMIC(CResults, CDialogEx)

CResults::CResults(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RESULTS, pParent)
{

}

CResults::~CResults()
{
}

void CResults::DoDataExchange(CDataExchange* pDX)
{
   CDialogEx::DoDataExchange(pDX);
   DDX_Control(pDX, IDC_LISTYEARS, YearList);
}


BEGIN_MESSAGE_MAP(CResults, CDialogEx)
END_MESSAGE_MAP()


// CResults message handlers


BOOL CResults::OnInitDialog()
{
   CDialogEx::OnInitDialog();
   
   YearList.InsertColumn(0, _T("Year"), LVCFMT_LEFT, 90);
   YearList.InsertColumn(1, _T("People Living"), LVCFMT_LEFT, 90);
   YearList.SendMessage(LVM_SETEXTENDEDLISTVIEWSTYLE, 0,
      LVS_EX_FULLROWSELECT);

   for (int x = 1900, y = 0; x < 2001; ++x, ++y)
   {
      if (LivingYears[y])
      {
         CString tmpString;
         tmpString.Format(_T("%d"), x);
         int nIndex = YearList.InsertItem(0, tmpString);
         tmpString.Format(_T("%d"), LivingYears[y]);
         YearList.SetItemText(nIndex, 1, tmpString);
      }
   }
   return TRUE;  // return TRUE unless you set the focus to a control
                 // EXCEPTION: OCX Property Pages should return FALSE
}
