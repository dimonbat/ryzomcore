// NeL - MMORPG Framework <http://dev.ryzom.com/projects/nel/>
// Copyright (C) 2010  Winch Gate Property Limited
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.



#if !defined(AFX_CHOOSE_NAME_H__AF59C290_0134_437B_BACA_3698979572B5__INCLUDED_)
#define AFX_CHOOSE_NAME_H__AF59C290_0134_437B_BACA_3698979572B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// choose_name.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChooseName dialog

class CChooseName : public CDialog
{
// Construction
public:
	CChooseName(const TCHAR *initialName, CWnd* pParent = NULL);   // standard constructor

	std::string getName();

// Dialog Data
	//{{AFX_DATA(CChooseName)
	enum { IDD = IDD_CHOOSE_NAME };
	CString	m_Name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChooseName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChooseName)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHOOSE_NAME_H__AF59C290_0134_437B_BACA_3698979572B5__INCLUDED_)
