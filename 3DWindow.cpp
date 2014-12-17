// C3DWindow.cpp : implementation file
//

#include "stdafx.h"
#include "TenVis.h"
#include "3DWindow.h"
#include "VisOpManager.h"

// C3DWindow

IMPLEMENT_DYNAMIC(C3DWindow, CWnd)

C3DWindow::C3DWindow()
: mRenderTimer(0)
, mDoc(NULL)
{   
	//New singleton for mFieldRenderer
	mFieldRenderer = mFieldRenderer->getInstance();
}

C3DWindow::~C3DWindow()
{
}


BEGIN_MESSAGE_MAP(C3DWindow, CWnd)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MBUTTONDBLCLK()
	ON_WM_MBUTTONDOWN()
	ON_WM_MBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void C3DWindow::createWindow(int left, int top, CWnd* parent, CTenVisDoc* pDoc)
{
	CRect rect;
	rect.left	= left;
	rect.top	= top;
	rect.right	= rect.left + VisOpManager::mWinWidth;
	rect.bottom	= rect.top  + VisOpManager::mWinHeight;

	CString classname = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_OWNDC,
		LoadCursor(NULL,IDC_ARROW), (HBRUSH)GetStockObject(BLACK_BRUSH), 
		NULL);

	CreateEx(0, classname, _T("3DWindow"), WS_CHILD | WS_VISIBLE |
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, parent, 0);

	mRenderTimer = this->SetTimer(1,10,NULL);		// set up render timer, interval: 10 milliseconds
	mDoc = pDoc;

}



void C3DWindow::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

   if(nIDEvent == mRenderTimer)
	{
		    //mDC = this->GetDC()->m_hDC;
	        //mRC = wglCreateContext(mDC);
			wglMakeCurrent(mDC, mRC);
			// Clear color and depth buffer bits
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if(mDoc->mPoly)
			{
			    //mFieldRenderer = mFieldRenderer->getInstance(mDoc->mPoly);
				mFieldRenderer->setPoly(mDoc->mPoly);
			    mFieldRenderer->setupTransform();
				mFieldRenderer->initGlsl(mDoc->isPlyChanged);
			    mFieldRenderer->renderEigVecMfd();
			    //displayInWindow(mDoc->mPoly);
			}

			SwapBuffers(mDC);

			wglMakeCurrent(NULL, NULL);

	}

	CWnd::OnTimer(nIDEvent);
}


void C3DWindow::initOpenGL(void)
{
		static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,    // bit depth
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		32,		// z-buffer depth
		8,		// stencil-buffer depth
		0, PFD_MAIN_PLANE, 0, 0, 0, 0,
	};
	mDC = this->GetDC()->m_hDC;
	int mPixelFormat;
	mPixelFormat = ChoosePixelFormat(mDC,&pfd);
	SetPixelFormat(mDC, mPixelFormat, &pfd);
	mRC = wglCreateContext(mDC);
	wglMakeCurrent(mDC, mRC);

	glViewport(0,0,VisOpManager::mWinWidth,VisOpManager::mWinHeight);
	glClearColor( 1.0, 1.0, 1.0, 1.0 );

	//initialize glew
	GLenum result = glewInit();
	if (result!=GLEW_OK)
        fprintf(stderr, "Error: %s\n", glewGetErrorString(result));

}


void C3DWindow::OnLButtonDown(UINT nFlags, CPoint point)
{
	mLButtonDownReceived = true;
	mLastMouseClick = point;

	CWnd::OnLButtonDown(nFlags, point);
}


void C3DWindow::OnLButtonUp(UINT nFlags, CPoint point)
{
	mLButtonDownReceived = false;
	mLastMouseClick = point;

	CWnd::OnLButtonUp(nFlags, point);
}



void C3DWindow::OnMButtonDown(UINT nFlags, CPoint point)
{
	mMButtonDownReceived = true;
	mLastMouseClick = point;

	CWnd::OnMButtonDown(nFlags, point);
}


void C3DWindow::OnMButtonUp(UINT nFlags, CPoint point)
{
	mMButtonDownReceived = false;
	mLastMouseClick = point;

	CWnd::OnMButtonUp(nFlags, point);
}


void C3DWindow::OnRButtonDown(UINT nFlags, CPoint point)
{
	mRButtonDownReceived = true;
	mLastMouseClick = point;

	CWnd::OnRButtonDown(nFlags, point);
}


void C3DWindow::OnRButtonUp(UINT nFlags, CPoint point)
{
	mRButtonDownReceived = false;
	mLastMouseClick = point;

	CWnd::OnRButtonUp(nFlags, point);
}


void C3DWindow::OnMouseMove(UINT nFlags, CPoint point)
{

	// point: relative to the upper-left corner of the window
	float dx, dy;
	dx = point.x - mLastMouseClick.x;
	dy = point.y - mLastMouseClick.y;

	if((nFlags & MK_LBUTTON) && mLButtonDownReceived)
	{
		float s = 1;
		Quaternion qx(Degree(dx*s), Vector3(0,1,0));
		Quaternion qy(Degree(dy*s), Vector3(1,0,0));
		mFieldRenderer->rotate(qx*qy);
	}
	else if((nFlags & MK_MBUTTON) && mMButtonDownReceived)
	{
		float s = mFieldRenderer->getPoly()->radius*0.006;
		mFieldRenderer->translate(dx*s, -dy*s, 0);
	}
	else if((nFlags & MK_RBUTTON) && mRButtonDownReceived)
	{
		float s = 0.002; //mFieldRenderer.getPoly()->radius*0.001;
		float d = (dx-dy) * s + 1;
		mFieldRenderer->scale(d,d,d);		
	}
	//float d =2.0;
	//mFieldRenderer.scale(d,d,d);

	mLastMouseClick = point;

	CWnd::OnMouseMove(nFlags, point);
}
