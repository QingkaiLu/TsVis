// GraphViewContainerView.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "GraphViewContainerView.h"


// GraphViewContainerView

IMPLEMENT_DYNCREATE(GraphViewContainerView, CView)

GraphViewContainerView::GraphViewContainerView()
{

}

GraphViewContainerView::~GraphViewContainerView()
{
}

BEGIN_MESSAGE_MAP(GraphViewContainerView, CView)
END_MESSAGE_MAP()


// GraphViewContainerView drawing

void GraphViewContainerView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// GraphViewContainerView diagnostics

#ifdef _DEBUG
void GraphViewContainerView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void GraphViewContainerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// GraphViewContainerView message handlers
