/***************************************************************
 * Name:      shuffleApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Galushin P. (galushin@gmail.com)
 * Created:   2014-09-16
 * Copyright: Galushin P. ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "shuffleApp.h"
#include "shuffleMain.h"

IMPLEMENT_APP(shuffleApp);

bool shuffleApp::OnInit()
{

    shuffleDialog* dlg = new shuffleDialog(0L, _("wxWidgets Application Template"));
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    this->SetTopWindow(dlg);
    return true;
}
