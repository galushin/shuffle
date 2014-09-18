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

#include <random>

class shuffleDialog: public wxFrame
{
public:
    shuffleDialog(wxDialog *dlg, const wxString& title);

private:
    void on_refresh(wxCommandEvent & event);

    wxTextCtrl * text_;

    std::mt19937 rnd_;
};

#endif // SHUFFLEMAIN_H
