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

shuffleDialog::shuffleDialog(wxDialog *dlg, const wxString &title)
    : wxFrame(dlg, wxID_ANY, title)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    auto * main_sizer = new wxFlexGridSizer(1);
    main_sizer->AddGrowableCol(0);
    main_sizer->AddGrowableRow(0);
    this->SetSizer(main_sizer);

    auto * splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition,
                                           wxDefaultSize,
                                           wxSP_NO_XP_THEME | wxSP_3D);

    source = new wxTextCtrl(splitter, wxID_ANY, wxEmptyString,
                                     wxDefaultPosition, wxDefaultSize,
                                     wxTE_MULTILINE | wxHSCROLL);

    result = new wxTextCtrl(splitter, wxID_ANY, wxEmptyString,
                                     wxDefaultPosition, wxDefaultSize,
                                     wxTE_MULTILINE | wxHSCROLL);

    main_sizer->Add(splitter, 1, wxEXPAND | wxALL, 0);

    this->Layout();

    splitter->SplitHorizontally(source, result, 0);

    this->Bind(wxEVT_UPDATE_UI, &shuffleDialog::on_text_update, this,
               result->GetId());
}

void shuffleDialog::on_text_update(wxUpdateUIEvent & event)
{
    result->SetValue(source->GetValue());
}
