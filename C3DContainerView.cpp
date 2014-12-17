// C3DContainerView.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "C3DContainerView.h"


// C3DContainerView

IMPLEMENT_DYNCREATE(C3DContainerView, CView)

C3DContainerView::C3DContainerView()
{

}

C3DContainerView::~C3DContainerView()
{
}

BEGIN_MESSAGE_MAP(C3DContainerView, CView)
END_MESSAGE_MAP()


// C3DContainerView drawing

void C3DContainerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
	//ValidateRect(NULL);
}


// C3DContainerView diagnostics

#ifdef _DEBUG
void C3DContainerView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void C3DContainerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// C3DContainerView message handlers
