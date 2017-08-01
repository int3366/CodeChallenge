
// CodeChallengeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CodeChallenge.h"
#include "CodeChallengeDlg.h"
#include "afxdialogex.h"
#include "Results.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCodeChallengeDlg dialog



CCodeChallengeDlg::CCodeChallengeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CODECHALLENGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCodeChallengeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCodeChallengeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_DATA1, &CCodeChallengeDlg::On_BtnClicked_Data1)
	ON_BN_CLICKED(IDC_BTN_DATA2, &CCodeChallengeDlg::On_BtnClicked_Data2)
	ON_BN_CLICKED(IDC_BTN_DATA3, &CCodeChallengeDlg::On_BtnClicked_Data3)
END_MESSAGE_MAP()


// CCodeChallengeDlg message handlers

BOOL CCodeChallengeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCodeChallengeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCodeChallengeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCodeChallengeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CCodeChallengeDlg::LogLivingYears(int birth, int death)
{
   int _birth = birth % 100;
   int _death = death % 100;
   for (int x = _birth; x <= _death; ++x)
   {
      Years[x] += 1;
   }
}

void CCodeChallengeDlg::On_BtnClicked_Data1()
{
   memset(Years, 0, sizeof(Years));

	LogLivingYears(1900, 1910);
   LogLivingYears(1900, 2000);
   LogLivingYears(1900, 1910);
   LogLivingYears(1900, 1920);
   LogLivingYears(1900, 1930);
   LogLivingYears(1900, 1940);
   LogLivingYears(1900, 1950);
	LogLivingYears(1900, 1960);
	LogLivingYears(1900, 1970);
	LogLivingYears(1900, 1980);

   // Display results.
   CResults dlgResults;
   memcpy(dlgResults.LivingYears, Years, sizeof(Years));
   dlgResults.DoModal();
}

void CCodeChallengeDlg::On_BtnClicked_Data2()
{
   memset(Years, 0, sizeof(Years));

   LogLivingYears(1901, 1910);
   LogLivingYears(1911, 1920);
   LogLivingYears(1921, 1930);
   LogLivingYears(1931, 1940);
   LogLivingYears(1941, 1950);
   LogLivingYears(1951, 1960);
   LogLivingYears(1961, 1970);
   LogLivingYears(1971, 1980);
   LogLivingYears(1981, 1990);

   // Display results.
   CResults dlgResults;
   memcpy(dlgResults.LivingYears, Years, sizeof(Years));
   dlgResults.DoModal();
}

void CCodeChallengeDlg::On_BtnClicked_Data3()
{
   memset(Years, 0, sizeof(Years));

   LogLivingYears(1900, 1950);
	LogLivingYears(1911, 1950);
	LogLivingYears(1980, 2000);
	LogLivingYears(1965, 1990);
	LogLivingYears(1950, 2000);
	LogLivingYears(1952, 1995);
	LogLivingYears(1948, 1970);
	LogLivingYears(1934, 1993);
	LogLivingYears(1945, 1975);

   // Display results.
   CResults dlgResults;
   memcpy(dlgResults.LivingYears, Years, sizeof(Years));
   dlgResults.DoModal();
}
