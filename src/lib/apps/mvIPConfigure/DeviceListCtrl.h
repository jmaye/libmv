//-----------------------------------------------------------------------------
#ifndef DeviceListCtrlH
#define DeviceListCtrlH DeviceListCtrlH
//-----------------------------------------------------------------------------
#include "wx/listctrl.h"

class IPConfigureFrame;
class LogOutputHandlerDlg;

//-----------------------------------------------------------------------------
/// \brief IDs for the menu commands
enum
//-----------------------------------------------------------------------------
{
	LIST_ABOUT = wxID_ABOUT,
	LIST_QUIT = wxID_EXIT,
	LIST_LIST_VIEW = wxID_HIGHEST,
	LIST_ICON_VIEW,
	LIST_ICON_TEXT_VIEW,
	LIST_SMALL_ICON_VIEW,
	LIST_SMALL_ICON_TEXT_VIEW,
	LIST_REPORT_VIEW,
	LIST_VIRTUAL_VIEW,
	LIST_SMALL_VIRTUAL_VIEW,
	LIST_DESELECT_ALL,
	LIST_SELECT_ALL,
	LIST_DELETE_ALL,
	LIST_DELETE,
	LIST_ADD,
	LIST_EDIT,
	LIST_SORT,
	LIST_SET_FG_COL,
	LIST_SET_BG_COL,
	LIST_TOGGLE_MULTI_SEL,
	LIST_TOGGLE_FIRST,
	LIST_SHOW_COL_INFO,
	LIST_SHOW_SEL_INFO,
	LIST_FOCUS_LAST,
	LIST_FREEZE,
	LIST_THAW,
	LIST_TOGGLE_LINES,
	LIST_CTRL = 1000
};

//-----------------------------------------------------------------------------
enum
//-----------------------------------------------------------------------------
{
	LIST_ASSIGN_TEMPORARY_IP = LIST_CTRL + 1
};

//-----------------------------------------------------------------------------
enum TListColumn
//-----------------------------------------------------------------------------
{
	lcProduct,
	lcSerial,
	lcPrimaryInterfaceIPAddress,
	lcLAST_COLUMN
};

//-----------------------------------------------------------------------------
class DeviceListCtrl: public wxListCtrl
//-----------------------------------------------------------------------------
{
public:
	DeviceListCtrl(wxWindow *parent, const wxWindowID id, const wxPoint& pos, const wxSize& size, long style, IPConfigureFrame* pParentFrame );
	void OnColClick( wxListEvent& e );
	void OnDeleteAllItems( wxListEvent& e );
	void OnSelected( wxListEvent& e ) { SetCurrentItemIndex( e.GetIndex() ); }
	void OnDeselected( wxListEvent& e );
	void OnItemRightClick( wxListEvent& e );
	void OnAssignTemporaryIP( wxCommandEvent& e );
	int  GetCurrentItemIndex( void ) const { return m_selectedItemID; }
	void SetCurrentItemIndex( int index );
private:
	IPConfigureFrame*		m_pParentFrame;
	int						m_selectedItemID;

	DECLARE_NO_COPY_CLASS(DeviceListCtrl)
	DECLARE_EVENT_TABLE()
};

#endif // DeviceListCtrlH
