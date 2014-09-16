/***************************************************************
 * Name:      shuffleMain.h
 * Purpose:   Defines Application Frame
 * Author:    Galushin P. (galushin@gmail.com)
 * Created:   2014-09-16
 * Copyright: Galushin P. ()
 * License:
 **************************************************************/

#ifndef SHUFFLEMAIN_H
#define SHUFFLEMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "shuffleApp.h"

class shuffleDialog: public wxFrame
{
public:
    shuffleDialog(wxDialog *dlg, const wxString& title);

private:
    wxTextCtrl * source;
    wxTextCtrl * result;

    void on_text_update(wxUpdateUIEvent & event);
};

#endif // SHUFFLEMAIN_H
