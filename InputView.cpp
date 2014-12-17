// InputView.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "InputView.h"


// CInputView

IMPLEMENT_DYNCREATE(CInputView, CFormView)

CInputView::CInputView()
	: CFormView(CInputView::IDD)
{

}

CInputView::~CInputView()
{
}

void CInputView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, mTabCtrl);
}

BEGIN_MESSAGE_MAP(CInputView, CFormView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CInputView diagnostics

#ifdef _DEBUG
void CInputView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInputView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CInputView message handlers


int CInputView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFormView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}


void CInputView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: Add your specialized code here and/or call the base class

		CFormView::OnInitialUpdate();

	/*
	RECT rect;
	this->GetClientRect(&rect);
	mTabCtrl.AdjustRect(FALSE, &rect);
	mTabCtrl.Create(TCS_TABS | WS_CHILD | WS_VISIBLE,
		rect, this, 0x1006);
	*/

	// These two lines cannot put in CInputView::onCreate():
	static bool initialized = false;
	if(!initialized)
	{
		initialized = true;
		mTabCtrl.createPages();
		mTabCtrl.InsertItem(0, "Visualization Option");
		mTabCtrl.InsertItem(1, "Misc Option");
		mTabCtrl.InsertItem(2, "Field Operation");
		mTabCtrl.activatePages();
	}	
}


void CInputView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: Add your specialized code here and/or call the base class
}
