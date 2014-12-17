
// MainFrm.cpp : implementation of the CMainFrame class
//
#include "stdafx.h"
#include "TenVis.h"
#include "InputView.h"
#include "TransControlView.h"
#include "3DContainerView.h"
#include "GraphViewContainerView.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int mWinWidth		= 512;//800;
const int mWinHeight	= 512;//800;

const int mGraphViewWinWidth	= 512;//800;
const int mGraphViewWinHeight	= 300;//100;


// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{ 
		if(		m_wndSplitter.CreateStatic(this,1,3) 
		&&  m_wndSplitter2.CreateStatic(&m_wndSplitter, 2,1,
				WS_CHILD | WS_VISIBLE | WS_BORDER, // WS_BORDER is needed	
				m_wndSplitter.IdFromRowCol(0,1)))
	{
		BOOL r1, r2, r3, r4, r5;

		// main 3D window
		CSize dim(mWinWidth, mWinHeight);
		CClientDC dc(this);
		dc.DPtoLP(&dim);
		r4 = m_wndSplitter2.CreateView(0,0,RUNTIME_CLASS(C3DContainerView),dim,pContext);

		// Graph view window (3D)
		CSize dim2(mGraphViewWinWidth, mGraphViewWinHeight);
		dc.DPtoLP(&dim2);
		r5 = m_wndSplitter2.CreateView(1,0,RUNTIME_CLASS(GraphViewContainerView),dim2,pContext);

		r1 = m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(CTransControlView),CSize(100,0),pContext);
		//r2 = m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(C3DContainerView),dim,pContext);
		r3 = m_wndSplitter.CreateView(0,2,RUNTIME_CLASS(CInputView),CSize(0,0),pContext);

	/*		if(		m_wndSplitter.GetSafeHwnd()
		&& m_wndSplitter2.GetSafeHwnd())
	{
		int w = mGraphViewWinWidth;
		m_wndSplitter.SetColumnInfo(1, w, 0);
		m_wndSplitter.RecalcLayout();

		int h1 = mWinHeight;
		int h2 = mGraphViewWinHeight;
		m_wndSplitter2.SetColumnInfo(0, w, 0);
		m_wndSplitter2.SetRowInfo(0, h1, 0);		
		m_wndSplitter2.SetRowInfo(1, h2, 0);
		m_wndSplitter2.RecalcLayout();
	}*/
		if(r1 && r3 && r4 && r5)
			return TRUE;
		else
			return FALSE;
	}
	return FALSE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

    cs.cx =	967; //962;	// 1130 when main 3D window is 700w
	cs.cy = 955;	// 1005 when main 3D window is 700h and Graph View window is 200h

	//! lock window size for now:
	cs.style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers


void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: Add your message handler code here

		if(		m_wndSplitter.GetSafeHwnd()
		&& m_wndSplitter2.GetSafeHwnd())
	{
		int w = mGraphViewWinWidth;
		m_wndSplitter.SetColumnInfo(1, w, 0);
		m_wndSplitter.RecalcLayout();

		int h1 = mWinHeight;
		int h2 = mGraphViewWinHeight;
		m_wndSplitter2.SetColumnInfo(0, w, 0);
		m_wndSplitter2.SetRowInfo(0, h1, 0);		
		m_wndSplitter2.SetRowInfo(1, h2, 0);
		m_wndSplitter2.RecalcLayout();
	}
}


void CMainFrame::OnDestroy()
{
	CFrameWnd::OnDestroy();

	// TODO: Add your message handler code here
}
