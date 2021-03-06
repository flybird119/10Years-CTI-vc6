// SelectTreeForm.cpp : implementation file
//

#include "stdafx.h"
#include "CifCommServer.h"
#include "ActiveMsgForm.h"
#include "SelectTreeForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern CActiveMsgForm *g_pActiveMsgForm;

/////////////////////////////////////////////////////////////////////////////
// CSelectTreeForm

IMPLEMENT_DYNCREATE(CSelectTreeForm, CFormView)

CSelectTreeForm::CSelectTreeForm()
	: CFormView(CSelectTreeForm::IDD)
{
	//{{AFX_DATA_INIT(CSelectTreeForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

}

CSelectTreeForm::~CSelectTreeForm()
{
}

void CSelectTreeForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSelectTreeForm)
	DDX_Control(pDX, IDC_TREE_SELECT, m_selectTree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSelectTreeForm, CFormView)
	//{{AFX_MSG_MAP(CSelectTreeForm)
	ON_WM_SIZE()
	ON_NOTIFY(NM_DBLCLK, IDC_TREE_SELECT, OnDblclkTreeSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelectTreeForm diagnostics

#ifdef _DEBUG
void CSelectTreeForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CSelectTreeForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSelectTreeForm message handlers

void CSelectTreeForm::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	if( 1 != m_InitialUpdate )
	{
		m_InitialUpdate=1;
		m_selectTree.MoveWindow(0,0,m_cx,m_cy);

		HTREEITEM  hitem= m_selectTree.InsertItem("Active",TVI_ROOT,TVI_LAST);
		m_selectTree.InsertItem( "ActiveSocket",  hitem, TVI_LAST );
		m_selectTree.InsertItem( "CITMessage",  hitem, TVI_LAST );
		m_selectTree.InsertItem( "AgentMessage",  hitem, TVI_LAST );
		m_selectTree.InsertItem( "IVRMessage",  hitem, TVI_LAST );
		m_selectTree.InsertItem( "ACDMessage",  hitem, TVI_LAST );
		m_selectTree.Expand( hitem, TVE_EXPAND );

	}
	
}

void CSelectTreeForm::OnSize(UINT nType, int cx, int cy) 
{
	m_cx=cx;
	m_cy=cy;
	if(m_InitialUpdate==1)
	{

		m_selectTree.MoveWindow(0,0,m_cx,m_cy);

	}
	
}

void CSelectTreeForm::OnDblclkTreeSelect(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HTREEITEM hItem = m_selectTree.GetSelectedItem();
	if( NULL == hItem  ) return;
	CString str = m_selectTree.GetItemText(hItem);
	if( "Active" == str ) return;
	if( g_pActiveMsgForm != NULL )
	{
		g_pActiveMsgForm->ShowList( str );
	}
	
	*pResult = 0;
}
