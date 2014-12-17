// MyTabCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "MyTabCtrl.h"


// CMyTabCtrl

IMPLEMENT_DYNAMIC(CMyTabCtrl, CTabCtrl)

CMyTabCtrl::CMyTabCtrl()
: mPage0(NULL)
, mPage1(NULL)
, mPage2(NULL)
{
	mPage0 = new CTabPage0;
	mPage1 = new CTabPage1;
	mPage2 = new CTabPage2;
}

CMyTabCtrl::~CMyTabCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTabCtrl, CTabCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTabCtrl::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTabCtrl message handlers




int CMyTabCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTabCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}


void CMyTabCtrl::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	activatePages();
	*pResult = 0;
}


void CMyTabCtrl::activatePages(void)
{
	if(mPage0->m_hWnd) mPage0->ShowWindow(SW_HIDE);
	if(mPage1->m_hWnd) mPage1->ShowWindow(SW_HIDE);
	if(mPage2->m_hWnd) mPage2->ShowWindow(SW_HIDE);

	CRect clientRect;
	GetClientRect(clientRect);
	AdjustRect(FALSE,clientRect);	// FALSE: move rect of whole tab contol to display area of tab control

	int sel = GetCurSel();
	switch(sel)
	{
	case 0:
		mPage0->SetWindowPos(&wndTop,clientRect.left,clientRect.top,clientRect.Width(),clientRect.Height(),SWP_SHOWWINDOW);
		mPage0->ShowWindow(SW_SHOW);
		break;
	case 2:
		mPage1->SetWindowPos(&wndTop,clientRect.left,clientRect.top,clientRect.Width(),clientRect.Height(),SWP_SHOWWINDOW);
		mPage1->ShowWindow(SW_SHOW);
		break;
	case 1:
		mPage2->SetWindowPos(&wndTop,clientRect.left,clientRect.top,clientRect.Width(),clientRect.Height(),SWP_SHOWWINDOW);
		mPage2->ShowWindow(SW_SHOW);
		break;
	}	
}


void CMyTabCtrl::createPages(void)
{
	mPage0->Create(CTabPage0::IDD, this);
	mPage1->Create(CTabPage1::IDD, this);
	mPage2->Create(CTabPage2::IDD, this);
}
