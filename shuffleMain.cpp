/***************************************************************
 * Name:      shuffleMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Galushin P. (galushin@gmail.com)
 * Created:   2014-09-16
 * Copyright: Galushin P. ()
 * License: GNU GPL v.3
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "shuffleMain.h"

#include <wx/splitter.h>
#include <wx/textctrl.h>

#include <algorithm>

#include <ctime>

shuffleDialog::shuffleDialog(wxDialog *dlg, const wxString &title)
 : wxFrame(dlg, wxID_ANY, title)
 , rnd_(std::time(0))
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    auto * main_sizer = new wxFlexGridSizer(1);
    main_sizer->AddGrowableCol(0);
    main_sizer->AddGrowableRow(0);
    this->SetSizer(main_sizer);

    text_ = new wxTextCtrl(this, wxID_ANY, wxEmptyString,
                           wxDefaultPosition, wxDefaultSize,
                           wxTE_MULTILINE | wxHSCROLL);

    main_sizer->Add(text_, 1, wxEXPAND | wxALL, 0);

    main_sizer->Add(new wxButton(this, wxID_REFRESH));

    this->Layout();

    Bind(wxEVT_BUTTON, &shuffleDialog::on_refresh, this, wxID_REFRESH);
}

void shuffleDialog::on_refresh(wxCommandEvent &)
{
    auto s = text_->GetValue().ToStdWstring();

    std::shuffle(s.begin(), s.end(), rnd_);

    text_->SetValue(s);
}
