
// TenVisDoc.cpp : implementation of the CTenVisDoc class
//

#include "stdafx.h"
#include <iostream>

// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TenVis.h"
#endif

#include "TenVisDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTenVisDoc

IMPLEMENT_DYNCREATE(CTenVisDoc, CDocument)

BEGIN_MESSAGE_MAP(CTenVisDoc, CDocument)
END_MESSAGE_MAP()


// CTenVisDoc construction/destruction

CTenVisDoc::CTenVisDoc()
	: fp(NULL)
	, mPoly(NULL)
{
	// TODO: add one-time construction code here
	isPlyChanged = false;
}

CTenVisDoc::~CTenVisDoc()
{
}

BOOL CTenVisDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CTenVisDoc serialization

void CTenVisDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTenVisDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTenVisDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTenVisDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTenVisDoc diagnostics

#ifdef _DEBUG
void CTenVisDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTenVisDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTenVisDoc commands


BOOL CTenVisDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	// TODO:  Add your specialized creation code here
	FILE* thisFile = fopen(lpszPathName, "r");
	mPoly = new Polyhedron(thisFile);
	//mPoly->initialize();
	//mFieldMaster = mFieldMaster->getInstance(mPoly);
	mFieldMaster = mFieldMaster->getInstance();
	mFieldMaster->setPoly(mPoly);
	mFieldMaster->initPoly();
	fclose(thisFile);

	//Redo initialization for glsl when ply file changed
	isPlyChanged = true;

	return TRUE;
}
